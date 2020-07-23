#pragma once

#include "Brigerad.h"
#include "text/Text.h"

class ApplicationLayer : public Brigerad::Layer
{
public:
    ApplicationLayer();
    virtual ~ApplicationLayer() override = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;

    void         OnUpdate(Brigerad::Timestep ts) override;
    virtual void OnImGuiRender() override;
    void         OnEvent(Brigerad::Event& e) override;

private:
};
