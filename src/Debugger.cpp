#include "Debugger.hpp"
#include <iomanip>
#include <unistd.h>

Debugger::Debugger(std::shared_ptr<IInterpreter> interpreter)
: interpreter_(interpreter)
{}

void Debugger::clearScreen()
{
    std::cout << "\E[H\E[2J";   
}

void Debugger::printProgramScope()
{
    const int32_t scopeSize = 15;
    std::string program = interpreter_->getProgram();
    int32_t pc = interpreter_->getProgramPointer();
    std::cout << "Program pointer: " << pc << std::endl;
    for(int32_t iter = 0; iter < scopeSize; ++iter)
    {
        std::cout << "    ";    
    }
    std::cout << "  ↓" << std::endl;

    for(int32_t index = pc - scopeSize; index<pc; ++index)
    {
        if (index >= 0)
        {
            std::cout <<"  "<< program[index] << " ";
        }
        else
        {
            std::cout << "    ";
        }
    }
    for(int32_t index = pc; index<(pc + scopeSize) && index < program.size(); ++index)
    {
        std::cout <<"  "<< program[index] << " ";
    }
    std::cout << std::endl << std::endl;
}

void Debugger::printMemoryScope()
{
    const int32_t scopeSize = 15;
    std::vector<uint32_t> memory = interpreter_->getMemory();
    int32_t mp = interpreter_->getMemoryPointer();
    std::cout << "Memory pointer: "<< mp << std::endl;
    for(int32_t iter = 0; iter < scopeSize; ++iter)
    {
        std::cout << "    ";    
    }
    std::cout << "  ↓" << std::endl;

    for(int32_t index = mp - scopeSize; index<mp; ++index)
    {
        if (index >= 0)
        {
            std::cout << std::setw(3) << memory[index] << " ";
        }
        else
        {
            std::cout << "    ";
        }
    }
    for(int32_t index = mp; index<(mp + scopeSize) && index < memory.size(); ++index)
    {
        std::cout << std::setw(3) << memory[index] << " ";
    }
    std::cout << std::endl << std::endl;
}

void Debugger::printOutputBuffer()
{
    std::cout << "Output Buffer: " << interpreter_->getOutput() << std::endl;
}

void Debugger::run()
{
    while(interpreter_->getProgramPointer() < interpreter_->getProgram().size())
    {
        clearScreen();
        printProgramScope();
        printMemoryScope();
        printOutputBuffer();
        interpreter_->step();
        usleep(100000);
    }
}