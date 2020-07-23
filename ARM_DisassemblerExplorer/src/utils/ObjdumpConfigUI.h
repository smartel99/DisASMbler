/**
 ******************************************************************************
 * @addtogroup ObjdumpConfigUI
 * @{
 * @file    ObjdumpConfigUI
 * @author  Client Microdata
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


/* Have a wonderful day :) */
#endif /* _ObjdumpConfigUI */
/**
 * @}
 */
/****** END OF FILE ******/
