/*
CrestaX1.cpp
Software version 1.2.0

Main project for Cresta X1 Synth.  Contains parser, synth engine, front end and sound output.

*/

#include "CrestaX1.h"
#include "RendFileDialog.h"
#include "stdafx.h"
// #include "audio_fns.h"

// to use visual leak detector:
#include "vld.h"

extern "C"
{
	#include "pre_prs_ifc.h"
	#include "pre_prs.h"
	#include "pre_lxr.h"
}

int yyparse(yyscan_t scanner);
CrestaX1App theApp;

BOOL CrestaX1App::InitInstance()
// initialise the app
{
	AfxEnableControlContainer();
	CMainDlg dlg;
	CCusCmdLineInfo cl_info;
	m_pMainWnd = &dlg;
	ParseCommandLine(cl_info);
	if (cl_info.arg_cnt > 0)
		SetCurrentDirectory(cl_info.pre_dir);
	if (cl_info.arg_cnt > 1)
		dlg.pre_file = _strdup(cl_info.pre_file);
	else
		dlg.pre_file = _strdup("presets.txt");
	dlg.DoModal();
	return FALSE;
}

CCusCmdLineInfo::~CCusCmdLineInfo()
// destructor
{
	free(pre_dir);
	free(pre_file);
}

void CCusCmdLineInfo::ParseParam(const char* pszParam, BOOL bFlag, BOOL bLast)
// stores a token from the command line
{
	if (arg_cnt == 0)
		pre_dir = _strdup(pszParam);
	else
		pre_file = _strdup(pszParam);
	arg_cnt++;
}

BEGIN_MESSAGE_MAP(CMainDlg, CDialog)
	ON_LBN_SELCHANGE(IDC_LI_BANK, &CMainDlg::OnLbnSelchangeLiBank)
	ON_LBN_DBLCLK(IDC_LI_PRE, &CMainDlg::OnLbnDblclkLiPre)
	ON_BN_CLICKED(IDC_BTN_LOAD, &CMainDlg::OnBnClickedBtnLoad)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BTN_STOP, &CMainDlg::OnBnClickedStop)
	ON_BN_CLICKED(IDC_BTN_RSTRT, &CMainDlg::OnBnClickedBtnRstrt)
	ON_BN_CLICKED(IDC_BTN_REND, &CMainDlg::OnBnClickedBtnRend)
END_MESSAGE_MAP()

CMainDlg::CMainDlg(CWnd* pParent): CDialog(CMainDlg::IDD, pParent)
// constructor
{
	m_synth = new Synth();
	m_player = NULL;
}

CMainDlg::~CMainDlg()
// destructor
{
	free(pre_file);
	freePrePrs();
	if(m_player != NULL)
		delete m_player;
	delete m_synth;
	if( m_smps != NULL )
		delete[] m_smps;
}

bool CMainDlg::initPlyr()
// initialises various variables and the sound player
{
	Player *pPlayer;
	SOUNDFORMAT format;
	std::vector<DWORD> events;
	int t, buf_sz;
	try
	{
		pPlayer = new Player();
		pPlayer->SetHWnd(m_hWnd);
		m_player = pPlayer;
		m_player->Init();
		format.NbBitsPerSample = 16;
		format.NbChannels = 1;
		format.SamplingRate = 44100;	
		m_ev_smps = 441;
		m_slew_r = 2 * 5 / (double)(format.SamplingRate);
		m_n_evs = 3;
		m_smps = new short[m_ev_smps];
		m_smp_scale = (int)pow(2, format.NbBitsPerSample - 1) - 1;
		m_max_tm = (int)((double)m_ev_smps / (double)(format.SamplingRate * 1000));
		m_ev_sz = m_ev_smps * format.NbBitsPerSample/8;
		buf_sz = m_ev_sz * m_n_evs;
		m_player->CreateSoundBuffer(format, buf_sz, 0);
		m_player->SetSoundEventListener(this);
		for(t = 0; t < m_n_evs; t++)
			events.push_back((int)((t + 1)*m_ev_sz - m_ev_sz * 0.95));
		m_player->CreateEventReadNotification(events);
		m_status = SC_STPD;
	}
	catch(MATExceptions &e)
	{
		MessageBox(e.getAllExceptionStr().c_str(), "Error initializing the sound player");
		EndDialog(IDCANCEL);
		return false;
	}
	return true;
}

