//#include <afxwin.h>
#include <afxcmn.h>
#include "resource.h"
#include "syn.h"
#include "player.h"
#include "afxwin.h"

#define APP_TITLE "Cresta X1"
#define MAX_CUS_SLDS 8
#define SLD_MAX 100
#define FD_STEP 0.0025
#define SC_STPD 0
#define SC_PLYNG 1
#define SC_FD_OUT 2
#define SC_STPNG 3

class CrestaX1App : public CWinApp
{
	public:
		virtual BOOL InitInstance();
};

class CCusCmdLineInfo : public CCommandLineInfo
{
	public:
		int arg_cnt;
		char* pre_dir;
		char* pre_file;
		CCusCmdLineInfo() { arg_cnt = 0; }
		~CCusCmdLineInfo();
		virtual void ParseParam(const char* pszParam, BOOL bFlag, BOOL bLast);
};

class CMainDlg : public CDialog, public IPlayer::SoundEventListener
{
	public:
		CMainDlg(CWnd* pParent = NULL);
		~CMainDlg();
		char* pre_file;
		std::string m_err;
		int m_sld_id[MAX_CUS_SLDS];
		int m_lb_id[MAX_CUS_SLDS];
		Synth* m_synth;
		IPlayer* m_player;
		Mutex m_mutex;
		int m_status;
		int m_cnt;
		double m_fade; // fade in / out volume [0, 1].
		int m_ev_smps;
		double m_slew_r; // slew rate (max parameter change per sample)
		int m_n_evs; // number of sound player events
		int m_ev_sz; // size in bytes
		int m_smp_scale;
		int m_max_tm; // time available to compute sound samples during an event (msec)
		short* m_smps;
		CString m_warn_msg;
		bool initPlyr();
		bool loadBankPre(std::string fname);
		BOOL OnInitDialog();
		void DoDataExchange(CDataExchange* pDX);
		void SetSldPos(CSliderCtrl* c, int i);
		bool ReadSynth(std::string str_fname);
		bool zORng(int id);
		void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
		void OnSoundPlayerNotify(int eventNumber);
		void start();
		void updSyn();
		enum { IDD = IDD_MAIN_DIALOG };
		DECLARE_MESSAGE_MAP()
		CEdit m_bpm;
		CEdit m_meter;
		CEdit m_range;
		CSliderCtrl m_atk;
		CSliderCtrl m_sus;
		CSliderCtrl m_dec;
		CSliderCtrl m_rel;
		CSliderCtrl m_sld_c[8];
		double v_atk, v_dec, v_sus, v_rel, v_sld_c[8];
		afx_msg void OnBnClickedTest();
		afx_msg void OnBnClickedStop();
		afx_msg void OnBnClickedBtnPlay();
		afx_msg void OnLbnSelchangeLiBank();
		afx_msg void OnBnClickedBtnLoad();
		afx_msg void OnLbnDblclkLiPre();
		CListBox m_bank;
		CListBox m_pre;
		afx_msg void OnBnClickedButton1();
		afx_msg void OnBnClickedBtnRstrt();
		afx_msg void OnBnClickedBtnRend();
};