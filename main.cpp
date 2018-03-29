// writing on a text file
#include <iostream>
#include <fstream>
#include <string>
#include "FILE.h"
#include <stdio.h>
#include <fcntl.h>

using namespace std;


int* value(){
	int x = 6;
	return &x;
}

int main() {

	cout << _get_descriptor_from_file_to_read("autko") << endl;
	_get_data_from_file_to_read(_get_descriptor_from_file_to_read("autko"));


	system("pause");
	return 0;
}