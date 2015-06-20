#include <iostream>
#include <exception>

#include "Interpreter.hpp"

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

    in.printMemory();
    
    return 0;
}