// OrderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HotelManager.h"
#include "OrderDlg.h"
#include "Columns.h"
#include "Column.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COrderDlg dialog
extern CHotelManagerApp theApp;

COrderDlg::COrderDlg(CWnd* pParent /*=NULL*/)
    : CDialog(COrderDlg::IDD, pParent) {
    //{{AFX_DATA_INIT(COrderDlg)
    m_strOrderId = _T("");
    m_strOrderName = _T("");
    m_strOrderNum = _T("");
    m_nOrderPeople = 0;
    m_nOrderYajin = 0;
    m_strOrderType = _T("");
    m_timeOrderD = 0;
    m_timeOrderT = 0;
    m_strOrderDinner = _T("");
    //}}AFX_DATA_INIT
}


void COrderDlg::DoDataExchange(CDataExchange* pDX) {
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(COrderDlg)
    DDX_Control(pDX, IDC_DATETIMEPICKER2, m_timectrlOrderT);
    DDX_Control(pDX, IDC_DATETIMEPICKER1, m_timectrlOrderD);
    DDX_Text(pDX, IDC_EDIT_ORDER_ID, m_strOrderId);
    DDX_Text(pDX, IDC_EDIT_ORDER_NAME, m_strOrderName);
    DDX_Text(pDX, IDC_EDIT_ORDER_NUM, m_strOrderNum);
    DDX_Text(pDX, IDC_EDIT_ORDER_PEOPLE, m_nOrderPeople);
    DDX_Text(pDX, IDC_EDIT_ORDER_YAJIN, m_nOrderYajin);
    DDX_CBString(pDX, IDC_COMBO_ORDER_TYPE, m_strOrderType);
    DDX_Control(pDX, IDC_DATAGRID_ORDER, m_dgOrder);
    DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_timeOrderD);
    DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER2, m_timeOrderT);
    DDX_CBString(pDX, IDC_COMBO_DINNER, m_strOrderDinner);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COrderDlg, CDialog)
    //{{AFX_MSG_MAP(COrderDlg)
    ON_BN_CLICKED(IDC_ORDER_BTN, OnOrderBtn)
    ON_BN_CLICKED(IDC_DEL_ORDER_BTN, OnDelOrderBtn)
    ON_EN_CHANGE(IDC_EDIT_ORDER_ID, OnChangeEditOrderId)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COrderDlg message handlers

BOOL COrderDlg::OnInitDialog() {
    CDialog::OnInitDialog();


    // TODO: Add extra initialization here
    m_strOrderDinner = _T("100");
    m_strOrderType = _T("会员");
    m_timeOrderD = 0;
    m_timeOrderT = 0;
    m_strOrderId = _T("0");
    m_strOrderName = _T("0");
    m_strOrderNum = _T("1");
    m_nOrderPeople = 0;
    m_nOrderYajin = 0;
    m_timeOrderD = CTime::GetCurrentTime();
    m_timeOrderT = CTime::GetCurrentTime();

    m_pRecordset.CreateInstance("ADODB.Recordset");
    m_pRecordset->Open("SELECT * FROM OrderInfo",_variant_t((IDispatch *)theApp.m_pConnection,true),adOpenDynamic,adLockPessimistic,adCmdText);

    m_dgOrder.SetRefDataSource(NULL);
    m_dgOrder.SetRefDataSource((LPUNKNOWN)m_pRecordset);
    m_dgOrder.SetColumnHeaders(2) ;

    _variant_t var;
    var = long(0);
    m_dgOrder.GetColumns().GetItem(var).SetCaption("编号");
    m_dgOrder.GetColumns().GetItem(var).SetWidth(40);
    var = long(1);
    m_dgOrder.GetColumns().GetItem(var).SetCaption("类型");
    m_dgOrder.GetColumns().GetItem(var).SetWidth(40);
    var = long(2);
    m_dgOrder.GetColumns().GetItem(var).SetCaption("登记人");
    m_dgOrder.GetColumns().GetItem(var).SetWidth(60);
    var = long(3);
    m_dgOrder.GetColumns().GetItem(var).SetCaption("证件号");
    m_dgOrder.GetColumns().GetItem(var).SetWidth(60);
    var = long(4);
    m_dgOrder.GetColumns().GetItem(var).SetCaption("人数");
    m_dgOrder.GetColumns().GetItem(var).SetWidth(40);
    var = long(5);
    m_dgOrder.GetColumns().GetItem(var).SetCaption("入住日期");
    m_dgOrder.GetColumns().GetItem(var).SetWidth(80);
    var = long(6);
    m_dgOrder.GetColumns().GetItem(var).SetCaption("入住时间");
    m_dgOrder.GetColumns().GetItem(var).SetWidth(80);
    var = long(7);
    m_dgOrder.GetColumns().GetItem(var).SetCaption("订餐");
    m_dgOrder.GetColumns().GetItem(var).SetWidth(40);
    var = long(8);
    m_dgOrder.GetColumns().GetItem(var).SetCaption("押金");
    m_dgOrder.GetColumns().GetItem(var).SetWidth(40);

    m_dgOrder.Refresh();

    UpdateData(FALSE);
    return TRUE; // return TRUE unless you set the focus to a control
    // EXCEPTION: OCX Property Pages should return FALSE
}

