/******************************************************************************
 * @file ObjdumpConfigUI
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
#ifndef _ObjdumpConfigUI
#define _ObjdumpConfigUI

/*****************************************************************************/
/* Includes */
#include "utils/ObjdumpConfig.h"

#include <map>
#include "StringUtils.h"

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
    static const char*                                     m_shouldSaveHint;
    static const char*                                     m_prjPathHint;
    static const char*                                     m_architectureHint;
    static const char*                                     m_filePathHint;
    static const std::map<ArchitectureEnum_t, const char*> m_architectures;
};

class ShowArchiveHeadersHandler
{
public:
    static void Process(ObjdumpConfig& config);

    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_showArchiveHeadersHint;
    static const char* m_objdumpFlag;
    static bool        m_active;
};

class AdjustVmaOffsetHandler
{
public:
    static void Process(ObjdumpConfig& config);

    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_hint;
    static const char* m_objdumpFlag;
    static int         m_offset;
};

class DemangleHandler
{
public:
    static void Process(ObjdumpConfig& config);

    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_hint;
    static const char* m_objdumFlag;
    static bool        m_active;
};

class ShowDebugInfoHandler
{
public:
    static void Process(ObjdumpConfig& config);

    static std::ostream& ToString(std::ostream& os);


private:
    static const char* m_hint;
    static const char* m_ctagHint;
    static const char* m_objdumpFlag;
    static const char* m_objdumpFlagCtag;
    static bool        m_debActive;
    static bool        m_debCtagActive;
};

class DisassembleHandler
{
public:
    static void Process(ObjdumpConfig& config);

    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_disassembleHint;
    static const char* m_disassembleAllHint;
    static const char* m_disassembleFlag;
    static const char* m_disassembleAllFlag;
    static bool        m_disActive;
    static bool        m_disAllActive;
};

class PrefixAddressesHandler
{
public:
    static void Process(ObjdumpConfig& config);

    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_hint;
    static const char* m_flag;
    static bool        m_active;
};

class EndiannessHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char*                             m_hint;
    static std::map<EndiannessEnum_t, const char*> m_flags;
    static std::map<EndiannessEnum_t, const char*> m_labels;
    static EndiannessEnum_t                        m_currentSelection;
};

class ShowFileOffsetHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_hint;
    static const char* m_flag;
    static bool        m_active;
};

class ShowFileStartContextHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_hint;
    static const char* m_flag;
    static bool        m_active;
};

class ShowInfoFromHeaderHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_hint;
    static const char* m_flag;
    static bool        m_active;
};

class ShowInfoFromSectionHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_hint;
    static const char* m_flag;
    static bool        m_active;
};

class DisassemblerOptionHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char*        m_hint;
    static ArchitectureEnum_t m_arch;

    static std::map<ArchitectureEnum_t, const char*> m_archLabels;
};

class ArcDisassemblerOptionsHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_dspHint;
    static const char* m_spfpHint;
    static const char* m_dpfpHint;
    static const char* m_quarkse_emHint;
    static const char* m_fpudaHint;
    static const char* m_fpusHint;
    static const char* m_fpudHint;
    static const char* m_displayAsHexHint;

    static const char* m_dspFlag;
    static const char* m_spfpFlag;
    static const char* m_dpfpFlag;
    static const char* m_quarkse_emFlag;
    static const char* m_fpudaFlag;
    static const char* m_fpusFlag;
    static const char* m_fpudFlag;
    static const char* m_displayAsHexFlag;

    static bool m_dspActive;
    static bool m_spfpActive;
    static bool m_dpfpActive;
    static bool m_quarkse_emActive;
    static bool m_fpudaActive;
    static bool m_fpusActive;
    static bool m_fpudActive;
    static bool m_displayAsHexActive;
};

class ArmDisassemblerOptionsHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_registerNameSetHint;
    static const char* m_forceThumbHint;
    static const char* m_cpuIsaHint;

    static const char* m_registerNameSetFlag;
    static const char* m_forceThumbFlag;
    static const char* m_cpuIsaFlag;

    static ArmRegisterNameSetEnum_t m_registerNameSet;
    static bool                     m_forceThumb;
    static std::string              m_cpuIsa;

    static std::map<ArmRegisterNameSetEnum_t, const char*> m_regNameSetLabels;
    static std::map<ArmRegisterNameSetEnum_t, const char*> m_regNameSetFlags;
};

