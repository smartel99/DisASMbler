#include "ProjectCreationLayer.h"

#include "ExplorerLayer.h"

#include "text/Text.h"

#include "ImGui/imgui.h"


ProjectCreationLayer::ProjectCreationLayer(const ObjdumpConfig& config, const std::string& args)
: m_config(config), m_args(args)
{
}

void ProjectCreationLayer::OnAttach()
{
    BR_PROFILE_FUNCTION();
    std::string objdump = "";
    // #TODO Make this universal for any platform
    switch (m_config.disassemblerOptions.architecture)
    {
        case Architecture_Arm:
            objdump = "GNUTools/arm-none-eabi-objdump.exe";
            break;
        case Architecture_Avr:
            objdump = "GNUTools/avr-objdump.exe";
            break;
        case Architecture_x86:
            objdump = "GNUTools/mingw32-objdump.exe";
            break;
        case Architecture_x86_64:
            objdump = "GNUTools/mingw64-objdump.exe";
            break;
        case Architecture_PowerPc:
            objdump = "GNUTools/powerpc-eabi-objdump.exe";
            break;
        case Architecture_RiscV:
            objdump = "GNUTools/riscv64-unknown-elf-objdump.exe";
            break;
        case Architecture_Aarch64:
        case Architecture_Mips:
            BR_ASSERT(false, "Unavailable");
            break;
        case ArchitectureEnum_t::Architecture_Auto:
        default:
            BR_ASSERT(false, "Unsupported architecture!")
    }

    BR_INFO("CMD: \"{}{}\"", objdump, m_args);
    m_task = Brigerad::CreateRef<BackgroundProcess>(objdump + m_args);
}

void ProjectCreationLayer::OnDetach()
{
    BR_PROFILE_FUNCTION();
    while (m_task->IsTaskRunning())
    {
        // Wait for task to complete.
    }
}

void ProjectCreationLayer::OnUpdate(Brigerad::Timestep ts)
{
    BR_PROFILE_FUNCTION();
    constexpr const char chars[4]    = {'/', '|', '\\', '-'};
    static float         time        = 0.0f;
    static size_t        currentChar = 0;

    time += ts.GetMilliseconds();
    if (time >= 250.0f)
    {
        time          = 0.0f;
        currentChar   = currentChar + 1 >= sizeof(chars) ? 0 : currentChar + 1;
        m_loadingChar = chars[currentChar];
    }

    if (m_task->IsTaskRunning() == false)
    {
        Brigerad::Application::Get().PushLayer(new ExplorerLayer(m_config, m_task->GetOutput()));
        Brigerad::Application::Get().PopLayer(this);
    }
}

void ProjectCreationLayer::OnImGuiRender()
{
    BR_PROFILE_FUNCTION();
    ImGui::Begin(TEXT_PROJECT_CREATION_LAYER_TITLE);
    ImGui::Text("Loading... %c", m_loadingChar);
    ImGui::Text("Args received: %s", m_args.c_str());
    ImGui::End();

    //     if (done)
    //     {
    //         th.join();
    //         // #TODO Send output file instead of args.
    //         Brigerad::Application::Get().PushLayer(new ExplorerLayer(m_config, m_args));
    //
    //         Brigerad::Application::Get().PopLayer(this);
    //     }
}

void ProjectCreationLayer::OnEvent(Brigerad::Event& e)
{
}