void COrderDlg::OnOrderBtn() {
    // TODO: Add your control notification handler code here
    if (theApp.m_blogin==false) {
        MessageBox("请先登录！","提示",MB_ICONEXCLAMATION );
        return; }
    if( theApp.m_level%2 == 0) { //取余
        AfxMessageBox("您不具有添加订房信息的权限");
        return; }
    UpdateData(TRUE);
    CString sql,str;
    //将房间状态设置为“已满”
    _RecordsetPtr m_pRecordset_room;
    sql = "select * from RoomInformation where ID = '"+m_strOrderId+"'";
    m_pRecordset_room.CreateInstance("ADODB.Recordset");
    m_pRecordset_room->Open((_variant_t)sql,_variant_t((IDispatch *)theApp.m_pConnection,true),adOpenDynamic,adLockPessimistic,adCmdText);
    if(m_pRecordset_room->GetRecordCount()!=0) {
        CString str;
        str=m_pRecordset_room->GetCollect("Status").bstrVal;
        if(str.CompareNoCase("已满")==0) {
            AfxMessageBox("该客房已满，请换个房间");
            return; }
        //
        //添加订房信息
        sql = "select * from OrderInfo ";
        m_pRecordset.CreateInstance("ADODB.Recordset");
        m_pRecordset->Open((_variant_t)sql,_variant_t((IDispatch *)theApp.m_pConnection,true),adOpenDynamic,adLockPessimistic,adCmdText);



        if(	m_strOrderDinner == _T("")||m_strOrderType == _T("")||m_strOrderId ==_T("")||m_strOrderName == _T("")||	m_strOrderNum == _T("")) {
            AfxMessageBox("请输入完整信息");
            return; }
        m_pRecordset->AddNew();
        m_pRecordset->PutCollect("ID",(_variant_t)m_strOrderId);
        m_pRecordset->PutCollect("OrderType",(_variant_t)m_strOrderType);
        m_pRecordset->PutCollect("OrderName",(_variant_t)m_strOrderName);
        m_pRecordset->PutCollect("OrderPaper",(_variant_t)m_strOrderNum);

        str.Format("%d",m_nOrderPeople);
        m_pRecordset->PutCollect("OrderAcount",(_variant_t)str);

        m_timeOrderD = CTime::GetCurrentTime();

        str.Format("%d-%d-%d",m_timeOrderD.GetYear(),m_timeOrderD.GetMonth(),m_timeOrderD.GetDay());
        m_pRecordset->PutCollect("StartDay",(_variant_t)str);

        m_timeOrderT = CTime::GetCurrentTime();
        str.Format("%d:%d:%d",m_timeOrderT.GetHour(),m_timeOrderT.GetMinute(),m_timeOrderT.GetSecond());
        m_pRecordset->PutCollect("StartTime",(_variant_t)str);

        m_pRecordset->PutCollect("Dinner",(_variant_t)m_strOrderDinner);

        str.Format("%d",m_nOrderYajin);
        m_pRecordset->PutCollect("Deposit",(_variant_t)str);

        m_pRecordset->Update();
        m_pRecordset->Close();
        //

        m_pRecordset_room->PutCollect("Status",(_variant_t)"已满");
        AfxMessageBox("订房成功！谢谢");
        m_pRecordset_room->Update();

    }
    else {
        AfxMessageBox("该客房不存在，订房失败！");
        return; }
    m_pRecordset_room->Close();


    UpdateList();
    UpdateData(FALSE); }

void COrderDlg::UpdateList() {
    m_pRecordset.CreateInstance("ADODB.Recordset");
    m_pRecordset->Open("SELECT * FROM OrderInfo",_variant_t((IDispatch *)theApp.m_pConnection,true),adOpenDynamic,adLockPessimistic,adCmdText);

    m_dgOrder.SetRefDataSource(NULL);
    m_dgOrder.SetRefDataSource((LPUNKNOWN)m_pRecordset);
    m_dgOrder.SetColumnHeaders(2) ;

    _variant_t var;
    var = long(0);
    m_dgOrder.GetColumns().GetItem(var).SetCaption("编号");
    m_dgOrder.GetColumns().GetItem(var).SetWidth(40);
    var = long(1);
    m_dgOrder.GetColumns().GetItem(var).SetCaption("类型");
    m_dgOrder.GetColumns().GetItem(var).SetWidth(40);
    var = long(2);
    m_dgOrder.GetColumns().GetItem(var).SetCaption("登记人");
    m_dgOrder.GetColumns().GetItem(var).SetWidth(60);
    var = long(3);
    m_dgOrder.GetColumns().GetItem(var).SetCaption("证件号");
    m_dgOrder.GetColumns().GetItem(var).SetWidth(60);
    var = long(4);
    m_dgOrder.GetColumns().GetItem(var).SetCaption("人数");
    m_dgOrder.GetColumns().GetItem(var).SetWidth(30);
    var = long(5);
    m_dgOrder.GetColumns().GetItem(var).SetCaption("入住日期");
    m_dgOrder.GetColumns().GetItem(var).SetWidth(80);
    var = long(6);
    m_dgOrder.GetColumns().GetItem(var).SetCaption("入住时间");
    m_dgOrder.GetColumns().GetItem(var).SetWidth(80);
    var = long(7);
    m_dgOrder.GetColumns().GetItem(var).SetCaption("订餐");
    m_dgOrder.GetColumns().GetItem(var).SetWidth(40);
    var = long(8);
    m_dgOrder.GetColumns().GetItem(var).SetCaption("押金");
    m_dgOrder.GetColumns().GetItem(var).SetWidth(40);

    m_dgOrder.Refresh();

    UpdateData(FALSE); }

