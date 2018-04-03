// writing on a text file
#include <iostream>
#include <fstream>
#include <string>
#include "FILE.h"
#include <stdio.h>

using namespace std;


int* value(){
	int x = 6;
	return &x;
}

int main() {
	// zadanie 8.2.1
	//cout << _get_descriptor_from_file_to_read("autko") << endl;
	// zadanie 8.2.2
	//_get_data_from_file_to_read(_get_descriptor_from_file_to_read("autko"));
	// zadanie 8.2.19
	/*
	int** _2d_array_data;
	int _row_count = 4;
	int _col_count = 4;
	_2d_array_data = new int*[_row_count];
	for (int i = 0; i < _row_count; i++){
		_2d_array_data[i] = new int[_col_count];
	}
	for (int i = 0; i < _row_count; i++){
		for (int j = 0; j < _row_count; j++){
			_2d_array_data[i][j] = i + j;
		}
	}

	_save_date_to_file("binaryfile", _2d_array_data, 3, 3);
	*/
	// zadanie 8.2.7
	// TO DO przeniesc do pliku .h i .cpp
	cout << _get_sum_from_file("liczby") << endl;

	system("pause");
	return 0;
}