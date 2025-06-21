#include <iostream>
#include "film.h"

using namespace std;

int Film::totalFilms = 0;
const int Film::MAX_TITLE_LENGTH;

void addFilm(Film*& films, int& count) {
    Film* newFilms = new Film[count + 1];

    for (int i = 0; i < count; i++) {
        newFilms[i] = films[i];
    }

    newFilms[count].title = new char[Film::MAX_TITLE_LENGTH];
    newFilms[count].director = new char[50];
    newFilms[count].year = new int;
    newFilms[count].genre = new char[50];
    newFilms[count].rating = new float;
    
    cout << "Введіть назву фільму: ";
    cin.getline(newFilms[count].title, Film::MAX_TITLE_LENGTH);
    
    cout << "Введіть режисера: ";
    cin.getline(newFilms[count].director, 50);
    
    cout << "Введіть рік випуску: ";
    cin >> *newFilms[count].year;
    cin.ignore();
    
    cout << "Введіть жанр: ";
    cin.getline(newFilms[count].genre, 50);
    
    cout << "Введіть рейтинг: ";
    cin >> *newFilms[count].rating;
    cin.ignore();
    
    delete[] films;
    films = newFilms;
    count++;
    Film::totalFilms++;
}

void showAllFilms(const Film* films, int count) {
    if (count == 0) {
        cout << "Немає фільмів у бібліотеці.\n";
        return;
    }
    
    for (int i = 0; i < count; i++) {
        cout << "Фільм #" << i+1 << ":\n";
        cout << "Назва: " << films[i].title << endl;
        cout << "Режисер: " << films[i].director << endl;
        cout << "Рік: " << *films[i].year << endl;
        cout << "Жанр: " << films[i].genre << endl;
        cout << "Рейтинг: " << *films[i].rating << endl << endl;
    }
}

void showFilmByIndex(const Film* films, int count, int index) {
    if (index < 0 || index >= count) {
        cout << "Невірний індекс.\n";
        return;
    }
    
    cout << "Фільм #" << index+1 << ":\n";
    cout << "Назва: " << films[index].title << endl;
    cout << "Режисер: " << films[index].director << endl;
    cout << "Рік: " << *films[index].year << endl;
    cout << "Жанр: " << films[index].genre << endl;
    cout << "Рейтинг: " << *films[index].rating << endl;
}

void deleteAllFilms(Film*& films, int& count) {
    for (int i = 0; i < count; i++) {
        delete[] films[i].title;
        delete[] films[i].director;
        delete films[i].year;
        delete[] films[i].genre;
        delete films[i].rating;
    }
    delete[] films;
    films = nullptr;
    count = 0;
    Film::totalFilms = 0;
    cout << "Усі фільми видалено.\n";
}

void deleteFilmByIndex(Film*& films, int& count, int index) {
    if (index < 0 || index >= count) {
        cout << "Невірний індекс.\n";
        return;
    }
    
    Film* newFilms = new Film[count - 1];

    for (int i = 0; i < index; i++) {
        newFilms[i] = films[i];
    }

    for (int i = index + 1; i < count; i++) {
        newFilms[i-1] = films[i];
    }

    delete[] films[index].title;
    delete[] films[index].director;
    delete films[index].year;
    delete[] films[index].genre;
    delete films[index].rating;
    
    delete[] films;
    films = newFilms;
    count--;
    Film::totalFilms--;
    cout << "Фільм видалено.\n";
}

void searchFilms(const Film* films, int count) {
    if (count == 0) {
        cout << "Немає фільмів для пошуку.\n";
        return;
    }
    
    int choice;
    cout << "Пошук за:\n1. Режисером\n2. Жанром\n3. Роком\nВиберіть: ";
    cin >> choice;
    cin.ignore();
    
    char searchStr[50];
    int searchYear;
    
    switch (choice) {
        case 1:
            cout << "Введіть режисера: ";
            cin.getline(searchStr, 50);
            for (int i = 0; i < count; i++) {
                if (strcmp(films[i].director, searchStr) == 0) {
                    showFilmByIndex(films, count, i);
                }
            }
            break;
        case 2:
            cout << "Введіть жанр: ";
            cin.getline(searchStr, 50);
            for (int i = 0; i < count; i++) {
                if (strcmp(films[i].genre, searchStr) == 0) {
                    showFilmByIndex(films, count, i);
                }
            }
            break;
        case 3:
            cout << "Введіть рік: ";
            cin >> searchYear;
            cin.ignore();
            for (int i = 0; i < count; i++) {
                if (*films[i].year == searchYear) {
                    showFilmByIndex(films, count, i);
                }
            }
            break;
        default:
            cout << "Невірний вибір.\n";
    }
}

void freeMemory(Film*& films, int count) {
    deleteAllFilms(films, count);
}