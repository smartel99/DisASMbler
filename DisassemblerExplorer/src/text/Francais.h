﻿/******************************************************************************
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
constexpr const char* TEXT_NEW_PROJECT_LAYER_WINDOW_NAME = "Nouveau Projet";

/************************************************************************/
/* SECTION: ApplicationLayer                                            */
/************************************************************************/
constexpr const char* TEXT_APPLICATION_LAYER_FILE  = "Fichier";
constexpr const char* TEXT_APPLICATION_LAYER_NEW   = "Nouveau";
constexpr const char* TEXT_APPLICATION_LAYER_EXIT  = "Quitter";
constexpr const char* TEXT_APPLICATION_LAYER_HELP  = "Aide";
constexpr const char* TEXT_APPLICATION_LAYER_ABOUT = "À propos";
constexpr const char* TEXT_APPLICATION_LAYER_ABOUT_TEXT =
  R"(Disassembly Explorer Copyright (C) 2020 
Samuel Martel - Pascal-Emmanuel Lachance

Ce programme viens avec AUCUNE GUARANTIE.
Ce programme est gratuit et libre, et vous êtes bienvenue à le
redistribuer sous les termes de la license GPLv3.)";

/************************************************************************/
/* SECTION: ObjdumpConfigUI                                             */
/************************************************************************/

// File Type Handler.
constexpr const char* TEXT_HINT_FILE_TYPE_HANDLER        = "Le type du fichier à désassembler";
constexpr const char* TEXT_FILE_TYPE_HANDLER_TYPE_ALL    = "Automatique";
constexpr const char* TEXT_FILE_TYPE_HANDLER_TYPE_ELF    = "Elf";
constexpr const char* TEXT_FILE_TYPE_HANDLER_INPUT_LABEL = "Type de fichier";

// Project Settings
constexpr const char* TEXT_PROJECT_SETTINGS_HANDLER_SHOULD_SAVE_HINT =
  "Cochez cette case pour sauvegarder le projet dans un fichier";
constexpr const char* TEXT_PROJECT_SETTINGS_HANDLER_PRJ_PATH_HINT =
  "Le fichier dans lequel le projet doit être sauvegarder. Cette option n'est pas disponible si "
  "l'option Sauvergarder n'est pas activé";
constexpr const char* TEXT_PROJECT_SETTINGS_HANDLER_ARCH_HINT =
  "Force Objdump à désassembler le fichier pour une architecture spécifique";
constexpr const char* TEXT_PROJECT_SETTINGS_HANDLER_FILE_PATH_HINT = "Le fichier à désassembler";
constexpr const char* TEXT_PROJECT_SETTINGS_HANDLER_SHOULD_SAVE_LABEL = "Sauvegarder le projet";
constexpr const char* TEXT_PROJECT_SETTINGS_HANDLER_PRJ_PATH_LABEL    = "Ficher du projet: %s";
constexpr const char* TEXT_PROJECT_SETTINGS_HANDLER_ARCH_LABEL        = "Architecture";
constexpr const char* TEXT_PROJECT_SETTINGS_HANDLER_FILE_PATH_LABEL = "Ficher à désassembler: %s";
constexpr const char* TEXT_PROJECT_SETTINGS_HANDLER_OPEN_PRJ_BUTTON_LABEL = "Ouvrir##prjPath";
constexpr const char* TEXT_PROJECT_SETTINGS_HANDLER_OPEN_BIN_BUTTON_LABEL = "Ouvrir##binPath";

// Show Archive Headers
constexpr const char* TEXT_SHOW_ARCHIVE_HEADERS_HINT =
  R"(Si le fichier actif est une archive, affiche les informations d'entêtes d'archive (dans un format similaire à `ls -l`).
En addition au informations données par `ar tv`, cette option donne aussi le format de fichier de chaque objets de l'archive.)";
constexpr const char* TEXT_SHOW_ARCHIVE_HEADERS_LABEL = "Afficher les entêtes d'archive";
constexpr const char* TEXT_SHOW_ARCHIVE_HEADERS_FLAG  = "-a";

// Adjust VMA Offset
constexpr const char* TEXT_ADJUST_VMA_OFFSET_HINT =
  R"(Lors du vidage d'informations, ajoute d'abord un décalage à toutes les adresses de section. 
Ceci est utile si les adresses de section ne correspondent pas à la table des symboles, 
ce qui peut se produire lorsque des sections sont plassées à des adresses particulières lors de 
l'utilisation d'un format qui ne peut pas représenter les adresses de section, comme le format .out.)";
constexpr const char* TEXT_ADJUST_VMA_OFFSET_FLAG  = "--adjust-vma=";
constexpr const char* TEXT_ADJUST_VMA_OFFSET_LABEL = "Décalage des sections";

