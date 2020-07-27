/******************************************************************************
 * @file ObjdumpConfigUI
 * @author Samuel Martel
 * @date 2020/07/27
 * @brief
 ******************************************************************************
 * Copyright (C) 2020  Samuel Martel - Pascal-Emmanuel Lachance
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *****************************************************************************/

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
const char* ProjectSettingsHandler::m_prjPathHint = TEXT_PROJECT_SETTINGS_HANDLER_PRJ_PATH_HINT;
const char* ProjectSettingsHandler::m_architectureHint = TEXT_PROJECT_SETTINGS_HANDLER_ARCH_HINT;
const char* ProjectSettingsHandler::m_filePathHint = TEXT_PROJECT_SETTINGS_HANDLER_FILE_PATH_HINT;
const std::map<ArchitectureEnum_t, const char*> ProjectSettingsHandler::m_architectures = {
  {ArchitectureEnum_t::Architecture_Auto, TEXT_ARCHITECTURE_AUTO},
  {ArchitectureEnum_t::Architecture_Arm, TEXT_ARCHITECTURE_ARM},
  {ArchitectureEnum_t::Architecture_Avr, TEXT_ARCHITECTURE_AVR},
  {ArchitectureEnum_t::Architecture_PowerPc, TEXT_ARCHITECTURE_POWER_PC},
  {ArchitectureEnum_t::Architecture_RiscV, TEXT_ARCHITECTURE_RISCV},
  {ArchitectureEnum_t::Architecture_x86, TEXT_ARCHITECTURE_X86},
  {ArchitectureEnum_t::Architecture_x86_64, TEXT_ARCHITECTURE_X86_64}};

void ProjectSettingsHandler::Process(ObjdumpConfig& config)
{
    constexpr char* shouldSaveLabel    = TEXT_PROJECT_SETTINGS_HANDLER_SHOULD_SAVE_LABEL;
    constexpr char* prjPathLabel       = TEXT_PROJECT_SETTINGS_HANDLER_PRJ_PATH_LABEL;
    constexpr char* archLabel          = TEXT_PROJECT_SETTINGS_HANDLER_ARCH_LABEL;
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
    const char* preview = m_architectures.at(config.disassemblerOptions.architecture);
    if (ImGui::BeginCombo(archLabel, preview))
    {
        for (const auto& type : m_architectures)
        {
            if (ImGui::Selectable(type.second))
            {
                config.disassemblerOptions.architecture = type.first;
            }
        }
        ImGui::EndCombo();
    }
    ImGui::EndGroup();
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip(m_architectureHint);
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
bool        ShowArchiveHeadersHandler::m_active                 = false;

void ShowArchiveHeadersHandler::Process(ObjdumpConfig& config)
{
    constexpr char* label = TEXT_SHOW_ARCHIVE_HEADERS_LABEL;
    if (ImGui::Checkbox(label, &config.showArchiveHeader))
    {
        m_active = config.showArchiveHeader;
    }
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip(m_showArchiveHeadersHint);
    }
}

std::ostream& ShowArchiveHeadersHandler::ToString(std::ostream& os)
{
    if (m_active)
    {
        os << " " << m_objdumpFlag;
    }

    return os;
}

/************************************************************************/
/* SECTION: AdjustVmaOffsetHandler                                      */
/************************************************************************/
const char* AdjustVmaOffsetHandler::m_hint        = TEXT_ADJUST_VMA_OFFSET_HINT;
const char* AdjustVmaOffsetHandler::m_objdumpFlag = TEXT_ADJUST_VMA_OFFSET_FLAG;
int         AdjustVmaOffsetHandler::m_offset      = 0;


void AdjustVmaOffsetHandler::Process(ObjdumpConfig& config)
{
    constexpr char* label = TEXT_ADJUST_VMA_OFFSET_LABEL;
    if (ImGui::InputInt(
          label, &config.adjustVmaOffset, 4, 0x0100, ImGuiInputTextFlags_CharsHexadecimal))
    {
        m_offset = config.adjustVmaOffset;
    }
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip(m_hint);
    }
}

std::ostream& AdjustVmaOffsetHandler::ToString(std::ostream& os)
{
    if (m_offset != 0)
    {
        os << " " << m_objdumpFlag << (unsigned int)m_offset;
    }

    return os;
}

/************************************************************************/
/* SECTION: DemangleHandler                                             */
/************************************************************************/
const char* DemangleHandler::m_hint       = TEXT_DEMANGLE_HINT;
const char* DemangleHandler::m_objdumFlag = TEXT_DEMANGLE_FLAG;
bool        DemangleHandler::m_active     = false;

void DemangleHandler::Process(ObjdumpConfig& config)
{
    constexpr char* label = TEXT_DEMANGLE_LABEL;

    if (ImGui::Checkbox(label, &config.demangle))
    {
        m_active = config.demangle;
    }
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip(m_hint);
    }
}

