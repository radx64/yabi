#ifndef MEMORYPRINTER_HPP_
#define MEMORYPRINTER_HPP_
#include <vector>
#include <cstdint>

class MemoryPrinter
{
public:
    void print(const std::vector<uint32_t>& memory);
    void print(const std::vector<uint32_t>& memory, uint16_t howMuchLines);
};

#endif // MEMORYPRINTER_HPP_