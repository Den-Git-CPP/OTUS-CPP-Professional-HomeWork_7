#include "Logger_in_File.h"

void Logger_in_File::notify(const long long int& time_first_command, const std::vector<std::string>& v_stream_command) {
	namespace fs = std::filesystem;
	if(!v_stream_command.empty()) {
		try {

			fs::path directory_with_log{"LOG/"};
			create_directories(directory_with_log);
			auto name_log_file = std::to_string(time_first_command) + ".log";
			auto path_log_file = directory_with_log / name_log_file;

			std::ofstream log_file{path_log_file};
			if(!log_file) {
				std::cerr << "OOPS, can't open \"" << path_log_file.string() << "\"\n";
			}

			log_file << std::to_string(time_first_command) + "\tbulk: ";
			for(auto elem : v_stream_command) {
				log_file << elem << ", ";
			};
			log_file << '\n';

		}
		catch(const fs::filesystem_error& e) {
			std::cerr << "EXCEPTION: " << e.what() << '\n';
			std::cerr << "    path1: \"" << e.path1().string() << "\"\n";
		}
	}
}
