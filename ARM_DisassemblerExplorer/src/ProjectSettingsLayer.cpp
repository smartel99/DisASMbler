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

ProjectSettingsLayer::ProjectSettingsLayer()
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
}


void ProjectSettingsLayer::OnImGuiRender()
{
    if (m_isOpen == false)
    {
        Brigerad::Application::Get().PopLayer(this);
        return;
    }
    ImGui::Begin(TEXT_NEW_PROJECT_LAYER_WINDOW_NAME, &m_isOpen);

    FileTypeHandler::Process(m_config);
    ProjectSettingsHandler::Process(m_config);
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

    ImGui::End();

    std::stringstream ss;
    ss << "objdump";
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

    BR_INFO("ObjDump Command: {}", ss.str().c_str());
}


void ProjectSettingsLayer::OnEvent(Brigerad::Event& e)
{
}
