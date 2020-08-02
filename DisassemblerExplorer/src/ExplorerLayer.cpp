#include "ExplorerLayer.h"


#include <ImGui/imgui.h>

ExplorerLayer::ExplorerLayer(const ObjdumpConfig& config, const std::string& content)
: m_config(config), m_content(content)
{
}


void ExplorerLayer::OnAttach()
{
}



void ExplorerLayer::OnDetach()
{
}



void ExplorerLayer::OnUpdate(Brigerad::Timestep ts)
{
    if (m_open == false)
    {
        Brigerad::Application::Get().PopLayer(this);
    }
}



void ExplorerLayer::OnImGuiRender()
{
    ImGui::Begin("Placeholder name", &m_open);
    ImGui::TextUnformatted(m_content.c_str());
    ImGui::End();
}



void ExplorerLayer::OnEvent(Brigerad::Event& e)
{
}
