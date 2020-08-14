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
/* SECTION: Button Labels                                               */
/************************************************************************/
constexpr const char* TEXT_BUTTON_LABEL_CONFIRM = "Confirmer";
constexpr const char* TEXT_BUTTON_LABEL_CANCEL  = "Annuler";

/************************************************************************/
/* SECTION: NewProjectLayer                                             */
/************************************************************************/
constexpr const char* TEXT_NEW_PROJECT_LAYER_WINDOW_NAME = "Nouveau Projet";

/************************************************************************/
/* SECTION: Project Creation Layer                                      */
/************************************************************************/
constexpr const char* TEXT_PROJECT_CREATION_LAYER_TITLE = "Création du projet en cours...";

/************************************************************************/
/* SECTION: ApplicationLayer                                            */
/************************************************************************/
constexpr const char* TEXT_APPLICATION_LAYER_FILE  = "Fichier";
constexpr const char* TEXT_APPLICATION_LAYER_NEW   = "Nouveau";
constexpr const char* TEXT_APPLICATION_LAYER_OPEN  = "Ouvrir";
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
/* SECTION: ExplorerLayer                                               */
/************************************************************************/
constexpr const char* TEXT_EXPLORER_LAYER_DEFAULT_PROJECT_NAME = "Nouveau Projet##";

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

// Show Format Specific Information.
// #TODO Translate this
constexpr const char* TEXT_SHOW_FORMAT_SPECIFIC_LABEL       = "Show Format Specific Information";
constexpr const char* TEXT_SHOW_FORMAT_SPECIFIC_PARAM_LABEL = "Parameters";
constexpr const char* TEXT_SHOW_FORMAT_SPECIFIC_HINT =
  R"(Show information that is specific to the object file format.
The exact information shown depends upon the object file format. For some object file formats,
no additional information is printed.)";
constexpr const char* TEXT_SHOW_FORMAT_SPECIFIC_PARAM_HINT =
  R"(Show information that is specific to the object file format.
The value of this setting is a comma separated list that depends on the format.

For XCOFF, the available options are:
- header
- aout
- sections
- syms
- relocs
- lineno
- loader
- except
- typchk
- traceback
- toc
- ldinfo

Not all object formats support this option. In particular the ELF format does not use it.)";
constexpr const char* TEXT_SHOW_FORMAT_SPECIFIC_FLAG       = "-p";
constexpr const char* TEXT_SHOW_FORMAT_SPECIFIC_PARAM_FLAG = "-p ";

// Show Reloc Entries
// #TODO Translate this
constexpr const char* TEXT_SHOW_RELOC_ENTRIES_LABEL         = "Show Relocation Entries";
constexpr const char* TEXT_SHOW_DYNAMIC_RELOC_ENTRIES_LABEL = "Show Dynamic Relocation Entries";
constexpr const char* TEXT_SHOW_RELOC_ENTRIES_HINT = R"(Show the relocation entries of the file.
If the file is being disassembled, the relocations are shown interspersed with the disassembly.)";
constexpr const char* TEXT_SHOW_DYNAMIC_RELOC_ENTRIES_HINT =
  R"(Show the dynamic relocation entries of the file.
This is only meaningful for dynamic objects, such as certain types of shared libraries.
If the file is being disassembled, the relocations are printed interspersed with the disassembly.)";
constexpr const char* TEXT_SHOW_RELOC_ENTRIES_FLAG         = "-r";
constexpr const char* TEXT_SHOW_DYNAMIC_RELOC_ENTRIES_FLAG = "-R";

// Show All Content
// #TODO Translate this
constexpr const char* TEXT_SHOW_ALL_CONTENT_LABEL = "Show All Content";
constexpr const char* TEXT_SHOW_ALL_CONTENT_HINT =
  R"(Display the full content of any sections requested.
By default, all non-empty sections are displayed.)";
constexpr const char* TEXT_SHOW_ALL_CONTENT_FLAG = "-s";

