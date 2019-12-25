#if !defined(AFX_CHECKDLG_H__49253113_2B0F_47D0_A8EF_364A0532F3A5__INCLUDED_)
#define AFX_CHECKDLG_H__49253113_2B0F_47D0_A8EF_364A0532F3A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CheckDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCheckDlg dialog

class CCheckDlg : public CDialog
{
// Construction
public:
	CTime strtotime(CString   str,CString str1);
	int StrToIntAt(CString   string,   int   startPos,   int   endPos);
	_RecordsetPtr m_pRecordset;
	CCheckDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCheckDlg)
//	enum={IDI_ICON_Cancel};
	enum { IDD = IDD_CHECK_DLG };
	CDateTimeCtrl	m_timectrlOrderD;
	CDateTimeCtrl	m_timectrlOrderT;
	CString	m_strCheckId;
	CString	m_strCheckName;
	CString	m_strCheckNum;
	int		m_nCheckPeople;
	int		m_nDinner;
	int		m_nCheckMoney;
	int		m_nYajin;
	CTime	m_timeOrderD;
	CTime	m_timeOrderT;
	CTime	m_timeCheckD;
	CTime	m_timeCheckT;
	CString	m_strCheckType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCheckDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCheckDlg)
	afx_msg void OnCalBtn();
	afx_msg void OnCheckBtn();
	afx_msg void OnChangeEditCheckId();
	afx_msg void OnMENUHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHECKDLG_H__49253113_2B0F_47D0_A8EF_364A0532F3A5__INCLUDED_)