// Demangle
constexpr const char* TEXT_DEMANGLE_LABEL = "Démêler les noms de symbols";
constexpr const char* TEXT_DEMANGLE_HINT =
  R"(Décode les noms de symbôle bas-niveau en des noms du niveau de l'utilisateur.
En plus d'enlever tout caractères de soulignement ajouté par le système,
cette option rends les noms de fonctions C++ lisible.)";
constexpr const char* TEXT_DEMANGLE_FLAG = "-C";

// Show Debug Information
constexpr const char* TEXT_SHOW_DEBUG_INFO_LABEL = "Afficher les informations de debuggage";
constexpr const char* TEXT_SHOW_DEBUG_INFO_HINT =
  R"(Affiche les informations de débuggage.
Cette option essaie d'extraire des informations sous le format STABS et/ou IEEE
stocké dans le fichier et les affiches en utilisant une syntaxe semblable au C.
Si aucun des formats ne sont trouvé dans le fichier, cette option se fit sur la
configuration de l'option DWARF pour afficher toute information DWARF dans le fichier.)";
constexpr const char* TEXT_SHOW_DEBUG_INFO_FLAG = "-g";
constexpr const char* TEXT_SHOW_DEBUG_INFO_CTAG_LABEL =
  "Afficher les informations de debuggage pour CTAG";
constexpr const char* TEXT_SHOW_DEBUG_INFO_CTAG_HINT =
  R"(Comme "Afficher les informations de debuggage,
mais l'information est généré dans un format compatible avec les outils CTAG)";
constexpr const char* TEXT_SHOW_DEBUG_INFO_CTAG_FLAG = "-e";

// Disassemble
constexpr const char* TEXT_DISASSEMBLE_LABEL = "Désassembler";
constexpr const char* TEXT_DISASSEMBLE_HINT =
  R"(
Affiche les mnémoniques des instructions machine à partir du fichier binaire.
Cette option ne désassemble que les sections censées contenir des instructions.)";
constexpr const char* TEXT_DISASSEMBLE_FLAG      = "-d";
constexpr const char* TEXT_DISASSEMBLE_ALL_LABEL = "Tout désassembler";
constexpr const char* TEXT_DISASSEMBLE_ALL_HINT =
  R"(
Comme "Désassembler", mais désassemble le contenu de toutes les sections,
pas seulement ceux censés contenir des instructions.

Si la cible est une architecture ARM, cette option a également pour effet de
forcer le désassembleur à décoder les données trouvés dans les sections de code
comme s'il s'agissait d'instructions.)";
constexpr const char* TEXT_DISASSEMBLE_ALL_FLAG = "-D";

// Prefix Addresses
constexpr const char* TEXT_PREFIX_ADDRESSES_LABEL = "Afficher l'addresse des instructions.";
constexpr const char* TEXT_PREFIX_ADDRESSES_HINT =
  R"(Lors du désassemblage, affiche l'adresse complète sur chaque ligne.
Il s'agit de l'ancien format de désassemblage.)";
constexpr const char* TEXT_PREFIX_ADDRESSES_FLAG = "--prefix-addresses";

// Endianness
constexpr const char* TEXT_ENDIANNESS_LABEL = "Boutisme";
constexpr const char* TEXT_ENDIANNESS_HINT =
  R"(Spécifie le boutisme du fichier.
Cela n'affecte que le désassemblage. Cela peut être utile lors du désassemblage d'un format de fichier
qui ne décrit pas les informations de boutisme, telles que les enregistrements S.)";
constexpr const char* TEXT_ENDIANNESS_FLAG_BIG     = "-EB";
constexpr const char* TEXT_ENDIANNESS_FLAG_SMALL   = "-EL";
constexpr const char* TEXT_ENDIANNESS_LABELS_AUTO  = "Automatique";
constexpr const char* TEXT_ENDIANNESS_LABELS_BIG   = "Grand";
constexpr const char* TEXT_ENDIANNESS_LABELS_SMALL = "Petit";

// Show File Offset
constexpr const char* TEXT_SHOW_FILE_OFFSET_LABEL = "Afficher le décalage dans le fichier";
constexpr const char* TEXT_SHOW_FILE_OFFSET_HINT =
  R"(Lors du désassemblage de sections, chaque fois qu'un symbole est affiché,
affiche également le décalage de fichier de la région de données sur le point d'être sauvegardée.
Si des zéros sont ignorés, lorsque le désassemblage reprend, indique à l'utilisateur combien de zéros
ont été ignorés et le décalage de fichier de l'emplacement à partir duquel le désassemblage reprend.
Lors du vidage de sections, affiche le décalage de fichier de l'emplacement à partir duquel le vidage commence.)";
constexpr const char* TEXT_SHOW_FILE_OFFSET_FLAG = "-F";

