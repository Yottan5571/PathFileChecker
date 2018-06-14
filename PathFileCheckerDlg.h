
// PathFileCheckerDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CPathFileCheckerDlg dialog
class CPathFileCheckerDlg : public CDialogEx
{
// Construction
public:
	CPathFileCheckerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PATHFILECHECKER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CEdit m_filePath;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	CStatic m_message;
	afx_msg void OnBnClickedButton2();
};
