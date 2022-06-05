#pragma once
#include <iostream>
#include <sstream>
#include <vector>

class Accumulator_Commands {
public:
	Accumulator_Commands(int commands_in_pull)
		: _number_commands_in_pull{ commands_in_pull }
		, _number_commands{ commands_in_pull }
	{};

	~Accumulator_Commands() {};
	void out_bulk();
	void clear_bulk();
	void out_and_clear_bulk();
	void work_with_commands();

private:
	int _number_commands{ 0 };
	int _number_commands_in_pull{ 0 };
	int _number_brackets{ 0 };
	std::string _commands{};
	std::vector<std::string>_all_commands;
};