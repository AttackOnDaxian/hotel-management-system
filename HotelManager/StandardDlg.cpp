// StandardDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HotelManager.h"
#include "StandardDlg.h"
#include "Columns.h"
#include "Column.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStandardDlg dialog

extern CHotelManagerApp theApp;
CStandardDlg::CStandardDlg(CWnd* pParent /*=NULL*/)
    : CDialog(CStandardDlg::IDD, pParent) {
    //{{AFX_DATA_INIT(CStandardDlg)
    m_Aircondition = FALSE;
    m_Internet = FALSE;
    m_Telephone = FALSE;
    m_Television = FALSE;
    m_Washroom = FALSE;
    m_strStanType = _T("");
    m_strStanId = _T("");
    m_nStanArea = 0;
    m_nStanPrice = 0;
    m_nPeople = 0;
    //}}AFX_DATA_INIT
}


void CStandardDlg::DoDataExchange(CDataExchange* pDX) {
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CStandardDlg)
    DDX_Check(pDX, IDC_CHECK_AIRCONDITION, m_Aircondition);
    DDX_Check(pDX, IDC_CHECK_INTERNET, m_Internet);
    DDX_Check(pDX, IDC_CHECK_TELEPHONE, m_Telephone);
    DDX_Check(pDX, IDC_CHECK_TELEVISION, m_Television);
    DDX_Check(pDX, IDC_CHECK_WASHROOM, m_Washroom);
    DDX_CBString(pDX, IDC_COMBO_STAN_TYPE, m_strStanType);
    DDX_Control(pDX, IDC_DATAGRID_STANDARD, m_dgStandard);
    DDX_Text(pDX, IDC_EDIT_STAN_ID, m_strStanId);
    DDX_Text(pDX, IDC_EDIT_STAN_AREA, m_nStanArea);
    DDX_Text(pDX, IDC_EDIT_STAN_PRICE, m_nStanPrice);
    DDX_Text(pDX, IDC_EDIT_STAN_PEOPLE, m_nPeople);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStandardDlg, CDialog)
    //{{AFX_MSG_MAP(CStandardDlg)
    ON_BN_CLICKED(ID_ADD_STAN_BTN, OnAddStanBtn)
    ON_BN_CLICKED(IDC_MODIFY_STAN_BTN, OnModifyStanBtn)
    ON_BN_CLICKED(IDC__DEL_STAN_BTN, OnDelStanBtn)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStandardDlg message handlers

void CStandardDlg::OnAddStanBtn() {
    // TODO: Add your control notification handler code here
    if (theApp.m_blogin==false) {
        MessageBox("请先登录！","提示",MB_ICONEXCLAMATION );
        return; }
    if( theApp.m_level%2 == 0) { //取余
        AfxMessageBox("您不具有添加客房标准信息的权限");
        return; }
    UpdateData(TRUE);
    CString sql,str;
    sql= "select * from RoomStandard where ID = '"+m_strStanId+"'";
    m_pRecordset.CreateInstance("ADODB.Recordset");
    m_pRecordset->Open((_variant_t)sql,_variant_t((IDispatch *)theApp.m_pConnection,true),adOpenDynamic,adLockPessimistic,adCmdText);
    if (m_pRecordset->GetRecordCount()>0) {
        AfxMessageBox("该客房已添加,请重新输入客房");
        return; }
    else {
        m_pRecordset->AddNew();

        m_pRecordset->PutCollect("ID",(_variant_t)m_strStanId);

        str.Format("%d",m_Aircondition);
        m_pRecordset->PutCollect("Aircondition",(_variant_t)str);

        str.Format("%d",m_Internet);
        m_pRecordset->PutCollect("Internet",(_variant_t)str);

        str.Format("%d",m_Telephone);
        m_pRecordset->PutCollect("Telephone",(_variant_t)str);

        str.Format("%d",m_Television);
        m_pRecordset->PutCollect("Television",(_variant_t)str);

        str.Format("%d",m_Washroom);
        m_pRecordset->PutCollect("Washroom",(_variant_t)str);

        m_pRecordset->PutCollect("Type",(_variant_t)m_strStanType);

        str.Format("%d",m_nStanArea);
        m_pRecordset->PutCollect("Area",(_variant_t)str);

        str.Format("%d",m_nPeople);
        m_pRecordset->PutCollect("PeopleNum",(_variant_t)str);

        str.Format("%d",m_nStanPrice);
        m_pRecordset->PutCollect("Price",(_variant_t)str);
        m_pRecordset->Update();
        m_pRecordset->Close();

        UpdateList();

        UpdateData(FALSE); } }

