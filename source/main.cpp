#include <iostream>
#include <sstream>
#include <vector>

int main(int argc, char** argv)
{
	std::stringstream num_arg;
	int num_commands {0};
	std:: vector<std::string> v_all_commands;

	if (argc <= 1) {
		num_arg << "Incorrect number of arguments";
	}
	else
	{
		num_commands = std::stoi(argv[1]);
		std::string line_commands; 

		for(int i=0; i < num_commands;i++){
		std::getline(std::cin, line_commands);
		v_all_commands.emplace_back(std::move(line_commands));
		}

		std::cout <<"bulk:";
		for(auto elem:v_all_commands){
			
			std::cout << elem<<" ";
			};
	}
	
		

	std::cin.get();
}
