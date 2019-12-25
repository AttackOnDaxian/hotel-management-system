// RoomDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HotelManager.h"
#include "RoomDlg.h"
#include "Columns.h"
#include "Column.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CHotelManagerApp theApp;
/////////////////////////////////////////////////////////////////////////////
// CRoomDlg dialog


CRoomDlg::CRoomDlg(CWnd* pParent /*=NULL*/)
    : CDialog(CRoomDlg::IDD, pParent) {
    //{{AFX_DATA_INIT(CRoomDlg)
    m_strRoomStatus = _T("");
    m_strRoomType = _T("");
    m_strRoomId = _T("");
    m_nRoomPrice = 0;
    //}}AFX_DATA_INIT
}


void CRoomDlg::DoDataExchange(CDataExchange* pDX) {
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CRoomDlg)
    DDX_CBString(pDX, IDC_COMBO_ROOM_STATUS, m_strRoomStatus);
    DDX_CBString(pDX, IDC_COMBO_ROOM_TYPE, m_strRoomType);
    DDX_Text(pDX, IDC_EDIT_ROOM_ID, m_strRoomId);
    DDX_Text(pDX, IDC_EDIT_ROOM_PRICE, m_nRoomPrice);
    DDX_Control(pDX, IDC_DATAGRID_ROOM, m_dgRoom);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRoomDlg, CDialog)
    //{{AFX_MSG_MAP(CRoomDlg)
    ON_BN_CLICKED(IDC_ADD_ROOM_BTN, OnAddRoomBtn)
    ON_BN_CLICKED(IDC_MODIFY_ROOM_BTN, OnModifyRoomBtn)
    ON_BN_CLICKED(IDC_DELETE_ROOM_BTN, OnDeleteRoomBtn)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRoomDlg message handlers

BOOL CRoomDlg::OnInitDialog() {
    CDialog::OnInitDialog();

    // TODO: Add extra initialization here
    m_strRoomStatus=_T("");
    m_strRoomType=_T("");
    m_strRoomId=_T("");
    m_nRoomPrice=0;

    m_pRecordset.CreateInstance("ADODB.Recordset");
    m_pRecordset->Open("SELECT * FROM RoomInformation",_variant_t((IDispatch *)theApp.m_pConnection,true),adOpenDynamic,adLockPessimistic,adCmdText);

    m_dgRoom.SetRefDataSource(NULL);

    m_dgRoom.SetRefDataSource((LPUNKNOWN)m_pRecordset);
    m_dgRoom.SetColumnHeaders(2);

    _variant_t var;
    var=long(0);
    m_dgRoom.GetColumns().GetItem(var).SetCaption("编号");
    m_dgRoom.GetColumns().GetItem(var).SetWidth(40);
    var=long(1);
    m_dgRoom.GetColumns().GetItem(var).SetCaption("类型");
    m_dgRoom.GetColumns().GetItem(var).SetWidth(60);
    var=long(2);
    m_dgRoom.GetColumns().GetItem(var).SetCaption("价格");
    m_dgRoom.GetColumns().GetItem(var).SetWidth(40);
    var=long(3);
    m_dgRoom.GetColumns().GetItem(var).SetCaption("状态");
    m_dgRoom.GetColumns().GetItem(var).SetWidth(50);
    var=long(4);
    m_dgRoom.Refresh();
    UpdateData(FALSE);

    return TRUE;  // return TRUE unless you set the focus to a control
    // EXCEPTION: OCX Property Pages should return FALSE
}

void CRoomDlg::OnAddRoomBtn() {
    // TODO: Add your control notification handler code here
    if (theApp.m_blogin==false) {
        MessageBox("请先登录！","提示",MB_ICONEXCLAMATION );
        return; }
    if( theApp.m_level%2 == 0) { //取余
        AfxMessageBox("您不具有添加客房信息的权限");
        return; }
    if (m_strRoomId==_T("")||m_strRoomStatus==_T("")) {
        MessageBox("请先填入完整信息！","提示",MB_ICONEXCLAMATION );
        return; }
    UpdateData(TRUE);
    CString sql,str;
    _RecordsetPtr m_pRecordset_;
    sql = "select * from RoomInformation where ID = '"+m_strRoomId+"'";
    m_pRecordset.CreateInstance("ADODB.Recordset");
    m_pRecordset->Open((_variant_t)sql,_variant_t((IDispatch *)theApp.m_pConnection,true),adOpenDynamic,adLockPessimistic,adCmdText);
    if (m_pRecordset->GetRecordCount()>0 ) {
        AfxMessageBox("该客房信息已添加");
        return; }
    else {
        m_pRecordset->AddNew();
        m_pRecordset->PutCollect("ID",(_variant_t)m_strRoomId);
        m_pRecordset->PutCollect("Type",(_variant_t)m_strRoomType);
        str.Format("%d",m_nRoomPrice);
        m_pRecordset->PutCollect("Price",(_variant_t)str);
        m_pRecordset->PutCollect("Status",(_variant_t)m_strRoomStatus);
        m_pRecordset->Update();
        m_pRecordset->Close();
        UpdateList();
        UpdateData(FALSE); } }

