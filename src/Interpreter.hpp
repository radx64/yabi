#ifndef INTERPRETER_HPP_
#define INTERPRETER_HPP_

#include "IInterpreter.hpp"

class Interpreter : public IInterpreter
{
public:
    void load(std::string program) override;
    void run() override;
    void step() override;

    std::vector<uint32_t>& getMemory() override;
    std::string getOutput() override;
    std::string getProgram() override;

    void increaseMemoryPointer() override;
    void decreaseMemoryPointer() override;
    void increaseMemoryAtPointer() override;
    void decreaseMemoryAtPointer() override;

    uint32_t getMemoryPointer() override;
    uint32_t getProgramPointer() override;

private:
    void printChar();
    void beginLoop();
    void endLoop();
    const uint16_t memorySize_ = 30000;
    std::string program_;
    std::vector<uint32_t> memory_;
    std::string output_;
    uint32_t memoryPointer_;
    uint32_t programPointer_;
    uint32_t loopLevelCount_;
};

#endif // INTERPRETER_HPP_