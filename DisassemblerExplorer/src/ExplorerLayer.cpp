#include "ExplorerLayer.h"


#include <ImGui/imgui.h>

ExplorerLayer::ExplorerLayer(const ObjdumpConfig& config, const std::string& content)
: m_config(config)
{
    size_t pos = m_config.pathOfBin.find_last_of("/\\");
    m_name     = m_config.pathOfBin.substr(pos);

    std::stringstream ss(content);

    std::string tmp;
    while (std::getline(ss, tmp, '\n'))
    {
        m_content.emplace_back(tmp);
    }
}


void ExplorerLayer::OnAttach()
{
    if (m_config.shouldSavePrj)
    {
        Save();
    }
}



void ExplorerLayer::OnDetach()
{
    if (m_config.shouldSavePrj && m_dirty)
    {
        Save();
    }
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
    for (const auto& line : m_content)
    {
        ImGui::TextUnformatted(line.c_str());
    }
    ImGui::End();
}



void ExplorerLayer::OnEvent(Brigerad::Event& e)
{
}

void ExplorerLayer::Save()
{
    std::ofstream file = std::ofstream(m_config.pathOfPrj);
    if (file.is_open() == false)
    {
        BR_ERROR("Unable to open output file \"{}\"", m_config.pathOfPrj.c_str());
        return;
    }

    file << m_config.Serialize();
    for (const auto& line : m_content)
    {
        file << line << "\n";
    }

    file.close();
}
