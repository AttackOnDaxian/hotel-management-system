// HotelManagerDlg.h : header file
//

#if !defined(AFX_HotelManagerDLG_H__7CAE93DF_2EAE_4D85_87B9_FC2C13451B13__INCLUDED_)
#define AFX_HotelManagerDLG_H__7CAE93DF_2EAE_4D85_87B9_FC2C13451B13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHotelManagerDlg dialog
#include "UserDlg.h"
#include "RegisterDlg.h"
#include "StandardDlg.h"
#include "OrderDlg.h"
#include "RoomDlg.h"
#include "CheckDlg.h"

class CHotelManagerDlg : public CDialog
{
// Construction
public:
	CHotelManagerDlg(CWnd* pParent = NULL);	// standard constructor
	CUserDlg * m_pUserDlg;
	CRegisterDlg *  m_pRegisterDlg;
	CStandardDlg *m_pStandardDlg;
	COrderDlg *m_pOrderDlg;
	CRoomDlg * m_pRoomDlg;
	CCheckDlg *m_pCheckDlg;
	BOOL status[5];
	void SetDlgStatus();
// Dialog Data
	//{{AFX_DATA(CHotelManagerDlg)
	enum { IDD = IDD_HotelManager_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHotelManagerDlg)
	public:
	virtual	BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHotelManagerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMenuZhuce();
	afx_msg void OnMenuDenglu();
	afx_msg void OnMenuExit();
	afx_msg void OnMENUkfbz();
	afx_msg void OnMENUdfxx();
	afx_msg void OnMENUkfxx();
	afx_msg void OnMenuCaizheng();
	afx_msg void OnMENUHelp();
		afx_msg void OnIconCaizheng();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CToolBar m_Toolbar;
	CStatusBar m_Statusbar;
	CImageList m_Imagelist;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HotelManagerDLG_H__7CAE93DF_2EAE_4D85_87B9_FC2C13451B13__INCLUDED_)
