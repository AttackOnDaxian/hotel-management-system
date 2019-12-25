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
    //��ʼ��Com����
    CoInitialize(NULL);
    try {
        //��ʼ�����ݿ����Ӷ���
        _ConnectionPtr pConn("ADODB.Connection");
        //�������ݿ������ַ���
        _bstr_t Connection ="Provider=Microsoft.Jet.OLEDB.4.0;Data Source=.\\HotelManager.mdb;Persist Security Info=False";
        //�����ݿ�����
        pConn->Open(Connection, "", "", adConnectUnspecified);
        //��ʼ����¼������
        _RecordsetPtr pRs("ADODB.Recordset");

        CString strSQL;
        strSQL.Format("%s\"%s\"", "Select * From UserInformation Where Name like ", UserName->GetBuffer(UserName->GetLength()));
        //��ָ����¼��
        pRs->Open(_variant_t(strSQL.GetBuffer(strSQL.GetLength())),
                  _variant_t(pConn, true),
                  adOpenStatic,
                  adLockOptimistic,
                  adCmdText);
        //���ʼ�¼��������
        if (pRs->BOF) {
            //�رռ�¼��
            pRs->Close();
            pRs.Release();
            //�ر����ݿ�����
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
            //�ر����ݿ�����
            pConn->Close();
            pConn.Release();
            UserName->ReleaseBuffer();
            Password->ReleaseBuffer();
            return TRUE; } }
    catch(_com_error &e) {
        ::CoUninitialize();
        ::AfxMessageBox(e.ErrorMessage());
        return FALSE; } }
