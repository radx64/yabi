#include "Interpreter.hpp"
#include <iostream>
#include <iomanip>
#include <exception>

void Interpreter::load(std::string program)
{
    program_ = program;
    output_.clear();
    memory_.clear();
    memory_.resize(memorySize_,0);
    memoryPointer_ = 0;
    programPointer_ = 0;
    std::cout << "Loaded program:" << std::endl;
    std::cout << program << std::endl;
}

void Interpreter::run()
{
    while(programPointer_<program_.size())
    {
        char command = program_[programPointer_];
        switch(command)
        {
            case '>' : increaseMemoryPointer();break;
            case '<' : decreaseMemoryPointer();break;
            case '+' : increaseMemoryAtPointer();break;
            case '-' : decreaseMemoryAtPointer();break;
            case '[' : beginLoop();break;
            case ']' : endLoop();break;
            case '.' : printChar();break;
            default  : throw std::string("Unknown operand: " + std::string(1,command));
        }
        ++programPointer_;
    }
}

std::vector<uint32_t>& Interpreter::getMemory()
{
    return memory_;
}

void Interpreter::printChar()
{
    output_ += std::string(1,memory_[memoryPointer_] % 255);
}

std::string Interpreter::getOutput()
{
    return output_;
}

void Interpreter::beginLoop()
{
    if (memory_[memoryPointer_] == 0)
    {
        loopLevelCount_ = 1;
        while (loopLevelCount_ > 0)
        {
            ++programPointer_;    

            if (program_[programPointer_] == '[')
            {
                ++loopLevelCount_;
            }
            if (program_[programPointer_] == ']')
            {
                --loopLevelCount_;
            }
        }
    }
}
void Interpreter::endLoop()
{
    if (memory_[memoryPointer_] != 0)
    {
        loopLevelCount_ = 1;
        while (loopLevelCount_ > 0)
        {
            --programPointer_;
            if (program_[programPointer_] == '[')
            {
                --loopLevelCount_;
            }
            if (program_[programPointer_] == ']')
            {
                ++loopLevelCount_;
            }    
        }
    }
}

void Interpreter::increaseMemoryPointer()
{
    if (memoryPointer_+1 < memorySize_)
    {
        ++memoryPointer_;
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
        --memoryPointer_;
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
