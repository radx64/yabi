#ifndef DEBUGGER_HPP_
#define DEBUGGER_HPP_

#include <iostream>
#include <memory>

#include "IInterpreter.hpp"

class Debugger
{
public:
	Debugger(std::shared_ptr<IInterpreter> interpreter);
	void run();

private:
	void clearScreen();
	void printProgramScope();
	void printMemoryScope();
	void printOutputBuffer();
	std::shared_ptr<IInterpreter> interpreter_;

};

#endif  // DEBUGGER_HPP_