// Show Source
// #TODO Translate this
constexpr const char* TEXT_SHOW_SOURCE_LABEL        = "Show Source";
constexpr const char* TEXT_SHOW_SOURCE_PREFIX_LABEL = "Source Prefix";
constexpr const char* TEXT_SHOW_SOURCE_HINT =
  R"(Display source code intermixed with disassembly, if possible.
This activates the "Disassemble" option.)";
constexpr const char* TEXT_SHOW_SOURCE_PREFIX_HINT = R"(Like the "Show Source" option, 
but all source code lines are displayed with the specified prefix. Typically, this string will be a comment
string which can be used to distinguish the assembler code from the source code.)";
constexpr const char* TEXT_SHOW_SOURCE_FLAG        = "-S";
constexpr const char* TEXT_SHOW_SOURCE_PREFIX_FLAG = "--source-comment=";

// Path Options
// #TODO Translate this
constexpr const char* TEXT_PATH_PREFIX_LABEL      = "Path Prefix";
constexpr const char* TEXT_PATH_STRIP_LEVEL_LABEL = "Path Prefix Strip Levels";
constexpr const char* TEXT_PATH_PREFIX_HINT       = R"(Add a string to the absolute paths)";
constexpr const char* TEXT_PATH_STRIP_LEVEL_HINT =
  R"(Indicate how many initial directory names to strip off the hardwired absolute paths)";
constexpr const char* TEXT_PATH_PREFIX_FLAG      = "--prefix=";
constexpr const char* TEXT_PATH_STRIP_LEVEL_FLAG = "--prefix-strip=";

// Show Raw Instructions
// #TODO Translate this
constexpr const char* TEXT_SHOW_RAW_INSTRUCTION_LABEL   = "Show Raw Instructions";
constexpr const char* TEXT_SHOW_INSTRUCTION_WIDTH_LABEL = "Instruction Display Width";
constexpr const char* TEXT_SHOW_RAW_INSTRUCTION_HINT =
  R"(When disassembling instructions, print the instruction in hex
as well as in symbolic form. This is the default except when the "Prefix Addresses" option is used.)";
constexpr const char* TEXT_SHOW_INSTRUCTION_WIDTH_HINT =
  R"(Set the number of bytes displayed on a single line when disassembling instructions.)";
constexpr const char* TEXT_SHOW_RAW_INSTRUCTION_FLAG   = "--show-raw-insn";
constexpr const char* TEXT_SHOW_INSTRUCTION_WIDTH_FLAG = "--insn-width=";

// Visualize Jumps
// #TODO Translate this
constexpr const char* TEXT_VISUALIZE_JUMPS_LABEL = "Visualize Jumps";
constexpr const char* TEXT_VISUALIZE_JUMPS_HINT =
  R"(Visualize jumps that stay inside a function by drawing ASCII art between the start
and target addresses.)";
constexpr const char* TEXT_VISUALIZE_JUMPS_FLAG = "--visualize-jumps";

// DWARF Options
// #TODO Translate this
constexpr const char* TEXT_DWARF_LABEL = "DWARF Options";
constexpr const char* TEXT_DWARF_HINT =
  R"(Display the contents of the DWARF debug sections in the file, if any are present.
Compressed debug sections are automatically decompressed (temporarily) before they are displayed.
If one or more of the optional settings are enabled, only those type(s) of data will be dumped.

Note: Displaying the contents of ".debug_static_funcs", ".debug_static_vars" and "debug_weaknames" sections
is not currently supported.)";
constexpr const char* TEXT_DWARF_FLAG         = "-W";
constexpr const char* TEXT_DWARF_ABBREV_LABEL = "Abbrev";
constexpr const char* TEXT_DWARF_ABBREV_HINT =
  R"(Display the contents of the ".debug_abbrev" section.)";
constexpr const char* TEXT_DWARF_ABBREV_FLAG = "a";
constexpr const char* TEXT_DWARF_ADDR_LABEL  = "Addr";
constexpr const char* TEXT_DWARF_ADDR_HINT =
  R"(Display the contents of the ".debug_addr" section.)";
constexpr const char* TEXT_DWARF_ADDR_FLAG      = "A";
constexpr const char* TEXT_DWARF_CU_INDEX_LABEL = "CU Index";
constexpr const char* TEXT_DWARF_CU_INDEX_HINT =
  R"(Display the contents of the ".debug_cu_index" and/or ".debug_tu_index" sections.)";
