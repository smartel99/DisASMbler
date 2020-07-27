/******************************************************************************
 * @file Francais
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
#pragma once

/*****************************************************************************/
/* Includes */


/************************************************************************/
/* SECTION: NewProjectLayer                                             */
/************************************************************************/
constexpr char* TEXT_NEW_PROJECT_LAYER_WINDOW_NAME = "Nouveau Projet";

/************************************************************************/
/* SECTION: ApplicationLayer                                            */
/************************************************************************/
constexpr char* TEXT_APPLICATION_LAYER_FILE  = "Fichier";
constexpr char* TEXT_APPLICATION_LAYER_NEW   = "Nouveau";
constexpr char* TEXT_APPLICATION_LAYER_EXIT  = "Quitter";
constexpr char* TEXT_APPLICATION_LAYER_HELP  = "Aide";
constexpr char* TEXT_APPLICATION_LAYER_ABOUT = "À propos";
constexpr char* TEXT_APPLICATION_LAYER_ABOUT_TEXT =
  R"(Disassembly Explorer Copyright (C) 2020 
Samuel Martel - Pascal-Emmanuel Lachance

Ce programme viens avec AUCUNE GUARANTIE.
Ce programme est gratuit et libre, et vous êtes bienvenue à le
redistribuer sous les termes de la license GPLv3.)";

/************************************************************************/
/* SECTION: ObjdumpConfigUI                                             */
/************************************************************************/

// File Type Handler.
constexpr char* TEXT_HINT_FILE_TYPE_HANDLER        = "Le type du fichier à désassembler";
constexpr char* TEXT_FILE_TYPE_HANDLER_TYPE_ALL    = "Automatique";
constexpr char* TEXT_FILE_TYPE_HANDLER_TYPE_ELF    = "Elf";
constexpr char* TEXT_FILE_TYPE_HANDLER_INPUT_LABEL = "Type de fichier";

// Project Settings
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_SHOULD_SAVE_HINT =
  "Cochez cette case pour sauvegarder le projet dans un fichier";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_PRJ_PATH_HINT =
  "Le fichier dans lequel le projet doit être sauvegarder. Cette option n'est pas disponible si "
  "l'option Sauvergarder n'est pas activé";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_ARCH_HINT =
  "Force Objdump à désassembler le fichier pour une architecture spécifique";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_FILE_PATH_HINT        = "Le fichier à désassembler";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_SHOULD_SAVE_LABEL     = "Sauvegarder le projet";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_PRJ_PATH_LABEL        = "Ficher du projet: %s";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_ARCH_LABEL            = "Architecture";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_FILE_PATH_LABEL       = "Ficher à désassembler: %s";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_OPEN_PRJ_BUTTON_LABEL = "Ouvrir##prjPath";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_OPEN_BIN_BUTTON_LABEL = "Ouvrir##binPath";

// Show Archive Headers
constexpr char* TEXT_SHOW_ARCHIVE_HEADERS_HINT =
  R"(Si le fichier actif est une archive, affiche les informations d'entêtes d'archive (dans un format similaire à `ls -l`).
En addition au informations données par `ar tv`, cette option donne aussi le format de fichier de chaque objets de l'archive.)";
constexpr char* TEXT_SHOW_ARCHIVE_HEADERS_LABEL = "Afficher les entêtes d'archive";
constexpr char* TEXT_SHOW_ARCHIVE_HEADERS_FLAG  = "-a";

// Adjust VMA Offset
constexpr char* TEXT_ADJUST_VMA_OFFSET_HINT =
  R"(Lors du vidage d'informations, ajoute d'abord un décalage à toutes les adresses de section. 
Ceci est utile si les adresses de section ne correspondent pas à la table des symboles, 
ce qui peut se produire lorsque des sections sont plassées à des adresses particulières lors de 
l'utilisation d'un format qui ne peut pas représenter les adresses de section, comme le format .out.)";
constexpr char* TEXT_ADJUST_VMA_OFFSET_FLAG  = "--adjust-vma=";
constexpr char* TEXT_ADJUST_VMA_OFFSET_LABEL = "Décalage des sections";

// Demangle
constexpr char* TEXT_DEMANGLE_LABEL = "Démêler les noms de symbols";
constexpr char* TEXT_DEMANGLE_HINT =
  R"(Décode les noms de symbôle bas-niveau en des noms du niveau de l'utilisateur.
En plus d'enlever tout caractères de soulignement ajouté par le système,
cette option rends les noms de fonctions C++ lisible.)";
constexpr char* TEXT_DEMANGLE_FLAG = "-C";

// Show Debug Information
constexpr char* TEXT_SHOW_DEBUG_INFO_LABEL = "Afficher les informations de debuggage";
constexpr char* TEXT_SHOW_DEBUG_INFO_HINT =
  R"(Affiche les informations de débuggage.
Cette option essaie d'extraire des informations sous le format STABS et/ou IEEE
stocké dans le fichier et les affiches en utilisant une syntaxe semblable au C.
Si aucun des formats ne sont trouvé dans le fichier, cette option se fit sur la
configuration de l'option DWARF pour afficher toute information DWARF dans le fichier.)";
constexpr char* TEXT_SHOW_DEBUG_INFO_FLAG = "-g";
constexpr char* TEXT_SHOW_DEBUG_INFO_CTAG_LABEL =
  "Afficher les informations de debuggage pour CTAG";
constexpr char* TEXT_SHOW_DEBUG_INFO_CTAG_HINT =
  R"(Comme "Afficher les informations de debuggage,
