/**
 ******************************************************************************
 * @addtogroup File
 * @{
 * @file    File
 * @author  Samuel Martel
 * @brief   Header for the File module.
 *
 * @date 7/23/2020 8:34:00 AM
 *
 ******************************************************************************
 */
#ifndef _File
#define _File

/*****************************************************************************/
/* Includes */
#include <string>
#include <map>

/*****************************************************************************/
/* Exported defines */


/*****************************************************************************/
/* Exported macro */


/*****************************************************************************/
/* Exported types */
enum class FileTypes
{
    Elf = 0,
    All
};

enum class FileMode
{
    Open = 0,
    Save
};


class File
{
public:
    static std::string OpenFile(FileTypes type = FileTypes::All, FileMode mode = FileMode::Open);
    static std::string GetCurrentPath();

    static const char* GetExtensionForFileType(FileTypes type)
    {
        auto it = m_fileTypeExtensions.find(type);
        if (it != m_fileTypeExtensions.end())
        {
            return it->second.c_str();
        }
        else
        {
            return "*.*";
        }
    }

private:
    static std::map<FileTypes, std::string> m_fileTypeExtensions;
};

/*****************************************************************************/
/* Exported functions */


/* Have a wonderful day :) */
#endif /* _File */
/**
 * @}
 */
/****** END OF FILE ******/
