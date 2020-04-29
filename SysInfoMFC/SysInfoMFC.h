
// SysInfoMFC.h : main header file for the SysInfoMFC application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSysInfoMFCApp:
// See SysInfoMFC.cpp for the implementation of this class
//

class CSysInfoMFCApp : public CWinApp
{
public:
	CSysInfoMFCApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnAppScan();
};

extern CSysInfoMFCApp theApp;
