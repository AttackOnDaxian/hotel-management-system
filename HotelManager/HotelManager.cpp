// HotelManager.cpp : Defines the class behaviors for the application.
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
// CHotelManagerApp

BEGIN_MESSAGE_MAP(CHotelManagerApp, CWinApp)
    //{{AFX_MSG_MAP(CHotelManagerApp)
    // NOTE - the ClassWizard will add and remove mapping macros here.
    //    DO NOT EDIT what you see in these blocks of generated code!
    //}}AFX_MSG
    ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHotelManagerApp construction

CHotelManagerApp::CHotelManagerApp() {
    // TODO: add construction code here,


    // Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CHotelManagerApp object

CHotelManagerApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CHotelManagerApp initialization

BOOL CHotelManagerApp::InitInstance() {
    m_level = 0;
    m_blogin=false;
    AfxEnableControlContainer();
    AfxOleInit();//初始化COM库

    //以下是连接access2000数据库。。。
    HRESULT hr;
    try {
        hr = m_pConnection.CreateInstance("ADODB.Connection");///创建Connection对象

        if(SUCCEEDED(hr)) {
            m_pConnection->ConnectionTimeout=8;///设置超时时间为8秒
            m_pConnection->PutCursorLocation(adUseClient);
            hr = m_pConnection->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=HotelManager.mdb;","","",adModeUnknown); } }
    catch(_com_error e) {   ///捕捉异常
        CString temp;
        temp.Format("连接数据库错误信息:%s",e.ErrorMessage());
        ::MessageBox(NULL,temp,"提示信息",NULL);
        return false; }
    // Standard initialization
    // If you are not using these features and wish to reduce the size
    //  of your final executable, you should remove from the following
    //  the specific initialization routines you do not need.

#ifdef _AFXDLL
    Enable3dControls();			// Call this when using MFC in a shared DLL
#else
    Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

    CHotelManagerDlg dlg;
    m_pMainWnd = &dlg;
    int nResponse = dlg.DoModal();
    if (nResponse == IDOK) {
        // TODO: Place code here to handle when the dialog is
        //  dismissed with OK
    }
    else if (nResponse == IDCANCEL) {
        // TODO: Place code here to handle when the dialog is
        //  dismissed with Cancel
    }

    // Since the dialog has been closed, return FALSE so that we exit the
    //  application, rather than start the application's message pump.
    return FALSE; }
