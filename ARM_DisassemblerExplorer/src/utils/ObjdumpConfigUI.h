/******************************************************************************
 * @file ObjdumpConfigUI
 * @author Samuel Martel
 * @date 2020/07/27
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
#ifndef _ObjdumpConfigUI
#define _ObjdumpConfigUI

/*****************************************************************************/
/* Includes */
#include "utils/ObjdumpConfig.h"

#include <map>
#include "StringUtils.h"

class FileTypeHandler
{
public:
    static void Process(ObjdumpConfig& config);

private:
    static const char*                            m_hint;
    static const std::map<FileTypes, const char*> m_types;
};

class ProjectSettingsHandler
{
public:
    static void Process(ObjdumpConfig& config);

private:
    static const char*                                     m_shouldSaveHint;
    static const char*                                     m_prjPathHint;
    static const char*                                     m_architectureHint;
    static const char*                                     m_filePathHint;
    static const std::map<ArchitectureEnum_t, const char*> m_architectures;
};

class ShowArchiveHeadersHandler
{
public:
    static void Process(ObjdumpConfig& config);

    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_showArchiveHeadersHint;
    static const char* m_objdumpFlag;
    static bool        m_active;
};

class AdjustVmaOffsetHandler
{
public:
    static void Process(ObjdumpConfig& config);

    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_hint;
    static const char* m_objdumpFlag;
    static int         m_offset;
};

class DemangleHandler
{
public:
    static void Process(ObjdumpConfig& config);

    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_hint;
    static const char* m_objdumFlag;
    static bool        m_active;
};

class ShowDebugInfoHandler
{
public:
    static void Process(ObjdumpConfig& config);

    static std::ostream& ToString(std::ostream& os);


private:
    static const char* m_hint;
    static const char* m_ctagHint;
    static const char* m_objdumpFlag;
    static const char* m_objdumpFlagCtag;
    static bool        m_debActive;
    static bool        m_debCtagActive;
};

class DisassembleHandler
{
public:
    static void Process(ObjdumpConfig& config);

    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_disassembleHint;
    static const char* m_disassembleAllHint;
    static const char* m_disassembleFlag;
    static const char* m_disassembleAllFlag;
    static bool        m_disActive;
    static bool        m_disAllActive;
};

class PrefixAddressesHandler
{
public:
    static void Process(ObjdumpConfig& config);

    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_hint;
    static const char* m_flag;
    static bool        m_active;
};

class EndiannessHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char*                             m_hint;
    static std::map<EndiannessEnum_t, const char*> m_flags;
    static std::map<EndiannessEnum_t, const char*> m_labels;
    static EndiannessEnum_t                        m_currentSelection;
};

class ShowFileOffsetHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_hint;
    static const char* m_flag;
    static bool        m_active;
};

class ShowFileStartContextHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_hint;
    static const char* m_flag;
    static bool        m_active;
};

class ShowInfoFromHeaderHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_hint;
    static const char* m_flag;
    static bool        m_active;
};

class ShowInfoFromSectionHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_hint;
    static const char* m_flag;
    static bool        m_active;
};

class DisassemblerOptionHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_hint;
    static const char* m_flag;
};

/* Have a wonderful day :) */
#endif /* _ObjdumpConfigUI */
/**
 * @}
 */
/****** END OF FILE ******/
