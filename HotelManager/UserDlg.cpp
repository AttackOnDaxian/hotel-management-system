// UserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HotelManager.h"
#include "UserDlg.h"
#include "UserData.h"
#include "MD5.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CHotelManagerApp theApp;
//extern CHotelManagerApp m_blogin;
/////////////////////////////////////////////////////////////////////////////
// CUserDlg dialog


CUserDlg::CUserDlg(CWnd* pParent /*=NULL*/)
    : CDialog(CUserDlg::IDD, pParent) {
    //{{AFX_DATA_INIT(CUserDlg)
    //}}AFX_DATA_INIT
//	i = 0;
//	Count=0;
}


void CUserDlg::DoDataExchange(CDataExchange* pDX) {
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CUserDlg)
    DDX_Control(pDX, IDC_EDIT_Pwd, m_Upasswd);
    DDX_Control(pDX, IDC_EDIT_Name, m_Uname);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserDlg, CDialog)
    //{{AFX_MSG_MAP(CUserDlg)
    ON_BN_CLICKED(IDC_BUTTON_LOGIN, OnButtonLogin)
    ON_BN_CLICKED(IDC_BUTTON_Cancel, OnBUTTONCancel)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserDlg message handlers
//


void CUserDlg::OnButtonLogin() {
    // TODO: Add your control notification handler code here
    CString Password,strPassword;
    int nLevel;
    CString UserName,StrTemp;
    UpdateData(TRUE);
    //实例化加密解密算法类型
    CMD5* MyEncrypt = new CMD5;
    //获取用户输入的用户名
    m_Uname.GetWindowText(StrTemp);
    //加密用户名
    UserName=MyEncrypt->MD5_Algorithm(StrTemp);
    //调用GetPassword函数判断数据库中是否有用户输入的用户名
    //如果有则返回与用户名相对应的用户密码
    if(m_userdata->GetPassword(&UserName,&strPassword,&nLevel)) {
        //获取用户输入的用户密码
        m_Upasswd.GetWindowText(StrTemp);
        //加密用户密码
        Password=(CString)MyEncrypt->MD5_Algorithm(StrTemp);
        //和数据库中密码比较，得到登录密码
        if(Password.CompareNoCase(strPassword)==0) {
            MessageBox("登录系统成功","系统登录",MB_OK|MB_ICONWARNING);
            theApp.m_level = nLevel;
            theApp.m_blogin=true;
            CDialog::OnOK();
            UpdateData(FALSE); }
        else {
            //如果登录次数小于3，程序关闭
            if (Count<3) {
                MessageBox("密码不正确","系统登录错误",MB_OK|MB_ICONWARNING);
                Count++;           //登录次数记录
                UpdateData(FALSE); }
            else {
                MessageBox("登录次数过多，系统关闭","系统登录错误",MB_OK|MB_ICONWARNING);
                UpdateData(FALSE);
                CDialog::OnOK(); } } }
    else {
        //如果登录次数小于3，程序关闭
        if (Count<3) {
            MessageBox("非法用户名","系统登录错误",MB_OK|MB_ICONWARNING);
            Count++;           //登录次数记录
            UpdateData(FALSE); }
        else {
            MessageBox("登录次数过多，系统关闭","系统登录错误",MB_OK|MB_ICONWARNING);
            UpdateData(FALSE);
            CDialog::OnOK(); } }

}



BOOL CUserDlg::OnInitDialog() {
    CDialog::OnInitDialog();

    // TODO: Add extra initialization here
    //初始化m_uersdata
    m_userdata = new CUserdata;
    //初始化登录次数
    Count=1;
    return TRUE;  // return TRUE unless you set the focus to a control
    // EXCEPTION: OCX Property Pages should return FALSE
}

void CUserDlg::OnBUTTONCancel() {
    // TODO: Add your control notification handler code here
    CDialog::OnCancel(); }
