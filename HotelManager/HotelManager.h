// HotelManager.h : main header file for the HotelManager application
//

#if !defined(AFX_HotelManager_H__8B803593_6653_4ED5_964E_ED7AE1BC4274__INCLUDED_)
#define AFX_HotelManager_H__8B803593_6653_4ED5_964E_ED7AE1BC4274__INCLUDED_
//#import "C:\\Program Files\\Common Files\\System\\ado\\msado15.dll"no_namespace rename("EOF","adoEOF")

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHotelManagerApp:
// See HotelManager.cpp for the implementation of this class
//

class CHotelManagerApp : public CWinApp
{
public:
	bool m_blogin;
	CHotelManagerApp();
	int m_level;
//	CString pwd;
//	CString name;
	_ConnectionPtr m_pConnection;

//	CHotelManagerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHotelManagerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHotelManagerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HotelManager_H__8B803593_6653_4ED5_964E_ED7AE1BC4274__INCLUDED_)
