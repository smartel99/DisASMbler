/**************************************************************************************************
 * @addtogroup  Parser
 * {
 * @file        Instruction
 * @author      Pascal-Emmanuel Lachance
 * @date        2020/07/24  -  19:48
 * @brief       Base pure virtual class onto which all assembly instructions are based.
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

#include <memory>


namespace Parser
{


/*************************************************************************************************/
/* Classes ------------------------------------------------------------------------------------- */
class Instruction
{
protected:
    std::shared_ptr<InstructionSyntax> m_syntax{};
    std::string                        m_lineOfCode;

public:
    Instruction(std::shared_ptr<InstructionSyntax> syntax, const std::string_view lineOfCode)
    : m_lineOfCode{lineOfCode}, m_syntax{syntax}
    {
        CleanLineOfCode();
    }

    const std::string& GetLineOfCode() { return m_lineOfCode; }

private:
    [[nodiscard]] virtual const std::string_view GetRawInstructionSyntax() const = 0;
    void                                         CleanLineOfCode();
};


/*************************************************************************************************/
}    // namespace Parser
/**
 * @}
 */
/* ----- END OF FILE ----- */
