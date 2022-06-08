#pragma once
#include<iostream>
#include<vector>

#include"Observer.h"
#include "Accumulator_Commands.h"

class Logger_in_Console: public Observer
{
public:
	Logger_in_Console(Accumulator_Commands* loger) {
		loger->add_subscriber(this);
	}
	~Logger_in_Console() = default;

	void notify(const long long int& time_first_command,
				const std::vector<std::string>& v_stream_command);

private:
	long long int _time_first_command{0};
	Logger_in_Console() = default;
	Logger_in_Console(const Logger_in_Console& root) = delete;
	Logger_in_Console& operator=(const Logger_in_Console&) = delete;
	Logger_in_Console(Logger_in_Console&& root) = delete;
	Logger_in_Console& operator=(Logger_in_Console&&) = delete;
};
