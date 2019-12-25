// HotelManagerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HotelManager.h"
#include "HotelManagerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog {
public:
    CAboutDlg();

// Dialog Data
    //{{AFX_DATA(CAboutDlg)
    enum { IDD = IDD_ABOUTBOX };
    //}}AFX_DATA

    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CAboutDlg)
protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:
    //{{AFX_MSG(CAboutDlg)
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP() };

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD) {
    //{{AFX_DATA_INIT(CAboutDlg)
    //}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX) {
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CAboutDlg)
    //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
    //{{AFX_MSG_MAP(CAboutDlg)
    // No message handlers
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHotelManagerDlg dialog

CHotelManagerDlg::CHotelManagerDlg(CWnd* pParent /*=NULL*/)
    : CDialog(CHotelManagerDlg::IDD, pParent) {
    //{{AFX_DATA_INIT(CHotelManagerDlg)
    // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
    // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME); }

void CHotelManagerDlg::DoDataExchange(CDataExchange* pDX) {
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CHotelManagerDlg)
    // NOTE: the ClassWizard will add DDX and DDV calls here
    //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CHotelManagerDlg, CDialog)
    //{{AFX_MSG_MAP(CHotelManagerDlg)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_COMMAND(ID_MENU_ZHUCE, OnMenuZhuce)
    ON_COMMAND(ID_MENU_DENGLU, OnMenuDenglu)
    ON_COMMAND(ID_MENU_EXIT, OnMenuExit)
    ON_COMMAND(ID_MENU_kfbz, OnMENUkfbz)
    ON_COMMAND(ID_MENU_dfxx, OnMENUdfxx)
    ON_COMMAND(ID_MENU_kfxx, OnMENUkfxx)
    ON_COMMAND(ID_MENU_CAIZHENG, OnMenuCaizheng)
    ON_COMMAND(IDI_ICON_pay,OnIconCaizheng)
    ON_COMMAND(ID_MENU_Help, OnMENUHelp)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHotelManagerDlg message handlers

BOOL CHotelManagerDlg::OnInitDialog() {
    CDialog::OnInitDialog();

    // Add "About..." menu item to system menu.

    // IDM_ABOUTBOX must be in the system command range.
    ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
    ASSERT(IDM_ABOUTBOX < 0xF000);

    CMenu* pSysMenu = GetSystemMenu(FALSE);
    if (pSysMenu != NULL) {
        CString strAboutMenu;
        strAboutMenu.LoadString(IDS_ABOUTBOX);
        if (!strAboutMenu.IsEmpty()) {
            pSysMenu->AppendMenu(MF_SEPARATOR);
            pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu); } }

    // Set the icon for this dialog.  The framework does this automatically
    //  when the application's main window is not a dialog
    SetIcon(m_hIcon, TRUE);			// Set big icon
    SetIcon(m_hIcon, FALSE);		// Set small icon

    // TODO: Add extra initialization here
//
// 	m_Imagelist.Create(32,32,ILC_COLOR24|ILC_MASK,1,1);
// 	m_Imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON_login));
// 	m_Imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON_reg));
// 	m_Imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON_open));
// 	m_Imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON_pay));
// 	//m_Imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON_rishouru));
// 	m_Imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON_Cancel));
    UINT Array[6];
    for (int i=0; i<6; i++) {
        Array[i]=9000+i; }
// 	m_Toolbar.Create(this);
// 	m_Toolbar.SetButtons(Array,5);
// 	m_Toolbar.SetButtonText(0,"系统登陆");
// 	m_Toolbar.SetButtonText(1,"用户注册");
// 	m_Toolbar.SetButtonText(2,"订房");
// 	m_Toolbar.SetButtonText(3,"顾客买单");
// //	m_Toolbar.SetButtonText(4,"本日收入");
// 	m_Toolbar.SetButtonText(4,"退出系统");
// 	m_Toolbar.GetToolBarCtrl().SetButtonWidth(60,120);
// 	m_Toolbar.GetToolBarCtrl().SetImageList(&m_Imagelist);
// 	m_Toolbar.SetSizes(CSize(70,60),CSize(28,40));
// 	m_Toolbar.EnableToolTips(TRUE);

    m_Statusbar.Create(this);
    m_Statusbar.SetIndicators(Array,4);
    for(int n=0; n<3; n++) {
        m_Statusbar.SetPaneInfo(n,Array[n],0,80); }
    CTime ct;
    ct=CTime::GetCurrentTime();
    CString strdate;
    strdate.Format("%s",ct.Format("%y-%m-%d"));

    m_Statusbar.SetPaneInfo(1,Array[1],0,200);
    m_Statusbar.SetPaneInfo(2,Array[2],0,800);
    m_Statusbar.SetPaneText(2,"当前时间"+strdate);
    m_Statusbar.SetPaneText(0,"餐饮管理系统");
    m_Statusbar.SetPaneText(1,"当前用户");
    RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);
    m_pUserDlg = new CUserDlg;
    m_pRegisterDlg = new CRegisterDlg;
    m_pStandardDlg=new CStandardDlg;
    m_pOrderDlg= new COrderDlg;
    m_pRoomDlg=new CRoomDlg;
    m_pCheckDlg=new CCheckDlg;
    return TRUE;  // return TRUE  unless you set the focus to a control
}

