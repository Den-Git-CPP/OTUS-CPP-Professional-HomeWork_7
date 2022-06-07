#pragma once
#include<iostream>
#include <fstream>
#include<vector>
#include <filesystem>

#include"Observer.h"
#include "Accumulator_Commands.h"

class Logger_in_File: public Observer
{
public:
	Logger_in_File(Accumulator_Commands* loger) {
		loger->add_subscriber(this);
	}
	~Logger_in_File() = default;

	void notify(const long long int& time_first_command,
				const std::vector<std::string>& v_stream_command);
private:
	Logger_in_File() = default;
	Logger_in_File(const Logger_in_File& root) = delete;
	Logger_in_File& operator=(const Logger_in_File&) = delete;
	Logger_in_File(Logger_in_File&& root) = delete;
	Logger_in_File& operator=(Logger_in_File&&) = delete;
};
