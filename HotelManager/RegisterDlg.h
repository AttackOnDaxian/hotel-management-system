#if !defined(AFX_REGISTERDLG_H__E4675B35_816C_4077_A4E4_3E116C3E2DEC__INCLUDED_)
#define AFX_REGISTERDLG_H__E4675B35_816C_4077_A4E4_3E116C3E2DEC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RegisterDlg.h : header file
//
//extern CHotelManagerApp theApp;
/////////////////////////////////////////////////////////////////////////////
// CRegisterDlg dialog

class CRegisterDlg : public CDialog
{
// Construction
public:
	int Level();
	_RecordsetPtr m_pRs;
	CRegisterDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRegisterDlg)
	enum { IDD = IDD_REGISTER_DIALOG };
	CButton	m_LookFor;
	CButton	m_Edit;
	CButton	m_Del;
	CButton	m_Add;
	CEdit	m_Password;
	CEdit	m_PasswordC;
	CEdit	m_UserName;
	CEdit   m_ID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegisterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRegisterDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGISTERDLG_H__E4675B35_816C_4077_A4E4_3E116C3E2DEC__INCLUDED_)
