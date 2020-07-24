/**
 ******************************************************************************
 * @addtogroup English
 * @{
 * @file    English
 * @author  Samuel Martel
 * @brief   Header for the English module.
 *
 * @date 7/23/2020 3:15:52 PM
 *
 ******************************************************************************
 */
#ifndef _English
#define _English

/*****************************************************************************/
/* Includes */

/************************************************************************/
/* SECTION: NewProjectLayer                                             */
/************************************************************************/
constexpr char* TEXT_NEW_PROJECT_LAYER_WINDOW_NAME = "New Project";

/************************************************************************/
/* SECTION: ApplicationLayer                                            */
/************************************************************************/
constexpr char* TEXT_APPLICATION_LAYER_FILE = "File";
constexpr char* TEXT_APPLICATION_LAYER_NEW  = "New";
constexpr char* TEXT_APPLICATION_LAYER_EXIT = "Exit";

/************************************************************************/
/* SECTION: ObjdumpConfigUI                                             */
/************************************************************************/
constexpr char* TEXT_HINT_FILE_TYPE_HANDLER        = "The type of file that is to be disassembled";
constexpr char* TEXT_FILE_TYPE_HANDLER_TYPE_ALL    = "Automatic";
constexpr char* TEXT_FILE_TYPE_HANDLER_TYPE_ELF    = "Elf";
constexpr char* TEXT_FILE_TYPE_HANDLER_INPUT_LABEL = "File Type";

constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_SHOULD_SAVE_HINT =
  "Check this box to save the project into a file";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_PRJ_PATH_HINT =
  "The path where the project should be saved. This option is disabled if the Should Save option "
  "is not enabled";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_FILE_PATH_HINT =
  "The path to the file to disassemble";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_SHOULD_SAVE_LABEL     = "Save Project";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_PRJ_PATH_LABEL        = "Project Path: %s";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_FILE_PATH_LABEL       = "Binary File Path: %s";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_OPEN_PRJ_BUTTON_LABEL = "Open##prjPath";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_OPEN_BIN_BUTTON_LABEL = "Open##binPath";

constexpr char* TEXT_SHOW_ARCHIVE_HEADERS_HINT =
  R"(If the file being worked on is an archive, display the archive header information (in a format similar to `ls -l`).
Besides the information you could list with `ar tv`, this option shows the object file format of each archive member.)";
constexpr char* TEXT_SHOW_ARCHIVE_HEADERS_LABEL = "Show Archive Headers";
constexpr char* TEXT_SHOW_ARCHIVE_HEADERS_FLAG  = "-a";

constexpr char* TEXT_ADJUST_VMA_OFFSET_HINT =
  R"(When dumping information, first add an offset to all the section addresses.
This is useful if the section addresses do not correspond to the symbol table, 
which can happen when putting sections at particular addresses when using a format which can not represent section addresses, 
such as the .out file format.)";
constexpr char* TEXT_ADJUST_VMA_OFFSET_FLAG = "--adjust-vma=";

#endif
/* Have a wonderful day :) */
/**
 * @}
 */
/****** END OF FILE ******/