class Aarch64DisassemblerOptionsHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_disassembleIntoGenericInstructionHint;
    static const char* m_disassembleIntoGenericInstructionFlag;
    static bool        m_disassembleIntoGenericInstruction;
};

class x86DisassemblerOptionsHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_architectureHint;
    static const char* m_syntaxHint;
    static const char* m_isaHint;
    static const char* m_addrSizeHint;
    static const char* m_dataSizeHint;
    static const char* m_displaySuffixHint;

    static const char* m_displaySuffixFlag;

    static x86DisassemblyArchitectureEnum_t m_architecture;
    static x86SyntaxModeEnum_t              m_syntax;
    static x86IsaEnum_t                     m_isa;
    static x86AddrSizeEnum_t                m_addrSize;
    static x86DataSizeEnum_t                m_dataSize;
    static bool                             m_displaySuffix;

    static std::map<x86DisassemblyArchitectureEnum_t, const char*> m_archLabels;
    static std::map<x86SyntaxModeEnum_t, const char*>              m_syntaxLabels;
    static std::map<x86IsaEnum_t, const char*>                     m_isaLabels;
    static std::map<x86AddrSizeEnum_t, const char*>                m_addrSizeLabels;
    static std::map<x86DataSizeEnum_t, const char*>                m_dataSizeLabels;

    static std::map<x86DisassemblyArchitectureEnum_t, const char*> m_archFlags;
    static std::map<x86SyntaxModeEnum_t, const char*>              m_syntaxFlags;
    static std::map<x86IsaEnum_t, const char*>                     m_isaFlags;
    static std::map<x86AddrSizeEnum_t, const char*>                m_addrSizeFlags;
    static std::map<x86DataSizeEnum_t, const char*>                m_dataSizeFlags;
};

class PowerPcDisassemberOptionsHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_useRawHint;
    static const char* m_cpuIsaHint;
    static const char* m_enable64BitsHint;
    static const char* m_useAltivecHint;
    static const char* m_useAnyHint;
    static const char* m_useHtmHint;
    static const char* m_useVsxHint;
    static const char* m_useSpeHint;

    static const char* m_useRawFlag;
    static const char* m_enable64BitsFlag;
    static const char* m_disable64BitsFlag;
    static const char* m_useAltivecFlag;
    static const char* m_useAnyFlag;
    static const char* m_useHtmFlag;
    static const char* m_useVsxFlag;
    static const char* m_useSpeFlag;

    static bool         m_useRaw;
    static PpcCpuEnum_t m_cpuIsa;
    static bool         m_enable64Bits;
    static bool         m_useAltivec;
    static bool         m_useAny;
    static bool         m_useHtm;
    static bool         m_useVsx;
    static bool         m_useSpe;

    static std::map<PpcCpuEnum_t, const char*> m_cpuIsaLabels;
};

class MipsDisassemlerOptionsHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_useRawMnemonicHint;
    static const char* m_disassembleMsaHint;
    static const char* m_disassembleVirtHint;
    static const char* m_disassembleXpaHint;
    static const char* m_gprNamesAbiHint;
    static const char* m_fprNamesAbiHint;
    static const char* m_cp0ArchNameHint;
    static const char* m_hwrArchNameHint;
    static const char* m_regNamesAbiHint;
    static const char* m_regArchNameHint;

    static const char* m_useRawMnemonicFlag;
    static const char* m_disassembleMsaFlag;
    static const char* m_disassembleVirtFlag;
    static const char* m_disassembleXpaFlag;
    static const char* m_gprNamesAbiFlag;
    static const char* m_fprNamesAbiFlag;
    static const char* m_cp0ArchNameFlag;
    static const char* m_hwrArchNameFlag;
    static const char* m_regNamesAbiFlag;
    static const char* m_regArchNameFlag;

    static bool        m_useRawMnemonic;
    static bool        m_disassembleMsa;
    static bool        m_disassembleVirt;
    static bool        m_disassembleXpa;
    static std::string m_gprNamesAbi;
    static std::string m_fprNamesAbi;
    static std::string m_cp0ArchName;
    static std::string m_hwrArchName;
    static std::string m_regNamesAbi;
    static std::string m_regArchName;
};

class ShowFormatSpecificInfoHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_hint;
    static const char* m_paramHint;
    static const char* m_flag;
    static const char* m_paramFlag;

    static bool        m_active;
    static std::string m_param;
};

class ShowRelocEntriesHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_relocHint;
    static const char* m_dynamicRelocHint;
    static const char* m_relocFlag;
    static const char* m_dynamicRelocFlag;

    static bool m_reloc;
    static bool m_dynamicReloc;
};

class ShowAllContentHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_hint;
    static const char* m_flag;
    static const char* m_label;
    static bool        m_active;
};

class ShowSourceHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_showSourceLabel;
    static const char* m_prefixLabel;

    static const char* m_showSourceHint;
    static const char* m_prefixHint;

    static const char* m_showSourceFlag;
    static const char* m_prefixFlag;

    static bool        m_showSource;
    static std::string m_prefix;
};

class PathHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_prefixLabel;
    static const char* m_stripLabel;
    static const char* m_prefixHint;
    static const char* m_stripHint;
    static const char* m_prefixFlag;
    static const char* m_stripFlag;

    static std::string m_prefix;
    static int         m_strip;
    static bool        m_showSource;
};

class ShowRawInstructionHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_label;
    static const char* m_widthLabel;
    static const char* m_hint;
    static const char* m_widthHint;
    static const char* m_flag;
    static const char* m_widthFlag;

    static bool m_active;
    static int  m_width;
};

class VisualizeJumpsHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_label;
    static const char* m_hint;
    static const char* m_flag;

    static bool m_active;
};

class DwarfOptionsHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static void AssignPtrs(ObjdumpConfig& config);

private:
    static const char* m_label;
    static const char* m_hint;
    static const char* m_flag;

    static const char* m_depthLabel;
    static const char* m_depthHint;
    static const char* m_depthFlag;

    static const char* m_startLabel;
    static const char* m_startHint;
    static const char* m_startFlag;

    static const char* m_checkLabel;
    static const char* m_checkHint;
    static const char* m_checkFlag;

    struct Option
    {
        const char* label;
        const char* hint;
        const char* flag;
        bool*       active = nullptr;

        Option(const char* l, const char* h, const char* f) : label(l), hint(h), flag(f) {}
    };

    static std::array<Option, 21> m_options;

    static DwarfDisplayOptions* m_config;
};

class CtfSectionHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_sectionNameLabel;
    static const char* m_sectionNameHint;
    static const char* m_sectionNameFlag;

    static const char* m_sectionParentLabel;
    static const char* m_sectionParentHint;
    static const char* m_sectionParentFlag;

    static std::string m_sectionName;
    static std::string m_sectionParent;
};

class ShowFullSectionContentHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_label;
    static const char* m_hint;
    static const char* m_flag;

    static bool m_active;
};

class AddressRangeHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_startAddrLabel;
    static const char* m_startAddrHint;
    static const char* m_startAddrFlag;
    static const char* m_stopAddrLabel;
    static const char* m_stopAddrHint;
    static const char* m_stopAddrFlag;

    static int m_startAddr;
    static int m_stopAddr;
};

class ShowSymbolTableAsSymsHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_symsLabel;
    static const char* m_symsHint;
    static const char* m_symsFlag;
    static const char* m_dynSymsLabel;
    static const char* m_dynSymsHint;
    static const char* m_dynSymsFlag;
    static const char* m_specSymsLabel;
    static const char* m_specSymsHint;
    static const char* m_specSymsFlag;

    static bool m_syms;
    static bool m_dynSyms;
    static bool m_specSyms;
};

class ExtraFormatOptionsHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_fmtForWideLabel;
    static const char* m_fmtForWideHint;
    static const char* m_fmtForWideFlag;

    static bool m_fmtForWide;
};

class ShowAllHeadersHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_label;
    static const char* m_hint;
    static const char* m_flag;

    static bool m_active;
};

class DisassembleZerosHandler
{
public:
    static void          Process(ObjdumpConfig& config);
    static std::ostream& ToString(std::ostream& os);

private:
    static const char* m_label;
    static const char* m_hint;
    static const char* m_flag;

    static bool m_active;
};

/* Have a wonderful day :) */
#endif /* _ObjdumpConfigUI */
/**
 * @}
 */
/****** END OF FILE ******/
