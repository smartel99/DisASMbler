/**
 * @addtogroup  Parser
 * @{
 * @file        InstructionSyntax.h
 * @author      Pascal-Emmanuel Lachance
 * @p           https://www.github.com/Raesangur
 * @date        2020/07/24  -  17:12
 *
 * @brief       Pure virtual class making the base of the parsing engine to parse an instruction's
 *              assembly code. Each instruction should instantiate an object of a derived class of
 *              this base class.
 */
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
/**
 * @}
 */
/* ----- END OF FILE ----- */