bool CMainDlg::loadBankPre(std::string fname)
// load bank and preset lists
{
	int err, i;
	yyscan_t scanner;
	FILE *src;
	std::string name_str;
	bool ret_val;
	pre_fname = _strdup(fname.c_str());
	if (prelex_init(&scanner))
 	{
		m_err = "Error initialising scanner.";
        return false;
	}
	src = fopen(fname.c_str(), "r");
	if (src == NULL)
	{
		m_err = "Could not open file: " + fname;
		ret_val = false;
	}
	else
	{
		preset_in(src, scanner);
		initPrePrs();
		err = preparse(scanner);
		if (err)
		{
			m_err = pre_err;
			ret_val = false;
		}
		else
		{
			if (pre_err[0] == 0)
			{
				for (i = 0; i < num_banks; i++)
					m_bank.AddString(bank[i]);
				ret_val = true;
			}
			else
			{
				m_err = pre_err;
				ret_val = false;
			}
		}
		fclose(src);
	}
    pre_delete_buffer(0, scanner);
    prelex_destroy(scanner);
	free(pre_fname);
	return ret_val;
}

BOOL CMainDlg::OnInitDialog()
// initialise dialog and variables
{
	CDialog::OnInitDialog();
	int i;
	m_lb_id[0] = IDC_LB_C1;
	m_lb_id[1] = IDC_LB_C2;
	m_lb_id[2] = IDC_LB_C3;
	m_lb_id[3] = IDC_LB_C4;
	m_lb_id[4] = IDC_LB_C5;
	m_lb_id[5] = IDC_LB_C6;
	m_lb_id[6] = IDC_LB_C7;
	m_lb_id[7] = IDC_LB_C8;
	m_sld_id[0] = IDC_SLD_C1;
	m_sld_id[1] = IDC_SLD_C2;
	m_sld_id[2] = IDC_SLD_C3;
	m_sld_id[3] = IDC_SLD_C4;
	m_sld_id[4] = IDC_SLD_C5;
	m_sld_id[5] = IDC_SLD_C6;
	m_sld_id[6] = IDC_SLD_C7;
	m_sld_id[7] = IDC_SLD_C8;
	SetDlgItemText(IDC_LB_BANK, "Bank");
	SetDlgItemText(IDC_LB_PRE, "Preset");
	SetDlgItemText(IDC_LB_BPM, "BPM");
	SetDlgItemText(IDC_LB_METER, "Meter");
	SetDlgItemText(IDC_LB_RANGE, "Range");
	SetDlgItemText(IDC_LB_ATK, "Attack Time");
	SetDlgItemText(IDC_LB_DEC, "Decay Time");
	SetDlgItemText(IDC_LB_SUS, "Sustain Level");
	SetDlgItemText(IDC_LB_REL, "Release Time");
	SetDlgItemText(IDC_LB_C1, "Custom 1");
	SetDlgItemText(IDC_LB_C2, "Custom 2");
	SetDlgItemText(IDC_LB_C3, "Custom 3");
	SetDlgItemText(IDC_LB_C4, "Custom 4");
	SetDlgItemText(IDC_LB_C5, "Custom 5");
	SetDlgItemText(IDC_LB_C6, "Custom 6");
	SetDlgItemText(IDC_LB_C7, "Custom 7");
	SetDlgItemText(IDC_LB_C8, "Custom 8");
	GetDlgItem(IDC_BTN_STOP)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_RSTRT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_REND)->EnableWindow(FALSE);
	m_atk.SetRange(0, SLD_MAX, TRUE);
	m_dec.SetRange(0, SLD_MAX, TRUE);
	m_sus.SetRange(0, SLD_MAX, TRUE);
	m_rel.SetRange(0, SLD_MAX, TRUE);
	for (i = 0; i < MAX_CUS_SLDS; i++)
		m_sld_c[i].SetRange(0, SLD_MAX, TRUE);
	if (loadBankPre(pre_file))
	{
		if (m_bank.GetCount() > 0)
		{
			m_bank.SetCurSel(0);
			OnLbnSelchangeLiBank();
		}
	}
	else
		MessageBox(m_err.c_str());
	return initPlyr();
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
// exchange data for various controls 
{
	DDX_Control(pDX, IDC_LI_BANK, m_bank);
	DDX_Control(pDX, IDC_LI_PRE, m_pre);
	DDX_Control(pDX, IDC_ED_BPM, m_bpm);
	DDX_Control(pDX, IDC_ED_METER, m_meter);
	DDX_Control(pDX, IDC_ED_RANGE, m_range);
	DDX_Control(pDX, IDC_SL_ATK, m_atk);
	DDX_Control(pDX, IDC_SL_SUS, m_sus);
	DDX_Control(pDX, IDC_SL_DEC, m_dec);
	DDX_Control(pDX, IDC_SL_REL, m_rel);
	DDX_Control(pDX, IDC_SLD_C1, m_sld_c[0]);
	DDX_Control(pDX, IDC_SLD_C2, m_sld_c[1]);
	DDX_Control(pDX, IDC_SLD_C3, m_sld_c[2]);
	DDX_Control(pDX, IDC_SLD_C4, m_sld_c[3]);
	DDX_Control(pDX, IDC_SLD_C5, m_sld_c[4]);
	DDX_Control(pDX, IDC_SLD_C6, m_sld_c[5]);
	DDX_Control(pDX, IDC_SLD_C7, m_sld_c[6]);
	DDX_Control(pDX, IDC_SLD_C8, m_sld_c[7]);
	DDX_Control(pDX, IDC_ED_METER, m_meter);
}

