// CheckDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HotelManager.h"
#include "CheckDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCheckDlg dialog
extern CHotelManagerApp theApp;

CCheckDlg::CCheckDlg(CWnd* pParent /*=NULL*/)
    : CDialog(CCheckDlg::IDD, pParent) {
    //{{AFX_DATA_INIT(CCheckDlg)
    m_strCheckId = _T("");
    m_strCheckName = _T("");
    m_strCheckNum = _T("");
    m_nCheckPeople = 0;
    m_nDinner = 0;
    m_nCheckMoney = 0;
    m_nYajin = 0;
    m_timeOrderD = 0;
    m_timeOrderT = 0;
    m_timeCheckD = 0;
    m_timeCheckT = 0;
    m_strCheckType = _T("");
    //}}AFX_DATA_INIT
}


void CCheckDlg::DoDataExchange(CDataExchange* pDX) {
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CCheckDlg)
    DDX_Control(pDX, IDC_DATETIMEPICKER_DAY, m_timectrlOrderD);
    DDX_Control(pDX, IDC_DATETIMEPICKER_TIME, m_timectrlOrderT);
    DDX_Text(pDX, IDC_EDIT_CHECK_ID, m_strCheckId);
    DDX_Text(pDX, IDC_EDIT_CHECK_NAME, m_strCheckName);
    DDX_Text(pDX, IDC_EDIT_CHECK_NUM, m_strCheckNum);
    DDX_Text(pDX, IDC_EDIT_CHECK_PEOPLE, m_nCheckPeople);
    DDX_Text(pDX, IDC_EDIT_CHECK_DINNER, m_nDinner);
    DDX_Text(pDX, IDC_EDIT_CHECK_MONEY, m_nCheckMoney);
    DDX_Text(pDX, IDC_EDIT_CHECK_YAJIN, m_nYajin);
    DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_TIME, m_timeOrderD);
    DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_DAY, m_timeOrderT);
    DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_CHECKDAY, m_timeCheckD);
    DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_CHECKTIME, m_timeCheckT);
    DDX_CBString(pDX, IDC_COMBO_CHECK_TYPE, m_strCheckType);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCheckDlg, CDialog)
    //{{AFX_MSG_MAP(CCheckDlg)
    ON_BN_CLICKED(IDC_CAL_BTN, OnCalBtn)
    ON_BN_CLICKED(IDC_CHECK_BTN, OnCheckBtn)
    ON_EN_CHANGE(IDC_EDIT_CHECK_ID, OnChangeEditCheckId)
    //ON_COMMAND(ID_MENU_Help, OnMENUHelp)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCheckDlg message handlers

void CCheckDlg::OnCalBtn() {
    // TODO: Add your control notification handler code here
    if (theApp.m_blogin==false) {
        MessageBox("���ȵ�¼��","��ʾ",MB_ICONEXCLAMATION );
        return; }
    if((!(theApp.m_level >=4 && theApp.m_level <= 7)) && (!(theApp.m_level >=12 && theApp.m_level <= 15)) ) {
        AfxMessageBox("���������˷�Ȩ��");
        return; }
    UpdateData(TRUE);
    CString sql,str;
    //������״̬����Ϊ�����С�
    _RecordsetPtr m_pRecordset_room;
    str = "����";
    sql = "select * from RoomInformation where ID = '"+m_strCheckId+"'and Status = '"+str+"'";
    m_pRecordset_room.CreateInstance("ADODB.Recordset");
    m_pRecordset_room->Open((_variant_t)sql,_variant_t((IDispatch *)theApp.m_pConnection,true),adOpenDynamic,adLockPessimistic,adCmdText);
    if(m_pRecordset_room->GetRecordCount()!=0) {
        m_pRecordset_room->PutCollect("Status",(_variant_t)"����");
        m_pRecordset_room->Update(); }
    else {
        AfxMessageBox("û�иÿͷ��Ķ�����Ϣ���˷�ʧ�ܣ�");
        return; }
    m_pRecordset_room->Close();
    //ɾ���ö�����Ϣ
    sql = "select * from OrderInfo where ID = '"+m_strCheckId+"'";
    m_pRecordset.CreateInstance("ADODB.Recordset");
    m_pRecordset->Open((_variant_t)sql,_variant_t((IDispatch *)theApp.m_pConnection,true),adOpenDynamic,adLockPessimistic,adCmdText);
    if(m_pRecordset->GetRecordCount()!=0) {
        m_pRecordset->Delete(adAffectCurrent); }
    m_pRecordset->Update();
    m_pRecordset->Close();

    AfxMessageBox("�˷��ɹ���");
    UpdateData(FALSE); }