// Show File Start Context
// #TODO translate this
constexpr const char* TEXT_SHOW_FILE_START_CONTEXT_LABEL = "Show File Start Context";
constexpr const char* TEXT_SHOW_FILE_START_CONTEXT_HINT =
  R"(Specify that when displaying inter listed source code/disassembly (assumes "Show Source" is enabled)
from a file that has not yet been displayed, extend the context to the start of the file.)";
constexpr const char* TEXT_SHOW_FILE_START_CONTEXT_FLAG = "--file-start-context";

// Show Info From Header
// #TODO translate this
constexpr const char* TEXT_SHOW_INFO_FROM_HEADER_LABEL = "Show Information From Header";
constexpr const char* TEXT_SHOW_INFO_FROM_HEADER_HINT =
  R"(Display summary information from the overall header of the file)";
constexpr const char* TEXT_SHOW_INFO_FROM_HEADER_FLAG = "-f";

// Show Info From Section
// #TODO translate this
constexpr const char* TEXT_SHOW_INFO_FROM_SECTION_LABEL = "Show Information From Section";
constexpr const char* TEXT_SHOW_INFO_FROM_SECTION_HINT =
  R"(Display summary information from the section headers of the object file.

File segment may be relocated to nonstandard addresses, for example by using the -Ttext, -Tdata,
or -Tbss options to ld. However, some object file formats, such as a .out,
do not store the starting address of the file segments. In those situations, 
although ld relocates the sections correctly, using this option to list the file
section headers cannot show the correct addresses. Insted, it shouws the usual
addresses, which are implicit for the target.)";
constexpr const char* TEXT_SHOW_INFO_FROM_SECTION_FLAG = "-h";

// Disassemble Options
// #TODO translate this
constexpr const char* TEXT_DISASSEMBLER_OPTION_LABEL = "Architecture";
constexpr const char* TEXT_DISASSEMBLER_OPTION_HINT =
  R"(The architecture of the file to disassemble)";

// Arm Disassembler Options
// #TODO translate this
constexpr const char* TEXT_ARM_DISASSEBLER_OPTION_REG_NAME_LABEL    = "Register Name Set";
constexpr const char* TEXT_ARM_DISASSEBLER_OPTION_FORCE_THUMB_LABEL = "Force Thumb";
constexpr const char* TEXT_ARM_DISASSEBLER_OPTION_CPU_ISA_LABEL =
  "CPU Instruction Set Architecture";
constexpr const char* TEXT_ARM_DISASSEMBLER_OPTION_REG_NAME_HINT =
  R"(Select which register name set is used during disassembly.
Choosing "Standard" will select the register names as used in ARM's instruction set documentation,
but with register 13 called "sp", register 14 called "lr" and register 15 called "pc".
Choosing "APCS" will select the name set used by the ARM Procedure Call Standard, 
whilst choosing "raw" will just use "r" followed by the ergister number.

There are also two variants on the APCS register naming scheme: Normal and Special, both 
of them using the ARM/Thumb Procedure Call Standard naming conventions, either with the 
normal register names or the special register names.)";
constexpr const char* TEXT_ARM_DISASSEMBLER_OPTION_FORCE_THUMB_HINT =
  R"(Select this option to force the disassembler to interpret all instructions as Thumb instructions. 
This can be useful when attempting to disassemble Thumb code produced by other compilers.)";
constexpr const char* TEXT_ARM_DISASSEMBLER_OPTION_CPU_ISA_HINT =
  R"(Explicitly tell Objdump the CPU Instruction Set Architecture)";
constexpr const char* TEXT_ARM_DISASSEMBLER_OPTION_FORCE_THUMB_FLAG = "-M force-thumb";
constexpr const char* TEXT_ARM_DISASSEMBLER_OPTION_CPU_ISA_FLAG     = "-m ";

// Arch64 Disassembler Options
// #TODO Translate this
constexpr const char* TEXT_AARCH64_DIS_OPTION_DIS_INTO_GENERIC_INST_LABEL =
  "Disassemble Into Generic Instructions";
constexpr const char* TEXT_AARCH64_DIS_OPTION_DIS_INTO_GENERIC_INST_HINT =
  R"(Enable this so that instructions are disassembled as the most general instruction.)";
constexpr const char* TEXT_AARCH64_DIS_OPTION_DIS_INTO_GENERIC_INST_FLAG = "-M no-aliases";

