#include <iostream>
#include <exception>
#include <cstdint>
#include <memory>
#include <sstream>
#include <fstream>

#include "Debugger.hpp"
#include "Interpreter.hpp"
#include "MemoryPrinter.hpp"

int main(int argc, char** argv)
{
    std::shared_ptr<Interpreter> in = std::make_shared<Interpreter>();

    if (argc > 1)
    {
        std::ifstream file(argv[1]);
        std::stringstream buffer;
        buffer << file.rdbuf();
        in->load(buffer.str());
    }
    else
    {
        std::cout << "Not enough parameters. Usage: "<<argv[0] << " BF_file_name [debug]"<<std::endl;
        return 1;
    }

    if (argc == 3 && std::string(argv[2]) == "debug")
    {
        Debugger debugger(in);
        debugger.run();
    }
    else if(argc == 2)
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