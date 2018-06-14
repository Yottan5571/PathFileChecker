
// PathFileCheckerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PathFileChecker.h"
#include "PathFileCheckerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPathFileCheckerDlg dialog



CPathFileCheckerDlg::CPathFileCheckerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PATHFILECHECKER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPathFileCheckerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_PATH, m_filePath);
	DDX_Control(pDX, IDC_STATIC_01, m_message);
}

BEGIN_MESSAGE_MAP(CPathFileCheckerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CPathFileCheckerDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDCANCEL, &CPathFileCheckerDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CPathFileCheckerDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, &CPathFileCheckerDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CPathFileCheckerDlg message handlers

BOOL CPathFileCheckerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPathFileCheckerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPathFileCheckerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPathFileCheckerDlg::OnBnClickedButton1()
{
	CString path = L"";
	m_filePath.GetWindowTextW(path);

	CFileFind ff;
	ff.FindFile(path, NULL);
	DWORD ret = GetLastError();
	
	
	CString message;
	message.Format(L"File find Error code = %d", ret);
	m_message.SetWindowTextW(message);
}


void CPathFileCheckerDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CPathFileCheckerDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void CPathFileCheckerDlg::OnBnClickedButton2()
{
	CString path = L"";
	m_filePath.GetWindowTextW(path);

	CreateDirectory(path, NULL);

	DWORD err = GetLastError();

	CString message;
	message.Format(L"Create directory Error code = %d", err);
	m_message.SetWindowTextW(message);
}
