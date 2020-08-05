#include "ExplorerLayer.h"


#include <ImGui/imgui.h>

ExplorerLayer::ExplorerLayer(const ObjdumpConfig& config, const std::string& content)
: m_config(config), m_content(content)
{
    size_t pos = m_config.pathOfBin.find_last_of("/\\");
    m_name     = m_config.pathOfBin.substr(pos);
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
    ImGui::Begin(m_name.c_str(), &m_open);
    ImGui::TextUnformatted(m_content.c_str());
    ImGui::End();
}



void ExplorerLayer::OnEvent(Brigerad::Event& e)
{
}
