#include "Dictionary.h"
#include <fstream>

void Dictionary::add_pare()
{
	string word1;
	string word2;

	cout << "write first world :";
	getline(cin, word1);
	cout << "write second world :";
	getline(cin, word2);

	this->dictionary[word1] = word2;


}

void Dictionary::dell_pair()
{
	string key;
	cout << "print key :";
	getline(cin, key);
	this->dictionary.erase(key);
}

void Dictionary::change_value()
{
	string key;
	string value;

	cout << "Print new value :";
	getline(cin, value);
	
	cout << "Print key :";
	getline(cin, key);

	this->dictionary[key] = value;


}

void Dictionary::change_key()
{
	string keyold;
	string keynew;
	string value;
	cout << "Write old key :";
	getline(cin, keyold);

	cout << "Write new key :";
	getline(cin, keynew);
	value = this->dictionary[keyold];
	this->dictionary.erase(keyold);
	this->dictionary[keynew] = value;


}

void Dictionary::print_dictionary()
{
	for (const auto& pair : this->dictionary) {
		cout << pair.first << " : " << pair.second << endl;
	}
}

void Dictionary::save_to_file(const string& filename) const
{
	ofstream out(filename);
	if (!out.is_open()) {
		cerr << "Error: cannot open file for writing." << endl;
		return;
	}

	for (const auto& pair : this->dictionary) {
		out << pair.first << '\t' << pair.second << '\n';
	}

	out.close();
	cout << "Dictionary saved to file: " << filename << endl;
}


void Dictionary::load_from_file(const string& filename)
{
	ifstream in(filename);
	if (!in.is_open()) {
		cerr << "Error: cannot open file for reading." << endl;
		return;
	}

	this->dictionary.clear(); 
	string key, value;

	while (getline(in, key, '\t') && getline(in, value)) {
		this->dictionary[key] = value;
	}

	in.close();
	cout << "Dictionary loaded from file: " << filename << endl;
}