BOOL CStandardDlg::OnInitDialog() {
    CDialog::OnInitDialog();

    // TODO: Add extra initialization here
    m_Aircondition=FALSE;
    m_Internet=FALSE;
    m_Telephone=FALSE;
    m_Washroom=FALSE;
    m_Television=FALSE;
    m_strStanType=_T("单人间");
    m_nStanArea=0;
//	m_nStanArea=_T("0");
    m_nPeople=0;
    m_nStanPrice=0;
    m_pRecordset.CreateInstance("ADODB.Recordset");
    m_pRecordset->Open("SELECT * FROM RoomStandard",_variant_t((IDispatch *)theApp.m_pConnection,true),adOpenDynamic,adLockPessimistic,adCmdText);
    m_dgStandard.SetRefDataSource(NULL);
    m_dgStandard.SetRefDataSource((LPUNKNOWN)m_pRecordset);
    m_dgStandard.SetColumnHeaders(2) ;
    _variant_t var;
    var = long(0);
    m_dgStandard.GetColumns().GetItem(var).SetCaption("编号");
    m_dgStandard.GetColumns().GetItem(var).SetWidth(40);
    var=long(1);
    m_dgStandard.GetColumns().GetItem(var).SetCaption("类型");
    m_dgStandard.GetColumns().GetItem(var).SetWidth(55);
    var = long(2);
    m_dgStandard.GetColumns().GetItem(var).SetCaption("面积");
    m_dgStandard.GetColumns().GetItem(var).SetWidth(40);
    var = long(3);
    m_dgStandard.GetColumns().GetItem(var).SetCaption("容纳");
    m_dgStandard.GetColumns().GetItem(var).SetWidth(40);
    var = long(4);
    m_dgStandard.GetColumns().GetItem(var).SetCaption("空调");
    m_dgStandard.GetColumns().GetItem(var).SetWidth(40);
    var = long(5);
    m_dgStandard.GetColumns().GetItem(var).SetCaption("电话");
    m_dgStandard.GetColumns().GetItem(var).SetWidth(40);
    var = long(6);
    m_dgStandard.GetColumns().GetItem(var).SetCaption("电视");
    m_dgStandard.GetColumns().GetItem(var).SetWidth(40);
    var = long(7);
    m_dgStandard.GetColumns().GetItem(var).SetCaption("网络");
    m_dgStandard.GetColumns().GetItem(var).SetWidth(40);
    var = long(8);
    m_dgStandard.GetColumns().GetItem(var).SetCaption("卫生间");
    m_dgStandard.GetColumns().GetItem(var).SetWidth(40);
    var = long(9);
    m_dgStandard.GetColumns().GetItem(var).SetCaption("价格");
    m_dgStandard.GetColumns().GetItem(var).SetWidth(40);

    m_dgStandard.Refresh();
    UpdateData(FALSE);
    return TRUE;  // return TRUE unless you set the focus to a control
    // EXCEPTION: OCX Property Pages should return FALSE
}

void CStandardDlg::UpdateList() {
    m_pRecordset.CreateInstance("ADODB.Recordset");
    m_pRecordset->Open("SELECT * FROM RoomStandard",_variant_t((IDispatch *)theApp.m_pConnection,true),adOpenDynamic,adLockPessimistic,adCmdText);

    m_dgStandard.SetRefDataSource(NULL);
    m_dgStandard.SetRefDataSource((LPUNKNOWN)m_pRecordset);
    m_dgStandard.SetColumnHeaders(2) ;
    _variant_t var;
    var = long(0);
    m_dgStandard.GetColumns().GetItem(var).SetCaption("编号");
    m_dgStandard.GetColumns().GetItem(var).SetWidth(40);
    var = long(1);
    m_dgStandard.GetColumns().GetItem(var).SetCaption("类型");
    m_dgStandard.GetColumns().GetItem(var).SetWidth(55);
    var = long(2);
    m_dgStandard.GetColumns().GetItem(var).SetCaption("面积");
    m_dgStandard.GetColumns().GetItem(var).SetWidth(40);
    var = long(3);
    m_dgStandard.GetColumns().GetItem(var).SetCaption("容纳");
    m_dgStandard.GetColumns().GetItem(var).SetWidth(40);
    var = long(4);
    m_dgStandard.GetColumns().GetItem(var).SetCaption("空调");
    m_dgStandard.GetColumns().GetItem(var).SetWidth(40);
    var = long(5);
    m_dgStandard.GetColumns().GetItem(var).SetCaption("电话");
    m_dgStandard.GetColumns().GetItem(var).SetWidth(40);
    var = long(6);
    m_dgStandard.GetColumns().GetItem(var).SetCaption("电视");
    m_dgStandard.GetColumns().GetItem(var).SetWidth(40);
    var = long(7);
    m_dgStandard.GetColumns().GetItem(var).SetCaption("网络");
    m_dgStandard.GetColumns().GetItem(var).SetWidth(40);
    var = long(8);
    m_dgStandard.GetColumns().GetItem(var).SetCaption("卫生间");
    m_dgStandard.GetColumns().GetItem(var).SetWidth(40);
    var = long(9);
    m_dgStandard.GetColumns().GetItem(var).SetCaption("价格");
    m_dgStandard.GetColumns().GetItem(var).SetWidth(40);

    m_dgStandard.Refresh();

    UpdateData(FALSE);

}

