#include <iostream>
#include <exception>
#include <cstdint>
#include <memory>

#include "Debugger.hpp"
#include "Interpreter.hpp"
#include "MemoryPrinter.hpp"

int main(int argc, char** argv)
{
    std::shared_ptr<Interpreter> in = std::make_shared<Interpreter>();
    in->load("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.");

    if (argc == 2 && std::string(argv[1]) == "debug")
    {
        Debugger debugger(in);
        debugger.run();
    }
    else
    {
        try
        {
            in->run();
            std::cout << "Output:" << std::endl;
            std::cout <<in->getOutput() <<std::endl;
        }
        catch (std::string e)
        {
            std::cout << "Exception was thrown: " << e <<std::endl;
        }
        std::cout << "Memory after run:" << std::endl;
        MemoryPrinter printer;
        printer.print(in->getMemory(),4);
    }


    
    
    





    return 0;
}