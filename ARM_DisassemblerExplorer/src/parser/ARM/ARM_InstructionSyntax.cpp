/**
 * @addtogroup  Parser
 * @{
 * @file        ARM_InstructionSyntax.cpp
 * @author      Pascal-Emmanuel Lachance
 * @p           https://www.github.com/Raesangur
 * @date        2020/07/24  -  18:24
 *
 * @brief
 */
/*************************************************************************************************/
#include "parser/ARM/ARM_InstructionSyntax.h"


namespace Parser
{


/*************************************************************************************************/
/* Public member functions definitions --------------------------------------------------------- */
const typename ARM_InstructionSyntax::MappedType&
ARM_InstructionSyntax::FindOperand(std::size_t index)
{
    for (const auto& token : m_instructionData)
    {
        /* Check to find a ',' character in the current key */
        if (token.first.find(',') != std::string::npos)
        {
            /* If there is, reduce the index and check if it is the desired one */
            if (--index == 0)
            {
                return token;
            }
        }
    }
    return GetEmptySyntaxPair();
}

std::size_t ARM_InstructionSyntax::FindNumberOfOperands(const std::string_view lineOfCode)
{
    if (lineOfCode.empty() == true)
    {
        return 0;
    }


}

/*************************************************************************************************/
/* Private member functions definitions -------------------------------------------------------- */
void ARM_InstructionSyntax::SplitInTokens(const std::string_view instructionSyntax)
{
    std::size_t firstPos = instructionSyntax.find_first_of("<{[");

    if (firstPos != std::string::npos)
    {
        /* Take the position of the end of the token */
        std::size_t secondPos = instructionSyntax.find_first_of(">}]");

        /* Add the token to the map */
        std::string token {instructionSyntax.substr(firstPos, ++secondPos - firstPos)};
        m_instructionData[token] = "";

        /* Recursion! */
        if (secondPos < instructionSyntax.length())
        {
            SplitInTokens(instructionSyntax.substr(secondPos + 1));
        }
    }
}

/*************************************************************************************************/
}    // namespace Parser
/**
 * @}
 */
/* ----- END OF FILE ----- */