void CMainDlg::SetSldPos(CSliderCtrl *c, int i)
// sets the slider passed (if visible) to the value in the matching synth parameter
{
	if (i < m_synth->num_cus_slds)
	{
		if (zORng(i))
			c->SetPos((int)(m_synth->getSldVal(i) * SLD_MAX));
		else
			c->SetPos((int)((double)((m_synth->getSldVal(i) + 1) * 0.5) * SLD_MAX));
	}
}

bool CMainDlg::ReadSynth(std::string str_fname)
// read synth from file and set the controls accordingly
{
	CString cs;
	int i;
	if (m_synth->read(str_fname))
	{
		for (i = 0; i < m_synth->num_cus_slds; i++)
		{
			SetDlgItemText(m_lb_id[i], m_synth->cus_sld[i].name.c_str());
			GetDlgItem(m_lb_id[i])->ShowWindow(SW_SHOW);
			GetDlgItem(m_sld_id[i])->ShowWindow(SW_SHOW);
		}
		for (i = m_synth->num_cus_slds; i < MAX_CUS_SLDS; i++)
		{
			GetDlgItem(m_lb_id[i])->ShowWindow(SW_HIDE);
			GetDlgItem(m_sld_id[i])->ShowWindow(SW_HIDE);
		}
		cs.Format("%3.1f", m_synth->sp.bpm);
		GetDlgItem(IDC_ED_BPM)->SetWindowText(cs);
		cs.Format("%d", m_synth->sp.meter);
		GetDlgItem(IDC_ED_METER)->SetWindowText(cs);
		cs.Format("%d", m_synth->sp.range);
		GetDlgItem(IDC_ED_RANGE)->SetWindowText(cs);
		m_atk.SetPos((int)(m_synth->sp.atk * SLD_MAX));
		m_dec.SetPos((int)(m_synth->sp.dec * SLD_MAX));
		m_sus.SetPos((int)(m_synth->sp.sus * SLD_MAX));
		m_rel.SetPos((int)(m_synth->sp.rel * SLD_MAX));
		for (i = 0; i < m_synth->num_cus_slds; i++)
			SetSldPos(&(m_sld_c[i]), i);
		v_atk = m_synth->sp.atk;
		v_dec = m_synth->sp.dec;
		v_sus = m_synth->sp.sus;
		v_rel = m_synth->sp.rel;
		for (i = 0; i < m_synth->num_cus_slds; i++)
			v_sld_c[i] = m_synth->getSldVal(i);
		return true;
	}
	else
	{
		MessageBox(m_synth->err_str.c_str());
		return false;
	}
}