std::ostream& DemangleHandler::ToString(std::ostream& os)
{
    if (m_active)
    {
        os << " " << m_objdumFlag;
    }

    return os;
}

/************************************************************************/
/* SECTION: ShowDebugInfoHandler                                        */
/************************************************************************/
const char* ShowDebugInfoHandler::m_hint            = TEXT_SHOW_DEBUG_INFO_HINT;
const char* ShowDebugInfoHandler::m_ctagHint        = TEXT_SHOW_DEBUG_INFO_CTAG_HINT;
const char* ShowDebugInfoHandler::m_objdumpFlag     = TEXT_SHOW_DEBUG_INFO_FLAG;
const char* ShowDebugInfoHandler::m_objdumpFlagCtag = TEXT_SHOW_DEBUG_INFO_CTAG_FLAG;
bool        ShowDebugInfoHandler::m_debActive       = false;
bool        ShowDebugInfoHandler::m_debCtagActive   = false;

void ShowDebugInfoHandler::Process(ObjdumpConfig& config)
{
    constexpr char* label     = TEXT_SHOW_DEBUG_INFO_LABEL;
    constexpr char* ctagLabel = TEXT_SHOW_DEBUG_INFO_CTAG_LABEL;

    if (ImGui::Checkbox(label, &config.showDebuggingInfo))
    {
        m_debActive = config.showDebuggingInfo;
    }
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip(m_hint);
    }
    if (ImGui::Checkbox(ctagLabel, &config.showDebuggingInfoForCtags))
    {
        m_debCtagActive = config.showDebuggingInfoForCtags;
    }
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip(m_ctagHint);
    }
}

std::ostream& ShowDebugInfoHandler::ToString(std::ostream& os)
{
    if (m_debActive)
    {
        os << " " << m_objdumpFlag;
    }
    if (m_debCtagActive)
    {
        os << " " << m_objdumpFlagCtag;
    }

    return os;
}

/************************************************************************/
/* SECTION: DisassembleHandler                                          */
/************************************************************************/
const char* DisassembleHandler::m_disassembleHint    = TEXT_DISASSEMBLE_HINT;
const char* DisassembleHandler::m_disassembleAllHint = TEXT_DISASSEMBLE_ALL_HINT;
const char* DisassembleHandler::m_disassembleFlag    = TEXT_DISASSEMBLE_FLAG;
const char* DisassembleHandler::m_disassembleAllFlag = TEXT_DISASSEMBLE_ALL_FLAG;
bool        DisassembleHandler::m_disActive          = false;
bool        DisassembleHandler::m_disAllActive       = false;

void DisassembleHandler::Process(ObjdumpConfig& config)
{
    constexpr char* disLabel    = TEXT_DISASSEMBLE_LABEL;
    constexpr char* disAllLabel = TEXT_DISASSEMBLE_ALL_LABEL;

    if (ImGui::Checkbox(disLabel, &config.disassemble))
    {
        m_disActive = config.disassemble;
    }
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip(m_disassembleHint);
    }

    if (ImGui::Checkbox(disAllLabel, &config.disassembleAll))
    {
        m_disAllActive = config.disassembleAll;
    }
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip(m_disassembleAllHint);
    }
}

std::ostream& DisassembleHandler::ToString(std::ostream& os)
{
    if (m_disActive)
    {
        os << " " << m_disassembleFlag;
    }
    if (m_disAllActive)
    {
        os << " " << m_disassembleAllFlag;
    }
    return os;
}

/************************************************************************/
/* SECTION: PrefixAddressesHandler                                      */
/************************************************************************/
const char* PrefixAddressesHandler::m_hint   = TEXT_PREFIX_ADDRESSES_HINT;
const char* PrefixAddressesHandler::m_flag   = TEXT_PREFIX_ADDRESSES_FLAG;
bool        PrefixAddressesHandler::m_active = false;


void PrefixAddressesHandler::Process(ObjdumpConfig& config)
{
    constexpr char* label = TEXT_PREFIX_ADDRESSES_LABEL;

    if (ImGui::Checkbox(label, &config.prefixAddresses))
    {
        m_active = config.prefixAddresses;
    }
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip(m_hint);
    }
}

std::ostream& PrefixAddressesHandler::ToString(std::ostream& os)
{
    if (m_active == false)
    {
        return os;
    }
    else
    {
        os << " " << m_flag;
        return os;
    }
}

/************************************************************************/
/* SECTION: EndiannessHandler                                           */
/************************************************************************/
const char*                             EndiannessHandler::m_hint  = TEXT_ENDIANNESS_HINT;
std::map<EndiannessEnum_t, const char*> EndiannessHandler::m_flags = {
  {Endianness_Auto, ""},
  {Endianness_Big, TEXT_ENDIANNESS_FLAG_BIG},
  {Endianness_Small, TEXT_ENDIANNESS_FLAG_SMALL}};
