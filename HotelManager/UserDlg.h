#if !defined(AFX_USERDLG_H__3CFE2F19_18A4_46EE_ACD8_350453F981B1__INCLUDED_)
#define AFX_USERDLG_H__3CFE2F19_18A4_46EE_ACD8_350453F981B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserDlg.h : header file
//

#include "Userdata.h"
/////////////////////////////////////////////////////////////////////////////
// CUserDlg dialog

class CUserDlg : public CDialog
{
// Construction
public:
	int Count;
//	int i;
	//_RecordsetPtr m_pRs;
	CUserDlg(CWnd* pParent = NULL);   // standard constructor
	CUserdata* m_userdata;
// Dialog Data
	//{{AFX_DATA(CUserDlg)
	enum { IDD = IDD_USER_DLG };
	CEdit	m_Upasswd;
	CEdit	m_Uname;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserDlg)
	afx_msg void OnButtonLogin();
	virtual BOOL OnInitDialog();
	afx_msg void OnBUTTONCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERDLG_H__3CFE2F19_18A4_46EE_ACD8_350453F981B1__INCLUDED_)