// ARC Disassembler Options
// #TODO Translate this
constexpr const char* TEXT_ARC_DIS_OPTION_DSP_LABEL  = "Show DSP Instructions";
constexpr const char* TEXT_ARC_DIS_OPTION_SPFP_LABEL = "Show FPX Single Precision FP Instructions";
constexpr const char* TEXT_ARC_DIS_OPTION_DPFP_LABEL = "Show FPX Double Precision FP Instructions";
constexpr const char* TEXT_ARC_DIS_OPTION_QUARKSE_EM_LABEL = "Show Special QuarkSE-EN Instructions";
constexpr const char* TEXT_ARC_DIS_OPTION_FPUDA_LABEL = "Show Double Precision Assist Instructions";
constexpr const char* TEXT_ARC_DIS_OPTION_FPUS_LABEL  = "Show Single Precision FP Instructions";
constexpr const char* TEXT_ARC_DIS_OPTION_FPUD_LABEL  = "Show Double Precision FP Instructions";
constexpr const char* TEXT_ARC_DIS_OPTION_DISPLAY_AS_HEX_LABEL = "Print Immediates in Hexadecimal";

constexpr const char* TEXT_ARC_DIS_OPTION_DSP_HINT = R"(Show DSP Instructions)";
constexpr const char* TEXT_ARC_DIS_OPTION_SPFP_HINT =
  R"(Show FPX Single Precision FP Instructions)";
constexpr const char* TEXT_ARC_DIS_OPTION_DPFP_HINT =
  R"(Show FPX Double Precision FP Instructions)";
constexpr const char* TEXT_ARC_DIS_OPTION_QUARKSE_EM_HINT =
  R"(Show Special QuarkSE-EN Instructions)";
constexpr const char* TEXT_ARC_DIS_OPTION_FPUDA_HINT =
  R"(Show Double Precision Assist Instructions)";
constexpr const char* TEXT_ARC_DIS_OPTION_FPUS_HINT = R"(Show Single Precision FP Instructions)";
constexpr const char* TEXT_ARC_DIS_OPTION_FPUD_HINT = R"(Show Double Precision FP Instructions)";
constexpr const char* TEXT_ARC_DIS_OPTION_DISPLAY_AS_HEX_HINT =
  R"(Print Immediates in Hexadecimal)";

constexpr const char* TEXT_ARC_DIS_OPTION_DSP_FLAG            = "-M dsp";
constexpr const char* TEXT_ARC_DIS_OPTION_SPFP_FLAG           = "-M spfp";
constexpr const char* TEXT_ARC_DIS_OPTION_DPFP_FLAG           = "-M dpfp";
constexpr const char* TEXT_ARC_DIS_OPTION_QUARKSE_EM_FLAG     = "-M quarkse_em";
constexpr const char* TEXT_ARC_DIS_OPTION_FPUDA_FLAG          = "-M fpuda";
constexpr const char* TEXT_ARC_DIS_OPTION_FPUS_FLAG           = "-M fpus";
constexpr const char* TEXT_ARC_DIS_OPTION_FPUD_FLAG           = "-M fpud";
constexpr const char* TEXT_ARC_DIS_OPTION_DISPLAY_AS_HEX_FLAG = "-M hex";

// x86/x86-64 Disassembler Options
// #TODO Translate this
constexpr const char* TEXT_X86_OPTIONS_ARCHITECTURE_LABEL   = "Architecture";
constexpr const char* TEXT_X86_OPTIONS_SYNTAX_LABEL         = "Syntax";
constexpr const char* TEXT_X86_OPTIONS_ISA_LABEL            = "Instruction Set Architecture";
constexpr const char* TEXT_X86_OPTIONS_ADDR_SIZE_LABEL      = "Address Size";
constexpr const char* TEXT_X86_OPTIONS_DATA_SIZE_LABEL      = "Data Size";
constexpr const char* TEXT_X86_OPTIONS_DISPLAY_SUFFIX_LABEL = "Display Suffix";

constexpr const char* TEXT_X86_OPTIONS_ARCHITECTURE_HINT =
  "Select disassembly for the given architecture.";
constexpr const char* TEXT_X86_OPTIONS_SYNTAX_HINT =
  "Select between intel syntax mode and AT&T syntax mode.";
constexpr const char* TEXT_X86_OPTIONS_ISA_HINT       = "Select between AMD64 ISA and Intel64 ISA.";
constexpr const char* TEXT_X86_OPTIONS_ADDR_SIZE_HINT = R"(Specify the default address size.
This option will be overridden if an architecture is specified.)";
constexpr const char* TEXT_X86_OPTIONS_DATA_SIZE_HINT = R"(Specify the default operand size.
This option will be overridden if an architecture is specified.)";
constexpr const char* TEXT_X86_OPTIONS_DISPLAY_SUFFIX_HINT =
  R"(When in AT&T mode, instructs the disassembler to print a mnemonic suffix
even when the suffix could be inferred by the operands.)";

constexpr const char* TEXT_X86_OPTIONS_DISPLAY_SUFFIX_FLAG = "-M suffix";

