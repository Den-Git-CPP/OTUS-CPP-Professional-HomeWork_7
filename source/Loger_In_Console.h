#pragma once
#include <ostream>
#include"Observer.h"
#include "Accumulator_Commands.h"

class Loger_In_Console :public Observer
{
public:
	
	static Loger_In_Console& create_file_logger() {
		 Loger_In_Console logger;
		return logger;
	}
	void set_data(Accumulator_Commands* accumulate_for_console);
	void notify();

private:
	Loger_In_Console() = default;
	Loger_In_Console(Loger_In_Console const&);
	Loger_In_Console& operator=(Loger_In_Console const&)=delete;
	~Loger_In_Console() = default;
};
