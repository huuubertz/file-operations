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

void _save_date_to_file(std::string _directory, int** _2d_array_data, int _row_count, int _col_count){
	// OPEN file from directory
	std::ofstream myfile(_directory + ".txt");

	// INITIALIZE 2D array
	//_2d_array_data = new int*[_row_count];
	//for (int i = 0; i < _row_count; i++){
	//	_2d_array_data[i] = new int[_col_count];
	//}

	// SAVE data to file
	if (myfile.is_open())
	{
		int _int_bit;
		myfile << _row_count << ", " << _col_count << std::endl;
		for (int i = 0; i < _row_count; i++){
			for (int j = 0; j < _row_count; j++){
				std::bitset<8> x(_2d_array_data[i][j]);
				myfile << x << std::endl;
				myfile << (int)(x.to_ulong()) << std::endl;
				//myfile << _2d_array_data[i][j] << std::endl;
			}
		}

		myfile.close();
	}
	else std::cout << "Unable to open file";

}

int _get_sum_from_file(std::string _directory){
	std::ifstream myfile(_directory + ".txt");
	std::string line;

	if (myfile.is_open()){
		int suma = 0;
		while (getline(myfile, line)){
			std::cout << line << std::endl;
			for (int k = 0; k < line.length(); k++){
				if (line[k] == ' '){
					continue;
				}
				else{
					suma += std::stoi(&line[k]);
				}
			}
		}
		myfile.close();
		return suma;
	}

	else std::cout << "Unable to open file";
}