constexpr const char* TEXT_DWARF_CU_INDEX_FLAG = "c";
constexpr const char* TEXT_DWARF_FRAMES_LABEL  = "Frame";
constexpr const char* TEXT_DWARF_FRAMES_HINT =
  R"(Display the contents of the ".debug_frame" section.)";
constexpr const char* TEXT_DWARF_FRAMES_FLAG        = "f";
constexpr const char* TEXT_DWARF_FRAME_INTERP_LABEL = "Interpreted Frame";
constexpr const char* TEXT_DWARF_FRAME_INTERP_HINT =
  R"(Display the interpreted contents of a ".debug_frame" section.)";
constexpr const char* TEXT_DWARF_FRAME_INTERP_FLAG = "F";
constexpr const char* TEXT_DWARF_GDB_INDEX_LABEL   = "GDB Index";
constexpr const char* TEXT_DWARF_GDB_INDEX_HINT =
  R"(Display the contents of the ".gdb_index" and/or ".debug_names" sections.)";
constexpr const char* TEXT_DWARF_GDB_INDEX_FLAG = "g";
constexpr const char* TEXT_DWARF_INFO_LABEL     = "Info";
constexpr const char* TEXT_DWARF_INFO_HINT = R"(Display the contents of the ".debug_info" section.
Note: the output from this option can also be restricted by the use of the "Depth" and "Start" options of the DWARF options.)";
constexpr const char* TEXT_DWARF_INFO_FLAG = "i";
constexpr const char* TEXT_DWARF_LINKS_LABEL = "Links";
constexpr const char* TEXT_DWARF_LINKS_HINT =
  R"(Display the contents of the ".gnu_debuglink" and/or ".gnu_debugaltlink" sections.
Also displays any links to separate DWARF object file (dwo), if they are specified by the 
DW_AT_GNU_dwo_name or _DW_AT_dwo_name attributes in the ".debug_info" section.)";
constexpr const char* TEXT_DWARF_LINKS_FLAG         = "k";
constexpr const char* TEXT_DWARF_FOLLOW_LINKS_LABEL = "Follow Links";
constexpr const char* TEXT_DWARF_FOLLOW_LINKS_HINT =
  R"(Display the contents of any selected debug sections that are found in linked,
separate debug info file(s). This can result in multiple versions of the same debug section being 
displayed if it exists in more than one file.
In addition, when displaying DWARF attributes, if a form is found that references the separate debug info file,
then the referenced contents will also be displayed.)";
constexpr const char* TEXT_DWARF_FOLLOW_LINKS_FLAG = "K";
constexpr const char* TEXT_DWARF_RAW_LINE_LABEL    = "Raw Line";
constexpr const char* TEXT_DWARF_RAW_LINE_HINT =
  R"(Display the contents of the ".debug_line" section in a raw format.)";
constexpr const char* TEXT_DWARF_RAW_LINE_FLAG      = "l";
constexpr const char* TEXT_DWARF_DECODED_LINE_LABEL = "Decoded Line";
constexpr const char* TEXT_DWARF_DECODED_LINE_HINT =
  R"(Display the interpreted contents of the ".debug_line" section.)";
constexpr const char* TEXT_DWARF_DECODED_LINE_FLAG = "L";
constexpr const char* TEXT_DWARF_MACRO_LABEL       = "Macro";
constexpr const char* TEXT_DWARF_MACRO_HINT =
  R"(Display the contents of the ".debug_macro" and/or ".debug_macinfo" sections.)";
constexpr const char* TEXT_DWARF_MACRO_FLAG = "m";
constexpr const char* TEXT_DWARF_LOC_LABEL  = "Loc";
constexpr const char* TEXT_DWARF_LOC_HINT =
  R"(Display the contents of the ".debug_loc" and/or ".debug_loclists" sections.)";
constexpr const char* TEXT_DWARF_LOC_FLAG       = "o";
constexpr const char* TEXT_DWARF_PUBNAMES_LABEL = "Pubnames";
constexpr const char* TEXT_DWARF_PUBNAMES_HINT =
  R"(Display the contents of the ".debug_pubnames" and/or ".debug_gnu_pubnames" sections.)";
