#include <iostream>
#include <cstring>

class String {
private:
    char* data;
    int length;
public:
    String operator*(const String& other) const {
        char temp[256] = {0}; 
        int idx = 0;
        for (int i = 0; i < length; i++) {
            if (strchr(other.data, data[i]) != nullptr) {
                temp[idx++] = data[i];
            }
        }
        return String(temp);
    }

    String operator/(const String& other) const {
        char temp[256] = {0};
        int idx = 0;
        for (int i = 0; i < length; i++) {
            if (strchr(other.data, data[i]) == nullptr) {
                temp[idx++] = data[i];
            }
        }
        return String(temp);
    }

    void show() const {
        std::cout << data << std::endl;
    }
};