void CHotelManagerDlg::OnSysCommand(UINT nID, LPARAM lParam) {
    if ((nID & 0xFFF0) == IDM_ABOUTBOX) {
        CAboutDlg dlgAbout;
        dlgAbout.DoModal(); }
    else {
        CDialog::OnSysCommand(nID, lParam); } }

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CHotelManagerDlg::OnPaint() {
    if (IsIconic()) {
        CPaintDC dc(this); // device context for painting

        SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

        // Center icon in client rectangle
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // Draw the icon
        dc.DrawIcon(x, y, m_hIcon); }
    else {
        CDialog::OnPaint(); } }
// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CHotelManagerDlg::OnQueryDragIcon() {
    return (HCURSOR) m_hIcon; }

void CHotelManagerDlg::SetDlgStatus() {
    if(status[0]) {
        m_pUserDlg->DestroyWindow();
        status[0] = FALSE; }
    if(status[1]) {
        m_pStandardDlg->DestroyWindow();
        status[1] = FALSE; }
    if(status[2]) {
        m_pRoomDlg->DestroyWindow();
        status[2] = FALSE; }
    if(status[3]) {
        m_pOrderDlg->DestroyWindow();
        status[3] = FALSE; }
    if(status[4]) {
        m_pCheckDlg->DestroyWindow();
        status[4] = FALSE; }
    if(status[5]) {
        m_pRegisterDlg->DestroyWindow();
        status[5] = FALSE; } }





void CHotelManagerDlg::OnMenuExit() {
    // TODO: Add your command handler code here
    CDialog::OnOK(); }

BOOL CHotelManagerDlg::DestroyWindow() {
    delete m_pUserDlg;
    delete m_pStandardDlg;
    delete m_pRoomDlg;
    delete m_pOrderDlg;
    delete m_pCheckDlg;
    delete m_pRegisterDlg;
    return CDialog::DestroyWindow(); }

void CHotelManagerDlg::OnMENUkfbz() {
    // TODO: Add your command handler code here
    SetDlgStatus();
    m_pStandardDlg->Create(IDD_STANDARD_DLG,this) ;
    status[1] = TRUE; }

void CHotelManagerDlg::OnMENUdfxx() {
    // TODO: Add your command handler code here
    SetDlgStatus();
    m_pOrderDlg->Create(IDD_ORDER_DLG,this);
    status[3]=TRUE; }
void CHotelManagerDlg::OnMenuZhuce() {
    // TODO: Add your command handler code here
    // 	CRegisterDlg dlg(this);
    // 	dlg.DoModal();
    //	m_pRegisterDlg = new CRegisterDlg;
    SetDlgStatus();
    m_pRegisterDlg->Create(IDD_REGISTER_DIALOG,this) ;
    status[5] = TRUE; }
void CHotelManagerDlg::OnMenuDenglu() {
    // TODO: Add your command handler code here
    // 	CUserDlg dlg(this);
    // 	dlg.DoModal();
    SetDlgStatus();
    m_pUserDlg->Create(IDD_USER_DLG,this) ;
    status[0] = TRUE; }

void CHotelManagerDlg::OnMENUkfxx() {
    // TODO: Add your command handler code here
    SetDlgStatus();
    m_pRoomDlg->Create(IDD_ROOM_DLG,this) ;
    status[2] = TRUE; }

void CHotelManagerDlg::OnMenuCaizheng() {
    // TODO: Add your command handler code here
    SetDlgStatus();
    m_pCheckDlg->Create(IDD_CHECK_DLG,this) ;
    status[4] = TRUE; }
void CHotelManagerDlg::OnIconCaizheng() {
    // TODO: Add your command handler code here
    SetDlgStatus();
    m_pCheckDlg->Create(IDD_CHECK_DLG,this) ;
    status[4] = TRUE; }
void CHotelManagerDlg::OnMENUHelp() {
    // TODO: Add your command handler code here
    ShellExecute(NULL,"open","help.doc",NULL,NULL,SW_SHOW); }
