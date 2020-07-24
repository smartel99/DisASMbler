/**
 ******************************************************************************
 * @addtogroup Francais
 * @{
 * @file    Francais
 * @author  Samuel Martel
 * @brief   Header for the Francais module.
 *
 * @date 7/23/2020 3:38:01 PM
 *
 ******************************************************************************
 */
#ifndef _Francais
#define _Francais

/*****************************************************************************/
/* Includes */


/************************************************************************/
/* SECTION: NewProjectLayer                                             */
/************************************************************************/
constexpr char* TEXT_NEW_PROJECT_LAYER_WINDOW_NAME = "Nouveau Projet";

/************************************************************************/
/* SECTION: ApplicationLayer                                            */
/************************************************************************/
constexpr char* TEXT_APPLICATION_LAYER_FILE = "Fichier";
constexpr char* TEXT_APPLICATION_LAYER_NEW  = "Nouveau";
constexpr char* TEXT_APPLICATION_LAYER_EXIT = "Quitter";

/************************************************************************/
/* SECTION: ObjdumpConfigUI                                             */
/************************************************************************/
constexpr char* TEXT_HINT_FILE_TYPE_HANDLER        = "Le type du fichier à désassembler";
constexpr char* TEXT_FILE_TYPE_HANDLER_TYPE_ALL    = "Automatique";
constexpr char* TEXT_FILE_TYPE_HANDLER_TYPE_ELF    = "Elf";
constexpr char* TEXT_FILE_TYPE_HANDLER_INPUT_LABEL = "Type de fichier";

constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_SHOULD_SAVE_HINT =
  "Cochez cette case pour sauvegarder le projet dans un fichier";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_PRJ_PATH_HINT =
  "Le fichier dans lequel le projet doit être sauvegarder. Cette option n'est pas disponible si "
  "l'option Sauvergarder n'est pas activé";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_FILE_PATH_HINT        = "Le fichier à désassembler";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_SHOULD_SAVE_LABEL     = "Sauvegarder le projet";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_PRJ_PATH_LABEL        = "Ficher du projet: %s";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_FILE_PATH_LABEL       = "Ficher à désassembler: %s";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_OPEN_PRJ_BUTTON_LABEL = "Ouvrir##prjPath";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_OPEN_BIN_BUTTON_LABEL = "Ouvrir##binPath";

constexpr char* TEXT_SHOW_ARCHIVE_HEADERS_HINT =
  R"(Si le fichier actif est une archive, affiche les informations d'entêtes d'archive (dans un format similaire à `ls -l`).
En addition au informations données par `ar tv`, cette option donne aussi le format de fichier de chaque objets de l'archive.)";
constexpr char* TEXT_SHOW_ARCHIVE_HEADERS_LABEL = "Afficher les entêtes d'archive";
constexpr char* TEXT_SHOW_ARCHIVE_HEADERS_FLAG  = "-a";

constexpr char* TEXT_ADJUST_VMA_OFFSET_HINT =
  R"(Lors du vidage d'informations, ajoute d'abord un décalage à toutes les adresses de section. 
Ceci est utile si les adresses de section ne correspondent pas à la table des symboles, 
ce qui peut se produire lorsque des sections sont plassées à des adresses particulières lors de 
l'utilisation d'un format qui ne peut pas représenter les adresses de section, comme le format .out.)";
constexpr char* TEXT_ADJUST_VMA_OFFSET_FLAG = "--adjust-vma=";
/* Have a wonderful day :) */
#endif /* _Francais */
/**
 * @}
 */
/****** END OF FILE ******/
