#include "../Visitor.hpp"

#include "exceptions/NotImplementedException.hpp"

using namespace FooLang;

void Visitor::visitInstructions(FooParser::InstructionsContext *context)
{
    for (auto &instructionContext : context->instruction())
    {
        this->visitInstruction(instructionContext);
    }
}

void Visitor::visitInstruction(FooParser::InstructionContext *context)
{
    throw NotImplementedException();
}
