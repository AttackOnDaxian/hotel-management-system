// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "split.h"

// Dispatch interfaces referenced by this interface
#include "columns.h"


/////////////////////////////////////////////////////////////////////////////
// CSplit properties

/////////////////////////////////////////////////////////////////////////////
// CSplit operations

BOOL CSplit::GetAllowFocus() {
    BOOL result;
    InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
    return result; }

void CSplit::SetAllowFocus(BOOL bNewValue) {
    static BYTE parms[] =
        VTS_BOOL;
    InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 bNewValue); }

BOOL CSplit::GetAllowRowSizing() {
    BOOL result;
    InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
    return result; }

void CSplit::SetAllowRowSizing(BOOL bNewValue) {
    static BYTE parms[] =
        VTS_BOOL;
    InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 bNewValue); }

BOOL CSplit::GetAllowSizing() {
    BOOL result;
    InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
    return result; }

void CSplit::SetAllowSizing(BOOL bNewValue) {
    static BYTE parms[] =
        VTS_BOOL;
    InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 bNewValue); }

BOOL CSplit::GetCurrentCellVisible() {
    BOOL result;
    InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
    return result; }

void CSplit::SetCurrentCellVisible(BOOL bNewValue) {
    static BYTE parms[] =
        VTS_BOOL;
    InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 bNewValue); }

VARIANT CSplit::GetFirstRow() {
    VARIANT result;
    InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
    return result; }

void CSplit::SetFirstRow(const VARIANT& newValue) {
    static BYTE parms[] =
        VTS_VARIANT;
    InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 &newValue); }

short CSplit::GetIndex() {
    short result;
    InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, NULL);
    return result; }

short CSplit::GetLeftCol() {
    short result;
    InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, NULL);
    return result; }

void CSplit::SetLeftCol(short nNewValue) {
    static BYTE parms[] =
        VTS_I2;
    InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 nNewValue); }

BOOL CSplit::GetLocked() {
    BOOL result;
    InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
    return result; }

void CSplit::SetLocked(BOOL bNewValue) {
    static BYTE parms[] =
        VTS_BOOL;
    InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 bNewValue); }

long CSplit::GetMarqueeStyle() {
    long result;
    InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
    return result; }

void CSplit::SetMarqueeStyle(long nNewValue) {
    static BYTE parms[] =
        VTS_I4;
    InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 nNewValue); }

BOOL CSplit::GetRecordSelectors() {
    BOOL result;
    InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
    return result; }

void CSplit::SetRecordSelectors(BOOL bNewValue) {
    static BYTE parms[] =
        VTS_BOOL;
    InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 bNewValue); }

long CSplit::GetScrollBars() {
    long result;
    InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
    return result; }

void CSplit::SetScrollBars(long nNewValue) {
    static BYTE parms[] =
        VTS_I4;
    InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 nNewValue); }

short CSplit::GetScrollGroup() {
    short result;
    InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, NULL);
    return result; }

void CSplit::SetScrollGroup(short nNewValue) {
    static BYTE parms[] =
        VTS_I2;
    InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 nNewValue); }

short CSplit::GetSelEndCol() {
    short result;
    InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, NULL);
    return result; }

void CSplit::SetSelEndCol(short nNewValue) {
    static BYTE parms[] =
        VTS_I2;
    InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 nNewValue); }

short CSplit::GetSelStartCol() {
    short result;
    InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, NULL);
    return result; }

void CSplit::SetSelStartCol(short nNewValue) {
    static BYTE parms[] =
        VTS_I2;
    InvokeHelper(0xe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 nNewValue); }

VARIANT CSplit::GetSize() {
    VARIANT result;
    InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
    return result; }

void CSplit::SetSize(const VARIANT& newValue) {
    static BYTE parms[] =
        VTS_VARIANT;
    InvokeHelper(0xf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 &newValue); }

long CSplit::GetSizeMode() {
    long result;
    InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
    return result; }

void CSplit::SetSizeMode(long nNewValue) {
    static BYTE parms[] =
        VTS_I4;
    InvokeHelper(0x10, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
                 nNewValue); }

void CSplit::ClearSelCols() {
    InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL); }

CColumns CSplit::GetColumns() {
    LPDISPATCH pDispatch;
    InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
    return CColumns(pDispatch); }
