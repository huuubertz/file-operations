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

int _get_the_lowest_number_from_file(std::string _directory){
	std::ifstream myfile(_directory + ".txt");
	std::string line;

	if (myfile.is_open()){
		std::vector<int> _data_from_file;
		while (getline(myfile, line)){
			std::cout << line << std::endl;
			for (int k = 0; k < line.length(); k++){
				if (line[k] == ' '){
					continue;
				}
				else{
					_data_from_file.push_back(std::stoi(&line[k]));
				}
			}
		}
		std::sort(begin(_data_from_file), end(_data_from_file));

		myfile.close();
		return _data_from_file.front();
	}

	else std::cout << "Unable to open file";
}

void _save_date_from_file_to_2D_array(std::string _directory){
	std::ifstream* myfile = new std::ifstream(_directory);
	//myfile->open(_directory);
	int _idx = 0;
	std::vector <int> dimension;
	std::cout << dimension.empty() << std::endl;
	std::string line;


	if (myfile->is_open()){
		while (std::getline(*myfile, line)){
			//std::cout << line << std::endl;
			if (_idx == 0){
				for (int k = 0; k < line.length(); k++){
					if (line[k] == ','){
						continue;
					}
					else{
						dimension.push_back(std::stoi(&line[k]));
					}
					if (k == line.length() - 1){
						if (!(dimension.empty())){
							//std::cout << dimension.empty() << std::endl;
							// INITIALIZE 2D array
							int** _2d_array_data;
							_2d_array_data = new int*[dimension.front()];
							for (int i = 0; i < dimension.front(); i++){
								_2d_array_data[i] = new int[dimension.back()];
							}
						}
						else std::cout << "dimension array's are 0" << std::endl;
					}
				}
			}
			else{
				dimension.clear();
				std::bitset<8> x(line);
				dimension.push_back((int)(x.to_ulong()));
			}
			_idx++;
		}
		//std::cout << dimension.front() << std::endl;
		//std::cout << dimension.back() << std::endl;
		myfile->close();
	}
	else std::cout << "Unable to open file" << std::endl;

}

