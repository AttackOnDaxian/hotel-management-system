// RegisterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HotelManager.h"
#include "RegisterDlg.h"
#include "math.h"
#include "MD5.h"
#include <string.h>

//#include "string.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define SHA256_ROTL(a, b) (((a >> (32 - b)) & (0x7fffffff >> (31 - b))) | (a << b))
#define SHA256_SR(a, b) ((a >> b) & (0x7fffffff >> (b - 1)))
#define SHA256_Ch(x, y, z) ((x & y) ^ ((~x) & z))
#define SHA256_Maj(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define SHA256_E0(x) (SHA256_ROTL(x, 30) ^ SHA256_ROTL(x, 19) ^ SHA256_ROTL(x, 10))
#define SHA256_E1(x) (SHA256_ROTL(x, 26) ^ SHA256_ROTL(x, 21) ^ SHA256_ROTL(x, 7))
#define SHA256_O0(x) (SHA256_ROTL(x, 25) ^ SHA256_ROTL(x, 14) ^ SHA256_SR(x, 3))
#define SHA256_O1(x) (SHA256_ROTL(x, 15) ^ SHA256_ROTL(x, 13) ^ SHA256_SR(x, 10))
char *StrSHA256(const char *str, _int64 length, char *sha256) {
    char *pp, *ppend;
    long l, i, W[64], T1, T2, A, B, C, D, E, F, G, H, H0, H1, H2, H3, H4, H5, H6, H7;
    H0 = 0x6a09e667, H1 = 0xbb67ae85, H2 = 0x3c6ef372, H3 = 0xa54ff53a;
    H4 = 0x510e527f, H5 = 0x9b05688c, H6 = 0x1f83d9ab, H7 = 0x5be0cd19;
    long K[64] = {
        0x428a2f98,
        0x71374491,
        0xb5c0fbcf,
        0xe9b5dba5,
        0x3956c25b,
        0x59f111f1,
        0x923f82a4,
        0xab1c5ed5,
        0xd807aa98,
        0x12835b01,
        0x243185be,
        0x550c7dc3,
        0x72be5d74,
        0x80deb1fe,
        0x9bdc06a7,
        0xc19bf174,
        0xe49b69c1,
        0xefbe4786,
        0x0fc19dc6,
        0x240ca1cc,
        0x2de92c6f,
        0x4a7484aa,
        0x5cb0a9dc,
        0x76f988da,
        0x983e5152,
        0xa831c66d,
        0xb00327c8,
        0xbf597fc7,
        0xc6e00bf3,
        0xd5a79147,
        0x06ca6351,
        0x14292967,
        0x27b70a85,
        0x2e1b2138,
        0x4d2c6dfc,
        0x53380d13,
        0x650a7354,
        0x766a0abb,
        0x81c2c92e,
        0x92722c85,
        0xa2bfe8a1,
        0xa81a664b,
        0xc24b8b70,
        0xc76c51a3,
        0xd192e819,
        0xd6990624,
        0xf40e3585,
        0x106aa070,
        0x19a4c116,
        0x1e376c08,
        0x2748774c,
        0x34b0bcb5,
        0x391c0cb3,
        0x4ed8aa4a,
        0x5b9cca4f,
        0x682e6ff3,
        0x748f82ee,
        0x78a5636f,
        0x84c87814,
        0x8cc70208,
        0x90befffa,
        0xa4506ceb,
        0xbef9a3f7,
        0xc67178f2, };
    l = length + ((length % 64 > 56) ? (128 - length % 64) : (64 - length % 64));
    if (!(pp = (char *)malloc((unsigned long)l))) {
        return 0; }
    for (i = 0; i < length; pp[i + 3 - 2 * (i % 4)] = str[i], i++);
    for (pp[i + 3 - 2 * (i % 4)] = 128, i++; i < l; pp[i + 3 - 2 * (i % 4)] = 0, i++);
    *((long *)(pp + l - 4)) = length << 3;
    *((long *)(pp + l - 8)) = length >> 29;
    for (ppend = pp + l; pp < ppend; pp += 64) {
        for (i = 0; i < 16; W[i] = ((long *)pp)[i], i++);
        for (i = 16; i < 64; W[i] = (SHA256_O1(W[i - 2]) + W[i - 7] + SHA256_O0(W[i - 15]) + W[i - 16]), i++);
        A = H0, B = H1, C = H2, D = H3, E = H4, F = H5, G = H6, H = H7;
        for (i = 0; i < 64; i++) {
            T1 = H + SHA256_E1(E) + SHA256_Ch(E, F, G) + K[i] + W[i];
            T2 = SHA256_E0(A) + SHA256_Maj(A, B, C);
            H = G, G = F, F = E, E = D + T1, D = C, C = B, B = A, A = T1 + T2; }
        H0 += A, H1 += B, H2 += C, H3 += D, H4 += E, H5 += F, H6 += G, H7 += H; }
    free(pp - l);
    sprintf(sha256, "%08X%08X%08X%08X%08X%08X%08X%08X", H0, H1, H2, H3, H4, H5, H6, H7);
    return sha256; }

/////////////////////////////////////////////////////////////////////////////
// CRegisterDlg dialog
//extern  CHotelManagerDlg theApp;
extern CHotelManagerApp theApp;

