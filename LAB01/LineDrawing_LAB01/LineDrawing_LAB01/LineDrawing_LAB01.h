
// LineDrawing_LAB01.h : main header file for the LineDrawing_LAB01 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CLineDrawingLAB01App:
// See LineDrawing_LAB01.cpp for the implementation of this class
//

class CLineDrawingLAB01App : public CWinAppEx
{
public:
	CLineDrawingLAB01App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLineDrawingLAB01App theApp;
