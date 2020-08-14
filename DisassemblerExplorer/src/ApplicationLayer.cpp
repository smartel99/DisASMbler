/******************************************************************************
 * @file ApplicationLayer
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

#include "ApplicationLayer.h"

#include "ProjectSettingsLayer.h"
#include "text/Text.h"
#include "utils/File.h"

#include "ImGui/imgui.h"

#include <string>
#include <sstream>

ApplicationLayer::ApplicationLayer() : Brigerad::Layer("ARM_DisassemblerExplorer")
{
}

void ApplicationLayer::OnAttach()
{
    BR_PROFILE_FUNCTION();
}

void ApplicationLayer::OnDetach()
{
    BR_PROFILE_FUNCTION();
}

void ApplicationLayer::OnUpdate(Brigerad::Timestep ts)
{
    BR_PROFILE_FUNCTION();
}

void ApplicationLayer::OnImGuiRender()
{
    BR_PROFILE_FUNCTION();

    static bool               dockspaceOpen             = true;
    static bool               opt_fullscreen_persistant = true;
    bool                      opt_fullscreen            = opt_fullscreen_persistant;
    static ImGuiDockNodeFlags dockspace_flags           = ImGuiDockNodeFlags_None;
    static bool               renderAbout               = false;

    // We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
    // because it would be confusing to have two docking targets within each others.
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
    if (opt_fullscreen)
    {
        ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->Pos);
        ImGui::SetNextWindowSize(viewport->Size);
        ImGui::SetNextWindowViewport(viewport->ID);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
                        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
    }

    // When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background and
    // handle the pass-thru hole, so we ask Begin() to not render a background.
    if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
        window_flags |= ImGuiWindowFlags_NoBackground;

    // Important: note that we proceed even if Begin() returns false (aka window is collapsed).
    // This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
    // all active windows docked into it will lose their parent and become un docked.
    // We cannot preserve the docking relationship between an active window and an inactive docking,
    // otherwise any change of dock space/settings would lead to windows being stuck in limbo and
    // never being visible.
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    ImGui::Begin("DockSpace Demo", &dockspaceOpen, window_flags);
    ImGui::PopStyleVar();

    if (opt_fullscreen)
        ImGui::PopStyleVar(2);

    // DockSpace
    ImGuiIO& io = ImGui::GetIO();
    if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
    {
        ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
    }

    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu(TEXT_APPLICATION_LAYER_FILE))
        {
            if (ImGui::MenuItem(TEXT_APPLICATION_LAYER_NEW))
            {
                Brigerad::Application::Get().PushLayer(new ProjectSettingsLayer());
            }
            if (ImGui::MenuItem(TEXT_APPLICATION_LAYER_OPEN))
            {
                LoadProject();
            }
            if (ImGui::MenuItem(TEXT_APPLICATION_LAYER_EXIT))
            {
                Brigerad::Application::Get().Close();
            }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu(TEXT_APPLICATION_LAYER_HELP))
        {
            if (ImGui::MenuItem(TEXT_APPLICATION_LAYER_ABOUT))
            {
                renderAbout = true;
            }
            ImGui::EndMenu();
        }

        ImGui::EndMenuBar();
    }

    ImGui::End();

    if (renderAbout)
    {
        ImGui::Begin(TEXT_APPLICATION_LAYER_ABOUT, &renderAbout);
        ImGui::Text(TEXT_APPLICATION_LAYER_ABOUT_TEXT);
        ImGui::End();
    }
}

void ApplicationLayer::OnEvent(Brigerad::Event& e)
{
}

void ApplicationLayer::LoadProject()
{
    std::string filePath = File::OpenFile(FileTypes::All);

    if (filePath.empty())
    {
        return;
    }

    std::ifstream file = std::ifstream(filePath);

    if (file.is_open() == false)
    {
        BR_WARN("Unable to open file \"{}\"", filePath);
        return;
    }

    std::stringstream ss;
    ss << file.rdbuf();

    std::string header = "";
    std::getline(ss, header);

    if (header != "DISASMBLER START")
    {
        BR_WARN("Unrecognized file format!");
        return;
    }

    // First 103 lines is the objdump configuration of the project.
    std::vector<std::string> config;
    config.reserve(103);

    for (int i = 0; i < 103; i++)
    {
        std::string line = "";
        if (!std::getline(ss, line))
        {
            break;
        }

        config.emplace_back(line);
    }

    std::string content;
    std::string line;
    while (std::getline(ss, line, '\0'))
    {
        content += line + '\n';
    }

    ObjdumpConfig objdumpConfig;
    objdumpConfig.Desirialize(config);

    Brigerad::Application::Get().PushLayer(new ExplorerLayer(objdumpConfig, content));
}
