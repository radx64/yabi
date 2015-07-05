#include <gtest/gtest.h>
#include "Interpreter.hpp"

class InterpreterShould : public ::testing::Test
{
public:
    InterpreterShould()
    {}

    Interpreter interpreter_;
};

TEST_F(InterpreterShould, haveMemoryPointerSetToZeroAfterLoad)
{
    interpreter_.load("");
    EXPECT_EQ(interpreter_.getMemoryPointer(),0);
}

TEST_F(InterpreterShould, haveProgramPointerSetToZeroAfterLoad)
{
    interpreter_.load("");
    EXPECT_EQ(interpreter_.getProgramPointer(),0);
}

TEST_F(InterpreterShould, increaseMemoryPointerShouldWork)
{
    interpreter_.load("");
    interpreter_.increaseMemoryPointer();
    EXPECT_EQ(interpreter_.getMemoryPointer(),1);
}

TEST_F(InterpreterShould, decreaseMemoryPointerShouldWork)
{
    interpreter_.load("");
    interpreter_.increaseMemoryPointer();
    interpreter_.decreaseMemoryPointer();
    EXPECT_EQ(interpreter_.getMemoryPointer(),0);
}

TEST_F(InterpreterShould, decreaseMemoryPointerBelowZeroShouldThrowException)
{
    interpreter_.load("");
    EXPECT_THROW(interpreter_.decreaseMemoryPointer(), std::string);
}


TEST_F(InterpreterShould, increaseMemoryAtPointerShouldWork)
{
    interpreter_.load("");
    interpreter_.increaseMemoryAtPointer();
    EXPECT_EQ(interpreter_.getMemory()[interpreter_.getMemoryPointer()],1);
}

TEST_F(InterpreterShould, decreaseMemoryAtPointerShouldWork)
{
    interpreter_.load("");
    interpreter_.decreaseMemoryAtPointer();
    EXPECT_EQ(interpreter_.getMemory()[interpreter_.getMemoryPointer()],-1);
}