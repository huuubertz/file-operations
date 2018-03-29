#include "FILE.h"

std::ifstream* _get_descriptor_from_file_to_read(std::string _directory){

	static std::ifstream myfile(_directory + ".txt");

	return &myfile;
}


void _get_data_from_file_to_read(std::ifstream* _file){

	std::string line;
	if (_file->is_open())
	{
		while (getline(*_file, line))
		{
			std::cout << line << '\n';
		}
		_file->close();
	}

	else std::cout << "Unable to open file";
}
