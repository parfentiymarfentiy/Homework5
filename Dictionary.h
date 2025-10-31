#include <iostream>
#include <string>
#include <map>
using namespace std;
#pragma once
class Dictionary
{
	map<string, string> dictionary;
public:
	void add_pare();
	void dell_pair();
	void change_value();
	void change_key();
	void print_dictionary();
	void save_to_file(const string& filename) const;
	void load_from_file(const string& filename);
};

