/**
 ******************************************************************************
 * @addtogroup Explorer
 * @{
 * @file    Explorer
 * @author  Samuel Martel
 * @brief   Header for the Explorer module.
 *
 * @date 7/22/2020 5:45:23 PM
 *
 ******************************************************************************
 */
#ifndef _Explorer
#define _Explorer

#include "Brigerad.h"

namespace Brigerad
{
class ExplorerLayer : public Layer
{
public:
    ExplorerLayer();
    virtual ~ExplorerLayer() = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;

    void         OnUpdate(Timestep ts) override;
    virtual void OnImGuiRender() override;
    void         OnEvent(Event& e) override;

private:
};
}    // namespace Brigerad


/* Have a wonderful day :) */
#endif /* _Explorer */
/**
 * @}
 */
/****** END OF FILE ******/