std::map<EndiannessEnum_t, const char*> EndiannessHandler::m_labels = {
  {Endianness_Auto, TEXT_ENDIANNESS_LABELS_AUTO},
  {Endianness_Big, TEXT_ENDIANNESS_LABELS_BIG},
  {Endianness_Small, TEXT_ENDIANNESS_LABELS_SMALL}};
;
EndiannessEnum_t EndiannessHandler::m_currentSelection;

void EndiannessHandler::Process(ObjdumpConfig& config)
{
    constexpr char* label = TEXT_ENDIANNESS_LABEL;

    ImGui::BeginGroup();
    if (ImGui::BeginCombo(label, m_labels[config.endianness]))
    {
        for (const auto& l : m_labels)
        {
            if (ImGui::Selectable(l.second))
            {
                m_currentSelection = l.first;
                config.endianness  = l.first;
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

std::ostream& EndiannessHandler::ToString(std::ostream& os)
{
    if (m_currentSelection != Endianness_Auto)
    {
        os << " " << m_flags[m_currentSelection];
    }
    return os;
}

/************************************************************************/
/* SECTION: ShowFileOffsetHandler                                       */
/************************************************************************/
const char* ShowFileOffsetHandler::m_hint   = TEXT_SHOW_FILE_OFFSET_HINT;
const char* ShowFileOffsetHandler::m_flag   = TEXT_SHOW_FILE_OFFSET_FLAG;
bool        ShowFileOffsetHandler::m_active = false;

void ShowFileOffsetHandler::Process(ObjdumpConfig& config)
{
    constexpr char* label = TEXT_SHOW_FILE_OFFSET_LABEL;
    if (ImGui::Checkbox(label, &config.showFileOffset))
    {
        m_active = config.showFileOffset;
    }
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip(m_hint);
    }
}

std::ostream& ShowFileOffsetHandler::ToString(std::ostream& os)
{
    if (m_active)
    {
        os << " " << m_flag;
    }
    return os;
}

/************************************************************************/
/* SECTION: ShowFileStartContextHandler                                 */
/************************************************************************/
const char* ShowFileStartContextHandler::m_hint   = TEXT_SHOW_FILE_START_CONTEXT_HINT;
const char* ShowFileStartContextHandler::m_flag   = TEXT_SHOW_FILE_START_CONTEXT_FLAG;
bool        ShowFileStartContextHandler::m_active = false;

void ShowFileStartContextHandler::Process(ObjdumpConfig& config)
{
    constexpr char* label = TEXT_SHOW_FILE_START_CONTEXT_LABEL;
    if (ImGui::Checkbox(label, &config.showFileStartContext))
    {
        m_active = config.showFileStartContext;
    }
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip(m_hint);
    }
}

std::ostream& ShowFileStartContextHandler::ToString(std::ostream& os)
{
    if (m_active)
    {
        os << " " << m_flag;
    }
    return os;
}

/************************************************************************/
/* SECTION: ShowInfoFromHeaderHandler                                   */
/************************************************************************/
const char* ShowInfoFromHeaderHandler::m_hint   = TEXT_SHOW_INFO_FROM_HEADER_HINT;
const char* ShowInfoFromHeaderHandler::m_flag   = TEXT_SHOW_INFO_FROM_HEADER_FLAG;
bool        ShowInfoFromHeaderHandler::m_active = false;

void ShowInfoFromHeaderHandler::Process(ObjdumpConfig& config)
{
    constexpr char* label = TEXT_SHOW_INFO_FROM_HEADER_LABEL;
    if (ImGui::Checkbox(label, &config.showInfoFromHeader))
    {
        m_active = config.showInfoFromHeader;
    }
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip(m_hint);
    }
}

std::ostream& ShowInfoFromHeaderHandler::ToString(std::ostream& os)
{
    if (m_active)
    {
        os << " " << m_flag;
    }
    return os;
}

/************************************************************************/
/* SECTION: ShowInfoFromSectionHandler                                   */
/************************************************************************/
const char* ShowInfoFromSectionHandler::m_hint   = TEXT_SHOW_INFO_FROM_SECTION_HINT;
const char* ShowInfoFromSectionHandler::m_flag   = TEXT_SHOW_INFO_FROM_SECTION_FLAG;
bool        ShowInfoFromSectionHandler::m_active = false;

void ShowInfoFromSectionHandler::Process(ObjdumpConfig& config)
{
    constexpr char* label = TEXT_SHOW_INFO_FROM_SECTION_LABEL;
    if (ImGui::Checkbox(label, &config.showInfoFromHeader))
    {
        m_active = config.showInfoFromHeader;
    }
    if (ImGui::IsItemHovered())
    {
        ImGui::SetTooltip(m_hint);
    }
}

std::ostream& ShowInfoFromSectionHandler::ToString(std::ostream& os)
{
    if (m_active)
    {
        os << " " << m_flag;
    }
    return os;
}
