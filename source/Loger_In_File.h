#pragma once
#include <ostream>
#include"Observer.h"
#include "Accumulator_Commands.h"

class Loger_In_File :public Observer
{
public:
	
	static Loger_In_File& create_file_logger() {
		 Loger_In_File logger;
		return logger;
	}
	void set_data(Accumulator_Commands* accumulate_for_file);
	void notify();

private:
	Loger_In_File() = default;
	Loger_In_File(Loger_In_File const&);
	Loger_In_File& operator=(Loger_In_File const&)=delete;
	~Loger_In_File() = default;
};
