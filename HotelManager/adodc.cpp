// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "adodc.h"

// Dispatch interfaces referenced by this interface
#include "_recordset.h"
#include "Font.h"

/////////////////////////////////////////////////////////////////////////////
// CAdodc

IMPLEMENT_DYNCREATE(CAdodc, CWnd)

/////////////////////////////////////////////////////////////////////////////
// CAdodc properties

/////////////////////////////////////////////////////////////////////////////
// CAdodc operations

CString CAdodc::GetConnectionString() {
    CString result;
    InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
    return result; }

void CAdodc::SetConnectionString(LPCTSTR lpszNewValue) {
    static BYTE parms[] =
        VTS_BSTR;
    InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 lpszNewValue); }

CString CAdodc::GetUserName_() {
    CString result;
    InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
    return result; }

void CAdodc::SetUserName(LPCTSTR lpszNewValue) {
    static BYTE parms[] =
        VTS_BSTR;
    InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 lpszNewValue); }

CString CAdodc::GetPassword() {
    CString result;
    InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
    return result; }

void CAdodc::SetPassword(LPCTSTR lpszNewValue) {
    static BYTE parms[] =
        VTS_BSTR;
    InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 lpszNewValue); }

long CAdodc::GetMode() {
    long result;
    InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
    return result; }

void CAdodc::SetMode(long nNewValue) {
    static BYTE parms[] =
        VTS_I4;
    InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 nNewValue); }

long CAdodc::GetCursorLocation() {
    long result;
    InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
    return result; }

void CAdodc::SetCursorLocation(long nNewValue) {
    static BYTE parms[] =
        VTS_I4;
    InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 nNewValue); }

long CAdodc::GetConnectionTimeout() {
    long result;
    InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
    return result; }

void CAdodc::SetConnectionTimeout(long nNewValue) {
    static BYTE parms[] =
        VTS_I4;
    InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 nNewValue); }

long CAdodc::GetCommandTimeout() {
    long result;
    InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
    return result; }

void CAdodc::SetCommandTimeout(long nNewValue) {
    static BYTE parms[] =
        VTS_I4;
    InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 nNewValue); }

CString CAdodc::GetRecordSource() {
    CString result;
    InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
    return result; }

void CAdodc::SetRecordSource(LPCTSTR lpszNewValue) {
    static BYTE parms[] =
        VTS_BSTR;
    InvokeHelper(0xe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 lpszNewValue); }

long CAdodc::GetCursorType() {
    long result;
    InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
    return result; }

void CAdodc::SetCursorType(long nNewValue) {
    static BYTE parms[] =
        VTS_I4;
    InvokeHelper(0xf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 nNewValue); }

long CAdodc::GetLockType() {
    long result;
    InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
    return result; }

void CAdodc::SetLockType(long nNewValue) {
    static BYTE parms[] =
        VTS_I4;
    InvokeHelper(0x10, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 nNewValue); }

long CAdodc::GetCommandType() {
    long result;
    InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
    return result; }

void CAdodc::SetCommandType(long nNewValue) {
    static BYTE parms[] =
        VTS_I4;
    InvokeHelper(0x11, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 nNewValue); }

long CAdodc::GetCacheSize() {
    long result;
    InvokeHelper(0x13, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
    return result; }

void CAdodc::SetCacheSize(long nNewValue) {
    static BYTE parms[] =
        VTS_I4;
    InvokeHelper(0x13, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 nNewValue); }

long CAdodc::GetMaxRecords() {
    long result;
    InvokeHelper(0x14, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
    return result; }

void CAdodc::SetMaxRecords(long nNewValue) {
    static BYTE parms[] =
        VTS_I4;
    InvokeHelper(0x14, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 nNewValue); }

long CAdodc::GetBOFAction() {
    long result;
    InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
    return result; }

void CAdodc::SetBOFAction(long nNewValue) {
    static BYTE parms[] =
        VTS_I4;
    InvokeHelper(0x15, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 nNewValue); }

long CAdodc::GetEOFAction() {
    long result;
    InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
    return result; }

void CAdodc::SetEOFAction(long nNewValue) {
    static BYTE parms[] =
        VTS_I4;
    InvokeHelper(0x16, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 nNewValue); }

CString CAdodc::GetCaption() {
    CString result;
    InvokeHelper(DISPID_CAPTION, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
    return result; }

void CAdodc::SetCaption(LPCTSTR lpszNewValue) {
    static BYTE parms[] =
        VTS_BSTR;
    InvokeHelper(DISPID_CAPTION, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 lpszNewValue); }

long CAdodc::GetAppearance() {
    long result;
    InvokeHelper(DISPID_APPEARANCE, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
    return result; }

void CAdodc::SetAppearance(long nNewValue) {
    static BYTE parms[] =
        VTS_I4;
    InvokeHelper(DISPID_APPEARANCE, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 nNewValue); }

unsigned long CAdodc::GetBackColor() {
    unsigned long result;
    InvokeHelper(DISPID_BACKCOLOR, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
    return result; }

void CAdodc::SetBackColor(unsigned long newValue) {
    static BYTE parms[] =
        VTS_I4;
    InvokeHelper(DISPID_BACKCOLOR, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 newValue); }

unsigned long CAdodc::GetForeColor() {
    unsigned long result;
    InvokeHelper(DISPID_FORECOLOR, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
    return result; }

void CAdodc::SetForeColor(unsigned long newValue) {
    static BYTE parms[] =
        VTS_I4;
    InvokeHelper(DISPID_FORECOLOR, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 newValue); }

long CAdodc::GetOrientation() {
    long result;
    InvokeHelper(0x17, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
    return result; }

void CAdodc::SetOrientation(long nNewValue) {
    static BYTE parms[] =
        VTS_I4;
    InvokeHelper(0x17, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 nNewValue); }

C_Recordset CAdodc::GetRecordset() {
    LPDISPATCH pDispatch;
    InvokeHelper(0x18, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
    return C_Recordset(pDispatch); }

void CAdodc::SetRefRecordset(LPDISPATCH newValue) {
    static BYTE parms[] =
        VTS_DISPATCH;
    InvokeHelper(0x18, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms,
                 newValue); }

COleFont CAdodc::GetFont() {
    LPDISPATCH pDispatch;
    InvokeHelper(DISPID_FONT, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
    return COleFont(pDispatch); }

void CAdodc::SetRefFont(LPDISPATCH newValue) {
    static BYTE parms[] =
        VTS_DISPATCH;
    InvokeHelper(DISPID_FONT, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms,
                 newValue); }

BOOL CAdodc::GetEnabled() {
    BOOL result;
    InvokeHelper(DISPID_ENABLED, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
    return result; }

void CAdodc::SetEnabled(BOOL bNewValue) {
    static BYTE parms[] =
        VTS_BOOL;
    InvokeHelper(DISPID_ENABLED, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 bNewValue); }

void CAdodc::Refresh() {
    InvokeHelper(0x19, DISPATCH_METHOD, VT_EMPTY, NULL, NULL); }
