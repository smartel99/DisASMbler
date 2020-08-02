/******************************************************************************
 * @file ExplorerLayer
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
#ifndef _Explorer
#define _Explorer

#include "Brigerad.h"
#include "utils/File.h"

#include "utils/ObjdumpConfig.h"


class ExplorerLayer : public Brigerad::Layer
{
public:
    ExplorerLayer() = delete;
    ExplorerLayer(const ObjdumpConfig& config, const std::string& content);
    virtual ~ExplorerLayer() override = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;

    void         OnUpdate(Brigerad::Timestep ts) override;
    virtual void OnImGuiRender() override;
    void         OnEvent(Brigerad::Event& e) override;

private:
    ObjdumpConfig m_config;
    std::string   m_content;
    bool          m_open = true;
};


/* Have a wonderful day :) */
#endif /* _Explorer */
/**
 * @}
 */
/****** END OF FILE ******/
