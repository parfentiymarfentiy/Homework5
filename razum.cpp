#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <cstdio>
using namespace std;

void initArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = 1 + rand() % 50;
	}
}

bool printArrayToFile(FILE* descriptor, int arr[], int size) {
	if (descriptor == nullptr) {
		return false;
	}

	for (int i = 0; i < size; i++) {
		fprintf(descriptor, "%i Hello %i", arr[i], i);
		fprintf(descriptor, "\n");
	}
	return true;
}

int main() {
	srand(time(NULL));
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << h << endl;
	FILE* fileDescriptor = nullptr;

	if ((fileDescriptor = fopen("p-48.txt", "w")) == NULL) {
		cout << "File wasn't successfuly created";
	}
	else {
		cout << "File created!!!" << endl;
		int arr[10];
		initArray(arr, 10);
		bool result = printArrayToFile(fileDescriptor, arr, 10);
		result ? cout << "File write status: \033[42mOK\033[0m\n" : cout << "File write status: \033[41mOK\033[0m\n";
		fclose(fileDescriptor);
	}
	const char* path = "p-48.txt";
	int openResult = fopen_s(&fileDescriptor, path, "r");
	if (openResult == 0) {
		char line[255];
		while (fgets(line, sizeof(line), fileDescriptor)) {
			cout << line;
		}
		fclose(fileDescriptor);
	}
	return 0;
}