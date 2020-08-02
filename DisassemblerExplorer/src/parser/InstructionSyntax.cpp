/**************************************************************************************************
 * @addtogroup  Parser
 * {
 * @file        InstructionSyntax
 * @author      Pascal-Emmanuel Lachance
 * @date        2020/07/24  -  17:28
 * @brief       Pure virtual class making the base of the parsing engine to parse an instruction's
 *              assembly code.
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
/* Includes ------------------------------------------------------------------------------------ */
#include "InstructionSyntax.h"


namespace Parser
{


/*************************************************************************************************/
/* Private static variables -------------------------------------------------------------------- */
const InstructionSyntax::StringPair p_emptyMap{"",""};


/*************************************************************************************************/
/* Member functions definitions ---------------------------------------------------------------- */
InstructionSyntax::~InstructionSyntax() = default;

[[nodiscard]] std::string InstructionSyntax::GetToken(const std::string_view searchedToken) const
{
    for (const StringPair& token : m_instructionData)
    {
        /* Search the map's keys for the token */
        if (searchedToken == token.first)
        {
            return token.second;
        }
    }

    /* Return an empty string if the token wasn't found */
    return std::string("");
}


/*************************************************************************************************/
/* Non-member functions public definitions ----------------------------------------------------- */
const InstructionSyntax::StringPair& GetEmptySyntaxPair()
{
    return p_emptyMap;
}


/*************************************************************************************************/
}    // namespace Parser
/**
 * @}
 */
/* ----- END OF FILE ----- */