CRegisterDlg::CRegisterDlg(CWnd *pParent /*=NULL*/)
    : CDialog(CRegisterDlg::IDD, pParent) {
    //{{AFX_DATA_INIT(CRegisterDlg)
    // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
}

void CRegisterDlg::DoDataExchange(CDataExchange *pDX) {
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CRegisterDlg)
    DDX_Control(pDX, IDC_CHECKLookFor, m_LookFor);
    DDX_Control(pDX, IDC_CHECKEdit, m_Edit);
    DDX_Control(pDX, IDC_CHECKDel, m_Del);
    DDX_Control(pDX, IDC_CHECKAdd, m_Add);
    DDX_Control(pDX, IDC_EDITPassword, m_Password);
    DDX_Control(pDX, IDC_EDITPasswordC, m_PasswordC);
    DDX_Control(pDX, IDC_EDITUser, m_UserName);
    DDX_Control(pDX, IDC_EDIT2, m_ID);
    //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRegisterDlg, CDialog)
//{{AFX_MSG_MAP(CRegisterDlg)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
//CRegisterDlg message handlers

void CRegisterDlg::OnOK() {
    // TODO: Add extra validation here
    //定义加密解密模块指针，并初始化
    CMD5 *MyMD5 = new CMD5;
    CString UserName, StrTemp, StrSQL, Password, PasswordC, StrLevel;
    UpdateData(TRUE);
    //获取用户输入的用户名
    m_UserName.GetWindowText(StrTemp);
    //加密用户输入的用户名
    UserName = MyMD5->MD5_Algorithm(StrTemp);
    //获取用户输入的密码
    m_Password.GetWindowText(StrTemp);
    //加密用户输入的密码
    Password = MyMD5->MD5_Algorithm(StrTemp);
    //获取用户输入的确认密码
    m_PasswordC.GetWindowText(StrTemp);
    //加密用户输入的确认密码
    PasswordC = MyMD5->MD5_Algorithm(StrTemp);
    //获取许可证
    m_ID.GetWindowText(StrTemp);
    char *ID = StrTemp.GetBuffer(0);
    char *result = new char[256];
    result = StrSHA256(ID, sizeof(ID) - 1, result);
    //StrTemp = result;
    //AfxMessageBox(StrTemp);
    char *test = "A665A45920422F9D417E4867EFDC4FB8A04A1F3FFF1FA07E998E86F7F7A27AE3";
    if (strcmp(result, test)) {
        AfxMessageBox("许可证不正确，请输入有效的许可证！");
        return; }
    //对查询字符串进行赋值
    StrSQL = "Select * From UserInformation Where Name = '" + UserName + " ' ";
    //初始化记录集
    m_pRs.CreateInstance("ADODB.Recordset");
    //打开记录集
    //从数据库中查找输入用户名
    m_pRs->Open((_variant_t)StrSQL,
                _variant_t((IDispatch *)theApp.m_pConnection, true),
                adOpenStatic,
                adLockOptimistic,
                adCmdText);
    //如果用户名存在，则提示“用户名存在，请重新输入用户名”
    if (m_pRs->GetRecordCount() != 0) {
        AfxMessageBox("此用户名已存在，请重新输入用户名");
        m_UserName.Clear();
        m_UserName.SetFocus(); }
    //如果用户名不存在，判断两次输入的密码是否一致
    //如果两次一致则保存注册信息，否则重新输入密码
    else {
        if (Level() == 0) {
            AfxMessageBox("请选择用户权限"); }
        else if (Password.CompareNoCase(PasswordC) == 0) {
            m_pRs->AddNew();
            m_pRs->PutCollect("Name", _variant_t(UserName));
            m_pRs->PutCollect("Pwd", _variant_t(Password));
            //将int型转换成CString型
            StrLevel.Format("%d", Level());
            m_pRs->PutCollect("Level", _variant_t(StrLevel));
            m_pRs->Update();
            AfxMessageBox("用户注册完毕");
            //清空输入信息
            m_UserName.Clear();
            m_Password.Clear();
            m_PasswordC.Clear();
            CDialog::OnOK(); }
        else {
            AfxMessageBox("输入密码不一致请重新输入密码");
            //清空输入信息
            m_Password.Clear();
            m_PasswordC.Clear();
            //设置焦点
            m_Password.SetFocus(); } } }
int CRegisterDlg::Level() {
    int LevelNum;
    LevelNum = 0;
    if (m_Add.GetCheck() == 1) {
        LevelNum += (int)pow(2, 1); }
    if (m_Del.GetCheck() == 1) {
        LevelNum += (int)pow(2, 2); }
    if (m_Edit.GetCheck() == 1) {
        LevelNum += (int)pow(2, 3); }
    if (m_LookFor.GetCheck() == 1) {
        LevelNum += (int)pow(2, 0); }
    return LevelNum; }

// void CRegisterDlg::OnOK()
// {
// 	// TODO: Add extra validation here
//
// 	CDialog::OnOK();
// }

BOOL CRegisterDlg::OnInitDialog() {
    CDialog::OnInitDialog();

    // TODO: Add extra initialization here
    m_Add.SetCheck(1);
    m_Del.SetCheck(1);
    m_Edit.SetCheck(1);
    m_LookFor.SetCheck(1);
    return TRUE; // return TRUE unless you set the focus to a control
    // EXCEPTION: OCX Property Pages should return FALSE
}
