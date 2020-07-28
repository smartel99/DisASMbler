/**
 * @addtogroup  Parser
 * @{
 * @file        InstructionSyntax.cpp
 * @author      Pascal-Emmanuel Lachance
 * @p           https://www.github.com/Raesangur
 * @date        2020/07/24  -  17:28
 *
 * @brief       Pure virtual class making the base of the parsing engine to parse an instruction's
 *              assembly code.
 */
/*************************************************************************************************/
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
