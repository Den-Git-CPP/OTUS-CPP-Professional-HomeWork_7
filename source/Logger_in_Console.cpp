#include "Logger_in_Console.h"

void Logger_in_Console::notify(const long long int& time_first_command, const std::vector<std::string>& v_stream_command) {
	if(!v_stream_command.empty()) {
		std::cout << "\tbulk: ";
		for(auto elem : v_stream_command) {
			std::cout << elem << ", ";
		};
		std::cout << '\n';
	}
}
