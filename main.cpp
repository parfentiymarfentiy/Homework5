#include <iostream>
#include "phonebook.h"

int main() {
    PhoneBook book;
    int choice;

    do {
        std::cout << "\n=== ТЕЛЕФОННА КНИГА ===\n";
        std::cout << "1. Додати контакт\n";
        std::cout << "2. Видалити контакт\n";
        std::cout << "3. Пошук контакту\n";
        std::cout << "4. Показати всі контакти\n";
        std::cout << "5. Зберегти у файл\n";
        std::cout << "6. Завантажити з файлу\n";
        std::cout << "0. Вихід\n";
        std::cout << "Вибір: ";
        std::cin >> choice;

        switch (choice) {
        case 1: book.addContact(); break;
        case 2: book.deleteContact(); break;
        case 3: book.searchContact(); break;
        case 4: book.showAllContacts(); break;
        case 5: book.saveToFile(); break;
        case 6: book.loadFromFile(); break;
        case 0: std::cout << "До побачення!\n"; break;
        default: std::cout << "Невірний вибір!\n";
        }
    } while (choice != 0);

    return 0;
}