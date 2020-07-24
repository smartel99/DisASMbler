#include "NewProjectLayer.h"

#include "utils/StringUtils.h"
#include "text/Text.h"
#include "ImGui/imgui.h"
#include "utils/ObjdumpConfigUI.h"

NewProjectLayer::NewProjectLayer()
{
}


void NewProjectLayer::OnAttach()
{
}


void NewProjectLayer::OnDetach()
{
}


void NewProjectLayer::OnUpdate(Brigerad::Timestep ts)
{
}


void NewProjectLayer::OnImGuiRender()
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

    ImGui::End();
}


void NewProjectLayer::OnEvent(Brigerad::Event& e)
{
}
