/**************************************************************************************************
 * @addtogroup  Parser
 * {
 * @file        ARM_InstructionSyntax
 * @author      Pascal-Emmanuel Lachance
 * @date        2020/07/24  -  17:31
 * @brief       Base of the ARM instruction set parsing engine.
 *              Each ARM instruction should instantiate an object of this class.
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
#include "parser/InstructionSyntax.h"

#include <map>
#include <string>
#include <string_view>
#include <vector>


namespace Parser
{


/*************************************************************************************************/
/* Class --------------------------------------------------------------------------------------- */
class ARM_InstructionSyntax : public InstructionSyntax
{
public:
    ARM_InstructionSyntax(const std::string_view instructionSyntax)
    {
        /* Split instruction syntax in tokens */
        SplitInTokens(instructionSyntax);
    }
    ~ARM_InstructionSyntax() = default;

    const StringPair FindOperand(std::size_t index);

    static std::uint32_t FindNumberOfOperands(const std::string& lineOfCode);


private:
    void SplitInTokens(const std::string_view instructionSyntax) override;
    static bool IsSpecialCharacter(char character);
};


/*************************************************************************************************/
}    // namespace Parser
/**
 * @}
 */
/* ----- END OF FILE ----- */