mais l'information est généré dans un format compatible avec les outils CTAG)";
constexpr char* TEXT_SHOW_DEBUG_INFO_CTAG_FLAG = "-e";

// Disassemble
constexpr char* TEXT_DISASSEMBLE_LABEL = "Désassembler";
constexpr char* TEXT_DISASSEMBLE_HINT =
  R"(
Affiche les mnémoniques des instructions machine à partir du fichier binaire.
Cette option ne désassemble que les sections censées contenir des instructions.)";
constexpr char* TEXT_DISASSEMBLE_FLAG      = "-d";
constexpr char* TEXT_DISASSEMBLE_ALL_LABEL = "Tout désassembler";
constexpr char* TEXT_DISASSEMBLE_ALL_HINT =
  R"(
Comme "Désassembler", mais désassemble le contenu de toutes les sections,
pas seulement ceux censés contenir des instructions.

Si la cible est une architecture ARM, cette option a également pour effet de
forcer le désassembleur à décoder les données trouvés dans les sections de code
comme s'il s'agissait d'instructions.)";
constexpr char* TEXT_DISASSEMBLE_ALL_FLAG = "-D";

// Prefix Addresses
constexpr char* TEXT_PREFIX_ADDRESSES_LABEL = "Afficher l'addresse des instructions.";
constexpr char* TEXT_PREFIX_ADDRESSES_HINT =
  R"(Lors du désassemblage, affiche l'adresse complète sur chaque ligne.
Il s'agit de l'ancien format de désassemblage.)";
constexpr char* TEXT_PREFIX_ADDRESSES_FLAG = "--prefix-addresses";

// Endianness
constexpr char* TEXT_ENDIANNESS_LABEL = "Boutisme";
constexpr char* TEXT_ENDIANNESS_HINT =
  R"(Spécifie le boutisme du fichier.
Cela n'affecte que le désassemblage. Cela peut être utile lors du désassemblage d'un format de fichier
qui ne décrit pas les informations de boutisme, telles que les enregistrements S.)";
constexpr char* TEXT_ENDIANNESS_FLAG_BIG     = "-EB";
constexpr char* TEXT_ENDIANNESS_FLAG_SMALL   = "-EL";
constexpr char* TEXT_ENDIANNESS_LABELS_AUTO  = "Automatique";
constexpr char* TEXT_ENDIANNESS_LABELS_BIG   = "Grand";
constexpr char* TEXT_ENDIANNESS_LABELS_SMALL = "Petit";

// Show File Offset
constexpr char* TEXT_SHOW_FILE_OFFSET_LABEL = "Afficher le décalage dans le fichier";
constexpr char* TEXT_SHOW_FILE_OFFSET_HINT =
  R"(Lors du désassemblage de sections, chaque fois qu'un symbole est affiché,
affiche également le décalage de fichier de la région de données sur le point d'être sauvegardée.
Si des zéros sont ignorés, lorsque le désassemblage reprend, indique à l'utilisateur combien de zéros
ont été ignorés et le décalage de fichier de l'emplacement à partir duquel le désassemblage reprend.
Lors du vidage de sections, affiche le décalage de fichier de l'emplacement à partir duquel le vidage commence.)";
constexpr char* TEXT_SHOW_FILE_OFFSET_FLAG = "-F";

// Show File Start Context
// #TODO translate this
constexpr char* TEXT_SHOW_FILE_START_CONTEXT_LABEL = "Show File Start Context";
constexpr char* TEXT_SHOW_FILE_START_CONTEXT_HINT =
  R"(Specify that when displaying inter listed source code/disassembly (assumes "Show Source" is enabled)
from a file that has not yet been displayed, extend the context to the start of the file.)";
constexpr char* TEXT_SHOW_FILE_START_CONTEXT_FLAG = "--file-start-context";

// Show Info From Header
// #TODO translate this
constexpr char* TEXT_SHOW_INFO_FROM_HEADER_LABEL = "Show Information From Header";
constexpr char* TEXT_SHOW_INFO_FROM_HEADER_HINT =
  R"(Display summary information from the overall header of the file)";
constexpr char* TEXT_SHOW_INFO_FROM_HEADER_FLAG = "-f";

// Show Info From Section
// #TODO translate this
constexpr char* TEXT_SHOW_INFO_FROM_SECTION_LABEL = "Show Information From Section";
constexpr char* TEXT_SHOW_INFO_FROM_SECTION_HINT =
  R"(Display summary information from the section headers of the object file.

File segment may be relocated to nonstandard addresses, for example by using the -Ttext, -Tdata,
or -Tbss options to ld. However, some object file formats, such as a .out,
do not store the starting address of the file segments. In those situations, 
although ld relocates the sections correctly, using this option to list the file
section headers cannot show the correct addresses. Insted, it shouws the usual
addresses, which are implicit for the target.)";
constexpr char* TEXT_SHOW_INFO_FROM_SECTION_FLAG = "-h";

/************************************************************************/
/* SECTION: Architecture Type                                           */
/************************************************************************/
constexpr char* TEXT_ARCHITECTURE_AUTO     = "Automatic";
constexpr char* TEXT_ARCHITECTURE_ARM      = "ARM";
constexpr char* TEXT_ARCHITECTURE_AVR      = "AVR";
constexpr char* TEXT_ARCHITECTURE_POWER_PC = "PowerPC";
constexpr char* TEXT_ARCHITECTURE_RISCV    = "RISC V";
constexpr char* TEXT_ARCHITECTURE_X86      = "x86";
constexpr char* TEXT_ARCHITECTURE_X86_64   = "x86-64";

/* Have a wonderful day :) */
/**
 * @}
 */
/****** END OF FILE ******/
