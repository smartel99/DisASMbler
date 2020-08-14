#pragma once

#include "Brigerad.h"

class ApplicationLayer : public Brigerad::Layer
{
public:
    ApplicationLayer();
    virtual ~ApplicationLayer() override = default;

    void OnAttach() override;
    void OnDetach() override;

    void OnUpdate(Brigerad::Timestep ts) override;
    void OnImGuiRender() override;
    void OnEvent(Brigerad::Event& e) override;

private:
    void LoadProject();
};
