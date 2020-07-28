/**
 * @addtogroup  Parser
 * @{
 * @file        ARM_InstructionSyntax.h
 * @author      Pascal-Emmanuel Lachance
 * @p           https://www.github.com/Raesangur
 * @date        2020/07/24  -  17:31
 *
 * @brief       Base of the ARM instruction set parsing engine.
 *              Each ARM instruction should instantiate an object of this class.
 */
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
    static std::size_t FindNumberOfOperands(const std::string& lineOfCode);

private:
    void SplitInTokens(const std::string_view instructionSyntax) override;
};


/*************************************************************************************************/
}    // namespace Parser
/**
 * @}
 */
/* ----- END OF FILE ----- */
