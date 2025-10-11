#include <iostream>
#include <string>
using namespace std;

string compressText(string text) {
    string result;
    bool wasSpace = false;
    
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == ' ') {
            if (result.empty() || wasSpace) {
                result += ' ';
            }
            wasSpace = true;
        } else {
            if (wasSpace && !result.empty() && result.back() != ' ') {
                result += ' ';
            }
            result += text[i];
            wasSpace = false;
        }
    }
    return result;
}

string removeComments(string code) {
    string result;
    int n = code.length();
    
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && code[i] == '/' && code[i + 1] == '/') {
            while (i < n && code[i] != '\n') {
                i++;
            }
            if (i < n) result += code[i];
        }
        else if (i + 1 < n && code[i] == '/' && code[i + 1] == '*') {
            i += 2;
            while (i + 1 < n && !(code[i] == '*' && code[i + 1] == '/')) {
                i++;
            }
            i++;
        }
        else {
            result += code[i];
        }
    }
    return result;
}

string highlightPattern(string text, string pattern) {
    string result;
    int n = text.length();
    int m = pattern.length();
    
    for (int i = 0; i < n; i++) {
        bool match = true;
        for (int j = 0; j < m; j++) {
            if (i + j >= n || text[i + j] != pattern[j]) {
                match = false;
                break;
            }
        }
        if (match && m > 0) {
            result += "(" + pattern + ")";
            i += m - 1;
        } else {
            result += text[i];
        }
    }
    return result;
}

void parseFilePath(string path) {
    string pathOnly, lastFolder, filename, extension, nameOnly;
    
    int lastSlash = path.find_last_of("\\/");
    int lastDot = path.find_last_of(".");
    
    if (lastSlash != string::npos) {
        pathOnly = path.substr(0, lastSlash);
        filename = path.substr(lastSlash + 1);
        
        int prevSlash = pathOnly.find_last_of("\\/");
        if (prevSlash != string::npos) {
            lastFolder = pathOnly.substr(prevSlash + 1);
        } else {
            lastFolder = pathOnly;
        }
    } else {
        filename = path;
    }
    
    if (lastDot != string::npos && lastDot > lastSlash) {
        extension = path.substr(lastDot + 1);
        nameOnly = filename.substr(0, filename.find_last_of("."));
    } else {
        nameOnly = filename;
    }
    
    cout << "a) " << pathOnly << endl;
    cout << "b) " << lastFolder << endl;
    cout << "c) " << filename << endl;
    cout << "d) " << extension << endl;
    cout << "e) " << nameOnly << endl;
}
