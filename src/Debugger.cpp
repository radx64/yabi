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

std::string Debugger::askForCommand()
{
    std::cout << std::endl << ":";
    std::string command;
    std::getline(std::cin, command);
    return command;
}

void Debugger::printHelp()
{
    std::cout << "Help!" << std::endl;
    std::cout << "help [h] - displays this help" << std::endl;
    std::cout << "reset    - reset state of interpreter" << std::endl;
    std::cout << "run  [r] - run program" << std::endl;
    std::cout << "step [s] - execute single instruction" << std::endl;
    std::cout << "quit [q] - quit program" << std::endl << std::endl;
    std::cout << "Press ENTER to return to debugger" << std::endl;
    std::string waitForEnter;
    std::getline(std::cin, waitForEnter);
}

void Debugger::step()
{
    interpreter_->step();
}

void Debugger::runToEnd()
{
    while(interpreter_->getProgramPointer() < interpreter_->getProgram().size()-1)
    {
        clearScreen();
        printProgramScope();
        printMemoryScope();
        printOutputBuffer();
        interpreter_->step();
        usleep(50000);       
    }
}

void Debugger::execute(std::string command)
{
    if (command == "help" || command == "h")
    {
        printHelp();
    }
    else if (command == "step" || command == "s")
    {
        step();
    }
    else if (command == "run" || command == "r")
    {
        runToEnd();
    }
    else if (command == "quit" || command == "q")
    {
        command = "quit";
    }

    else if (command == "reset")
    {
        interpreter_->reset();
    }
    else
    {
        throw std::string("Unknown command " + command);
    }
}

void Debugger::run()
{
    std::string command;
    std::string lastException;

    while(command != "quit")
    {
        clearScreen();
        printProgramScope();
        printMemoryScope();
        printOutputBuffer();
        std::cout << lastException << std::endl;
        command = askForCommand();
        try
        {
            execute(command);
        }
        catch (std::string exception)
        {
            lastException = "Exception \"" + exception + "\" was thrown";
        }
    }
}