void CRoomDlg::UpdateList() {
    m_pRecordset.CreateInstance("ADODB.Recordset");
    m_pRecordset->Open("SELECT * FROM RoomInformation",_variant_t((IDispatch *)theApp.m_pConnection,true),adOpenDynamic,adLockPessimistic,adCmdText);

    m_dgRoom.SetRefDataSource(NULL);

    m_dgRoom.SetRefDataSource((LPUNKNOWN)m_pRecordset);
    m_dgRoom.SetColumnHeaders(2);

    _variant_t var;
    var=long(0);
    m_dgRoom.GetColumns().GetItem(var).SetCaption("编号");
    m_dgRoom.GetColumns().GetItem(var).SetWidth(40);
    var=long(1);
    m_dgRoom.GetColumns().GetItem(var).SetCaption("类型");
    m_dgRoom.GetColumns().GetItem(var).SetWidth(40);
    var=long(2);
    m_dgRoom.GetColumns().GetItem(var).SetCaption("价格");
    m_dgRoom.GetColumns().GetItem(var).SetWidth(40);
    var=long(3);
    m_dgRoom.GetColumns().GetItem(var).SetCaption("状态");
    m_dgRoom.GetColumns().GetItem(var).SetWidth(50);
    var=long(4);
    m_dgRoom.Refresh();
    UpdateData(FALSE); }

void CRoomDlg::OnModifyRoomBtn() {
    // TODO: Add your control notification handler code here
    if (theApp.m_blogin==false) {
        MessageBox("请先登录！","提示",MB_ICONEXCLAMATION );
        return; }
    if(theApp.m_level!=2&&theApp.m_level!=3&&theApp.m_level!=6&&theApp.m_level!=7&&
            theApp.m_level!=10&&theApp.m_level!=11&&theApp.m_level!=14&&theApp.m_level!=15) {
        AfxMessageBox("您不具有修改客房信息的权限");
        return; }
    UpdateData(TRUE);
    CString sql,str;
    sql = "select * from RoomInformation where ID='"+m_strRoomId+"'";
    m_pRecordset.CreateInstance("ADODB.Recordset");
    m_pRecordset->Open((_variant_t)sql,_variant_t((IDispatch *)theApp.m_pConnection,true),adOpenDynamic,adLockPessimistic,adCmdText);
    if(m_pRecordset->GetRecordCount()!=0) {
        m_pRecordset->PutCollect("Type",(_variant_t)m_strRoomType);

        str.Format("%d",m_nRoomPrice);
        m_pRecordset->PutCollect("Price",(_variant_t)str);
        m_pRecordset->PutCollect("Status",(_variant_t)m_strRoomStatus);
        m_pRecordset->Update(); }
    else {
        AfxMessageBox("该客房信息不存在，修改失败！"); }
    m_pRecordset->Close();
    UpdateList();
    UpdateData(FALSE); }

void CRoomDlg::OnDeleteRoomBtn() {
    // TODO: Add your control notification handler code here
    if (theApp.m_blogin==false) {
        MessageBox("请先登录！","提示",MB_ICONEXCLAMATION );
        return; }
    if((!(theApp.m_level >=4 && theApp.m_level <= 7)) && (!(theApp.m_level >=12 && theApp.m_level <= 15)) ) {
        AfxMessageBox("您不具有删除客房信息的权限");
        return; }
    UpdateData(TRUE);
    CString sql,str;
    sql = "select * from RoomInformation where ID='"+m_strRoomId+"'";
    m_pRecordset.CreateInstance("ADODB.Recordset");
    m_pRecordset->Open((_variant_t)sql,_variant_t((IDispatch *)theApp.m_pConnection,true),adOpenDynamic,adLockPessimistic,adCmdText);

    if(m_pRecordset->GetRecordCount()!=0) {
        m_pRecordset->Delete(adAffectCurrent);
        m_pRecordset->Update(); }
    else {
        AfxMessageBox("该客房信息不存在，删除失败！"); }
    m_pRecordset->Close();

    UpdateList();
    UpdateData(FALSE); }
