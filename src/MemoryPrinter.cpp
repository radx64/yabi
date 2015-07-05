#include "MemoryPrinter.hpp"
#include <iostream>
#include <iomanip>


void MemoryPrinter::print(const std::vector<uint32_t>& memory, uint16_t howMuchLines)
{
    std::cout << std::hex << std::uppercase;

    std::cout << "     ";

    for(uint16_t index=0; index<= 0xF; ++index)
    {
        std::cout << std::setw(4)  << index << " ";
    } 

    std::cout << std::endl<< "....";

     for(uint16_t index=0; index<= 0xF; ++index)
    {
        std::cout << "----" << "|";
    } 
             
    std::cout << std::endl;
    for  (uint16_t line=0; line<howMuchLines; ++line)
    {
        std::cout << "0x" << line << ": ";
        for(uint16_t index=0; index<= 0xF; ++index)
        {
            std::cout << std::setw(4) << memory[index+line*0xF] << " ";
        }
        std::cout << std::endl;
    }
}

void MemoryPrinter::print(const std::vector<uint32_t>& memory)
{
    MemoryPrinter::print(memory, 0x10);
}