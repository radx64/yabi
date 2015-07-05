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

    std::vector<uint32_t>& getMemory();
    std::string getOutput();

    void increaseMemoryPointer();
    void decreaseMemoryPointer();
    void increaseMemoryAtPointer();
    void decreaseMemoryAtPointer();
    void printChar();
    void beginLoop();
    void endLoop();

    uint32_t getMemoryPointer();
    uint32_t getProgramPointer();

private:
    const uint16_t memorySize_ = 30000;
    std::string program_;
    std::vector<uint32_t> memory_;
    std::string output_;
    uint32_t memoryPointer_;
    uint32_t programPointer_;
    uint32_t loopLevelCount_;
};

#endif // INTERPRETER_HPP_