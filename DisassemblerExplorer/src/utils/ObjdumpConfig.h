/******************************************************************************
 * @file ObjdumpConfig
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
#ifndef _ObjdumpConfig
#define _ObjdumpConfig

/*****************************************************************************/
/* Includes */
#include "utils/File.h"

#include <string>

/*****************************************************************************/
/* Exported defines */


/*****************************************************************************/
/* Exported macro */


/*****************************************************************************/
/* Exported types */

using EndiannessEnum_t   = enum { Endianness_Auto = 0, Endianness_Big = 1, Endianness_Small = 2 };
using ArchitectureEnum_t = enum {
    Architecture_Auto    = 0,
    Architecture_Arm     = 1,
    Architecture_Avr     = 2,
    Architecture_x86     = 3,
    Architecture_x86_64  = 4,
    Architecture_PowerPc = 5,
    Architecture_RiscV   = 6,
    Architecture_Aarch64 = 7,
    Architecture_Mips    = 8
};
using ArmRegisterNameSetEnum_t = enum {
    ARM_Auto           = 0,
    ARM_StdSet         = 1,
    ARM_ApcsSet        = 2,
    ARM_ApcsSpecialSet = 3,
    ARM_Raw            = 4
};

using x86DisassemblyArchitectureEnum_t = enum {
    x86Arch_Auto   = 0,
    x86Arch_x86_64 = 1,
    x86Arch_i386   = 2,
    x86Arch_i8086  = 3
};

using x86SyntaxModeEnum_t = enum { x86Syntax_Auto = 0, x86Syntax_intel = 1, x86Syntax_att = 2 };

using x86IsaEnum_t = enum { x86Isa_Auto = 0, x86Isa_amd64 = 1, x86Isa_intel64 = 2 };

using x86AddrSizeEnum_t = enum {
    x86AddrSize_Auto = 0,
    x86AddrSize_64   = 1,
    x86AddrSize_32   = 2,
    x86AddrSize_16   = 3
};

using x86DataSizeEnum_t = enum { x86DataSize_Auto = 0, x86DataSize_32 = 1, x86DataSize_16 = 2 };

using PpcCpuEnum_t = enum {
    PpcCpu_Auto = 0,
    PpcCpu_403,
    PpcCpu_405,
    PpcCpu_440,
    PpcCpu_464,
    PpcCpu_476,
    PpcCpu_601,
    PpcCpu_603,
    PpcCpu_604,
    PpcCpu_620,
    PpcCpu_7400,
    PpcCpu_7410,
    PpcCpu_7450,
    PpcCpu_7455,
    PpcCpu_750cl,
    PpcCpu_821,
    PpcCpu_850,
    PpcCpu_860,
    PpcCpu_a2,
    PpcCpu_booke,
    PpcCpu_booke32,
    PpcCpu_cell,
    PpcCpu_com,
    PpcCpu_e200z4,
    PpcCpu_e300,
    PpcCpu_e500,
    PpcCpu_e500mc,
    PpcCpu_e500mc64,
    PpcCpu_e500x2,
    PpcCpu_e5500,
    PpcCpu_e6500,
    PpcCpu_efs,
    PpcCpu_power4,
    PpcCpu_power5,
    PpcCpu_power6,
    PpcCpu_power7,
    PpcCpu_power8,
    PpcCpu_power9,
    PpcCpu_ppc,
    PpcCpu_ppc32,
    PpcCpu_ppc64,
    PpcCpu_ppc64bridge,
    PpcCpu_ppcps,
    PpcCpu_pwr,
    PpcCpu_pwr2,
    PpcCpu_pwr4,
    PpcCpu_pwr5,
    PpcCpu_pwr5x,
    PpcCpu_pwr6,
    PpcCpu_pwr7,
    PpcCpu_pwr8,
    PpcCpu_pwr9,
    PpcCpu_pwrx,
    PpcCpu_titan,
    PpcCpu_vle
};

struct ArcDisassemblerOptions
{
    bool dsp          = false;
    bool spfp         = false;
    bool dpfp         = false;
    bool quarkse_em   = false;
    bool fpuda        = false;
    bool fpus         = false;
    bool fpud         = false;
    bool displayAsHex = false;
};

struct ArmDisassemblerOptions
{
    ArmRegisterNameSetEnum_t armRegisterNameSet = ARM_Auto;
    bool                     forceThumb         = false;
    std::string              cpuIsa;    // #TODO Make this into an enum
};

struct Aarch64DisassemblerOptions
{
    bool disassembleIntoGenericInstruction = false;
};

struct X86DisassemblerOptions
{
    x86DisassemblyArchitectureEnum_t architecture  = x86Arch_Auto;
    x86SyntaxModeEnum_t              syntax        = x86Syntax_Auto;
    x86IsaEnum_t                     isa           = x86Isa_Auto;
    x86AddrSizeEnum_t                addrSize      = x86AddrSize_Auto;
    x86DataSizeEnum_t                dataSize      = x86DataSize_Auto;
    bool                             displaySuffix = false;
};

