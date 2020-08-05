/******************************************************************************
 * @file ProjectCreationLayer
 * @author Samuel Martel
 * @date 2020/08/02
 * @brief
 ******************************************************************************
 * Copyright (C) 2020  Samuel Martel - Pascal-Emmanuel Lachance
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *****************************************************************************/
#pragma once

#include "Brigerad.h"
#include "utils/File.h"

#include "utils/ObjdumpConfig.h"
#include "utils/BackgroundProcess.h"


class ProjectCreationLayer : public Brigerad::Layer
{
public:
    ProjectCreationLayer() = delete;
    ProjectCreationLayer(const ObjdumpConfig& config, const std::string& args);
    virtual ~ProjectCreationLayer() override = default;

    void OnAttach() override;
    void OnDetach() override;

    void OnUpdate(Brigerad::Timestep ts) override;
    void OnImGuiRender() override;
    void OnEvent(Brigerad::Event& e) override;

private:
    Brigerad::Ref<BackgroundProcess> m_task;
    ObjdumpConfig                    m_config;
    std::string                      m_args;
    char                             m_loadingChar = '/';
};
