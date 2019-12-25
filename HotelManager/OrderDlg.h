//{{AFX_INCLUDES()
#include "datagrid.h"
//}}AFX_INCLUDES
#if !defined(AFX_ORDERDLG_H__1CD21D3D_D505_4EDD_9A68_555C7477C2AB__INCLUDED_)
#define AFX_ORDERDLG_H__1CD21D3D_D505_4EDD_9A68_555C7477C2AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OrderDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COrderDlg dialog

class COrderDlg : public CDialog
{
// Construction
public:
	void UpdateList();
	COrderDlg(CWnd* pParent = NULL);   // standard constructor
	_RecordsetPtr m_pRecordset;
// Dialog Data
	//{{AFX_DATA(COrderDlg)
	enum { IDD = IDD_ORDER_DLG };
	CDateTimeCtrl	m_timectrlOrderT;
	CDateTimeCtrl	m_timectrlOrderD;
	CString	m_strOrderId;
	CString	m_strOrderName;
	CString	m_strOrderNum;
	int		m_nOrderPeople;
	int		m_nOrderYajin;
	CString	m_strOrderType;
	CDataGrid	m_dgOrder;
	CTime	m_timeOrderD;
	CTime	m_timeOrderT;
	CString	m_strOrderDinner;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COrderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COrderDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnOrderBtn();
	afx_msg void OnDelOrderBtn();
	afx_msg void OnChangeEditOrderId();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ORDERDLG_H__1CD21D3D_D505_4EDD_9A68_555C7477C2AB__INCLUDED_)
