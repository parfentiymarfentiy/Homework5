#include <iostream>
using namespace std;

int main() {
    int rows = 5;
    int cols = 5;

    int** arr = new int* [rows];

    for (int i = 0; i < rows; i = i + 1) {
        arr[i] = new int[cols];
    }

    for (int i = 0; i < rows; i = i + 1) {
        for (int j = 0; j < cols; j = j + 1) {
            arr[i][j] = 0;
        }
    }

    for (int i = 0; i < rows; i = i + 1) {
        for (int j = 0; j < cols; j = j + 1) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < rows; i = i + 1) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}