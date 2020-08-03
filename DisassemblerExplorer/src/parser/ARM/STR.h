/**************************************************************************************************
 * @addtogroup  ARM
 * {
 * @file        STR
 * @author      Pascal-Emmanuel Lachance
 * @date        2020/07/24  -  20:10
 * @brief       The STR instruction is a single data transfer instruction used to store a single
 *              byte or a word of data.
 **************************************************************************************************
 *   Copyright (C) 2020  Samuel Martel - Pascal-Emmanuel Lachance
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
 *************************************************************************************************/
#pragma once
/*************************************************************************************************/
/* Includes ------------------------------------------------------------------------------------ */
#include "parser/ARM/ARM_Instruction.h"

#include <string_view>


namespace ARM
{


/*************************************************************************************************/
/* Static variables ---------------------------------------------------------------------------- */
static constexpr std::string_view c_syntax{"<STR> {cond} {B} {T} {Rd}, <Address>"};


/*************************************************************************************************/
/* Classes ------------------------------------------------------------------------------------- */
class STR : public Parser::ARM_Instruction
{
public:
    STR() : Parser::ARM_Instruction{GetRawInstructionSyntax(), ""} {}
    STR(const std::string_view lineOfCode)
    : Parser::ARM_Instruction{GetRawInstructionSyntax(), lineOfCode}
    {
    }

private:
    [[nodiscard]] const std::string_view GetRawInstructionSyntax() const override
    {
        return c_syntax;
    }
};

/*************************************************************************************************/
}    // namespace ARM
/**
 * @}
 */
/* ----- END OF FILE ----- */
