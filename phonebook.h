#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "contact.h"

class PhoneBook {
private:
    Contact* contacts;
    int count;
    int capacity;

public:
    PhoneBook();
    ~PhoneBook();

    void addContact();
    void deleteContact();
    void searchContact();
    void showAllContacts();
    void saveToFile();
    void loadFromFile();
};

#endif