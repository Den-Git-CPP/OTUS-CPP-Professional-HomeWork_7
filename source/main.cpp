#include <iostream>
#include <sstream>
#include <vector>

class Accumulator_Commands {
public:
	Accumulator_Commands(int number_commands)
		: _number_commands {number_commands} {};

	~Accumulator_Commands() {};
	//void add_one_command();
	//void add_pull_command();
	void out_bulk();
	void clear_bulk();
	void out_and_clear_bulk();
	void process_commands();
private:
	int _number_commands {0};
	int number_brackets {0};
	std::string _line_commands {0};
	std::vector<std::string>_all_commands;
};
void Accumulator_Commands::out_bulk() {
	if (!_all_commands.empty()) {
		std::cout << "bulk:";
		for (auto elem : _all_commands) {
			std::cout << elem << " ";
		};
	}
	std::cout << '\n';
}
void Accumulator_Commands::clear_bulk() {
	_all_commands.clear();
};
void Accumulator_Commands::out_and_clear_bulk() {
	out_bulk();
	clear_bulk();
};
void Accumulator_Commands::process_commands() {
	while (std::cin) {
		for (int i = 0; i < _number_commands; i++) {
			std::getline(std::cin, _line_commands);

			if (std::cin.eof()) { break; }

			if (_line_commands == "{") {
				if (number_brackets == 0) {
					out_and_clear_bulk();
				}
				number_brackets++;
			}

			if (_line_commands == "}") {
				number_brackets--;
				if (number_brackets == 0) {
					out_and_clear_bulk();
				}
			}

			if ((_line_commands != "{") &&
				(_line_commands != "}") &&
				(!_line_commands.empty())){
				_all_commands.emplace_back(std::move(_line_commands));
			}

		}
		//print
		if (!_all_commands.empty()) {
			out_and_clear_bulk();
		}
	}
};

int main(int argc, char** argv) {
	std::stringstream number_arguments;
	int number_commands {0};

	if (argc <= 1) {
		number_arguments << "Incorrect number of arguments";
	}
	else
	{
		try {
			number_commands = std::stoi(argv[1]);
			if (number_commands <= 0) {
				std::cout << "Number of commands in bulk must be positive";
			}
		}
		catch (const std::exception& error_command) {
			std::cerr << error_command.what();
		}
	}
	Accumulator_Commands com(number_commands);
	com.process_commands();
	std::cin.get();
}
