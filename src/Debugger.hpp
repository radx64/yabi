#ifndef DEBUGGER_HPP_
#define DEBUGGER_HPP_

#include <iostream>
#include <memory>
#include <string>

#include "IInterpreter.hpp"

class Debugger
{
public:
    Debugger(std::shared_ptr<IInterpreter> interpreter);
    void run();

private:
    void clearScreen();
    void printProgramScope();
    void printMemoryScope();
    void printOutputBuffer();
    std::string askForCommand();
    void execute(std::string command);
    void printHelp();
    void step();
    void runToEnd();
    std::shared_ptr<IInterpreter> interpreter_;

};

#endif  // DEBUGGER_HPP_