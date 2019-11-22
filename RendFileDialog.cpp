// RendFileDialog.cpp : implementation file
//

#include <string>
#include "stdafx.h"
#include "RendFileDialog.h"
//#include "afxdialogex.h"

#define MAX_SEQ_CNT 64

//IMPLEMENT_DYNAMIC(CRendFileDialog, CDialog)

BEGIN_MESSAGE_MAP(CRendFileDialog, CDialog)
	ON_BN_CLICKED(IDOK, &CRendFileDialog::OnBnClickedOk)
END_MESSAGE_MAP()

CRendFileDialog::CRendFileDialog(CWnd* pParent): CDialog(CRendFileDialog::IDD, pParent)
// constructor
{
}

CRendFileDialog::~CRendFileDialog()
// destructor
{
}

BOOL CRendFileDialog::OnInitDialog()
// initialise dialog and variables
{
	CDialog::OnInitDialog();
	SetDlgItemText(IDC_LB_CNT, "Sequences");
	return true;
}

void CRendFileDialog::DoDataExchange(CDataExchange* pDX)
// updates the control variable
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ED_CNT, m_cnt);
}

void CRendFileDialog::OnBnClickedOk()
// validates the count then opens a file save dialog
{
	CString txt;
	m_cnt.GetWindowText(txt);
	cnt = atoi(txt);
	if ((cnt > 0) && (cnt <= MAX_SEQ_CNT))
	{
		txt = "Wav Files (*.wav)|*.wav";
		CFileDialog file_dlg(FALSE, CString(".wav"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, txt);
		if (file_dlg.DoModal() == IDOK)
		{
			fname = file_dlg.GetPathName();
			CDialog::OnOK();
		}
	}
	else
	{
		std::string str = "Value must be between 1 and " + std::to_string(MAX_SEQ_CNT) + " inclusively.";
		MessageBox(str.c_str(), "Warning", 0);
	}
}