/**************************************************************************************************
 * @addtogroup  Parser
 * {
 * @file        ARM_InstructionSyntax
 * @author      Pascal-Emmanuel Lachance
 * @date        2020/07/24  -  18:24
 * @brief
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
/*************************************************************************************************/
#include "parser/ARM/ARM_InstructionSyntax.h"

#include <algorithm>
#include <array>
#include <iterator>
#include <sstream>


namespace Parser
{


/*************************************************************************************************/
/* Public member functions definitions --------------------------------------------------------- */
const typename ARM_InstructionSyntax::StringPair
ARM_InstructionSyntax::FindOperand(std::size_t index)
{
    if (index == 0)
    {
        index = 1;
    }

    for (const auto& token : m_instructionData)
    {
        /* Check to find a ',' character in the current key */
        if (token.first.find(',') != std::string::npos)
        {
            /* If there is, reduce the index and check if it is the desired one */
            if (--index == 0)
            {
                return StringPair{token};
            }
        }
    }
    return GetEmptySyntaxPair();
}

std::uint32_t ARM_InstructionSyntax::FindNumberOfOperands(const std::string& lineOfCode)
{
    if (lineOfCode.empty() == true)
    {
        return 0;
    }
    else
    {
        bool          inBrackets       = false;
        bool          previousWasSpace = false;
        std::uint32_t numberOfOperands = 0;

        for (char character : lineOfCode)
        {
            /* Check if the current character is still withing brackets */
            if (inBrackets)
            {
                if (character == ']')
                {
                    inBrackets = false;
                }
            }
            /* Try to find a space or special character, or bracket opening */
            else
            {
                if (character == ' ')
                {
                    /* Count the space only if the previous character wasn't also a space. */
                    if (previousWasSpace == false)
                    {
                        numberOfOperands++;
                        previousWasSpace = true;
                    }
                }
                else
                {
                    if (character == '[')
                    {
                        inBrackets = true;
                    }
                    else if (IsSpecialCharacter(character))
                    {
                        if (previousWasSpace == false)
                        {
                            /* Count the special character only if the previous character wasn't a
                             * space. */
                            numberOfOperands++;
                        }
                    }

                    previousWasSpace = false;
                }
            }
        }

        return numberOfOperands;
#if false
        /* From https://stackoverflow.com/a/3672259 */
        std::stringstream str{lineOfCode};
        using StringIteratorType = std::istream_iterator<std::string>;

        return std::distance(StringIteratorType {str}, StringIteratorType {});
#endif
    }
}

/*************************************************************************************************/
/* Private member functions definitions --------------------------------------------------------
 */
void ARM_InstructionSyntax::SplitInTokens(const std::string_view instructionSyntax)
{
    std::size_t firstPos = instructionSyntax.find_first_of("<{[");

    if (firstPos != std::string::npos)
    {
        /* Take the position of the end of the token */
        std::size_t secondPos = instructionSyntax.find_first_of(">}]");

        /* Add the token to the map */
        std::string token{instructionSyntax.substr(firstPos, ++secondPos - firstPos)};
        m_instructionData[token] = "";

        /* Recursion! */
        if (secondPos < instructionSyntax.length())
        {
            SplitInTokens(instructionSyntax.substr(secondPos + 1));
        }
    }
}

bool ARM_InstructionSyntax::IsSpecialCharacter(char character)
{
    static constexpr std::array specialCharacters{'!'};

    /* From : https://stackoverflow.com/a/19299555 + https://stackoverflow.com/a/19299719 */
    /* clang-format off */
    return std::any_of(specialCharacters.begin(), specialCharacters.end(),
                       [=](char c)
                       {
                            return character == c;
                       });
    /* clang-format on */
}

/*************************************************************************************************/
}    // namespace Parser
/**
 * @}
 */
/* ----- END OF FILE ----- */
