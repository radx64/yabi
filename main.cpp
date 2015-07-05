#include <iostream>
#include <exception>
#include <cstdint>

#include "Interpreter.hpp"
#include "MemoryPrinter.hpp"

int main(int argc, char** argv)
{
    Interpreter in;
    in.load("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.");
    
    try
    {
        in.run();
    }
    catch (std::string e)
    {
        std::cout << "Exception was thrown: " << e <<std::endl;
    }

    std::cout << "Output:" << std::endl;
    std::cout <<in.getOutput() <<std::endl;

    std::cout << "Memory after run:" << std::endl;
    MemoryPrinter printer;
    printer.print(in.getMemory(),4);
    return 0;
}