#pragma once
#include <windows.h>    // For common windows data types and function headers
#define STRICT_TYPED_ITEMIDS
#include <shlobj.h>
#include <objbase.h>     // For COM headers
#include <shobjidl.h>    // for IFileDialogEvents and IFileDialogControlEvents
#include <shlwapi.h>
#include <knownfolders.h>    // for KnownFolder APIs/data types/function headers
#include <propvarutil.h>     // for PROPVAR-related functions
#include <propkey.h>         // for the Property key APIs/data types
#include <propidl.h>         // for the Property System APIs
#include <strsafe.h>         // for StringCchPrintfW
#include <shtypes.h>         // for COMDLG_FILTERSPEC
#include <new>

#include <iostream>

const COMDLG_FILTERSPEC c_rgSaveTypes[] = {{L"All Documents (*.*)", L"*.*"}};

// Indices of file types.
using FileTypeEnum_t = enum { INDEX_DEFAULT };

// Controls.
#define CONTROL_GROUP           2000
#define CONTROL_RADIOBUTTONLIST 2
#define CONTROL_RADIOBUTTION1   1
#define CONTROL_RADIOBUTTION2   2

// IDs for the Task Dialog Buttons.
#define IDC_BASICFILEOPEN                       100
#define IDC_ADDITEMSTOCUSTOMPLACES              101
#define IDC_ADDCUSTOMCONTROLS                   102
#define IDC_SETDEFAULTVALUESFORPROPERTIES       103
#define IDC_WRITEPROPERTIESUSINGHANDLERS        104
#define IDC_WRITEPROPERTIESWITHOUTUSINGHANDLERS 105

/* File Dialog Event Handler *************************************************/
class CDialogEventHandler : public IFileDialogEvents, public IFileDialogControlEvents
{
public:
    // IUnknown methods
    IFACEMETHODIMP QueryInterface(REFIID riid, void** ppv)
    {
        static const QITAB qit[] = {
          QITABENT(CDialogEventHandler, IFileDialogEvents),
          QITABENT(CDialogEventHandler, IFileDialogControlEvents),
          {nullptr},
#pragma warning(suppress : 4838)
        };
        return QISearch(this, qit, riid, ppv);
    }

    IFACEMETHODIMP_(ULONG) AddRef() { return InterlockedIncrement(&_cRef); }

    IFACEMETHODIMP_(ULONG) Release()
    {
        long cRef = InterlockedDecrement(&_cRef);
        if (!cRef)
            delete this;
        return cRef;
    }

    // IFileDialogEvents methods
    IFACEMETHODIMP OnFileOk(IFileDialog*) { return S_OK; };
    IFACEMETHODIMP OnFolderChange(IFileDialog*) { return S_OK; };
    IFACEMETHODIMP OnFolderChanging(IFileDialog*, IShellItem*) { return S_OK; };
    IFACEMETHODIMP OnHelp(IFileDialog*) { return S_OK; };
    IFACEMETHODIMP OnSelectionChange(IFileDialog*) { return S_OK; };
        // Disable warning for FDE_SHAREVIOLATION_RESPONSE enum.
#pragma warning(suppress : 26812)
    IFACEMETHODIMP OnShareViolation(IFileDialog*, IShellItem*, FDE_SHAREVIOLATION_RESPONSE*)
    {
        return S_OK;
    };
    IFACEMETHODIMP OnTypeChange(IFileDialog* pfd);
    // Disable warning for FDE_OVERWRITE_RESPONSE enum.
#pragma warning(suppress : 26812)
    IFACEMETHODIMP OnOverwrite(IFileDialog*, IShellItem*, FDE_OVERWRITE_RESPONSE*) { return S_OK; };

    // IFileDialogControlEvents methods
    IFACEMETHODIMP OnItemSelected(IFileDialogCustomize* pfdc, DWORD dwIDCtl, DWORD dwIDItem);
    IFACEMETHODIMP OnButtonClicked(IFileDialogCustomize*, DWORD) { return S_OK; };
    IFACEMETHODIMP OnCheckButtonToggled(IFileDialogCustomize*, DWORD, BOOL) { return S_OK; };
    IFACEMETHODIMP OnControlActivating(IFileDialogCustomize*, DWORD) { return S_OK; };

    CDialogEventHandler() : _cRef(1){};

private:
    virtual ~CDialogEventHandler() = default;
    alignas(long long) long _cRef;
};

HRESULT CDialogEventHandler_CreateInstance(REFIID riid, void** ppv);
