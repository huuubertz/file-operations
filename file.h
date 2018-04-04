#ifndef _FILE_H
#define _FILE_H

#include<iostream>
#include<fstream>
#include<string>
#include <bitset>
#include <algorithm>
#include <vector>

std::ifstream* _get_descriptor_from_file_to_read(std::string _directory);
void _get_data_from_file_to_read(std::ifstream* _address);
void _save_date_to_file(std::string _directory, int** _2d_array_data, int x, int y);
int _get_sum_from_file(std::string _directory);
int _get_the_lowest_number_from_file(std::string _directory);
int** _save_date_from_file_to_2D_array(std::string _directory);

#endif