// Power PC Disassembler Options
// #TODO Translate this
constexpr const char* TEXT_PPC_OPTIONS_USE_RAW_LABEL        = "Use Hardware Instructions";
constexpr const char* TEXT_PPC_OPTIONS_CPU_ISA_LABEL        = "CPU Instruction Set Assembly";
constexpr const char* TEXT_PPC_OPTIONS_ENABLE_64_BITS_LABEL = "Enable 64 bits";
constexpr const char* TEXT_PPC_OPTIONS_USE_ALTIVEC_LABEL    = "Use Altivec";
constexpr const char* TEXT_PPC_OPTIONS_USE_ANY_LABEL        = "Disassemble All Known Opcodes";
constexpr const char* TEXT_PPC_OPTIONS_USE_HTM_LABEL        = "Use HTM";
constexpr const char* TEXT_PPC_OPTIONS_USE_VSX_LABEL        = "Use VSX";
constexpr const char* TEXT_PPC_OPTIONS_USE_SPE_LABEL        = "Use SPE";

constexpr const char* TEXT_PPC_OPTIONS_USE_RAW_HINT =
  R"(Use hardware instructions rather than aliases.
For example, you will see "rlwinm" rather than "clrlwi" and "addi" rather than "li")";
constexpr const char* TEXT_PPC_OPTIONS_CPU_ISA_HINT =
  "Specify to the disassembler which CPU ISA to use";
constexpr const char* TEXT_PPC_OPTIONS_ENABLE_64_BITS_HINT =
  "Disable (or enable) 64-bits instructions to be disassembled";
constexpr const char* TEXT_PPC_OPTIONS_USE_ALTIVEC_HINT = "Adds Altivec capabilities";
constexpr const char* TEXT_PPC_OPTIONS_USE_ANY_HINT = R"(Disassemble any opcodes known to binutils.
In cases where an opcode has two different meanings or figgerent arguments, you may not see the disassembly you expect")";
constexpr const char* TEXT_PPC_OPTIONS_USE_HTM_HINT = "Adds HTM capabilities to objdump";
constexpr const char* TEXT_PPC_OPTIONS_USE_VSX_HINT = "Adds VSX capabilities to objdump";
constexpr const char* TEXT_PPC_OPTIONS_USE_SPE_HINT = "Adds SPE capabilities to objdump";

constexpr const char* TEXT_PPC_OPTIONS_USE_RAW_FLAG         = "-M raw";
constexpr const char* TEXT_PPC_OPTIONS_ENABLE_64_BITS_FLAG  = "-M 64";
constexpr const char* TEXT_PPC_OPTIONS_DISABLE_64_BITS_FLAG = "-M 32";
constexpr const char* TEXT_PPC_OPTIONS_USE_ALTIVEC_FLAG     = "-M altivec";
constexpr const char* TEXT_PPC_OPTIONS_USE_ANY_FLAG         = "-M any";
constexpr const char* TEXT_PPC_OPTIONS_USE_HTM_FLAG         = "-M htm";
constexpr const char* TEXT_PPC_OPTIONS_USE_VSX_FLAG         = "-M vsx";
constexpr const char* TEXT_PPC_OPTIONS_USE_SPE_FLAG         = "-M spe";

// MIPS Disassembler Options
// #TODO Translate this
constexpr const char* TEXT_MIPS_OPTIONS_USE_RAW_MNEMONIC_LABEL = "Use Raw Mnemonics";
constexpr const char* TEXT_MIPS_OPTIONS_DISASSEMBLE_MSA_LABEL  = "Disassemble MSA Instructions";
constexpr const char* TEXT_MIPS_OPTIONS_DISASSEMBLE_VIRT_LABEL =
  "Disassemble Virtualization Instructions";
constexpr const char* TEXT_MIPS_OPTIONS_DISASSEMBLE_XPA_LABEL = "Disassemble XPA Instructions";
constexpr const char* TEXT_MIPS_OPTIONS_GPR_NAMES_ABI_LABEL   = "GPR Names ABI";
constexpr const char* TEXT_MIPS_OPTIONS_FPR_NAMES_ABI_LABEL   = "FPR Names ABI";
constexpr const char* TEXT_MIPS_OPTIONS_CP0_ARCH_NAME_LABEL   = "CP0 Architecture";
constexpr const char* TEXT_MIPS_OPTIONS_HWR_ARCH_NAME_LABEL   = "HWR Architecture";
constexpr const char* TEXT_MIPS_OPTIONS_REG_NAMES_ABI_LABEL   = "GPR/FPR Names ABI";
constexpr const char* TEXT_MIPS_OPTIONS_REG_ARCH_NAME_LABEL   = "CPU Architecture";

constexpr const char* TEXT_MIPS_OPTIONS_USE_RAW_MNEMONIC_HINT =
  R"(Print the "raw" instruction mnemonic instead of some pseudo instruction mnemonic.
