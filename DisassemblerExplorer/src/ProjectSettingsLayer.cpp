/******************************************************************************
 * @file ProjectSettingsLayer
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

#include "ProjectSettingsLayer.h"

#include "utils/StringUtils.h"
#include "text/Text.h"
#include "ImGui/imgui.h"
#include "utils/ObjdumpConfigUI.h"
#include "ProjectCreationLayer.h"

ProjectSettingsLayer::ProjectSettingsLayer() : m_editingProject(nullptr), m_config()
{
}

ProjectSettingsLayer::ProjectSettingsLayer(ExplorerLayer* prj, const ObjdumpConfig& config)
: m_editingProject(prj), m_config(config)
{
}


void ProjectSettingsLayer::OnAttach()
{
}


void ProjectSettingsLayer::OnDetach()
{
}


void ProjectSettingsLayer::OnUpdate(Brigerad::Timestep ts)
{
    if (m_isOpen == false)
    {
        Brigerad::Application::Get().PopLayer(this);
        return;
    }
}


void ProjectSettingsLayer::OnImGuiRender()
{
    ImGui::Begin(TEXT_NEW_PROJECT_LAYER_WINDOW_NAME, &m_isOpen);

    FileTypeHandler::Process(m_config);
    ProjectSettingsHandler::Process(m_config);
    DisassemblerOptionHandler::Process(m_config);
    ShowArchiveHeadersHandler::Process(m_config);
    AdjustVmaOffsetHandler::Process(m_config);
    DemangleHandler::Process(m_config);
    ShowDebugInfoHandler::Process(m_config);
    DisassembleHandler::Process(m_config);
    PrefixAddressesHandler::Process(m_config);
    EndiannessHandler::Process(m_config);
    ShowFileOffsetHandler::Process(m_config);
    ShowFileStartContextHandler::Process(m_config);
    ShowInfoFromHeaderHandler::Process(m_config);
    ShowRelocEntriesHandler::Process(m_config);
    ShowSourceHandler::Process(m_config);
    PathHandler::Process(m_config);
    ShowRawInstructionHandler::Process(m_config);
    VisualizeJumpsHandler::Process(m_config);
    DwarfOptionsHandler::Process(m_config);
    CtfSectionHandler::Process(m_config);
    ShowFullSectionContentHandler::Process(m_config);
    AddressRangeHandler::Process(m_config);
    ShowSymbolTableAsSymsHandler::Process(m_config);
    ExtraFormatOptionsHandler::Process(m_config);
    ShowAllHeadersHandler::Process(m_config);
    DisassembleZerosHandler::Process(m_config);

    ImGui::Separator();
    if (ImGui::Button(TEXT_BUTTON_LABEL_CONFIRM))
    {
        if (m_editingProject != nullptr)
        {
            Brigerad::Application::Get().PopLayer(m_editingProject);
        }
        Brigerad::Application::Get().PushLayer(
          new ProjectCreationLayer(m_config, MakeObjdumpCmd()));
        Brigerad::Application::Get().PopLayer(this);
    }

    ImGui::SameLine();

    if (ImGui::Button(TEXT_BUTTON_LABEL_CANCEL))
    {
        Brigerad::Application::Get().PopLayer(this);
    }

    ImGui::End();
}


void ProjectSettingsLayer::OnEvent(Brigerad::Event& e)
{
}

std::string ProjectSettingsLayer::MakeObjdumpCmd()
{
    std::stringstream ss;
    ShowArchiveHeadersHandler::ToString(ss);
    AdjustVmaOffsetHandler::ToString(ss);
    DemangleHandler::ToString(ss);
    ShowDebugInfoHandler::ToString(ss);
    DisassembleHandler::ToString(ss);
    PrefixAddressesHandler::ToString(ss);
    EndiannessHandler::ToString(ss);
    ShowFileOffsetHandler::ToString(ss);
    ShowFileStartContextHandler::ToString(ss);
    ShowInfoFromHeaderHandler::ToString(ss);
    DisassemblerOptionHandler::ToString(ss);
    ShowRelocEntriesHandler::ToString(ss);
    ShowSourceHandler::ToString(ss);
    PathHandler::ToString(ss);
    ShowRawInstructionHandler::ToString(ss);
    // VisualizeJumpsHandler::ToString(ss);
    DwarfOptionsHandler::ToString(ss);
    CtfSectionHandler::ToString(ss);
    ShowFullSectionContentHandler::ToString(ss);
    AddressRangeHandler::ToString(ss);
    ShowSymbolTableAsSymsHandler::ToString(ss);
    ExtraFormatOptionsHandler::ToString(ss);
    ShowAllHeadersHandler::ToString(ss);
    DisassembleZerosHandler::ToString(ss);
    ss << " " << '"'<< m_config.pathOfBin << '"';

    return ss.str();
}