constexpr const char* TEXT_DWARF_PUBNAMES_FLAG = "p";
constexpr const char* TEXT_DWARF_ARANGES_LABEL = "Aranges";
constexpr const char* TEXT_DWARF_ARANGES_HINT =
  R"(Display the contents of the ".debug_aranges" sections.)";
constexpr const char* TEXT_DWARF_ARANGES_FLAG = "r";
constexpr const char* TEXT_DWARF_RANGES_LABEL = "Ranges";
constexpr const char* TEXT_DWARF_RANGES_HINT =
  R"(Display the contents of the ".debug_ranges" and/or ".debug_rnglists" sections.)";
constexpr const char* TEXT_DWARF_RANGES_FLAG = "R";
constexpr const char* TEXT_DWARF_STR_LABEL   = "Str";
constexpr const char* TEXT_DWARF_STR_HINT =
  R"(Display the contents of the ".debug_str", ".debug_line_str" and/or ".debug_str_offsets" sections.)";
constexpr const char* TEXT_DWARF_STR_FLAG      = "s";
constexpr const char* TEXT_DWARF_PUBTYPE_LABEL = "Pubtype";
constexpr const char* TEXT_DWARF_PUBTYPE_HINT =
  R"(Display the contents of the ".debug_pubtypes" and/or ".debug_gun_pubtypes" sections.)";
constexpr const char* TEXT_DWARF_PUBTYPE_FLAG        = "t";
constexpr const char* TEXT_DWARF_TRACE_ARANGES_LABEL = "Trace Aranges";
constexpr const char* TEXT_DWARF_TRACE_ARANGES_HINT =
  R"(Display the contents of the ".trace_aranges" section.)";
constexpr const char* TEXT_DWARF_TRACE_ARANGES_FLAG = "T";
constexpr const char* TEXT_DWARF_TRACE_ABBREV_LABEL = "Trace Abbrev";
constexpr const char* TEXT_DWARF_TRACE_ABBREV_HINT =
  R"(Display the contents of the ".trace_abbrev" section.)";
constexpr const char* TEXT_DWARF_TRACE_ABBREV_FLAG = "u";
constexpr const char* TEXT_DWARF_TRACE_INFO_LABEL  = "Trace Info";
constexpr const char* TEXT_DWARF_TRACE_INFO_HINT =
  R"(Display the contents of the ".trace_info" section.)";
constexpr const char* TEXT_DWARF_TRACE_INFO_FLAG = "U";
constexpr const char* TEXT_DWARF_DEPTH_LABEL     = "Max Depth";
constexpr const char* TEXT_DWARF_DEPTH_HINT =
  R"(Limit the dump of the ".debug_info" section to a maximum number of children.
This is only useful when dumping the ".debug_info" section.
The default is to print all DIEs; the special value 0 for this setting will also have this effect.

With a non-zero value, DIEs at or deeper than the specified level will not be displayed.)";
constexpr const char* TEXT_DWARF_DEPTH_FLAG  = "--dwarf-depth=";
constexpr const char* TEXT_DWARF_START_LABEL = "Start Depth";
constexpr const char* TEXT_DWARF_START_HINT =
  R"(Print only DIEs beginning with the DIE numbered by this setting.
This is only useful when dumping the ".debug_info" section.
If used, this option will suppress printing of any header information and all DIEs before the DIE numbered by this setting.
Only siblings and children of the specified DIE will be printed.

This can be used in conjunction with the "Max Depth" option.)";
constexpr const char* TEXT_DWARF_START_FLAG  = "--dwarf-start=";
constexpr const char* TEXT_DWARF_CHECK_LABEL = "Additional Checks";
constexpr const char* TEXT_DWARF_CHECK_HINT =
  R"(Enable addition checks for consistency of DWARF information.)";
constexpr const char* TEXT_DWARF_CHECK_FLAG = "--dwarf-check";

