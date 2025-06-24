#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    string surname;
    string group;
    vector<int> marks;
};

void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Введіть ім'я: ";
    cin >> newStudent.name;
    cout << "Введіть прізвище: ";
    cin >> newStudent.surname;
    cout << "Введіть групу: ";
    cin >> newStudent.group;
    
    students.push_back(newStudent);
    cout << "Студента додано!\n";
}

void deleteStudent(vector<Student>& students) {
    if (students.empty()) {
        cout << "Список студентів порожній!\n";
        return;
    }
    
    int index;
    cout << "Введіть індекс студента для видалення (0-" << students.size()-1 << "): ";
    cin >> index;
    
    if (index >= 0 && index < students.size()) {
        students.erase(students.begin() + index);
        cout << "Студента видалено!\n";
    } else {
        cout << "Невірний індекс!\n";
    }
}

void changeStudentInfo(Student& student) {
    cout << "Поточні дані:\n";
    cout << "1. Ім'я: " << student.name << endl;
    cout << "2. Прізвище: " << student.surname << endl;
    cout << "3. Група: " << student.group << endl;
    
    int choice;
    cout << "Що змінити (1-3)? ";
    cin >> choice;
    
    switch(choice) {
        case 1:
            cout << "Нове ім'я: ";
            cin >> student.name;
            break;
        case 2:
            cout << "Нове прізвище: ";
            cin >> student.surname;
            break;
        case 3:
            cout << "Нова група: ";
            cin >> student.group;
            break;
        default:
            cout << "Невірний вибір!\n";
    }
}

void manageMarks(Student& student) {
    if (student.marks.empty()) {
        cout << "У студента поки що немає оцінок.\n";
    } else {
        cout << "Поточні оцінки: ";
        for (int mark : student.marks) {
            cout << mark << " ";
        }
        cout << endl;
    }
    
    cout << "1. Додати оцінку\n";
    cout << "2. Видалити оцінку\n";
    cout << "3. Змінити оцінку\n";
    
    int choice;
    cout << "Ваш вибір: ";
    cin >> choice;
    
    switch(choice) {
        case 1: {
            int mark;
            cout << "Введіть оцінку: ";
            cin >> mark;
            student.marks.push_back(mark);
            cout << "Оцінку додано!\n";
            break;
        }
        case 2: {
            int index;
            cout << "Введіть індекс оцінки для видалення (0-" << student.marks.size()-1 << "): ";
            cin >> index;
            if (index >= 0 && index < student.marks.size()) {
                student.marks.erase(student.marks.begin() + index);
                cout << "Оцінку видалено!\n";
            } else {
                cout << "Невірний індекс!\n";
            }
            break;
        }
        case 3: {
            int index, newMark;
            cout << "Введіть індекс оцінки для зміни (0-" << student.marks.size()-1 << "): ";
            cin >> index;
            if (index >= 0 && index < student.marks.size()) {
                cout << "Нова оцінка: ";
                cin >> newMark;
                student.marks[index] = newMark;
                cout << "Оцінку змінено!\n";
            } else {
                cout << "Невірний індекс!\n";
            }
            break;
        }
        default:
            cout << "Невірний вибір!\n";
    }
}

void printStudent(const Student& student) {
    cout << "Ім'я: " << student.name << endl;
    cout << "Прізвище: " << student.surname << endl;
    cout << "Група: " << student.group << endl;
    
    if (student.marks.empty()) {
        cout << "Оцінок немає.\n";
    } else {
        cout << "Оцінки: ";
        for (int mark : student.marks) {
            cout << mark << " ";
        }
        cout << endl;
    }
}

int main() 
    vector<Student> students;
    
    while (true) 
        cout << "\nМеню:\n";
        cout << "1. Додати студента\n";
        cout << "2. Видалити студента\n";
        cout << "3. Змінити інформацію про студента\n";
        cout << "4. Керування оцінками студента\n";
        cout << "5. Вивести інформацію про студента\n";
        cout << "6. Вийти\n";
        
        int choice;
        cout << "Ваш вибір: ";
        cin >> choice;
        
        switch(choice) 
            case 1:
                addStudent(students);
                break;
            case 2:
                deleteStudent(students);
                break;
            case 3: {
                if (students.empty()) {
                    cout << "Список студентів порожній!\n";
                    break;
                }
