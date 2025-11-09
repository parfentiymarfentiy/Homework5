#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string toLower(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

string cleanWord(const string& word) {
    string cleaned;
    for (char c : word) {
        if (isalpha(c) || c == '\'' || c == '-') {
            cleaned += tolower(c);
        }
    }
    return cleaned;
}

map<string, int> buildFrequencyDictionary(const string& filename) {
    map<string, int> freqDict;
    ifstream file(filename);
    string word;
    
    if (!file.is_open()) {
        cerr << "Помилка відкриття файлу: " << filename << endl;
        return freqDict;
    }
    
    while (file >> word) {
        string cleanedWord = cleanWord(word);
        if (!cleanedWord.empty()) {
            freqDict[cleanedWord]++;
        }
    }
    
    file.close();
    return freqDict;
}

void printAllWords(const map<string, int>& freqDict) {
    cout << "Частотний словник:" << endl;
    cout << "==================" << endl;
    for (const auto& pair : freqDict) {
        cout << "'" << pair.first << "': " << pair.second << " разів" << endl;
    }
    cout << endl;
}
