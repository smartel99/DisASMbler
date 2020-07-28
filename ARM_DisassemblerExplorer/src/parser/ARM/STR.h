/**
 * @addtogroup  ARM
 * @{
 * @file        STR.h
 * @author      Pascal-Emmanuel Lachance
 * @p           https://www.github.com/Raesangur
 * @date        2020/07/24  -  20:10
 *
 * @brief       The STR instruction is a single data transfer instruction used to store a single
 *              byte or a word of data.
 */
#pragma once
/*************************************************************************************************/
/* Includes ------------------------------------------------------------------------------------ */
#include "parser/ARM/ARM_Instruction.h"

#include <string_view>


namespace ARM
{


/*************************************************************************************************/
/* Static variables ---------------------------------------------------------------------------- */
static constexpr std::string_view c_syntax{"<STR> {cond} {B} {T} {Rd}, <Address>"};
static Parser::ARM_InstructionSyntax STR_syntax{c_syntax};


/*************************************************************************************************/
/* Classes ------------------------------------------------------------------------------------- */
class STR : public Parser::ARM_Instruction
{
public:
    STR() : Parser::ARM_Instruction{&STR_syntax} {}
    STR(const std::string_view lineOfCode) : Parser::ARM_Instruction{&STR_syntax}
    {
        /* Split line into to dictionary */
    }
};

/*************************************************************************************************/
}    // namespace ARM
/**
 * @}
 */
/* ----- END OF FILE ----- */
