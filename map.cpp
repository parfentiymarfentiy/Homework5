#include "Dictionary.h"


int main() {
	Dictionary d;
	while (true) {
		system("cls");
		int chose;
		cout << "1)add pair" << endl;
		cout << "2)Print dictionary" << endl;
		cout << "3)Dell pair" << endl;
		cout << "4)Change value" << endl;
		cout << "5)Change key" << endl;
		cout << "6)Save file" << endl;
		cout << "7)Load from file" << endl;

			
		cin >> chose;
		cin.ignore();

		switch (chose) {
		case 1:system("cls"); d.add_pare(); break;
		case 2:system("cls"); d.print_dictionary();cin.ignore(); break;
		case 3:system("cls");d.dell_pair();break;
		case 4:system("cls");d.change_value();break;
		case 5:system("cls");d.change_key();break;
		case 6:system("cls");d.save_to_file("FILE.txt"); break;
		case 7:system("cls");d.load_from_file("FILE.txt"); break;
		}

}
}