#include "contact.h"
#include <iostream>
#include <cstring>

Contact::Contact() {
    fullName = new char[1];
    fullName[0] = '\0';
    strcpy(homePhone, "");
    strcpy(workPhone, "");
    strcpy(mobilePhone, "");
    strcpy(additionalInfo, "");
}

Contact::Contact(const char* name, const char* home, const char* work, const char* mobile, const char* info) {
    fullName = new char[strlen(name) + 1];
    strcpy(fullName, name);
    strcpy(homePhone, home);
    strcpy(workPhone, work);
    strcpy(mobilePhone, mobile);
    strcpy(additionalInfo, info);
}

Contact::~Contact() {
    delete[] fullName;
}

void Contact::setName(const char* name) {
    delete[] fullName;
    fullName = new char[strlen(name) + 1];
    strcpy(fullName, name);
}

void Contact::setHomePhone(const char* phone) { strcpy(homePhone, phone); }
void Contact::setWorkPhone(const char* phone) { strcpy(workPhone, phone); }
void Contact::setMobilePhone(const char* phone) { strcpy(mobilePhone, phone); }
void Contact::setAdditionalInfo(const char* info) { strcpy(additionalInfo, info); }

const char* Contact::getName() const { return fullName; }
const char* Contact::getHomePhone() const { return homePhone; }
const char* Contact::getWorkPhone() const { return workPhone; }
const char* Contact::getMobilePhone() const { return mobilePhone; }
const char* Contact::getAdditionalInfo() const { return additionalInfo; }

void Contact::display() const {
    std::cout << "ПІБ: " << fullName << std::endl;
    std::cout << "Домашній: " << homePhone << std::endl;
    std::cout << "Робочий: " << workPhone << std::endl;
    std::cout << "Мобільний: " << mobilePhone << std::endl;
    std::cout << "Додатково: " << additionalInfo << std::endl;
    std::cout << "------------------------" << std::endl;
}

void Contact::saveToFile(std::ofstream& file) const {
    file << fullName << std::endl;
    file << homePhone << std::endl;
    file << workPhone << std::endl;
    file << mobilePhone << std::endl;
    file << additionalInfo << std::endl;
}

void Contact::loadFromFile(std::ifstream& file) {
    char buffer[256];

    file.getline(buffer, 256);
    setName(buffer);

    file.getline(buffer, 20);
    setHomePhone(buffer);

    file.getline(buffer, 20);
    setWorkPhone(buffer);

    file.getline(buffer, 20);
    setMobilePhone(buffer);

    file.getline(buffer, 100);
    setAdditionalInfo(buffer);
}