/******************************************************************************
 * @file ObjdumpConfig
 * @author Samuel Martel
 * @date 2020/08/05
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
#include "Brigerad.h"

#include "ObjdumpConfig.h"

#include "utils/StringUtils.h"


std::string ObjdumpConfig::Serialize()
{
    std::stringstream ss;

    ss << (int)fileType << "\n";
    ss << shouldSavePrj << "\n";
    ss << pathOfPrj << "\n";
    ss << pathOfBin << "\n";
    ss << objdumpCmd << "\n";
    ss << showArchiveHeader << "\n";
    ss << adjustVmaOffset << "\n";
    ss << demangle << "\n";
    ss << showDebuggingInfo << "\n";
    ss << showDebuggingInfoForCtags << "\n";
    ss << disassemble << "\n";
    ss << disassembleAll << "\n";
    ss << prefixAddresses << "\n";
    ss << (int)endianness << "\n";
    ss << showFileOffset << "\n";
    ss << showFileStartContext << "\n";
    ss << showInfoFromHeader << "\n";
    ss << showInfoFromSection << "\n";
    ss << (int)disassemblerOptions.architecture << "\n";

    ss << disassemblerOptions.arcDisassemblerOptions.displayAsHex << "\n";
    ss << disassemblerOptions.arcDisassemblerOptions.dpfp << "\n";
    ss << disassemblerOptions.arcDisassemblerOptions.dsp << "\n";
    ss << disassemblerOptions.arcDisassemblerOptions.fpud << "\n";
    ss << disassemblerOptions.arcDisassemblerOptions.fpuda << "\n";
    ss << disassemblerOptions.arcDisassemblerOptions.fpus << "\n";
    ss << disassemblerOptions.arcDisassemblerOptions.quarkse_em << "\n";
    ss << disassemblerOptions.arcDisassemblerOptions.spfp << "\n";

    ss << (int)disassemblerOptions.armDisassemblerOptions.armRegisterNameSet << "\n";
    ss << disassemblerOptions.armDisassemblerOptions.forceThumb << "\n";
    ss << disassemblerOptions.armDisassemblerOptions.cpuIsa << "\n";

    ss << disassemblerOptions.aArch64DisassemblerOptions.disassembleIntoGenericInstruction << "\n";

    ss << (int)disassemblerOptions.x86DisassemblerOptions.addrSize << "\n";
    ss << (int)disassemblerOptions.x86DisassemblerOptions.architecture << "\n";
    ss << (int)disassemblerOptions.x86DisassemblerOptions.dataSize << "\n";
    ss << disassemblerOptions.x86DisassemblerOptions.displaySuffix << "\n";
    ss << (int)disassemblerOptions.x86DisassemblerOptions.isa << "\n";
    ss << (int)disassemblerOptions.x86DisassemblerOptions.syntax << "\n";

    ss << (int)disassemblerOptions.powerPcDisassemblerOptions.cpuIsa << "\n";
    ss << disassemblerOptions.powerPcDisassemblerOptions.enable64Bits << "\n";
    ss << disassemblerOptions.powerPcDisassemblerOptions.useAltivec << "\n";
    ss << disassemblerOptions.powerPcDisassemblerOptions.useAny << "\n";
    ss << disassemblerOptions.powerPcDisassemblerOptions.useHtm << "\n";
    ss << disassemblerOptions.powerPcDisassemblerOptions.useRaw << "\n";
    ss << disassemblerOptions.powerPcDisassemblerOptions.useSpe << "\n";
    ss << disassemblerOptions.powerPcDisassemblerOptions.useVsx << "\n";

    ss << disassemblerOptions.mipsDisassemblerOptions.cp0ArchName << "\n";
    ss << disassemblerOptions.mipsDisassemblerOptions.disassembleMsa << "\n";
    ss << disassemblerOptions.mipsDisassemblerOptions.disassembleVirt << "\n";
    ss << disassemblerOptions.mipsDisassemblerOptions.disassembleXpa << "\n";
    ss << disassemblerOptions.mipsDisassemblerOptions.fprNamesAbi << "\n";
    ss << disassemblerOptions.mipsDisassemblerOptions.gprNamesAbi << "\n";
    ss << disassemblerOptions.mipsDisassemblerOptions.hwrArchName << "\n";
    ss << disassemblerOptions.mipsDisassemblerOptions.regArchName << "\n";
    ss << disassemblerOptions.mipsDisassemblerOptions.regNamesAbi << "\n";
    ss << disassemblerOptions.mipsDisassemblerOptions.useRawMnemonic << "\n";

    ss << showFormatSpecificInfo << "\n";
    ss << showFormatSpecificInfoParam << "\n";
    ss << showRelocEntries << "\n";
    ss << showDynamicRelocEntries << "\n";
    ss << showAllContent << "\n";
    ss << showSource << "\n";
    ss << showPrefixedSource << "\n";
    ss << sourcePrefix << "\n";
    ss << pathPrefix << "\n";
    ss << pathStripLevel << "\n";
    ss << showRawInstruction << "\n";
    ss << insnWidth << "\n";
    ss << visualizeJumps << "\n";

    ss << dwarfOptions.showDebugAbbrev << "\n";
    ss << dwarfOptions.showDebugAddr << "\n";
    ss << dwarfOptions.showDebugCuTuIndex << "\n";
    ss << dwarfOptions.showRawDebugFrame << "\n";
    ss << dwarfOptions.showInterpretedDebugFrame << "\n";
    ss << dwarfOptions.showGdbIndex << "\n";
    ss << dwarfOptions.showDebugInfo << "\n";
    ss << dwarfOptions.showGnuDebugLink << "\n";
    ss << dwarfOptions.followLinks << "\n";
    ss << dwarfOptions.showDebugLine << "\n";
    ss << dwarfOptions.showInterpretedDebugLine << "\n";
    ss << dwarfOptions.showDebugMacro << "\n";
    ss << dwarfOptions.showDebugLoc << "\n";
    ss << dwarfOptions.showDebugPubNames << "\n";
    ss << dwarfOptions.showDebugAranges << "\n";
    ss << dwarfOptions.showDebugRanges << "\n";
    ss << dwarfOptions.showDebugStr << "\n";
    ss << dwarfOptions.showDebugPubTypes << "\n";
    ss << dwarfOptions.showTraceAranges << "\n";
    ss << dwarfOptions.showTraceAbbrev << "\n";
    ss << dwarfOptions.showTraceInfo << "\n";
    ss << dwarfOptions.debugInfoDepthLimit << "\n";
    ss << dwarfOptions.debugInfoDepthStart << "\n";
    ss << dwarfOptions.enableAdditionChecks << "\n";

    ss << ctfSectionName << "\n";
    ss << ctfParentSectionName << "\n";
    ss << showFullSectionContent << "\n";
    ss << startAddress << "\n";
    ss << stopAddress << "\n";
    ss << showSymbolTableAsSyms << "\n";
    ss << showDynamicSymbolTableAsSyms << "\n";
    ss << includeSpecialSymbols << "\n";
    ss << formatForWideDevices << "\n";
    ss << showAllHeaders << "\n";
    ss << disassembleZeroes << "\n";

    return ss.str();
}

void ObjdumpConfig::Desirialize(const std::vector<std::string>& ser)
{
    BR_ASSERT(ser.size() == 103, "Bad amount of data for ObjdumpConfig De-serialization!");

    fileType                  = (FileTypes)StringUtils::ToVal(ser[0]);
    shouldSavePrj             = (bool)StringUtils::ToVal(ser[1]);
    pathOfPrj                 = ser[2];
    pathOfBin                 = ser[3];
    objdumpCmd                = ser[4];
    showArchiveHeader         = (bool)StringUtils::ToVal(ser[5]);
    adjustVmaOffset           = StringUtils::ToVal(ser[6]);
    demangle                  = (bool)StringUtils::ToVal(ser[7]);
    showDebuggingInfo         = (bool)StringUtils::ToVal(ser[8]);
    showDebuggingInfoForCtags = (bool)StringUtils::ToVal(ser[9]);
    disassemble               = (bool)StringUtils::ToVal(ser[10]);
    disassembleAll            = (bool)StringUtils::ToVal(ser[11]);
    prefixAddresses           = (bool)StringUtils::ToVal(ser[12]);
    endianness                = (EndiannessEnum_t)StringUtils::ToVal(ser[13]);
    showFileOffset            = (bool)StringUtils::ToVal(ser[14]);
    showFileStartContext      = (bool)StringUtils::ToVal(ser[15]);
    showInfoFromHeader        = (bool)StringUtils::ToVal(ser[16]);
    showInfoFromSection       = (bool)StringUtils::ToVal(ser[17]);

    disassemblerOptions.architecture = (ArchitectureEnum_t)StringUtils::ToVal(ser[18]);

    disassemblerOptions.arcDisassemblerOptions.displayAsHex = (bool)StringUtils::ToVal(ser[19]);
    disassemblerOptions.arcDisassemblerOptions.dpfp         = (bool)StringUtils::ToVal(ser[20]);
    disassemblerOptions.arcDisassemblerOptions.dsp          = (bool)StringUtils::ToVal(ser[21]);
    disassemblerOptions.arcDisassemblerOptions.fpud         = (bool)StringUtils::ToVal(ser[22]);
    disassemblerOptions.arcDisassemblerOptions.fpuda        = (bool)StringUtils::ToVal(ser[23]);
    disassemblerOptions.arcDisassemblerOptions.fpus         = (bool)StringUtils::ToVal(ser[24]);
    disassemblerOptions.arcDisassemblerOptions.quarkse_em   = (bool)StringUtils::ToVal(ser[25]);
    disassemblerOptions.arcDisassemblerOptions.spfp         = (bool)StringUtils::ToVal(ser[26]);

    disassemblerOptions.armDisassemblerOptions.armRegisterNameSet =
      (ArmRegisterNameSetEnum_t)StringUtils::ToVal(ser[27]);
    disassemblerOptions.armDisassemblerOptions.forceThumb = (bool)StringUtils::ToVal(ser[28]);
    disassemblerOptions.armDisassemblerOptions.cpuIsa     = ser[29];

    disassemblerOptions.aArch64DisassemblerOptions.disassembleIntoGenericInstruction =
      (bool)StringUtils::ToVal(ser[30]);

    disassemblerOptions.x86DisassemblerOptions.addrSize =
      (x86AddrSizeEnum_t)StringUtils::ToVal(ser[31]);
    disassemblerOptions.x86DisassemblerOptions.architecture =
      (x86DisassemblyArchitectureEnum_t)StringUtils::ToVal(ser[32]);
    disassemblerOptions.x86DisassemblerOptions.dataSize =
      (x86DataSizeEnum_t)StringUtils::ToVal(ser[33]);
    disassemblerOptions.x86DisassemblerOptions.displaySuffix = (bool)StringUtils::ToVal(ser[34]);
    disassemblerOptions.x86DisassemblerOptions.isa = (x86IsaEnum_t)StringUtils::ToVal(ser[35]);
    disassemblerOptions.x86DisassemblerOptions.syntax =
      (x86SyntaxModeEnum_t)StringUtils::ToVal(ser[36]);

    disassemblerOptions.powerPcDisassemblerOptions.cpuIsa =
      (PpcCpuEnum_t)StringUtils::ToVal(ser[37]);
    disassemblerOptions.powerPcDisassemblerOptions.enable64Bits = (bool)StringUtils::ToVal(ser[38]);
    disassemblerOptions.powerPcDisassemblerOptions.useAltivec   = (bool)StringUtils::ToVal(ser[39]);
    disassemblerOptions.powerPcDisassemblerOptions.useAny       = (bool)StringUtils::ToVal(ser[40]);
    disassemblerOptions.powerPcDisassemblerOptions.useHtm       = (bool)StringUtils::ToVal(ser[41]);
    disassemblerOptions.powerPcDisassemblerOptions.useRaw       = (bool)StringUtils::ToVal(ser[42]);
    disassemblerOptions.powerPcDisassemblerOptions.useSpe       = (bool)StringUtils::ToVal(ser[43]);
    disassemblerOptions.powerPcDisassemblerOptions.useVsx       = (bool)StringUtils::ToVal(ser[44]);

    disassemblerOptions.mipsDisassemblerOptions.cp0ArchName     = ser[45];
    disassemblerOptions.mipsDisassemblerOptions.disassembleMsa  = (bool)StringUtils::ToVal(ser[46]);
    disassemblerOptions.mipsDisassemblerOptions.disassembleVirt = (bool)StringUtils::ToVal(ser[47]);
    disassemblerOptions.mipsDisassemblerOptions.disassembleXpa  = (bool)StringUtils::ToVal(ser[48]);
    disassemblerOptions.mipsDisassemblerOptions.fprNamesAbi     = ser[49];
    disassemblerOptions.mipsDisassemblerOptions.gprNamesAbi     = ser[50];
    disassemblerOptions.mipsDisassemblerOptions.hwrArchName     = ser[51];
    disassemblerOptions.mipsDisassemblerOptions.regArchName     = ser[52];
    disassemblerOptions.mipsDisassemblerOptions.regNamesAbi     = ser[53];
    disassemblerOptions.mipsDisassemblerOptions.useRawMnemonic  = (bool)StringUtils::ToVal(ser[54]);

    showFormatSpecificInfo      = (bool)StringUtils::ToVal(ser[55]);
    showFormatSpecificInfoParam = (bool)StringUtils::ToVal(ser[56]);
    showRelocEntries            = (bool)StringUtils::ToVal(ser[57]);
    showDynamicRelocEntries     = (bool)StringUtils::ToVal(ser[58]);
    showAllContent              = (bool)StringUtils::ToVal(ser[59]);
    showSource                  = (bool)StringUtils::ToVal(ser[60]);
    showPrefixedSource          = (bool)StringUtils::ToVal(ser[61]);
    sourcePrefix                = ser[62];
    pathPrefix                  = ser[63];
    pathStripLevel              = StringUtils::ToVal(ser[64]);
    showRawInstruction          = (bool)StringUtils::ToVal(ser[65]);
    insnWidth                   = StringUtils::ToVal(ser[66]);
    visualizeJumps              = (bool)StringUtils::ToVal(ser[67]);

    dwarfOptions.showDebugAbbrev           = (bool)StringUtils::ToVal(ser[68]);
    dwarfOptions.showDebugAddr             = (bool)StringUtils::ToVal(ser[69]);
    dwarfOptions.showDebugCuTuIndex        = (bool)StringUtils::ToVal(ser[70]);
    dwarfOptions.showRawDebugFrame         = (bool)StringUtils::ToVal(ser[71]);
    dwarfOptions.showInterpretedDebugFrame = (bool)StringUtils::ToVal(ser[72]);
    dwarfOptions.showGdbIndex              = (bool)StringUtils::ToVal(ser[73]);
    dwarfOptions.showDebugInfo             = (bool)StringUtils::ToVal(ser[74]);
    dwarfOptions.showGnuDebugLink          = (bool)StringUtils::ToVal(ser[75]);
    dwarfOptions.followLinks               = (bool)StringUtils::ToVal(ser[76]);
    dwarfOptions.showDebugLine             = (bool)StringUtils::ToVal(ser[77]);
    dwarfOptions.showInterpretedDebugLine  = (bool)StringUtils::ToVal(ser[78]);
    dwarfOptions.showDebugMacro            = (bool)StringUtils::ToVal(ser[79]);
    dwarfOptions.showDebugLoc              = (bool)StringUtils::ToVal(ser[80]);
    dwarfOptions.showDebugPubNames         = (bool)StringUtils::ToVal(ser[81]);
    dwarfOptions.showDebugAranges          = (bool)StringUtils::ToVal(ser[82]);
    dwarfOptions.showDebugRanges           = (bool)StringUtils::ToVal(ser[83]);
    dwarfOptions.showDebugStr              = (bool)StringUtils::ToVal(ser[84]);
    dwarfOptions.showDebugPubTypes         = (bool)StringUtils::ToVal(ser[85]);
    dwarfOptions.showTraceAranges          = (bool)StringUtils::ToVal(ser[86]);
    dwarfOptions.showTraceAbbrev           = (bool)StringUtils::ToVal(ser[87]);
    dwarfOptions.showTraceInfo             = (bool)StringUtils::ToVal(ser[88]);
    dwarfOptions.debugInfoDepthLimit       = StringUtils::ToVal(ser[89]);
    dwarfOptions.debugInfoDepthStart       = StringUtils::ToVal(ser[90]);
    dwarfOptions.enableAdditionChecks      = (bool)StringUtils::ToVal(ser[91]);

    ctfSectionName               = ser[92];
    ctfParentSectionName         = ser[93];
    showFullSectionContent       = (bool)StringUtils::ToVal(ser[94]);
    startAddress                 = StringUtils::ToVal(ser[95]);
    stopAddress                  = StringUtils::ToVal(ser[96]);
    showSymbolTableAsSyms        = (bool)StringUtils::ToVal(ser[97]);
    showDynamicSymbolTableAsSyms = (bool)StringUtils::ToVal(ser[98]);
    includeSpecialSymbols        = (bool)StringUtils::ToVal(ser[99]);
    formatForWideDevices         = (bool)StringUtils::ToVal(ser[100]);
    showAllHeaders               = (bool)StringUtils::ToVal(ser[101]);
    disassembleZeroes            = (bool)StringUtils::ToVal(ser[102]);
}
