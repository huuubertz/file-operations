#ifndef _FILE_H
#define _FILE_H

#include<iostream>
#include<fstream>
#include<string>

std::ifstream* _get_descriptor_from_file_to_read(std::string _directory);
void _get_data_from_file_to_read(std::ifstream* _address);


#endif