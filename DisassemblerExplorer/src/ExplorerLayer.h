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
#include "utils/File.h"


class ExplorerLayer : public Brigerad::Layer
{
public:
    ExplorerLayer();
    virtual ~ExplorerLayer() override = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;

    void         OnUpdate(Brigerad::Timestep ts) override;
    virtual void OnImGuiRender() override;
    void         OnEvent(Brigerad::Event& e) override;

private:
};


/* Have a wonderful day :) */
#endif /* _Explorer */
/**
 * @}
 */
/****** END OF FILE ******/
