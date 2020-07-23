/**
 ******************************************************************************
 * @addtogroup NewProjectLayer
 * @{
 * @file    NewProjectLayer
 * @author  Samuel Martel
 * @brief   Header for the NewProjectLayer module.
 *
 * @date 7/23/2020 9:26:49 AM
 *
 ******************************************************************************
 */
#ifndef _NewProjectLayer
#define _NewProjectLayer

#include "Brigerad.h"

#include "utils/ObjdumpConfig.h"

class NewProjectLayer : public Brigerad::Layer
{
public:
    NewProjectLayer();
    virtual ~NewProjectLayer() override = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;

    void         OnUpdate(Brigerad::Timestep ts) override;
    virtual void OnImGuiRender() override;
    void         OnEvent(Brigerad::Event& e) override;

private:
    bool          m_isOpen = true;
    ObjdumpConfig m_config;
};
/* Have a wonderful day :) */
#endif /* _NewProjectLayer */
/**
 * @}
 */
/****** END OF FILE ******/
