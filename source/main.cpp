#include <iostream>
#include <sstream>
#include <vector>
void print_bulk(const std::vector<std::string>& v_all_commands) {
	std::cout << "bulk:";
	for (auto elem : v_all_commands) {
		std::cout << elem << " ";
	};
	std::cout << '\n';
};

int main(int argc, char** argv) {
	std::stringstream num_arg;
	int num_commands {0};
	std::vector<std::string> v_all_commands;

	if (argc <= 1) {
		num_arg << "Incorrect number of arguments";
	}
	else
	{
		num_commands = std::stoi(argv[1]);
		std::string line_commands;
		while (!std::cin.eof() && line_commands != "EOF") {
			for (int i = 0; i < num_commands; i++) {
				std::getline(std::cin, line_commands);
				if (!std::cin.eof() && line_commands != "EOF") {
					v_all_commands.emplace_back(std::move(line_commands));
				}
				else {
					break;
				};
			};

			print_bulk(v_all_commands);
			v_all_commands.clear();
		}

	}
	std::cin.get();
}