void COrderDlg::OnDelOrderBtn() {
    // TODO: Add your control notification handler code here
    if (theApp.m_blogin==false) {
        MessageBox("请先登录！","提示",MB_ICONEXCLAMATION );
        return; }
    if((!(theApp.m_level >=4 && theApp.m_level <= 7)) && (!(theApp.m_level >=12 && theApp.m_level <= 15)) ) {
        AfxMessageBox("您不具有删除订房信息的权限");
        return; }
    UpdateData(TRUE);
    UpdateData(TRUE);
    CString sql,str;
    //将房间状态设置为“空闲”
    _RecordsetPtr m_pRecordset_room;
    sql = "select * from RoomInformation where ID = '"+m_strOrderId+"'";
    m_pRecordset_room.CreateInstance("ADODB.Recordset");
    m_pRecordset_room->Open((_variant_t)sql,_variant_t((IDispatch *)theApp.m_pConnection,true),adOpenDynamic,adLockPessimistic,adCmdText);
    if(m_pRecordset_room->GetRecordCount()>0) {
        m_pRecordset_room->PutCollect("Status",(_variant_t)"空闲");
        m_pRecordset_room->Update(); }
    else {
        AfxMessageBox("没有该客房的信息，删除失败！");

        return; }
    m_pRecordset_room->Close();
    sql = "select * from OrderInfo where ID='"+m_strOrderId+"'";

    m_pRecordset.CreateInstance("ADODB.Recordset");
    m_pRecordset->Open((_variant_t)sql,_variant_t((IDispatch *)theApp.m_pConnection,true),adOpenDynamic,adLockPessimistic,adCmdText);

    if(m_pRecordset->GetRecordCount()!=0) {
        m_pRecordset->Delete(adAffectCurrent); }
    else {
        AfxMessageBox("没有该客房的订房信息，删除失败！");
        return; }
    m_pRecordset->Update();
    m_pRecordset->Close();

    UpdateList();
    UpdateData(FALSE);

}

void COrderDlg::OnChangeEditOrderId() {
    // TODO: If this is a RICHEDIT control, the control will not
    // send this notification unless you override the CDialog::OnInitDialog()
    // function and call CRichEditCtrl().SetEventMask()
    // with the ENM_CHANGE flag ORed into the mask.

    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    CString sql,str;
    sql = "select * from OrderInfo where ID = '"+m_strOrderId+"'";
    m_pRecordset.CreateInstance("ADODB.Recordset");
    m_pRecordset->Open((_variant_t)sql,_variant_t((IDispatch *)theApp.m_pConnection,true),adOpenDynamic,adLockPessimistic,adCmdText);
    if(m_pRecordset->GetRecordCount()!= 0) {
        m_strOrderType = m_pRecordset->GetCollect("OrderType").bstrVal;
        m_strOrderName = m_pRecordset->GetCollect("OrderName").bstrVal;
        m_strOrderNum = m_pRecordset->GetCollect("OrderPaper").bstrVal;
        m_nOrderPeople = m_pRecordset->GetCollect("OrderAcount").lVal;
        str = m_pRecordset->GetCollect("StartDay").bstrVal;
        m_timectrlOrderD.SetFormat(str);
        str = m_pRecordset->GetCollect("StartTime").bstrVal;
        m_timectrlOrderT.SetFormat(str);
        int dinner = m_pRecordset->GetCollect("Dinner").lVal;
        m_strOrderDinner.Format("%d",dinner);
        m_nOrderYajin= m_pRecordset->GetCollect("Deposit").lVal; }
    else {
        m_strOrderDinner = _T("");
        m_strOrderType = _T("");
        m_timeOrderD = 0;
        m_timeOrderT = 0;
        m_strOrderName = _T("");
        m_strOrderNum= _T("");
        m_nOrderPeople = 0;
        m_nOrderYajin = 0; }
    m_pRecordset->Close();

    UpdateData(FALSE); }
