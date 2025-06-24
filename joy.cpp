#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Film {
    char name[100];
    char date[20];
};

void addFilm(Film* films, int& count) {
    if (count >= 100) {
        cout << "Database is full!" << endl;
        return;
    }
    
    cout << "Enter film name: ";
    cin.ignore();
    cin.getline(films[count].name, 100);
    
    cout << "Enter film date: ";
    cin.getline(films[count].date, 20);
    
    count++;
    cout << "Film added successfully!" << endl;
}

void printFilms(Film* films, int count) {
    if (count == 0) {
        cout << "No films in database!" << endl;
        return;
    }
    
    for (int i = 0; i < count; i++) {
        cout << "------ FILM " << i+1 << " ------" << endl;
        cout << "Name: " << films[i].name << endl;
        cout << "Date: " << films[i].date << endl;
        cout << "--------------------" << endl;
    }
}

void saveToFile(Film* films, int count) {
    ofstream outFile("Films.txt");
    
    if (!outFile) {
        cout << "Error creating file!" << endl;
        return;
    }
    
    for (int i = 0; i < count; i++) {
        outFile << "------ FILM " << i+1 << " ------" << endl;
        outFile << "Name: " << films[i].name << endl;
        outFile << "Date: " << films[i].date << endl;
        outFile << "--------------------" << endl << endl;
    }
    
    outFile.close();
    cout << "Database saved to Films.txt successfully!" << endl;
}

int main() {
    Film films[100];
    int count = 0;
    int choice;
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Add film\n";
        cout << "2. Show all films\n";
        cout << "3. Save to file\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                addFilm(films, count);
                break;
            case 2:
                printFilms(films, count);
                break;
            case 3:
                saveToFile(films, count);
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);
    
    return 0;
}