//{{AFX_INCLUDES()
#include "datagrid.h"
//}}AFX_INCLUDES
#if !defined(AFX_ROOMDLG_H__C818F08F_0287_49A9_8CF6_F9035CCE8ED7__INCLUDED_)
#define AFX_ROOMDLG_H__C818F08F_0287_49A9_8CF6_F9035CCE8ED7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RoomDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRoomDlg dialog

class CRoomDlg : public CDialog
{
// Construction
public:
	void UpdateList();
	CRoomDlg(CWnd* pParent = NULL);   // standard constructor
	_RecordsetPtr m_pRecordset;
// Dialog Data
	//{{AFX_DATA(CRoomDlg)
	enum { IDD = IDD_ROOM_DLG };
	CString	m_strRoomStatus;
	CString	m_strRoomType;
	CString	m_strRoomId;
	int		m_nRoomPrice;
	CDataGrid	m_dgRoom;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRoomDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRoomDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnAddRoomBtn();
	afx_msg void OnModifyRoomBtn();
	afx_msg void OnDeleteRoomBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROOMDLG_H__C818F08F_0287_49A9_8CF6_F9035CCE8ED7__INCLUDED_)