For example: print "daddu" or "or" instead of "move", "sll" instead of "nop", etc.)";
constexpr const char* TEXT_MIPS_OPTIONS_DISASSEMBLE_MSA_HINT = R"(Disassemble MSA instructions.)";
constexpr const char* TEXT_MIPS_OPTIONS_DISASSEMBLE_VIRT_HINT =
  R"(Disassemble the virtualization ASE instructions.)";
constexpr const char* TEXT_MIPS_OPTIONS_DISASSEMBLE_XPA_HINT =
  R"(Disassemble the eXtended Physical Address (XPA) ASE instructions.)";
constexpr const char* TEXT_MIPS_OPTIONS_GPR_NAMES_ABI_HINT =
  R"(Use GPR (General-Purpose Register) names as appropriate for the specified ABI.
By default, GPR names are selected according to the ABI of the binary being disassembled.)";
constexpr const char* TEXT_MIPS_OPTIONS_FPR_NAMES_ABI_HINT =
  R"(Use FPR (Floating-Point Register) names as appropriate for the specified ABI.
By default, FPR numbers are used rather than names.)";
constexpr const char* TEXT_MIPS_OPTIONS_CP0_ARCH_NAME_HINT =
  R"(Use CP0 (System control coprocessor; coprocessor 0) register names as appropriate
for the CPU or architecture specified.
By default, CP- register names are selected according to the architecture and CPU of the binary being disassembled.)";
constexpr const char* TEXT_MIPS_OPTIONS_HWR_ARCH_NAME_HINT =
  R"(Use HWR (HardWare Register, used by the "rdhwr" instruction) names as
appropriate for the CPU or architecture specified. By default, HWR names are selected according to
the architecture and CPU of the binary being disassembled.)";
constexpr const char* TEXT_MIPS_OPTIONS_REG_NAMES_ABI_HINT =
  R"(Use GPR and FPR names as appropriate for the selected ABI.
This is the equivalent of specifying the GPR ABI and FPR separately.)";
constexpr const char* TEXT_MIPS_OPTIONS_REG_ARCH_NAME_HINT =
  R"(Use CPU-specific register names (CP0 register and HWR names)
as approprite for the selected CPU or architecture.)";

constexpr const char* TEXT_MIPS_OPTIONS_USE_RAW_MNEMONIC_FLAG = "-M no-aliases";
constexpr const char* TEXT_MIPS_OPTIONS_DISASSEMBLE_MSA_FLAG  = "-M msa";
constexpr const char* TEXT_MIPS_OPTIONS_DISASSEMBLE_VIRT_FLAG = "-M virt";
constexpr const char* TEXT_MIPS_OPTIONS_DISASSEMBLE_XPA_FLAG  = "-M xpa";
constexpr const char* TEXT_MIPS_OPTIONS_GPR_NAMES_ABI_FLAG    = "-M gpr-names=";
constexpr const char* TEXT_MIPS_OPTIONS_FPR_NAMES_ABI_FLAG    = "-M fpr-names=";
constexpr const char* TEXT_MIPS_OPTIONS_CP0_ARCH_NAME_FLAG    = "-M cp0-names=";
constexpr const char* TEXT_MIPS_OPTIONS_HWR_ARCH_NAME_FLAG    = "-M hwr-names=";
constexpr const char* TEXT_MIPS_OPTIONS_REG_NAMES_ABI_FLAG    = "-M reg-names=";
constexpr const char* TEXT_MIPS_OPTIONS_REG_ARCH_NAME_FLAG    = "-M reg-names=";

/************************************************************************/
/* SECTION: Architecture Type                                           */
/************************************************************************/
constexpr const char* TEXT_ARCHITECTURE_AUTO     = "Automatic";
constexpr const char* TEXT_ARCHITECTURE_ARM      = "ARM";
constexpr const char* TEXT_ARCHITECTURE_AVR      = "AVR";
constexpr const char* TEXT_ARCHITECTURE_POWER_PC = "PowerPC";
constexpr const char* TEXT_ARCHITECTURE_RISCV    = "RISC V";
constexpr const char* TEXT_ARCHITECTURE_X86      = "x86";
constexpr const char* TEXT_ARCHITECTURE_X86_64   = "x86-64";

/************************************************************************/
/* SECTION: Arm Register Name Set                                       */
/************************************************************************/
constexpr const char* TEXT_ARM_REG_SET_NAME_AUTO             = "Automatique";
constexpr const char* TEXT_ARM_REG_SET_NAME_STD_SET          = "Standard";
constexpr const char* TEXT_ARM_REG_SET_NAME_APCS_SET         = "APCS";
constexpr const char* TEXT_ARM_REG_SET_NAME_APCS_SPECIAL_SET = "APCS Special";
constexpr const char* TEXT_ARM_REG_SET_NAME_RAW              = "Raw";

