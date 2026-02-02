#ifndef JSON_H
#define JSON_H

#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
#include"task.h"

void parsefile(const std::string& file_name, std::vector<Task>& tasks);
void write(const std::string& file_name, std::vector<Task>& tasks);

#endif