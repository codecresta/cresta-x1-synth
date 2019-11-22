#include "resource.h"

class CRendFileDialog : public CDialog
{
public:
	enum { IDD = IDD_REND_DIALOG };
	CRendFileDialog(CWnd* pParent = NULL);
	~CRendFileDialog();
	BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	CEdit m_fname;
	CEdit m_cnt;
	std::string fname;
	int cnt;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	DECLARE_MESSAGE_MAP()
};