constexpr const char* TEXT_ARM_REG_SET_NAME_AUTO_FLAG             = "";
constexpr const char* TEXT_ARM_REG_SET_NAME_STD_SET_FLAG          = "-M reg-names-std";
constexpr const char* TEXT_ARM_REG_SET_NAME_APCS_SET_FLAG         = "-M reg-names-apcs";
constexpr const char* TEXT_ARM_REG_SET_NAME_APCS_SPECIAL_SET_FLAG = "-M reg-names-special-apcs";
constexpr const char* TEXT_ARM_REG_SET_NAME_RAW_FLAG              = "-M reg-names-raw";

/************************************************************************/
/* SECTION: x86/x86-64 Architecture                                     */
/************************************************************************/
constexpr const char* TEXT_X86_ARCH_AUTO_LABEL   = "Automatic";
constexpr const char* TEXT_X86_ARCH_I386_LABEL   = "i386";
constexpr const char* TEXT_X86_ARCH_I8086_LABEL  = "i8086";
constexpr const char* TEXT_X86_ARCH_X86_64_LABEL = "x86-64";
constexpr const char* TEXT_X86_ARCH_AUTO_FLAG    = "";
constexpr const char* TEXT_X86_ARCH_I386_FLAG    = "-M i386";
constexpr const char* TEXT_X86_ARCH_I8086_FLAG   = "-M i8086";
constexpr const char* TEXT_X86_ARCH_X86_64_FLAG  = "-M x86-64";

/************************************************************************/
/* SECTION: x86/x86-64 Syntax Mode                                      */
/************************************************************************/
constexpr const char* TEXT_X86_SYNTAX_AUTOMATIC_LABEL = "Automatic";
constexpr const char* TEXT_X86_SYNTAX_INTEL_LABEL     = "Intel";
constexpr const char* TEXT_X86_SYNTAX_ATT_LABEL       = "AT&T";
constexpr const char* TEXT_X86_SYNTAX_AUTOMATIC_FLAG  = "";
constexpr const char* TEXT_X86_SYNTAX_INTEL_FLAG      = "-M intel";
constexpr const char* TEXT_X86_SYNTAX_ATT_FLAG        = "-M att";

/************************************************************************/
/* SECTION: x86/x86-64 ISA                                              */
/************************************************************************/
constexpr const char* TEXT_X86_ISA_AUTOMATIC_LABEL = "Automatic";
constexpr const char* TEXT_X86_ISA_AMD64_LABEL     = "AMD64";
constexpr const char* TEXT_X86_ISA_INTEL64_LABEL   = "Intel64";
constexpr const char* TEXT_X86_ISA_AUTOMATIC_FLAG  = "";
constexpr const char* TEXT_X86_ISA_AMD64_FLAG      = "-M amd64";
constexpr const char* TEXT_X86_ISA_INTEL64_FLAG    = "-M intel64";

/************************************************************************/
/* SECTION: x86/x86-64 Address Size                                     */
/************************************************************************/
constexpr const char* TEXT_X86_ADDR_SIZE_AUTO_LABEL = "Automatic";
constexpr const char* TEXT_X86_ADDR_SIZE_64_LABEL   = "64 bits";
constexpr const char* TEXT_X86_ADDR_SIZE_32_LABEL   = "32 bits";
constexpr const char* TEXT_X86_ADDR_SIZE_16_LABEL   = "16 bits";
constexpr const char* TEXT_X86_ADDR_SIZE_AUTO_FLAG  = "";
constexpr const char* TEXT_X86_ADDR_SIZE_64_FLAG    = "-M addr64";
constexpr const char* TEXT_X86_ADDR_SIZE_32_FLAG    = "-M addr32";
constexpr const char* TEXT_X86_ADDR_SIZE_16_FLAG    = "-M addr16";

/************************************************************************/
/* SECTION: x86/x86-64 Operand Size                                     */
/************************************************************************/
constexpr const char* TEXT_X86_DATA_SIZE_AUTO_LABEL = "Automatic";
constexpr const char* TEXT_X86_DATA_SIZE_32_LABEL   = "32 bits";
constexpr const char* TEXT_X86_DATA_SIZE_16_LABEL   = "16 bits";
constexpr const char* TEXT_X86_DATA_SIZE_AUTO_FLAG  = "";
constexpr const char* TEXT_X86_DATA_SIZE_32_FLAG    = "-M data32";
constexpr const char* TEXT_X86_DATA_SIZE_16_FLAG    = "-M data16";

