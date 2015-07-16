#ifndef IINTERPRETER_HPP_
#define IINTERPRETER_HPP_

#include <string>
#include <vector>
#include <cstdint>

class IInterpreter
{
public:
    virtual void load(std::string program) = 0;
    virtual void run() = 0;
    virtual void step() = 0;
    virtual void reset() = 0;

    virtual std::vector<uint32_t>& getMemory() = 0;
    virtual std::string getOutput() = 0;
    virtual std::string getProgram() = 0;

    virtual void increaseMemoryPointer() = 0;
    virtual void decreaseMemoryPointer() = 0;
    virtual void increaseMemoryAtPointer() = 0;
    virtual void decreaseMemoryAtPointer() = 0;

    virtual uint32_t getMemoryPointer() = 0;
    virtual uint32_t getProgramPointer() = 0;
};

#endif  // IINTERPRETER_HPP_