// CTF Section Names
// #TODO Translate this
constexpr const char* TEXT_CTF_SECTION_NAME_LABEL = "CTF Section";
constexpr const char* TEXT_CTF_SECTION_NAME_HINT =
  R"(Display the contents of the specified CTF section. 
CTF sections themselves contain many subsections, all of which are displayed in order.)";
constexpr const char* TEXT_CTF_SECTION_NAME_FLAG         = "--ctf=";
constexpr const char* TEXT_CTF_PARENT_SECTION_NAME_LABEL = "CTF Parent Section";
constexpr const char* TEXT_CTF_PARENT_SECTION_NAME_HINT =
  R"(Specify the name of another section from which the CTF dictionary can inherit types.
If none is specified, the CTF  dictionary is assumed to inherit types from the default-named
member of the archive contained within this section.)";
constexpr const char* TEXT_CTF_PARENT_SECTION_NAME_FLAG = "--ctf-parent=";

// Show Full Section Content
// #TODO Translate this
constexpr const char* TEXT_SHOW_FULL_SECTION_CONTENT_LABEL = "Show Full Section Content";
constexpr const char* TEXT_SHOW_FULL_SECTION_CONTENT_HINT =
  R"(Display the full contents of any sections requested.
Disaply the contents of the .stab and .stab.index and .stab.excl sections from an ELF file.
This is only useful on systems (such as Solaris 2.0) in which .stab debugging symbol-table
entries are carried in an ELF section. In most other file formats, 
debugging symbol-table entries are interleaved with linkage symbols, and are visible with the "Show Symbol Table" option.)";
constexpr const char* TEXT_SHOW_FULL_SECTION_CONTENT_FLAG = "-G";

// Address Range Options
// #TODO Translate this
constexpr const char* TEXT_ADDRESS_RANGE_HANDLER_START_LABEL = "Start Address";
constexpr const char* TEXT_ADDRESS_RANGE_HANDLER_START_HINT =
  R"(Start displaying data at the specified address.
This is only useful when disassembling a file and/or showing its source code.)";
constexpr const char* TEXT_ADDRESS_RANGE_HANDLER_START_FLAG = "--start-address=";
constexpr const char* TEXT_ADDRESS_RANGE_HANDLER_STOP_LABEL = "Stop Address";
constexpr const char* TEXT_ADDRESS_RANGE_HANDLER_STOP_HINT =
  R"(Stop displaying data at the specified address.
This is only useful when disassembling a file and/or showing it's source code.)";
constexpr const char* TEXT_ADDRESS_RANGE_HANDLER_STOP_FLAG = "--stop-address=";

// Show Symbol Table as Syms Options
// #TODO Translate this
constexpr const char* TEXT_SHOW_SYMBOL_TABLE_AS_SYMS_LABEL = "Show Symbol Table";
constexpr const char* TEXT_SHOW_SYMBOL_TABLE_AS_SYMS_HINT =
  R"(Display the symbol table entries of the file.
This is similar to the information provided by the "nm" program of binutils, although the display format is different.
The format of the output depends upon the format of the file being dumped, but there are two main types.
One looks like this:
    [  4](sec  3)(fl 0x00)(ty   0)(scl   3)(nx 1) 0x00000000 .bss
    [  6](sec  1)(fl 0x00)(ty   0)(scl   2)(nx 0) 0x00000000 fred
Where the number inside the square brackets is the number of the entry in the symbol,
the "sec" number is the section number,
the "fl" value are the symbol's flag bits, 
the "ty" number is the symbol's type,
the "scl" number is the symbol's storage class and
the "nx" value is the number of auxiliary entries associated with the symbol.
The las two fields are the symbol's value and its name.

The other common output format, usually seen with ELF based files, looks like this:
    00000000 l   d  .bss   00000000 .bss
    00000000 g      .text  00000000 fred
Here the first number is the symbol's value (sometimes refered to as its address).
The next field is actually a set of characters and spaces indicating the flag bits that are set on the symbol.
These characters are described below. Next is the section with which the symbol is associated or "*ABS*" if the
section is absolut (ie not connected with any section), or "*UND*" if the section is referenced in the 
file being dumped, but not defined there.