void CCheckDlg::OnCheckBtn() {
    // TODO: Add your control notification handler code here
    if (theApp.m_blogin==false) {
        MessageBox("���ȵ�¼��","��ʾ",MB_ICONEXCLAMATION );
        return; }
    if( theApp.m_level%2 == 0) { //ȡ��
        AfxMessageBox("����������ӽ�����Ϣ��Ȩ��");
        return; }

    UpdateData(TRUE);

    CString sql,str,str1;
    int price;
    //��ȡ�ͷ�����
    _RecordsetPtr m_pRecordset_room;
    str = "����";
    sql = "select * from RoomInformation where ID = '"+m_strCheckId+"' and Status = '"+str+"'";
    m_pRecordset_room.CreateInstance("ADODB.Recordset");
    m_pRecordset_room->Open((_variant_t)sql,_variant_t((IDispatch *)theApp.m_pConnection,true),adOpenDynamic,adLockPessimistic,adCmdText);
    if(m_pRecordset_room->GetRecordCount()!=0) {
        price = m_pRecordset_room->GetCollect("Price").lVal; }
    else {
        AfxMessageBox("��ȡ�ÿͷ���Ϣʧ�ܣ���ʱ���ܽ��㣡");
        return; }
    m_pRecordset_room->Close();
    //������סʱ���:10���Ժ�����һ��
    m_timeCheckD = CTime::GetCurrentTime();
    m_timeCheckT = CTime::GetCurrentTime();
    CTimeSpan d1 = m_timeCheckD - m_timeOrderD;
    int day = d1.GetDays() ;
    if(m_timeCheckD.GetHour() >=10) {
        day +=1 ; }

    //�ۿ�
    float repay;
    if(m_strCheckType.CompareNoCase("��Ա") == 0) { //8��
        repay = (float)0.8; }
    else if(m_strCheckType.CompareNoCase("����") == 0) {   //9��
        repay = (float)0.9; }
    else {
        repay = (float)1.0; }

    //�����ܽ��
    m_nCheckMoney = (int)((m_nDinner + price )*day*repay - m_nYajin);

    _RecordsetPtr m_pRecordset_check;
    //��ӽ�����Ϣ
    sql = "select * from CheckInfo ";
    m_pRecordset_check.CreateInstance("ADODB.Recordset");
    m_pRecordset_check->Open((_variant_t)sql,_variant_t((IDispatch *)theApp.m_pConnection,true),adOpenDynamic,adLockPessimistic,adCmdText);
    m_pRecordset_check->AddNew();
    m_pRecordset_check->PutCollect("ID",(_variant_t)m_strCheckId);
    str.Format("%d",price);
    m_pRecordset_check->PutCollect("Price",(_variant_t)str);
    str.Format("%d",m_nDinner);
    m_pRecordset_check->PutCollect("Dinner",(_variant_t)str);
    str.Format("%d-%d-%d",m_timeCheckD.GetYear(),m_timeCheckD.GetMonth(),m_timeCheckD.GetDay());
    m_pRecordset_check->PutCollect("EndDay",(_variant_t)str);
    str.Format("%d:%d:%d",m_timeCheckT.GetHour(),m_timeCheckT.GetMinute(),m_timeCheckT.GetSecond());
    m_pRecordset_check->PutCollect("EndTime",(_variant_t)str);
    str.Format("%d",day);
    m_pRecordset_check->PutCollect("Day",(_variant_t)str);
    str.Format("%2f",repay);
    m_pRecordset_check->PutCollect("Repay",(_variant_t)str);
    str.Format("%d",m_nCheckMoney);
    m_pRecordset_check->PutCollect("Money",(_variant_t)str);

    m_pRecordset_check->Update();
    m_pRecordset_check->Close();
    UpdateData(FALSE); }

void CCheckDlg::OnChangeEditCheckId() {

    // TODO: Add your control notification handler code here
    UpdateData(TRUE);

    CString sql,str,str1;
    sql = "select * from OrderInfo where ID = '"+m_strCheckId+"'";
    m_pRecordset.CreateInstance("ADODB.Recordset");
    m_pRecordset->Open((_variant_t)sql,_variant_t((IDispatch *)theApp.m_pConnection,true),adOpenDynamic,adLockPessimistic,adCmdText);

    if(m_pRecordset->GetRecordCount()!= 0) {
        m_strCheckType = m_pRecordset->GetCollect("OrderType").bstrVal;
        m_strCheckName = m_pRecordset->GetCollect("OrderName").bstrVal;
        m_strCheckNum = m_pRecordset->GetCollect("OrderPaper").bstrVal;
        m_nCheckPeople = m_pRecordset->GetCollect("OrderAcount").lVal;
        m_nDinner = m_pRecordset->GetCollect("Dinner").lVal;
        m_nYajin = m_pRecordset->GetCollect("Deposit").lVal;

        str = m_pRecordset->GetCollect("StartDay").bstrVal;
        m_timectrlOrderD.SetFormat(str);

        str = m_pRecordset->GetCollect("StartTime").bstrVal;
        m_timectrlOrderT.SetFormat(str);

        str = m_pRecordset->GetCollect("StartDay").bstrVal;
        m_timectrlOrderD.SetFormat(str);

        str1 = m_pRecordset->GetCollect("StartTime").bstrVal;
        m_timectrlOrderT.SetFormat(str1);
        //str to CTime
        m_timeOrderD   =   strtotime(str, str1); }
    m_pRecordset->Close();
    UpdateData(FALSE); }

int CCheckDlg::StrToIntAt(CString string, int startPos, int endPos) {
    CString   strChange   =   _T("");
    char   c_change;
    for   (int   i=startPos;   i<=endPos;   i++) {
        c_change   =   string.GetAt   (i);
        strChange   +=   c_change; }
    int   iresult   =   (int)atof(strChange);
    return   iresult; }

CTime CCheckDlg::strtotime(CString str, CString str1) {
    int  iYear,   iMonth,   iDay, iHour,   iMinute,   iSecond;

    int one = str.Find("-", 1) ;
    int two = str.Find("-",one+1) ;
    int length = str.GetLength();

    iYear   =   StrToIntAt(str,   0,   one-1);
    iMonth  =   StrToIntAt(str,   one+1,   two-1);
    iDay    =   StrToIntAt(str,   two+1,   length-1);

    one = str1.Find(":", 1) ;
    two = str1.Find(":",one+1) ;
    length = str1.GetLength();

    iHour   =   StrToIntAt(str1,  0,   one-1);
    iMinute =   StrToIntAt(str1,  one+1,   two-1);
    iSecond =   StrToIntAt(str1,  two+1,   length-1);

    CTime time = CTime(iYear,   iMonth,   iDay,   iHour,   iMinute,   iSecond);
    return time; }

