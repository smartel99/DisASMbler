/******************************************************************************
 * @file BackgroundProcess
 * @author Samuel Martel
 * @date 2020/08/04
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

#include <string>
#include <thread>

class BackgroundProcess
{
public:
    BackgroundProcess(const std::string& cmd, bool redirectOut = true);
    ~BackgroundProcess();

    std::string GetOutput();
    bool        IsTaskRunning();

private:
    void Task();

private:
    std::thread m_task;
    std::string m_fileName;
    std::string m_cmd;
    bool        m_isRunning;
    bool        m_redirectOut;
};
