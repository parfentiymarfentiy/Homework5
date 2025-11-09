#include <iostream>

class DynamicArray {
private:
    int* data;
    int currentSize;
    int currentCapacity;

    void resize(int newCapacity) {
        int* newData = new int[newCapacity];
        for (int i = 0; i < currentSize; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        currentCapacity = newCapacity;
    }

public:
    DynamicArray() : data(nullptr), currentSize(0), currentCapacity(0) {}

    DynamicArray(int capacity) : currentSize(0), currentCapacity(capacity) {
        data = new int[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    DynamicArray(const DynamicArray& other) {
        currentSize = other.currentSize;
        currentCapacity = other.currentCapacity;
        data = new int[currentCapacity];
        for (int i = 0; i < currentSize; i++) {
            data[i] = other.data[i];
        }
    }

    void add(int value) {
        if (currentSize >= currentCapacity) {
            int newCapacity = (currentCapacity == 0) ? 1 : currentCapacity * 2;
            resize(newCapacity);
        }
        data[currentSize] = value;
        currentSize++;
    }

    void remove(int index) {
        if (index < 0 || index >= currentSize) return;
        
        for (int i = index; i < currentSize - 1; i++) {
            data[i] = data[i + 1];
        }
        currentSize--;
    }

    int get(int index) {
        if (index < 0 || index >= currentSize) return 0;
        return data[index];
    }

    int size() {
        return currentSize;
    }

    int capacity() {
        return currentCapacity;
    }

    void print() {
        for (int i = 0; i < currentSize; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    int& operator[](int index) {
        return data[index];
    }

    DynamicArray operator+(const DynamicArray& other) {
        DynamicArray result(currentSize + other.currentSize);
        for (int i = 0; i < currentSize; i++) {
            result.add(data[i]);
        }
        for (int i = 0; i < other.currentSize; i++) {
            result.add(other.data[i]);
        }
        return result;
    }

    DynamicArray& operator+=(int value) {
        add(value);
        return *this;
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data;
            currentSize = other.currentSize;
            currentCapacity = other.currentCapacity;
            data = new int[currentCapacity];
            for (int i = 0; i < currentSize; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    bool operator==(const DynamicArray& other) {
        if (currentSize != other.currentSize) return false;
        for (int i = 0; i < currentSize; i++) {
            if (data[i] != other.data[i]) return false;
        }
        return true;
    }
};