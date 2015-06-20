#ifndef INTERPRETER_HPP_
#define INTERPRETER_HPP_

#include <string>
#include <vector>
#include <cstdint>

class Interpreter
{
public:
    void load(std::string program);
    void run();

    void printMemory();

private:

    void increaseMemoryPointer();
    void decreaseMemoryPointer();
    void increaseMemoryAtPointer();
    void decreaseMemoryAtPointer();

    void printChar();
    void beginLoop();
    void endLoop();

    const uint16_t memorySize_ = 30000;
    std::string program_;
    std::vector<uint32_t> memory_;
    uint32_t memoryPointer_;
    uint32_t programPointer_;
    uint32_t loopLevelCount_;
};

#endif // INTERPRETER_HPP_