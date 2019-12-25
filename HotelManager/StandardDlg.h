//{{AFX_INCLUDES()
#include "datagrid.h"
//}}AFX_INCLUDES
#if !defined(AFX_STANDARDDLG_H__E5DD73DA_C367_4C5C_B468_4BE14F3287A9__INCLUDED_)
#define AFX_STANDARDDLG_H__E5DD73DA_C367_4C5C_B468_4BE14F3287A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StandardDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStandardDlg dialog

class CStandardDlg : public CDialog
{
// Construction
public:
	void UpdateList();
	_RecordsetPtr m_pRecordset;
	int m_nStanPrice;
	int m_nPeople;
	CStandardDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CStandardDlg)
	enum { IDD = IDD_STANDARD_DLG };
	BOOL	m_Aircondition;
	BOOL	m_Internet;
	BOOL	m_Telephone;
	BOOL	m_Television;
	BOOL	m_Washroom;
	CString	m_strStanType;
	CDataGrid	m_dgStandard;
	CString	m_strStanId;
	int		m_nStanArea;
	//int		m_nStanPrice;
	//int		m_nPeople;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStandardDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStandardDlg)
	afx_msg void OnAddStanBtn();
	virtual BOOL OnInitDialog();
	afx_msg void OnModifyStanBtn();
	afx_msg void OnDelStanBtn();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STANDARDDLG_H__E5DD73DA_C367_4C5C_B468_4BE14F3287A9__INCLUDED_)
