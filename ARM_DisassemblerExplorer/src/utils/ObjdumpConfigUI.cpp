#include "ObjdumpConfigUI.h"

#include "text/Text.h"

#include <ImGui/imgui.h>

/*****************************************************************************/
/* FileTypeHandler                                                           */
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
}
