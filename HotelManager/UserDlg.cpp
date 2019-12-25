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
    //ʵ�������ܽ����㷨����
    CMD5* MyEncrypt = new CMD5;
    //��ȡ�û�������û���
    m_Uname.GetWindowText(StrTemp);
    //�����û���
    UserName=MyEncrypt->MD5_Algorithm(StrTemp);
    //����GetPassword�����ж����ݿ����Ƿ����û�������û���
    //������򷵻����û������Ӧ���û�����
    if(m_userdata->GetPassword(&UserName,&strPassword,&nLevel)) {
        //��ȡ�û�������û�����
        m_Upasswd.GetWindowText(StrTemp);
        //�����û�����
        Password=(CString)MyEncrypt->MD5_Algorithm(StrTemp);
        //�����ݿ�������Ƚϣ��õ���¼����
        if(Password.CompareNoCase(strPassword)==0) {
            MessageBox("��¼ϵͳ�ɹ�","ϵͳ��¼",MB_OK|MB_ICONWARNING);
            theApp.m_level = nLevel;
            theApp.m_blogin=true;
            CDialog::OnOK();
            UpdateData(FALSE); }
        else {
            //�����¼����С��3������ر�
            if (Count<3) {
                MessageBox("���벻��ȷ","ϵͳ��¼����",MB_OK|MB_ICONWARNING);
                Count++;           //��¼������¼
                UpdateData(FALSE); }
            else {
                MessageBox("��¼�������࣬ϵͳ�ر�","ϵͳ��¼����",MB_OK|MB_ICONWARNING);
                UpdateData(FALSE);
                CDialog::OnOK(); } } }
    else {
        //�����¼����С��3������ر�
        if (Count<3) {
            MessageBox("�Ƿ��û���","ϵͳ��¼����",MB_OK|MB_ICONWARNING);
            Count++;           //��¼������¼
            UpdateData(FALSE); }
        else {
            MessageBox("��¼�������࣬ϵͳ�ر�","ϵͳ��¼����",MB_OK|MB_ICONWARNING);
            UpdateData(FALSE);
            CDialog::OnOK(); } }

}



BOOL CUserDlg::OnInitDialog() {
    CDialog::OnInitDialog();

    // TODO: Add extra initialization here
    //��ʼ��m_uersdata
    m_userdata = new CUserdata;
    //��ʼ����¼����
    Count=1;
    return TRUE;  // return TRUE unless you set the focus to a control
    // EXCEPTION: OCX Property Pages should return FALSE
}

void CUserDlg::OnBUTTONCancel() {
    // TODO: Add your control notification handler code here
    CDialog::OnCancel(); }
