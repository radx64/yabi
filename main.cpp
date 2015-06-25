#include <iostream>
#include <exception>
#include <cstdint>

#include "Interpreter.hpp"
#include "MemoryPrinter.hpp"

int main(int argc, char** argv)
{
    std::cout << "Hello in World of YABI! " << argc << argv[0] <<std::endl;
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

    std::cout << "Memory after run:" << std::endl;
    MemoryPrinter printer;
    printer.print(in.getMemory());

    std::cout << "Output:" << std::endl;
    std::cout <<in.getOutput() <<std::endl;
    
    return 0;
}