void CMainDlg::start()
// starts playback
{
	m_pre.EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_LOAD)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_RSTRT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_STOP)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_REND)->EnableWindow(FALSE);
	m_synth->initSeq();
	m_status = SC_PLYNG;
	m_fade = 1;
	m_player->Play(1);
}

void CMainDlg::OnLbnSelchangeLiBank()
// displays the appropriate list of presets
{
	CString bank_cstr;
	int i;
	int bank_idx = m_bank.GetCurSel();
	if (bank_idx != LB_ERR)
	{
		m_bank.GetText(bank_idx, bank_cstr);
		m_pre.ResetContent();
		for (i = 0; i < num_pres; i++)
			if (strcmp(bank_cstr, pre[i].bank) == 0)
				m_pre.AddString(pre[i].name);
	}
}

void CMainDlg::OnLbnDblclkLiPre()
// loads the selected preset
{
	OnBnClickedBtnLoad();
}

void CMainDlg::OnBnClickedBtnLoad()
// loads the selected preset
{
	ScopeGuardMutex guard(&m_mutex);
	CString pre_cstr;
	std::string pre_str;
	int pre_idx;
	pre_idx = m_pre.GetCurSel();
	if (pre_idx != LB_ERR)
	{
		m_pre.GetText(pre_idx, pre_cstr);
		pre_str = pre_cstr;
		pre_str += ".txt";
		if (ReadSynth(pre_str))
			start();
	}
}

bool CMainDlg::zORng(int id)
{
    switch(id)
    {
        case IDC_SL_ATK:
			return true;
        case IDC_SL_DEC:
			return true;
        case IDC_SL_SUS:
			return true;
        case IDC_SL_REL:
			return true;
        case IDC_SLD_C1:
			return m_synth->isZORng(0);
        case IDC_SLD_C2:
			return m_synth->isZORng(1);
        case IDC_SLD_C3:
			return m_synth->isZORng(2);
        case IDC_SLD_C4:
			return m_synth->isZORng(3);
        case IDC_SLD_C5:
			return m_synth->isZORng(4);
        case IDC_SLD_C6:
			return m_synth->isZORng(5);
        case IDC_SLD_C7:
			return m_synth->isZORng(6);
        case IDC_SLD_C8:
			return m_synth->isZORng(7);
        default:
            return false;
    }
}

void CMainDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
// catches slider horizontal scrolling events
{
    CSliderCtrl *sld_ctrl;
	double val;
    int id;
	ScopeGuardMutex guard(&m_mutex);
    sld_ctrl = (CSliderCtrl *)pScrollBar;
    id = sld_ctrl->GetDlgCtrlID();
	if (zORng(id))
		val = (double)(((CSliderCtrl *)pScrollBar)->GetPos()) / (double)SLD_MAX;
	else
		val = (double)(2*((CSliderCtrl *)pScrollBar)->GetPos()) / (double)SLD_MAX - 1;
    switch(id)
    {
        case IDC_SL_ATK:
			v_atk = val;
            break;
        case IDC_SL_DEC:
			v_dec = val;
            break;
        case IDC_SL_SUS:
			v_sus = val;
            break;
        case IDC_SL_REL:
			v_rel = val;
            break;
        case IDC_SLD_C1:
			v_sld_c[0] = val;
            break;
        case IDC_SLD_C2:
			v_sld_c[1] = val;
            break;
        case IDC_SLD_C3:
			v_sld_c[2] = val;
            break;
        case IDC_SLD_C4:
			v_sld_c[3] = val;
            break;
        case IDC_SLD_C5:
			v_sld_c[4] = val;
            break;
        case IDC_SLD_C6:
			v_sld_c[5] = val;
            break;
        case IDC_SLD_C7:
			v_sld_c[6] = val;
            break;
        case IDC_SLD_C8:
			v_sld_c[7] = val;
            break;
        default:
            break;
    }
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CMainDlg::OnSoundPlayerNotify(int ev_num)
// render some sound samples and check for errors
{
	ScopeGuardMutex guard(&m_mutex);
	int i, j, end, begin, elapsed;
	bool stop;
	begin = GetTickCount();
	stop = false;
	if (m_status == SC_STPNG)
	{
		for(i = 0; i < m_ev_smps; i++)
			m_smps[i] = 0;
		if (m_cnt == m_n_evs)
			stop = true;
		m_cnt++;
	}
	else
	{
		try
		{
			for(i = 0; i < m_ev_smps; i++)
			{
				m_synth->sp.atk = Synth::slew(m_synth->sp.atk, v_atk, m_slew_r);
				m_synth->sp.dec = Synth::slew(m_synth->sp.dec, v_dec, m_slew_r);
				m_synth->sp.sus = Synth::slew(m_synth->sp.sus, v_sus, m_slew_r);
				m_synth->sp.rel = Synth::slew(m_synth->sp.rel, v_rel, m_slew_r);
				for (j = 0; j < m_synth->num_cus_slds; j++)
					m_synth->setSldVal(j, Synth::slew(m_synth->getSldVal(j), v_sld_c[j], m_slew_r));
				m_smps[i] = (int)(m_synth->rend(true) * m_smp_scale * m_fade);
				if (m_status == SC_FD_OUT)
				{
					m_fade -= FD_STEP;
					if (m_fade < 0)
					{
						m_fade = 0;
						m_status = SC_STPNG;
						m_cnt = 0;
					}
				}
			}
		}
		catch(MATExceptions &e)
		{
			OutputDebugString(e.getAllExceptionStr().c_str());
		}
	}
	try
	{
		m_player->Write(((ev_num + 1) % m_n_evs)*m_ev_sz, (unsigned char*)m_smps, m_ev_sz);
	}
	catch(MATExceptions &e)
	{
		OutputDebugString(e.getAllExceptionStr().c_str()); // it would be better to stop the program...
	}			
	end = GetTickCount();
	elapsed = end - begin;
	if(elapsed > m_max_tm)
		m_warn_msg.Format(_T("Warning! compute time: %dms"), elapsed);
	else
		m_warn_msg.Format(_T("compute time: %dms"), elapsed);
	if (stop)
	{
		m_player->Stop();
		m_status = SC_STPD;
		m_pre.EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_LOAD)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_RSTRT)->EnableWindow(TRUE);
	}
}

void CMainDlg::OnBnClickedStop()
// causes fade out
{
	ScopeGuardMutex guard(&m_mutex);
	m_status = SC_FD_OUT;
	GetDlgItem(IDC_BTN_STOP)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_REND)->EnableWindow(TRUE);
}

void CMainDlg::updSyn()
// updates synth with dialog settings
{
	CString txt;
	double t;
	int i;
	m_bpm.GetWindowText(txt);
	t = atof(txt);
	if (t < 5)
		t = 5;
	else if (t > 1800)
		t = 1800;
	m_synth->sp.bpm = t;
	m_meter.GetWindowText(txt);
	i = atoi(txt);
	m_synth->sp.meter = i;
	m_range.GetWindowText(txt);
	i = atoi(txt);
	if (i < 1)
		i = 1;
	else if (i > 60)
		i = 60;
	m_synth->sp.range = i;
	m_synth->calcPrms();
	m_synth->calcTot();
	m_synth->recalcPos();
}

void CMainDlg::OnBnClickedBtnRstrt()
// gets variables from the dialog and reinitialises
{
	updSyn();
	start();
}

void CMainDlg::OnBnClickedBtnRend()
// gets the sequencer count and file name then render the wav file
{
	CRendFileDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		updSyn();
		m_synth->rendFile(dlg.fname, dlg.cnt);
	}
}
