#include "utils/File.h"

#include "platform/Windows/CDialogEventHandler.h"

#include <array>

std::map<FileTypes, std::string> File::m_fileTypeExtensions = {{FileTypes::Elf, "*.elf"},
                                                               {FileTypes::All, "*.*"}};

static std::array<CLSID, 2> fileDialogMode = {CLSID_FileOpenDialog, CLSID_FileSaveDialog};

static std::wstring StringToWString(const std::string& str);
static std::string  WStringToString(const std::wstring& str);

std::string File::OpenFile(FileTypes type, FileMode mode)
{
    std::string path = "";
    // Co-create the File Open Dialog object.
    IFileDialog* pfd = nullptr;
    HRESULT      hr  = CoCreateInstance(
      fileDialogMode[size_t(mode)], nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pfd));

    if (SUCCEEDED(hr))
    {
        // Create an event handling object, and hook it up to the dialog.
        IFileDialogEvents* pfde = nullptr;
        hr                      = CDialogEventHandler_CreateInstance(IID_PPV_ARGS(&pfde));

        if (SUCCEEDED(hr))
        {
            // Hook up the event handler.
            DWORD dwCookie;
            hr = pfd->Advise(pfde, &dwCookie);

            if (SUCCEEDED(hr))
            {
                // Set up the options on the dialog.
                DWORD dwFlags;

                // Before setting, always get the options first to avoid overwriting
                // existing options.
                hr = pfd->GetOptions(&dwFlags);
                if (SUCCEEDED(hr))
                {
                    // Set the file types to display.
                    hr = pfd->SetFileTypes(ARRAYSIZE(c_rgSaveTypes), c_rgSaveTypes);
                    if (SUCCEEDED(hr))
                    {
                        // Set the selected file type index to the one received.
                        hr = pfd->SetFileTypeIndex((UINT)type);
                        if (SUCCEEDED(hr))
                        {
                            // Set the default extension to be the one for `type`.
                            std::wstring ext = StringToWString(File::GetExtensionForFileType(type));
                            hr               = pfd->SetDefaultExtension(ext.c_str());
                            if (SUCCEEDED(hr))
                            {
                                // Show the dialog.
                                hr = pfd->Show(nullptr);
                                if (SUCCEEDED(hr))
                                {
                                    // Obtain the result, once the use clicks
                                    // the "Open" button.
                                    // The result is an IShellItem object.
                                    IShellItem* psiResult;
                                    hr = pfd->GetResult(&psiResult);
                                    if (SUCCEEDED(hr))
                                    {
                                        // Do the things we want to do.
                                        PWSTR pszFilePath = nullptr;
                                        hr = psiResult->GetDisplayName(SIGDN_FILESYSPATH,
                                                                       &pszFilePath);
                                        if (SUCCEEDED(hr))
                                        {
                                            path = WStringToString(pszFilePath);
                                            CoTaskMemFree(pszFilePath);
                                        }
                                        psiResult->Release();
                                    }
                                }
                            }
                        }
                    }
                }
                // Unhook the event handler.
                pfd->Unadvise(dwCookie);
            }
            pfde->Release();
        }
        pfd->Release();
    }
    return path;
}

std::string File::GetCurrentPath()
{
    return std::string();
}

std::wstring StringToWString(const std::string& str)
{
    return std::wstring(str.begin(), str.end()).c_str();
}

std::string WStringToString(const std::wstring& str)
{
    std::string strTo;
    char*       szTo = new char[str.length() + 1];
    szTo[str.size()] = '\0';
    WideCharToMultiByte(CP_ACP, 0, str.c_str(), -1, szTo, (int)str.length(), nullptr, nullptr);
    strTo = szTo;
    delete[] szTo;

    return strTo;
}
