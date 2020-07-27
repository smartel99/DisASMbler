/******************************************************************************
 * @file English
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
constexpr char* TEXT_NEW_PROJECT_LAYER_WINDOW_NAME = "New Project";

/************************************************************************/
/* SECTION: ApplicationLayer                                            */
/************************************************************************/
constexpr char* TEXT_APPLICATION_LAYER_FILE  = "File";
constexpr char* TEXT_APPLICATION_LAYER_NEW   = "New";
constexpr char* TEXT_APPLICATION_LAYER_EXIT  = "Exit";
constexpr char* TEXT_APPLICATION_LAYER_HELP  = "Help";
constexpr char* TEXT_APPLICATION_LAYER_ABOUT = "About";
constexpr char* TEXT_APPLICATION_LAYER_ABOUT_TEXT =
  R"(Disassembly Explorer Copyright (C) 2020 
Samuel Martel - Pascal-Emmanuel Lachance

This program comes with ABSOLUTELY NO WARRANTY.
This is free software, and you are welcome to redistribute it
under the GPLv3)";

/************************************************************************/
/* SECTION: ObjdumpConfigUI                                             */
/************************************************************************/

// File Type
constexpr char* TEXT_HINT_FILE_TYPE_HANDLER        = "The type of file that is to be disassembled";
constexpr char* TEXT_FILE_TYPE_HANDLER_TYPE_ALL    = "Automatic";
constexpr char* TEXT_FILE_TYPE_HANDLER_TYPE_ELF    = "Elf";
constexpr char* TEXT_FILE_TYPE_HANDLER_INPUT_LABEL = "File Type";

// Project Settings
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_SHOULD_SAVE_HINT =
  "Check this box to save the project into a file";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_PRJ_PATH_HINT =
  "The path where the project should be saved. This option is disabled if the Should Save option "
  "is not enabled";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_ARCH_HINT =
  "Forces Objdump to disassemble for a specific architecture";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_FILE_PATH_HINT =
  "The path to the file to disassemble";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_SHOULD_SAVE_LABEL     = "Save Project";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_PRJ_PATH_LABEL        = "Project Path: %s";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_ARCH_LABEL            = "Architecture";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_FILE_PATH_LABEL       = "Binary File Path: %s";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_OPEN_PRJ_BUTTON_LABEL = "Open##prjPath";
constexpr char* TEXT_PROJECT_SETTINGS_HANDLER_OPEN_BIN_BUTTON_LABEL = "Open##binPath";

// Show Archive Headers
constexpr char* TEXT_SHOW_ARCHIVE_HEADERS_HINT =
  R"(If the file being worked on is an archive, display the archive header information (in a format similar to `ls -l`).
Besides the information you could list with `ar tv`, this option shows the object file format of each archive member.)";
constexpr char* TEXT_SHOW_ARCHIVE_HEADERS_LABEL = "Show Archive Headers";
constexpr char* TEXT_SHOW_ARCHIVE_HEADERS_FLAG  = "-a";

// Adjust VMA Offset
constexpr char* TEXT_ADJUST_VMA_OFFSET_HINT =
  R"(When dumping information, first add an offset to all the section addresses.
This is useful if the section addresses do not correspond to the symbol table, 
which can happen when putting sections at particular addresses when using a format which can not represent section addresses, 
such as the .out file format.)";
constexpr char* TEXT_ADJUST_VMA_OFFSET_FLAG  = "--adjust-vma=";
constexpr char* TEXT_ADJUST_VMA_OFFSET_LABEL = "Section Offset";

// Demangle
constexpr char* TEXT_DEMANGLE_LABEL = "Demangle symbol names";
constexpr char* TEXT_DEMANGLE_HINT =
  R"(Decode (demangle) low-level symbol names into user-level names.
Besides removing any intial underscore prepended by the system,
this makes C++ function names readable.)";
constexpr char* TEXT_DEMANGLE_FLAG = "-C";

// Show Debug Info
constexpr char* TEXT_SHOW_DEBUG_INFO_LABEL = "Show debugging information";
constexpr char* TEXT_SHOW_DEBUG_INFO_HINT =
  R"(Display debugging information.
