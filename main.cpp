#include <iostream>
#include <cctype> 
using namespace std;

void removeCharAt(char* str, int index) {
    if (index < 0) return; 
    
    char* p = str + index;
    while (*p) {
        *p = *(p + 1);
        p++;
    }
}

void removeAllChars(char* str, char c) {
    char* dest = str;
    char* src = str;
    
    while (*src) {
        if (*src != c) {
            *dest = *src;
            dest++;
        }
        src++;
    }
    *dest = '\0';
}

void insertCharAt(char* str, int pos, char c) {
    char* p = str;
    while (*p) p++;
    p++;
    
    while (p > str + pos) {
        *p = *(p - 1);
        p--;
    }
    *(str + pos) = c;
}

void replaceDots(char* str) {
    char* p = str;
    while (*p) {
        if (*p == '.') *p = '!';
        p++;
    }
}

int countChar(const char* str, char c) {
    int count = 0;
    const char* p = str;
    while (*p) {
        if (*p == c) count++;
        p++;
    }
    return count;
}

void countChars(const char* str, int& letters, int& digits, int& others) {
    letters = digits = others = 0;
    const char* p = str;
    
    while (*p) {
        if (isalpha(*p)) letters++;
        else if (isdigit(*p)) digits++;
        else others++;
        p++;
    }
}

int main() {
    char str[100]; 

    cout << "1. Введіть рядок: ";
    cin.getline(str, 100);
    removeCharAt(str, 3);
    cout << "   Після видалення 3-го символу: " << str << endl;

    cout << "2. Введіть рядок: ";
    cin.getline(str, 100);
    removeAllChars(str, 'a');
    cout << "   Після видалення всіх 'a': " << str << endl;

    cout << "3. Введіть рядок: ";
    cin.getline(str, 100);
    insertCharAt(str, 2, 'X');
    cout << "   Після вставки 'X' на позицію 2: " << str << endl;
    
    cout << "4. Введіть рядок: ";
    cin.getline(str, 100);
    replaceDots(str);
    cout << "   Після заміни . на !: " << str << endl;

    cout << "5. Введіть рядок: ";
    cin.getline(str, 100);
    char c;
    cout << "   Введіть символ для підрахунку: ";
    cin >> c;
    cin.ignore(); 
    cout << "   Символ '" << c << "' зустрічається " << countChar(str, c) << " разів" << endl;

    cout << "6. Введіть рядок: ";
    cin.getline(str, 100);
    int letters, digits, others;
    countChars(str, letters, digits, others);
    cout << "   Літер: " << letters << ", цифр: " << digits << ", інших символів: " << others << endl;
    
    return 0;
}