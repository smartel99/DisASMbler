/**
 * @addtogroup  Parser
 * @{
 * @file        ARM_Instruction.h
 * @author      Pascal-Emmanuel Lachance
 * @p           https://www.github.com/Raesangur
 * @date        2020/07/24  -  19:51
 *
 * @brief       Base pure virtual class onto which all ARM assembly instructions are based.
 */
#pragma once
/*************************************************************************************************/
#include "parser/ARM/ARM_InstructionSyntax.h"
#include "parser/Instruction.h"

#include <string_view>


namespace Parser
{


/*************************************************************************************************/
/* Classes ------------------------------------------------------------------------------------- */
class ARM_Instruction : public Instruction
{
public:
    ARM_Instruction(ARM_InstructionSyntax* syntax)
    {
        m_syntax = syntax;
    }

    ARM_InstructionSyntax& GetSyntax()
    {
        return *dynamic_cast<ARM_InstructionSyntax*>(m_syntax);
    }
};


/*************************************************************************************************/
}    // namespace Parser
/**
 * @}
 */
/* ----- END OF FILE ----- */