This attempts to parse STABS and IEEE debugging format information
stored in the file and print it out using a C like syntax.
If neither of these formats are found this option falls back on the DWARF setting
to print any DWARF information in the file.)";
constexpr char* TEXT_SHOW_DEBUG_INFO_FLAG       = "-g";
constexpr char* TEXT_SHOW_DEBUG_INFO_CTAG_LABEL = "Show ctag debugging information";
constexpr char* TEXT_SHOW_DEBUG_INFO_CTAG_HINT =
  R"(Like "Show debugging information",
but the information is generated in a format compatible with ctags tool.)";
constexpr char* TEXT_SHOW_DEBUG_INFO_CTAG_FLAG = "-e";

// Disassemble
constexpr char* TEXT_DISASSEMBLE_LABEL = "Disassemble";
constexpr char* TEXT_DISASSEMBLE_HINT =
  R"(Display the assembly mnemonics for the machine instructions from the binary file.
This option only disassembles those sections which are expected to contain instructions.)";
constexpr char* TEXT_DISASSEMBLE_FLAG      = "-d";
constexpr char* TEXT_DISASSEMBLE_ALL_LABEL = "Disassemble All";
constexpr char* TEXT_DISASSEMBLE_ALL_HINT =
  R"(Like "Disassemble, but disassemble the contents of all sections,
not just those expected to contain instructions.

If the target is an ARM architecture this switch also has the effect of
forcing the disassembler to decode pieces of data found in code sections
as if they were instructions.)";
constexpr char* TEXT_DISASSEMBLE_ALL_FLAG = "-D";

// Prefix Addresses
constexpr char* TEXT_PREFIX_ADDRESSES_LABEL = "Prefix addresses to disassembly";
constexpr char* TEXT_PREFIX_ADDRESSES_HINT =
  R"(When disassembling, print the complete address on each line.
This is the older disassembly format.)";
constexpr char* TEXT_PREFIX_ADDRESSES_FLAG = "--prefix-addresses";

// Endianness
constexpr char* TEXT_ENDIANNESS_LABEL = "Endianness";
constexpr char* TEXT_ENDIANNESS_HINT =
  R"(Specify the endianness of the object file.
This only affects disassembly. This can be useful when disassembling a file format
which does not describe endianness information, such as S-records.)";
constexpr char* TEXT_ENDIANNESS_FLAG_BIG     = "-EB";
constexpr char* TEXT_ENDIANNESS_FLAG_SMALL   = "-EL";
constexpr char* TEXT_ENDIANNESS_LABELS_AUTO  = "Automatic";
constexpr char* TEXT_ENDIANNESS_LABELS_BIG   = "Big";
constexpr char* TEXT_ENDIANNESS_LABELS_SMALL = "Little";

// Show File Offset
constexpr char* TEXT_SHOW_FILE_OFFSET_LABEL = "Show File Offset";
constexpr char* TEXT_SHOW_FILE_OFFSET_HINT =
  R"(When disassembling sections, whenever a symbol is displayed,
also display the file offset of the region of data that is about to be dumped.
If zeroes are being skipped, then when disassembly resumes, tell the use how many zeroes
were skipped and the file offset of the location from where the disassembly resumes.
When dumping sections, display the file offset of the location from where the dump starts.)";
constexpr char* TEXT_SHOW_FILE_OFFSET_FLAG = "-F";

// Show File Start Context
constexpr char* TEXT_SHOW_FILE_START_CONTEXT_LABEL = "Show File Start Context";
constexpr char* TEXT_SHOW_FILE_START_CONTEXT_HINT =
  R"(Specify that when displaying inter listed source code/disassembly (assumes "Show Source" is enabled)
from a file that has not yet been displayed, extend the context to the start of the file.)";
constexpr char* TEXT_SHOW_FILE_START_CONTEXT_FLAG = "--file-start-context";

// Show Info From Header
constexpr char* TEXT_SHOW_INFO_FROM_HEADER_LABEL = "Show Information From Header";
constexpr char* TEXT_SHOW_INFO_FROM_HEADER_HINT =
  R"(Display summary information from the overall header of the file)";
constexpr char* TEXT_SHOW_INFO_FROM_HEADER_FLAG = "-f";

// Show Info From Section
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
