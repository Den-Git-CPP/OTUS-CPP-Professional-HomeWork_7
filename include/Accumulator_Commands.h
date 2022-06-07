#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>

#include"Observer.h"

class Accumulator_Commands
{
public:
	Accumulator_Commands(int commands_in_pull)
		: _number_commands_in_pull{commands_in_pull} {
		clear_bulk();
	};
	~Accumulator_Commands() {};

	bool empty();
	void add_commands();
	void clear_bulk();
	void out_and_clear_bulk();
	void work_with_commands();

	void add_subscriber(Observer* ob);
	void remove_subscriber(Observer* ob);
	void notify_subscriber();

private:
	Accumulator_Commands() = default;
	int _number_commands{0};
	int _number_commands_in_pull{0};
	int _number_brackets{0};
	long long int _time_first_command{0};
	std::string _commands{};
	std::vector<std::string> _all_commands;

	std::vector<Observer*> subscriber;

};