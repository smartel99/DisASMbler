/******************************************************************************
 * @file WindowsBackgroundProcess
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

#include "utils/BackgroundProcess.h"

#include "Brigerad/Debug/Instrumentor.h"

#include <sstream>
#include <fstream>
#include <windows.h>

BackgroundProcess::BackgroundProcess(const std::string& cmd, bool redirectOut)
: m_cmd(cmd), m_redirectOut(redirectOut), m_isRunning(true)

{
    if (m_redirectOut)
    {
        std::stringstream ss;
        ss << this << ".tmp";
        m_fileName = ss.str();
    }

    m_task = std::thread(&BackgroundProcess::Task, this);
}

BackgroundProcess::~BackgroundProcess()
{
    // Wait for task to be done.
    while (m_isRunning)
    {
    }

    // Join thread.
    if (m_task.joinable())
    {
        m_task.join();
    }
}

std::string BackgroundProcess::GetOutput()
{
    if (m_redirectOut == false || m_isRunning)
    {
        return "";
    }

    std::ifstream     file = std::ifstream(m_fileName);
    std::stringstream ss;
    ss << file.rdbuf();

    return ss.str();
}

bool BackgroundProcess::IsTaskRunning()
{
    return m_isRunning;
}

void BackgroundProcess::Task()
{
    BR_PROFILE_FUNCTION();

    SECURITY_ATTRIBUTES sa;
    sa.nLength              = sizeof(sa);
    sa.lpSecurityDescriptor = nullptr;
    sa.bInheritHandle       = true;

    HANDLE outFile = CreateFileA(m_fileName.c_str(),
                                 GENERIC_WRITE,
                                 FILE_SHARE_WRITE | FILE_SHARE_READ,
                                 &sa,
                                 CREATE_ALWAYS,
                                 FILE_ATTRIBUTE_NORMAL,
                                 nullptr);

    STARTUPINFOA        si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    si.dwFlags |= m_redirectOut ? STARTF_USESTDHANDLES : 0;
    si.hStdOutput = outFile;
    si.hStdError  = outFile;
    si.hStdInput  = GetStdHandle(STD_INPUT_HANDLE);
    ZeroMemory(&pi, sizeof(pi));

    BR_INFO("Starting background task...");

    if (!CreateProcessA(nullptr,
                        m_cmd.data(),
                        nullptr,
                        nullptr,
                        true,
                        CREATE_NO_WINDOW,
                        nullptr,
                        nullptr,
                        &si,
                        &pi))
    {
        BR_ERROR("Unable to start background task!");
        return;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    CloseHandle(outFile);

    BR_INFO("Done!");

    m_isRunning = false;
}
