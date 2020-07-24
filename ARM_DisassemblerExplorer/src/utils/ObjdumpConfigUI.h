/**
 ******************************************************************************
 * @addtogroup ObjdumpConfigUI
 * @{
 * @file    ObjdumpConfigUI
 * @author  Samuel Martel
 * @brief   Header for the ObjdumpConfigUI module.
 *
 * @date 7/23/2020 3:05:54 PM
 *
 ******************************************************************************
 */
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
    static const char* m_shouldSaveHint;
    static const char* m_prjPathHint;
    static const char* m_filePathHint;
};

class ShowArchiveHeadersHandler
{
public:
    static void        Process(ObjdumpConfig& config);
    static const char* GetObjdumpFlag() { return m_objdumpFlag; }

private:
    static const char* m_showArchiveHeadersHint;
    static const char* m_objdumpFlag;
};

class AdjustVmaOffsetHandler
{
public:
    static void        Process(ObjdumpConfig& config);
    static const char* GetObjdumpFlag()
    {
        return "";
        //         return std::string(m_objdumpFlag + StringUtils::ToString(m_offset)).c_str();
    }

private:
    static const char* m_hint;
    static const char* m_objdumpFlag;
    static size_t      m_offset;
};


/* Have a wonderful day :) */
#endif /* _ObjdumpConfigUI */
/**
 * @}
 */
/****** END OF FILE ******/
