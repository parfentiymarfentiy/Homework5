#pragma once
class contact
{
private:
    char* fullName;
    char homePhone[20];
    char workPhone[20];
    char mobilePhone[20];
    char additionalInfo[100];

public:
    Contact();
    Contact(const char* name, const char* home, const char* work, const char* mobile, const char* info);
    ~Contact();

    void setName(const char* name);
    void setHomePhone(const char* phone);
    void setWorkPhone(const char* phone);
    void setMobilePhone(const char* phone);
    void setAdditionalInfo(const char* info);

    const char* getName() const;
    const char* getHomePhone() const;
    const char* getWorkPhone() const;
    const char* getMobilePhone() const;
    const char* getAdditionalInfo() const;

    void display() const;
    void saveToFile(std::ofstream& file) const;
    void loadFromFile(std::ifstream& file);
};

