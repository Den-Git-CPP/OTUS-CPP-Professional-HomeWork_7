#include <iostream>
#include <sstream>
#include <vector>

void print_bulk(const std::vector<std::string>& v_all_commands) {
	if (!v_all_commands.empty()) {
		std::cout << "bulk:";
		for (auto elem : v_all_commands) {
			std::cout << elem << " ";
		};
	}
	std::cout << '\n';
};

int main(int argc, char** argv) {
	std::stringstream num_arg;
	int num_commands {0}, number_brackets {0};
	std::vector<std::string> v_all_commands;

	if (argc <= 1) {
		num_arg << "Incorrect number of arguments";
	}
	else
	{
	//	num_commands = std::stoi(argv[1]);
		num_commands =20;
		std::string line_commands;

		while (std::cin) {
			for (int i = 0; i < num_commands; i++) {
				std::getline(std::cin, line_commands);
		
				if (std::cin.eof()) { break; }
					
					if (line_commands == "{") {
						if (number_brackets == 0) {
							print_bulk(v_all_commands);
							v_all_commands.clear();
						}
						number_brackets++;
						
					}
					if (line_commands == "}") {
							number_brackets--;
							if (number_brackets == 0) {
								print_bulk(v_all_commands);
								v_all_commands.clear();
							}
					}
					//add command
					if (
						(line_commands != "{")&&
						(line_commands != "}")&&
						(!line_commands.empty())
						)
					{
						v_all_commands.emplace_back(std::move(line_commands));
					}
					
			}
			//print
			if (!v_all_commands.empty()) {
				print_bulk(v_all_commands);
				v_all_commands.clear();
			}
		}
		
	}

	std::cin.get();
}
