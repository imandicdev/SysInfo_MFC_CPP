
// SysInfoMFC.cpp : Defines the class behaviors for the application.
// Copyright (C) Ilija Mandic, 2020.
#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "SysInfoMFC.h"
#include "MainFrm.h"

#include "SysInfoMFCDoc.h"
#include "SysInfoMFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSysInfoMFCApp

BEGIN_MESSAGE_MAP(CSysInfoMFCApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CSysInfoMFCApp::OnAppAbout)
	ON_COMMAND(ID_APP_SCAN, &CSysInfoMFCApp::OnAppScan)

	// Standard file based document commands
	//ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	//ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	
END_MESSAGE_MAP()


// CSysInfoMFCApp construction

CSysInfoMFCApp::CSysInfoMFCApp() noexcept
{
	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("SysInfoMFC.AppID.NoVersion"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// The one and only CSysInfoMFCApp object

CSysInfoMFCApp theApp;


// CSysInfoMFCApp initialization

BOOL CSysInfoMFCApp::InitInstance()
{
	CWinApp::InitInstance();


	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// AfxInitRichEdit2() is required to use RichEdit control
	// AfxInitRichEdit2();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	LoadStdProfileSettings(4);  // Load standard INI file options (including MRU)


	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CSysInfoMFCDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CSysInfoMFCView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// Dispatch commands specified on the command line.  Will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

int CSysInfoMFCApp::ExitInstance()
{
	//TODO: handle additional resources you may have added
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// CSysInfoMFCApp message handlers


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// App command to run the dialog
void CSysInfoMFCApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CSysInfoMFCApp message handlers


class CScanDlg : public CDialogEx
{
public:
	CScanDlg() noexcept;

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMfcbutton1();
};

CScanDlg::CScanDlg() noexcept : CDialogEx(IDD_DIALOG1)
{
}

void CScanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CScanDlg, CDialogEx)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &CScanDlg::OnBnClickedMfcbutton1)
END_MESSAGE_MAP()

// App command to run the dialog
void CSysInfoMFCApp::OnAppScan()
{
	CScanDlg scanDlg;
	scanDlg.DoModal();




}





void CScanDlg::OnBnClickedMfcbutton1()
{
	CString  myProcNum, myPageSize,myProcArc;
	

	SYSTEM_INFO si;
	::GetNativeSystemInfo(&si);

	myProcNum.Format(_T("%u"), si.dwNumberOfProcessors);
	myPageSize.Format(_T("%u"), si.dwPageSize);
	myProcArc.Format(_T("%u"), si.wProcessorArchitecture);
	

	SetDlgItemText(IDC_EDIT2, myProcNum);
	SetDlgItemText(IDC_EDIT3, myPageSize);
	//if (myProcArc == "9") SetDlgItemText(IDC_EDIT4,_T("AMD"));
	
		switch (_ttoi(myProcArc))
		{
		case 9:
			SetDlgItemText(IDC_EDIT4, _T("x64 AMD"));
			break;
		case 5:
			SetDlgItemText(IDC_EDIT4, _T("ARM"));
			break;
		case 12:
			SetDlgItemText(IDC_EDIT4, _T("ARM64"));
			break;
		case 6:
			SetDlgItemText(IDC_EDIT4, _T("Intel Itanium"));
			break;
		case 0:
			SetDlgItemText(IDC_EDIT4, _T("x86 Intel"));
			break;
		default:
			try {
			}
			catch (CException *ex) { ex->ReportError(); AfxMessageBox(_T("The operation is not implemented"));
			}
	
		}
	
	

	
	UpdateData(FALSE);

	// TODO: Add your control notification handler code here
}