struct PowerPcDisassemberOptions
{
    bool         useRaw       = false;
    PpcCpuEnum_t cpuIsa       = PpcCpu_Auto;
    bool         enable64Bits = false;
    bool         useAltivec   = false;
    bool         useAny       = false;
    bool         useHtm       = false;
    bool         useVsx       = false;
    bool         useSpe       = false;
};

struct MipsDisassemlerOptions
{
    bool        useRawMnemonic  = false;
    bool        disassembleMsa  = false;
    bool        disassembleVirt = false;
    bool        disassembleXpa  = false;
    std::string gprNamesAbi     = std::string(128, '\0');
    std::string fprNamesAbi     = std::string(128, '\0');
    std::string cp0ArchName     = std::string(128, '\0');
    std::string hwrArchName     = std::string(128, '\0');
    std::string regNamesAbi     = std::string(128, '\0');
    std::string regArchName     = std::string(128, '\0');
};

struct DisassemblerOptions
{
    ArchitectureEnum_t         architecture = Architecture_Arm;
    ArcDisassemblerOptions     arcDisassemblerOptions;
    ArmDisassemblerOptions     armDisassemblerOptions;
    Aarch64DisassemblerOptions aArch64DisassemblerOptions;
    X86DisassemblerOptions     x86DisassemblerOptions;
    PowerPcDisassemberOptions  powerPcDisassemblerOptions;
    MipsDisassemlerOptions     mipsDisassemblerOptions;
};

struct DwarfDisplayOptions
{
    bool   showDebugAbbrev           = false;
    bool   showDebugAddr             = false;
    bool   showDebugCuTuIndex        = false;
    bool   showRawDebugFrame         = false;
    bool   showInterpretedDebugFrame = false;
    bool   showGdbIndex              = false;
    bool   showDebugInfo             = false;
    bool   showGnuDebugLink          = false;
    bool   followLinks               = false;
    bool   showDebugLine             = false;
    bool   showInterpretedDebugLine  = false;
    bool   showDebugMacro            = false;
    bool   showDebugLoc              = false;
    bool   showDebugPubNames         = false;
    bool   showDebugAranges          = false;
    bool   showDebugStr              = false;
    bool   showDebugPubTypes         = false;
    bool   showTraceAranges          = false;
    bool   showTraceAbbrev           = false;
    bool   showTraceInfo             = false;
    size_t debugInfoDepthLimit       = 0;
    size_t debugInfoDepthStart       = 0;
    bool   enableAdditionChecks      = false;
};

struct ObjdumpConfig
{
    FileTypes           type                      = FileTypes::All;
    bool                shouldSavePrj             = false;
    std::string         pathOfPrj                 = "";
    std::string         pathOfBin                 = "";
    std::string         objdumpCmd                = "";
    bool                showArchiveHeader         = false;
    int                 adjustVmaOffset           = 0;
    bool                demangle                  = false;
    bool                showDebuggingInfo         = false;
    bool                showDebuggingInfoForCtags = false;
    bool                disassemble               = false;
    bool                disassembleAll            = false;
    bool                prefixAddresses           = false;
    EndiannessEnum_t    endianness                = Endianness_Auto;
    bool                showFileOffset            = false;
    bool                showFileStartContext      = false;
    bool                showInfoFromHeader        = false;
    bool                showInfoFromSection       = false;
    DisassemblerOptions disassemblerOptions;
    bool                showFormatSpecificInfo      = false;
    std::string         showFormatSpecificInfoParam = std::string(128, '\0');
    bool                showRelocEntries            = false;
    bool                showDynamicRelocEntries     = false;
    bool                showAllContent              = false;
    bool                showSource                  = false;
    bool                showPrefixedSource          = false;
    std::string         sourcePrefix                = std::string(128, '\0');
    std::string         pathPrefix                  = std::string(128, '\0');
    size_t              pathStripLevel              = 0;
    bool                showRawInstruction          = true;
    bool                visualizeJumps              = false;
    DwarfDisplayOptions dwarfOptions;
    std::string         ctfSectionName               = std::string(128, '\0');
    std::string         ctfParentSectionName         = std::string(128, '\0');
    bool                showFullSectionContent       = false;
    size_t              startAddress                 = 0;
    size_t              stopAddress                  = 0;
    bool                showSymbolTableAsSyms        = false;
    bool                showDynamicSymbolTableAsSyms = false;
    bool                includeSpecialSymbols        = false;
    bool                showVersion                  = false;
    bool                showAllHeaders               = false;
    bool                formatForWideDevices         = true;
    bool                disassembleZeroes            = false;
};

/*****************************************************************************/
/* Exported functions */


/* Have a wonderful day :) */
#endif /* _ObjdumpConfig */
/**
 * @}
 */
/****** END OF FILE ******/
