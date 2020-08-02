#include "ProjectCreationLayer.h"

#include "ExplorerLayer.h"

#include "text/Text.h"

#include "ImGui/imgui.h"

#include <thread>

static std::thread th;
static bool        done = false;

static void ThFunc()
{
    done = false;
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    done = true;
}

ProjectCreationLayer::ProjectCreationLayer(const ObjdumpConfig& config, const std::string& args)
: m_config(config), m_args(args)
{
}

void ProjectCreationLayer::OnAttach()
{
    th = std::thread(ThFunc);
    // Find which objdump to use
    // Start objdump process with args
}

void ProjectCreationLayer::OnDetach()
{
}

void ProjectCreationLayer::OnUpdate(Brigerad::Timestep ts)
{
}

void ProjectCreationLayer::OnImGuiRender()
{
    ImGui::Begin(TEXT_PROJECT_CREATION_LAYER_TITLE);
    ImGui::Text("Args received: %s", m_args.c_str());
    ImGui::End();

    if (done)
    {
        th.join();
        // #TODO Send output file instead of args.
        Brigerad::Application::Get().PushLayer(new ExplorerLayer(m_config, m_args));

        Brigerad::Application::Get().PopLayer(this);
    }
}

void ProjectCreationLayer::OnEvent(Brigerad::Event& e)
{
}
