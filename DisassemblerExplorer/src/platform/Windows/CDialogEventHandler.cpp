#include "CDialogEventHandler.h"


// This method gets called when the file type is changed (combo-box selection
// changes).
HRESULT CDialogEventHandler::OnTypeChange(IFileDialog* pfd)
{
    IFileSaveDialog* pfsd;
    HRESULT          hr = pfd->QueryInterface(&pfsd);
    if (SUCCEEDED(hr))
    {
        UINT uIndex;
        hr = pfsd->GetFileTypeIndex(&uIndex);    // Index of current file type.
        if (SUCCEEDED(hr))
        {
            IPropertyDescriptionList* pdl = nullptr;

            switch (uIndex)
            {
                case INDEX_SCRIPT:
                    // When .s is selected, let's ask for some arbitrary property,
                    // like Title.
                    hr = PSGetPropertyDescriptionListFromString(L"prop:System.Title",
                                                                IID_PPV_ARGS(&pdl));
                    if (SUCCEEDED(hr))
                    {
                        // FALSE as second param == do not show default properties.
                        hr = pfsd->SetCollectedProperties(pdl, FALSE);
                        pdl->Release();
                    }
                    break;
            }
        }
        pfsd->Release();
    }
    return hr;
}

/**
 * This method gets called when a dialog control item selection happens
 * (radio-button selection, etc)
 */
HRESULT CDialogEventHandler::OnItemSelected(IFileDialogCustomize* pfdc,
                                            DWORD                 dwIDCtl,
                                            DWORD                 dwIDItem)
{
    IFileDialog* pfd = nullptr;
    HRESULT      hr  = pfdc->QueryInterface(&pfd);
    if (SUCCEEDED(hr))
    {
        if (dwIDCtl == CONTROL_RADIOBUTTONLIST)
        {
            switch (dwIDItem)
            {
                case CONTROL_RADIOBUTTION1:
                    hr = pfd->SetTitle(L"Longhorn Dialog");
                    break;
                case CONTROL_RADIOBUTTION2:
                    hr = pfd->SetTitle(L"Vista Dialog");
                    break;
            }
        }
        pfd->Release();
    }
    return hr;
}

// Instance creation helper
HRESULT CDialogEventHandler_CreateInstance(REFIID riid, void** ppv)
{
    *ppv                                     = nullptr;
    CDialogEventHandler* pDialogEventHandler = new (std::nothrow) CDialogEventHandler();
    HRESULT              hr                  = pDialogEventHandler ? S_OK : E_OUTOFMEMORY;
    if (SUCCEEDED(hr))
    {
        hr = pDialogEventHandler->QueryInterface(riid, ppv);
        pDialogEventHandler->Release();
    }
    return hr;
}