After the section name comes another field, a number, which for common symbols is the alignment and for
other symbol is the size. Finally the symbol's name is displayed.

The flag characters are divided into 7 groups as follows:

l, g, u, !
The symbol is a local (l), global (g), unique gloabal (u), neither global nor local (a space)
or both global and local (!). A symbol can be neither local or global for a variety of reasons, e.g., because it
is used for debugging, but it is probably an indication of a bug if it is ever both local and global.
Unique global symbols are a GNU extension to the standard set of ELF symbol bindings. For such a symbol the
dynamic linker will make sure that in the entire process there is just one symbol with this name and type in use.

w
The symbol is weak (w) or strong (a space).

C
The symbol denotes a constructor (C) or an ordinary symbol (a space).

W
The symbol is a warning (W) or a normal symbol (a space). A warning symbol's name
is a message to be displayed if the symbol following the warning symbol is ever referenced.

I, i
The symbol is an indirect reference to another symbol (I), a function to be evaluated
during reloc processing (i) or a normal symbol (a space).

d, D
The symbol is a debugging symbol (d) or a dynamic symbol (D) or a normal symbol (a space).

F, f, O
The symbol is the name of a function (F) or a file(f) or an object (O) or just a normal
symbol (a space).
)";
constexpr const char* TEXT_SHOW_SYMBOL_TABLE_AS_SYMS_FLAG      = "-t";
constexpr const char* TEXT_SHOW_DYN_SYMBOL_TABLE_AS_SYMS_LABEL = "Show Dynamic Symbol Table";
constexpr const char* TEXT_SHOW_DYN_SYMBOL_TABLE_AS_SYMS_HINT =
  R"(Show the dynamic symbol table entries of the file.
This is only meaningful for dynamic objects, such as certain types of shared libraries.
This is similar to the information provided by the "nm" program of binutils when given the "-D" option.

The output format is similar to that produced by the "Show Symbol Table" option, except that an extra field
is inserted before the symbol's name, giving the version information associated with the symbol.
If the version is the default version to be used when resolving unversioned references to the symbol, then it is
displayed as is, otherwise this information is placed into parentheses.)";
constexpr const char* TEXT_SHOW_DYN_SYMBOL_TABLE_AS_SYMS_FLAG  = "-T";
constexpr const char* TEXT_SHOW_SPE_SYMBOL_TABLE_AS_SYMS_LABEL = "Show Special Symbols";
constexpr const char* TEXT_SHOW_SPE_SYMBOL_TABLE_AS_SYMS_HINT =
  R"(When displaying symbols, include those which the target considers to be special in some way 
and which would not normally be of interest to the user.)";
constexpr const char* TEXT_SHOW_SPE_SYMBOL_TABLE_AS_SYMS_FLAG = "--special-syms";

// Extra Formatting Options
// #TODO Translate this
constexpr const char* TEXT_FORMAT_FOR_WIDE_DEVICES_LABEL = "Format for Wide Devices";
constexpr const char* TEXT_FORMAT_FOR_WIDE_DEVICES_HINT =
  R"(Format some lines for output devices that have more than 80 columns.
Also do not truncate symbol names when they are displayed.)";
constexpr const char* TEXT_FORMAT_FOR_WIDE_DEVICES_FLAG = "-w";

// Show All Headers Options
// #TODO Translate this
constexpr const char* TEXT_SHOW_ALL_HEADERS_LABEL = "Show All Headers";
constexpr const char* TEXT_SHOW_ALL_HEADERS_HINT =
  R"(Display all available header information, including the symbol table and relocation entries.)";
constexpr const char* TEXT_SHOW_ALL_HEADERS_FLAG = "-x";

// Disassemble Zeros
// #TODO Translate this
constexpr const char* TEXT_DISASSEMBLE_ZEROS_LABEL = "Disassemble Zeros";
constexpr const char* TEXT_DISASSEMBLE_ZEROS_HINT =
  R"(Normally the disassembly output will skip blocks of zeros.
This option directs the disassembler to disassemble those blocks, just like any other data.)";
constexpr const char* TEXT_DISASSEMBLE_ZEROS_FLAG = "-z";

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
