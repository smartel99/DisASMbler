#include "ObjdumpConfigUI.h"

#include "text/Text.h"

#include <ImGui/imgui.h>

/*****************************************************************************/
/* SECTION: FileTypeHandler                                                  */
/*****************************************************************************/
const char*                            FileTypeHandler::m_hint  = TEXT_HINT_FILE_TYPE_HANDLER;
const std::map<FileTypes, const char*> FileTypeHandler::m_types = {
  {FileTypes::All, TEXT_FILE_TYPE_HANDLER_TYPE_ALL},
  {FileTypes::Elf, TEXT_FILE_TYPE_HANDLER_TYPE_ELF}};

void FileTypeHandler::Process(ObjdumpConfig& config)
{
    constexpr char* label   = TEXT_FILE_TYPE_HANDLER_INPUT_LABEL;
    const char*     preview = m_types.at(config.type);

    ImGui::BeginGroup();
    if (ImGui::BeginCombo(label, preview))
    {
        for (const auto& type : m_types)
        {
            if (ImGui::Selectable(type.second))
            {
                config.type = type.first;
            }
        }
        ImGui::EndCombo();
    }
    ImGui::EndGroup();
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip(m_hint);
    }
}

/************************************************************************/
/* SECTION: ProjectSettingsHandler                                      */
/************************************************************************/
const char* ProjectSettingsHandler::m_shouldSaveHint =
  TEXT_PROJECT_SETTINGS_HANDLER_SHOULD_SAVE_HINT;
const char* ProjectSettingsHandler::m_prjPathHint  = TEXT_PROJECT_SETTINGS_HANDLER_PRJ_PATH_HINT;
const char* ProjectSettingsHandler::m_filePathHint = TEXT_PROJECT_SETTINGS_HANDLER_FILE_PATH_HINT;

void ProjectSettingsHandler::Process(ObjdumpConfig& config)
{
    constexpr char* shouldSaveLabel    = TEXT_PROJECT_SETTINGS_HANDLER_SHOULD_SAVE_LABEL;
    constexpr char* prjPathLabel       = TEXT_PROJECT_SETTINGS_HANDLER_PRJ_PATH_LABEL;
    constexpr char* filePathLabel      = TEXT_PROJECT_SETTINGS_HANDLER_FILE_PATH_LABEL;
    constexpr char* openPrjButtonLabel = TEXT_PROJECT_SETTINGS_HANDLER_OPEN_PRJ_BUTTON_LABEL;
    constexpr char* openBinButtonLabel = TEXT_PROJECT_SETTINGS_HANDLER_OPEN_BIN_BUTTON_LABEL;

    ImGui::Checkbox(shouldSaveLabel, &config.shouldSavePrj);
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip(m_shouldSaveHint);
    }

    ImGui::BeginGroup();
    if (config.shouldSavePrj)
    {
        ImGui::Text(prjPathLabel, config.pathOfPrj.c_str());
        ImGui::SameLine();
        if (ImGui::Button(openPrjButtonLabel))
        {
            config.pathOfPrj = File::OpenFile(FileTypes::All, FileMode::Save);
        }
    }
    else
    {
        ImGui::TextDisabled(prjPathLabel, config.pathOfPrj.c_str());
        ImGui::SameLine();
        ImGui::PushStyleColor(ImGuiCol_Button, ImGui::GetStyleColorVec4(ImGuiCol_TextDisabled));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive,
                              ImGui::GetStyleColorVec4(ImGuiCol_TextDisabled));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered,
                              ImGui::GetStyleColorVec4(ImGuiCol_TextDisabled));
        ImGui::Button(openPrjButtonLabel);
        ImGui::PopStyleColor(3);
    }
    ImGui::EndGroup();
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip(m_prjPathHint);
    }

    ImGui::BeginGroup();
    ImGui::Text(filePathLabel, config.pathOfBin.c_str());
    ImGui::SameLine();
    if (ImGui::Button(openBinButtonLabel))
    {
        config.pathOfBin = File::OpenFile(FileTypes::All);
    }
    ImGui::EndGroup();
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip(m_filePathHint);
    }
}

/************************************************************************/
/* SECTION: ShowArchiveHeadersHandler                                   */
/************************************************************************/
const char* ShowArchiveHeadersHandler::m_showArchiveHeadersHint = TEXT_SHOW_ARCHIVE_HEADERS_HINT;
const char* ShowArchiveHeadersHandler::m_objdumpFlag            = TEXT_SHOW_ARCHIVE_HEADERS_FLAG;

void ShowArchiveHeadersHandler::Process(ObjdumpConfig& config)
{
    constexpr char* label = TEXT_SHOW_ARCHIVE_HEADERS_LABEL;
    ImGui::Checkbox(label, &config.showArchiveHeader);
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip(m_showArchiveHeadersHint);
    }
}

/************************************************************************/
/* SECTION: AdjustVmaOffsetHandler                                      */
/************************************************************************/
const char* AdjustVmaOffsetHandler::m_hint        = TEXT_ADJUST_VMA_OFFSET_HINT;
const char* AdjustVmaOffsetHandler::m_objdumpFlag = TEXT_ADJUST_VMA_OFFSET_FLAG;
size_t      AdjustVmaOffsetHandler::m_offset;

void AdjustVmaOffsetHandler::Process(ObjdumpConfig& config)
{
}
