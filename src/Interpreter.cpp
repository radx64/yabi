#include "Interpreter.hpp"
#include <iostream>
#include <iomanip>
#include <exception>

void Interpreter::load(std::string program)
{
    program_ = program;
    memory_.clear();
    memory_.resize(memorySize_,0);
    memoryPointer_ = 0;
    programPointer_ = 0;
}

void Interpreter::run()
{
    while(true)
    {
        char command = program_[programPointer_];
        switch(command)
        {
            case '>' : increaseMemoryPointer();break;
            case '<' : decreaseMemoryPointer();break;
            case '+' : increaseMemoryAtPointer();break;
            case '-' : decreaseMemoryAtPointer();break;
            default : throw std::string("Unknown operand: " + std::to_string(command));
        }
        ++programPointer_;
    }
}

void Interpreter::printMemory()
{
    for  (uint16_t line=0; line<4; ++line)
    {
        std::cout << "0x" << line << ": ";
        for(uint16_t index=0; index< 0xF; ++index)
        {
            std::cout << std::setw(2) << std::hex << memory_[index+line*0xF] << " ";
        }
        std::cout << std::endl;
    }
}

void Interpreter::increaseMemoryPointer()
{
    if (memoryPointer_+1 < memorySize_)
    {
        memoryPointer_+=1;
    }
    else
    {
        throw std::string("Out of memory!");
    }
}
void Interpreter::decreaseMemoryPointer()
{
    if (memoryPointer_ != 0)
    {
        memoryPointer_+=1;
    }
    else
    {
        throw std::string("Memory out of bounds!");
    }
}
void Interpreter::increaseMemoryAtPointer()
{
    ++memory_[memoryPointer_];
}
void Interpreter::decreaseMemoryAtPointer()
{
    --memory_[memoryPointer_];
}
