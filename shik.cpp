#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void task1() {
    ifstream in("input1.txt");
    ofstream out("output1.txt");
    string line, prevLine;
    
    if (!in.is_open() || !out.is_open()) {
        cout << "File error" << endl;
        return;
    }
    
    while (getline(in, line)) {
        if (!prevLine.empty()) {
            out << prevLine << endl;
        }
        prevLine = line;
    }
    
    in.close();
    out.close();
}

void task2() {
    ifstream in("input2.txt");
    string line;
    int maxLen = 0;
    
    if (!in.is_open()) {
        cout << "File error" << endl;
        return;
    }
    
    while (getline(in, line)) {
        if (line.length() > maxLen) {
            maxLen = line.length();
        }
    }
    
    cout << "Longest line: " << maxLen << endl;
    in.close();
}

void task3() {
    ifstream in("input3.txt");
    string word, target;
    int count = 0;
    
    cout << "Enter word to count: ";
    cin >> target;
    
    if (!in.is_open()) {
        cout << "File error" << endl;
        return;
    }
    
    while (in >> word) {
        if (word == target) {
            count++;
        }
    }
    
    cout << "Word count: " << count << endl;
    in.close();
}

void task4() {
    ifstream in("input4.txt");
    ofstream out("output4.txt");
    string line, target, replacement;
    
    cout << "Enter word to replace: ";
    cin >> target;
    cout << "Enter replacement word: ";
    cin >> replacement;
    
    if (!in.is_open() || !out.is_open()) {
        cout << "File error" << endl;
        return;
    }
    
    while (getline(in, line)) {
        size_t pos = 0;
        while ((pos = line.find(target, pos)) != string::npos) {
            line.replace(pos, target.length(), replacement);
            pos += replacement.length();
        }
        out << line << endl;
    }
    
    in.close();
    out.close();
}

void task5() {
    ifstream in1("file1.txt"), in2("file2.txt");
    ofstream out("differences.txt");
    string line1, line2;
    int lineNum = 1;
    bool match = true;
    
    if (!in1.is_open() || !in2.is_open() || !out.is_open()) {
        cout << "File error" << endl;
        return;
    }
    
    while (getline(in1, line1) && getline(in2, line2)) {
        if (line1 != line2) {
            match = false;
            out << "Line " << lineNum << ":" << endl;
            out << "File1: " << line1 << endl;
            out << "File2: " << line2 << endl << endl;
        }
        lineNum++;
    }
    
    if (match) {
        out << "Files match" << endl;
    }
    
    in1.close();
    in2.close();
    out.close();
}

void task6() {
    ifstream in("input6.txt");
    ofstream out("output6.txt");
    string line;
    int key;
    
    cout << "Enter cipher key: ";
    cin >> key;
    
    if (!in.is_open() || !out.is_open()) {
        cout << "File error" << endl;
        return;
    }
    
    while (getline(in, line)) {
        for (char &c : line) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                c = (c - base + key) % 26;
                if (c < 0) c += 26;
                c += base;
            }
        }
        out << line << endl;
    }
    
    in.close();
    out.close();
}

int main() {
    int choice;
    cout << "Enter task number (1-6): ";
    cin >> choice;
    
    switch(choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        case 5: task5(); break;
        case 6: task6(); break;
        default: cout << "Invalid choice" << endl;
    }
    
    return 0;
}