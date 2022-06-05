#include "Accumulator_Commands.h"

void Accumulator_Commands::out_bulk() {
	if (!_all_commands.empty()) {
		std::cout << "\tbulk:";
		for (auto elem : _all_commands) {
			std::cout << elem << " ";
		};
		std::cout << '\n';
	}
}

void Accumulator_Commands::clear_bulk() {
	_all_commands.clear();
}

void Accumulator_Commands::out_and_clear_bulk() {
	out_bulk();
	clear_bulk();
	_number_commands = _number_commands_in_pull;
}

void Accumulator_Commands::work_with_commands() {
	while (std::cin) {
		while (0 < _number_commands) {
			std::getline(std::cin, _commands);

			if (std::cin.eof()) {
				break;
			}

			if ((_commands != "{") &&
				(_commands != "}") &&
				(!_commands.empty())) {
				_number_commands--;
				_all_commands.emplace_back(std::move(_commands));
			}

			if (_commands == "{") {
				if ((_number_brackets == 0) &&
					(_number_commands < _number_commands_in_pull)
					) {
					out_and_clear_bulk();
				}
				_number_brackets++;
				_number_commands += _number_brackets;
			}
			if (_commands == "}") {
				if (_number_brackets <= 0) {
					std::cerr << "Warning: Unexpected bracket\n";
				}
				else {
					_number_brackets--;
					if (_number_brackets <= 0) { out_and_clear_bulk(); }
				}
			}
		}

		if (_number_brackets == 0) {
			out_and_clear_bulk();
		}
	}
}