void CStandardDlg::OnModifyStanBtn() {
    // TODO: Add your control notification handler code here
    if (theApp.m_blogin==false) {
        MessageBox("请先登录！","提示",MB_ICONEXCLAMATION );
        return; }
    if(theApp.m_level!=2&&theApp.m_level!=3&&theApp.m_level!=6&&theApp.m_level!=7&&
            theApp.m_level!=10&&theApp.m_level!=11&&theApp.m_level!=14&&theApp.m_level!=15) {
        AfxMessageBox("您不具有修改客房标准信息的权限");
        return; }
    UpdateData(TRUE);
    CString sql,str;
    sql = "select * from RoomStandard where ID='"+m_strStanId+"'";

    m_pRecordset.CreateInstance("ADODB.Recordset");
    m_pRecordset->Open((_variant_t)sql,_variant_t((IDispatch *)theApp.m_pConnection,true),adOpenDynamic,adLockPessimistic,adCmdText);
    if(m_pRecordset->GetRecordCount()!=0) {
        str.Format("%d",m_Aircondition);
        m_pRecordset->PutCollect("Aircondition",(_variant_t)str);

        str.Format("%d",m_Internet);
        m_pRecordset->PutCollect("Internet",(_variant_t)str);

        str.Format("%d",m_Telephone);
        m_pRecordset->PutCollect("Telephone",(_variant_t)str);

        str.Format("%d",m_Television);
        m_pRecordset->PutCollect("Television",(_variant_t)str);

        str.Format("%d",m_Washroom);
        m_pRecordset->PutCollect("Washroom",(_variant_t)str);

        m_pRecordset->PutCollect("Type",(_variant_t)m_strStanType);

        str.Format("%d",m_nStanArea);
        m_pRecordset->PutCollect("Area",(_variant_t)str);

        str.Format("%d",m_nPeople);
        m_pRecordset->PutCollect("PeopleNum",(_variant_t)str);

        str.Format("%d",m_nStanPrice);
        m_pRecordset->PutCollect("Price",(_variant_t)str);

        m_pRecordset->Update(); }
    else {
        AfxMessageBox("该客房不存在，修改失败！"); }
    m_pRecordset->Close();

    UpdateList();
    UpdateData(FALSE); }

void CStandardDlg::OnDelStanBtn() {
    // TODO: Add your control notification handler code here
    if (theApp.m_blogin==false) {
        MessageBox("请先登录！","提示",MB_ICONEXCLAMATION );
        return; }
    if((!(theApp.m_level >=4 && theApp.m_level <= 7)) && (!(theApp.m_level >=12 && theApp.m_level <= 15)) ) {
        AfxMessageBox("您不具有删除客房标准信息的权限");
        return; }
    UpdateData(TRUE);
    CString sql,str;
    sql = "select * from RoomStandard where ID='"+m_strStanId+"'";

    m_pRecordset.CreateInstance("ADODB.Recordset");
    m_pRecordset->Open((_variant_t)sql,_variant_t((IDispatch *)theApp.m_pConnection,true),adOpenDynamic,adLockPessimistic,adCmdText);

    if(m_pRecordset->GetRecordCount()!=0) {
        m_pRecordset->Delete(adAffectCurrent);
        m_pRecordset->Update(); }
    else {
        AfxMessageBox("该客房不存在，删除失败！"); }

    m_pRecordset->Close();

    UpdateList();
    UpdateData(FALSE); }

void CStandardDlg::OnCancel() {
    // TODO: Add extra cleanup here

    CDialog::OnCancel(); }
