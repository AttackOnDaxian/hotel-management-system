// Userdata.cpp: implementation of the CUserdata class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HotelManager.h"
#include "Userdata.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CUserdata::CUserdata() {

}

CUserdata::~CUserdata() {

}

BOOL CUserdata::GetPassword(CString *UserName, CString *Password, int *Level) {
    //初始化Com对象
    CoInitialize(NULL);
    try {
        //初始化数据库连接对象
        _ConnectionPtr pConn("ADODB.Connection");
        //定义数据库连接字符串
        _bstr_t Connection ="Provider=Microsoft.Jet.OLEDB.4.0;Data Source=.\\HotelManager.mdb;Persist Security Info=False";
        //打开数据库连接
        pConn->Open(Connection, "", "", adConnectUnspecified);
        //初始化记录集对象
        _RecordsetPtr pRs("ADODB.Recordset");

        CString strSQL;
        strSQL.Format("%s\"%s\"", "Select * From UserInformation Where Name like ", UserName->GetBuffer(UserName->GetLength()));
        //打开指定记录集
        pRs->Open(_variant_t(strSQL.GetBuffer(strSQL.GetLength())),
                  _variant_t(pConn, true),
                  adOpenStatic,
                  adLockOptimistic,
                  adCmdText);
        //访问记录集中数据
        if (pRs->BOF) {
            //关闭记录集
            pRs->Close();
            pRs.Release();
            //关闭数据库连接
            pConn->Close();
            pConn.Release();
            UserName->ReleaseBuffer();
            Password->ReleaseBuffer();
            return FALSE; }
        else {
            strcpy(Password->GetBuffer(255), _bstr_t(pRs->GetCollect("Pwd")));

            *Level = pRs->GetCollect("level").lVal;

            pRs->Close();
            pRs.Release();
            //关闭数据库连接
            pConn->Close();
            pConn.Release();
            UserName->ReleaseBuffer();
            Password->ReleaseBuffer();
            return TRUE; } }
    catch(_com_error &e) {
        ::CoUninitialize();
        ::AfxMessageBox(e.ErrorMessage());
        return FALSE; } }
