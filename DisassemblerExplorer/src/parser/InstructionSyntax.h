/**************************************************************************************************
 * @addtogroup  Parser
 * {
 * @file        InstructionSyntax
 * @author      Pascal-Emmanuel Lachance
 * @date        2020/07/24  -  17:12
 * @brief       Pure virtual class making the base of the parsing engine to parse an instruction's
 *              assembly code. Each instruction should instantiate an object of a derived class of
 *              this base class.
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
#include <map>
#include <string>
#include <string_view>


namespace Parser
{


/*************************************************************************************************/
/* Class --------------------------------------------------------------------------------------- */
class InstructionSyntax
{
protected:
    std::map<std::string, std::string> m_instructionData;

public:
    using StringPair = std::pair<std::string, std::string>;

    virtual ~InstructionSyntax() = 0;

    [[nodiscard]] std::string GetToken(const std::string_view searchedToken) const;

private:
    virtual void SplitInTokens(const std::string_view instructionSyntax) = 0;
};


/*************************************************************************************************/
/* Public functions declarations --------------------------------------------------------------- */
const InstructionSyntax::StringPair& GetEmptySyntaxPair();


/*************************************************************************************************/
}    // namespace Parser
/* ----- END OF FILE ----- */
