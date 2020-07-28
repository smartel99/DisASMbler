/**
 * @addtogroup  Parser
 * @{
 * @file        Instruction.h
 * @author      Pascal-Emmanuel Lachance
 * @p           https://www.github.com/Raesangur
 * @date        2020/07/24  -  19:48
 *
 * @brief       Base pure virtual class onto which all assembly instructions are based.
 */
#pragma once
/*************************************************************************************************/
#include "parser/InstructionSyntax.h"

namespace Parser
{


/*************************************************************************************************/
/* Classes ------------------------------------------------------------------------------------- */
class Instruction
{
protected:
    InstructionSyntax* m_syntax = nullptr;

public:
    virtual ~Instruction() = 0 ;
};


/*************************************************************************************************/
}
/**
 * @}
 */
/* ----- END OF FILE ----- */
