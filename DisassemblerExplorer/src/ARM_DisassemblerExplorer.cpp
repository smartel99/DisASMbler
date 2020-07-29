#include "Brigerad.h"
#include "Brigerad/Core/EntryPoint.h"

#include "Platform/OpenGL/OpenGLShader.h"

#include "ApplicationLayer.h"

#include "ImGui/imgui.h"

#include <glm/gtc/type_ptr.hpp>

#define sizeof_array(x) sizeof(x) / sizeof(x[0])

namespace Brigerad
{
class ArmDisassemblerExplorer : public Application
{
public:
    ArmDisassemblerExplorer() : Application("Brigerad Editor")
    {
        PushLayer(new ApplicationLayer());
    }

    ~ArmDisassemblerExplorer() override = default;
};

Application* CreateApplication()
{
    return new ArmDisassemblerExplorer();
}
}    // namespace Brigerad
