#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

struct Student {
    char name[50];
    int age;
    float avgGrade;
};

struct Rectangle {
    float width;
    float height;
};

float calculateArea(Rectangle rect) {
    return rect.width * rect.height;
}

struct Time {
    int hour;
    int minute;
    int second;
};

void printTime(Time t) {
    cout << t.hour << ":" << t.minute << ":" << t.second << endl;
}



struct Date {
    int day;
    int month;
    int year;
};

void printDate(Date d) {
    cout << d.day << "." << d.month << "." << d.year << endl;
}

struct Person {
    char name[50];
    int age;
    float height;
};

struct Book {
    char title[100];
    char author[50];
    int year;
};

struct Employee {
    char name[50];
    char position[50];
    float salary;
};

struct Triangle {
    float a;
    float b;
    float c;
};

bool isValidTriangle(Triangle t) {
    return (t.a + t.b > t.c) & (t.a + t.c > t.b) & (t.b + t.c > t.a);
}

int main() {

    Point p1;
    p1.x = 10;
    p1.y = 20;
    cout << "1. Point: (" << p1.x << ", " << p1.y << ")" << endl;

    Student s1;
    cout << "2. Введіть ім'я студента: ";
    cin.getline(s1.name, 50);
    cout << "Введіть вік студента: ";
    cin >> s1.age;
    cout << "Введіть середній бал: ";
    cin >> s1.avgGrade;
    cin.ignore(); 
    cout << "Студент: " << s1.name << ", " << s1.age << " років, середній бал " << s1.avgGrade << endl;

    Rectangle rect;
    rect.width = 5.5;
    rect.height = 3.2;
    cout << "3. Площа прямокутника: " << calculateArea(rect) << endl;

    Time t1 = {14, 30, 45};
    cout << "4. Час: ";
    printTime(t1);

    // без понятия (5)

    Date today = {15, 10, 2023};
    cout << "6. Дата: ";
    printDate(today);

    Person person;
    cout << "7. Введіть ім'я: ";
    cin.getline(person.name, 50);
    cout << "Введіть вік: ";
    cin >> person.age;
    cout << "Введіть зріст: ";
    cin >> person.height;
    cin.ignore();
    cout << "Людина: " << person.name << ", " << person.age << " років, зріст " << person.height << " см" << endl;
    Book book1;
    strcpy(book1.title, "Війна і мир");
    strcpy(book1.author, "Л. Толстой");
    book1.year = 1869;
    cout << "8. Книга: " << book1.title << ", " << book1.author << ", " << book1.year << " рік" << endl;

    Employee emp1;
    strcpy(emp1.name, "Іван Петренко");
    strcpy(emp1.position, "Програміст");
    emp1.salary = 25000.0;
    cout << "9. Працівник: " << emp1.name << ", " << emp1.position << ", зарплата " << emp1.salary << endl;

    Triangle tri;
    tri.a = 3;
    tri.b = 4;
    tri.c = 5;
    cout << "10. Трикутник зі сторонами " << tri.a << ", " << tri.b << ", " << tri.c;
    if (isValidTriangle(tri)) {
        cout << " - існує" << endl;
    } else {
        cout << " - не існує" << endl;
    }

    return 0;
}