/************************************************************************/
/* SECTION: Power PC CPU                                                */
/************************************************************************/
constexpr const char* TEXT_PPC_CPU_LABEL_Auto        = "Automatic";
constexpr const char* TEXT_PPC_CPU_LABEL_403         = "403";
constexpr const char* TEXT_PPC_CPU_LABEL_405         = "405";
constexpr const char* TEXT_PPC_CPU_LABEL_440         = "440";
constexpr const char* TEXT_PPC_CPU_LABEL_464         = "464";
constexpr const char* TEXT_PPC_CPU_LABEL_476         = "476";
constexpr const char* TEXT_PPC_CPU_LABEL_601         = "601";
constexpr const char* TEXT_PPC_CPU_LABEL_603         = "603";
constexpr const char* TEXT_PPC_CPU_LABEL_604         = "604";
constexpr const char* TEXT_PPC_CPU_LABEL_620         = "620";
constexpr const char* TEXT_PPC_CPU_LABEL_7400        = "7400";
constexpr const char* TEXT_PPC_CPU_LABEL_7410        = "7410";
constexpr const char* TEXT_PPC_CPU_LABEL_7450        = "7450";
constexpr const char* TEXT_PPC_CPU_LABEL_7455        = "7455";
constexpr const char* TEXT_PPC_CPU_LABEL_750cl       = "750cl";
constexpr const char* TEXT_PPC_CPU_LABEL_821         = "821";
constexpr const char* TEXT_PPC_CPU_LABEL_850         = "850";
constexpr const char* TEXT_PPC_CPU_LABEL_860         = "860";
constexpr const char* TEXT_PPC_CPU_LABEL_a2          = "a2";
constexpr const char* TEXT_PPC_CPU_LABEL_booke       = "booke";
constexpr const char* TEXT_PPC_CPU_LABEL_booke32     = "booke32";
constexpr const char* TEXT_PPC_CPU_LABEL_cell        = "cell";
constexpr const char* TEXT_PPC_CPU_LABEL_com         = "com";
constexpr const char* TEXT_PPC_CPU_LABEL_e200z4      = "e200z4";
constexpr const char* TEXT_PPC_CPU_LABEL_e300        = "e300";
constexpr const char* TEXT_PPC_CPU_LABEL_e500        = "e500";
constexpr const char* TEXT_PPC_CPU_LABEL_e500mc      = "e500mc";
constexpr const char* TEXT_PPC_CPU_LABEL_e500mc64    = "e500mc64";
constexpr const char* TEXT_PPC_CPU_LABEL_e500x2      = "e500x2";
constexpr const char* TEXT_PPC_CPU_LABEL_e5500       = "e5500";
constexpr const char* TEXT_PPC_CPU_LABEL_e6500       = "e6500";
constexpr const char* TEXT_PPC_CPU_LABEL_efs         = "efs";
constexpr const char* TEXT_PPC_CPU_LABEL_power4      = "power4";
constexpr const char* TEXT_PPC_CPU_LABEL_power5      = "power5";
constexpr const char* TEXT_PPC_CPU_LABEL_power6      = "power6";
constexpr const char* TEXT_PPC_CPU_LABEL_power7      = "power7";
constexpr const char* TEXT_PPC_CPU_LABEL_power8      = "power8";
constexpr const char* TEXT_PPC_CPU_LABEL_power9      = "power9";
constexpr const char* TEXT_PPC_CPU_LABEL_ppc         = "ppc";
constexpr const char* TEXT_PPC_CPU_LABEL_ppc32       = "ppc32";
constexpr const char* TEXT_PPC_CPU_LABEL_ppc64       = "ppc64";
constexpr const char* TEXT_PPC_CPU_LABEL_ppc64bridge = "ppc64bridge";
constexpr const char* TEXT_PPC_CPU_LABEL_ppcps       = "ppcps";
constexpr const char* TEXT_PPC_CPU_LABEL_pwr         = "pwr";
constexpr const char* TEXT_PPC_CPU_LABEL_pwr2        = "pwr2";
constexpr const char* TEXT_PPC_CPU_LABEL_pwr4        = "pwr4";
constexpr const char* TEXT_PPC_CPU_LABEL_pwr5        = "pwr5";
constexpr const char* TEXT_PPC_CPU_LABEL_pwr5x       = "pwr5x";
constexpr const char* TEXT_PPC_CPU_LABEL_pwr6        = "pwr6";
constexpr const char* TEXT_PPC_CPU_LABEL_pwr7        = "pwr7";
constexpr const char* TEXT_PPC_CPU_LABEL_pwr8        = "pwr8";
constexpr const char* TEXT_PPC_CPU_LABEL_pwr9        = "pwr9";
constexpr const char* TEXT_PPC_CPU_LABEL_pwrx        = "pwrx";
constexpr const char* TEXT_PPC_CPU_LABEL_titan       = "titan";
constexpr const char* TEXT_PPC_CPU_LABEL_vle         = "vle";

/* Have a wonderful day :) */
/**
 * @}
 */
/****** END OF FILE ******/
