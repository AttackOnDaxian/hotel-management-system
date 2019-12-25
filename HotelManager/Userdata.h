// Userdata.h: interface for the CUserdata class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_USERDATA_H__4CAF4B26_7066_4415_8ABD_F579E915CCF9__INCLUDED_)
#define AFX_USERDATA_H__4CAF4B26_7066_4415_8ABD_F579E915CCF9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CUserdata  
{
public:
	virtual BOOL GetPassword(CString *UserName, CString *Password,int *Level);
	CUserdata();
	virtual ~CUserdata();

};

#endif // !defined(AFX_USERDATA_H__4CAF4B26_7066_4415_8ABD_F579E915CCF9__INCLUDED_)
