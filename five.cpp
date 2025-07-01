// #include <iostream>

// using namespace std;

// int main() {

// // Завдання 1: <Запитайте у користувача два числа, запишіть їх у змінні а та б, поміняйте місцями значення у цих змінних>

// int a;
// int b;

// cout << "Enter number a" << endl;
// cin >> a;
// cout << "Enter number b" << endl;
// cin >> b;

// temp = a;
// a = b;
// b = temp;
// cout << a << b << endl;
// }

// ЗАВДАННЯ 2: Запитайте у користувача число, порахуйте кількість цифр в ньому

// #include <iostream>

// using namespace std;

// int main() {

// long long number;
// cout << "Введите число";
// cin >> number;

// if (number < 0) {

//  number = -number;

// }

// int count = 0;

// if (number == 0) {

//  count == 1;

// }
// else; {

//  while (number > 0) {

//   number = number / 10;

//   count = count + 1;

//  }

// }

// cout << "Количество цифр у числе:" << count << "\n";

// return 0;

// Завдання 3: Користувач вводить з клавіатури кількість студентів, які склали іспит, та кількість «боржників».Обчислити, який відсоток становлять «боржники» від загальної кількості студентів, а також який відсоток становлять студенти, які склали іспит.

// #include <iostream>

// using namespace std;

// int main() {

// int passed, debtors;
// cout << "Введіть кількість студентів яки склали іспит";
// cin >> passed;
// cout << "Введіть кількість боржників";
// cin >> debtors;
// int total = passed + debtors;

// double percent_debtors = (double)debtors / total * 100;
// double percent_passed = (double)passed / total * 100;

// cout << "Процент должников" << percent_debtors << "%" << endl;

// cout << "Процент студентов, котрі сдали іспит" << percent_passed << "%" << endl;

// return 0;

// }

// Завдання 4: Створіть масив з 20 елементів, ініціалізуйте масив випадковими числами від - 20 до 20.
// a.Порахуйте кількість нульових елементів
// b.Порахуйте середнє значення негативних
// c.Знайдіть максимальне значення серед позитвних чисел.

// #include <iostream>
// #include <cstdlib>
// #include <ctime>

// using namespace std;

// int main() {
//    int rows = 5;
//    int cols = 5;

//    int** arr = new int* [rows];
//    for (int i = 0; i < rows; i = i + 1) {
//        arr[i] = new int[cols];
//    }

//    srand(time(0));

//    for (int i = 0; i < rows; i = i + 1) {
//        for (int j = 0; j < cols; j = j + 1) {
//            arr[i][j] = rand() % 21 - 10;
//            cout << arr[i][j] << "\t";
//        }
//        cout << "\n";
//    }

//    int max_sum = arr[0][0] + arr[1][0] + arr[2][0] + arr[3][0] + arr[4][0];
//    int max_col = 0;

//    for (int j = 0; j < cols; j = j + 1) {
//        int sum = 0;
//        for (int i = 0; i < rows; i = i + 1) {
//            sum = sum + arr[i][j];
//        }
//        if (sum > max_sum) {
//            max_sum = sum;
//            max_col = j;
//        }
//    }

//    cout << "Максимальна сума елементів у стовпчику: " << max_sum << "\n";
//    cout << "Це стовпець номер: " << max_col << "\n";

//    for (int i = 0; i < rows; i = i + 1) {
//        delete[] arr[i];
//    }
//    delete[] arr;

//    return 0;
// }

// #include <iostream>
// #include <cstdlib>
// #include <ctime>

// using namespace std;

// int main() {
//    int rows = 5;
//    int cols = 5;

//    int** arr = new int* [rows];
//    for (int i = 0; i < rows; i = i + 1) {
//        arr[i] = new int[cols];
//    }

//    srand(time(0));

//    for (int i = 0; i < rows; i = i + 1) {
//        for (int j = 0; j < cols; j = j + 1) {
//            arr[i][j] = rand() % 21 - 10; 
//            cout << arr[i][j] << "\t";
//        }
//        cout << "\n";
//    }

//    for (int j = 0; j < cols; j = j + 1) {
//        int temp = arr[2][j];
//        arr[2][j] = arr[3][j];
//        arr[3][j] = temp;
//    }

//    cout << "\nПісля обміну 3-го та 4-го рядків:\n";

//    for (int i = 0; i < rows; i = i + 1) {
//        for (int j = 0; j < cols; j = j + 1) {
//            cout << arr[i][j] << "\t";
//        }
//        cout << "\n";
//    }

//    int max_sum = arr[0][0] + arr[1][0] + arr[2][0] + arr[3][0] + arr[4][0];
//    int max_col = 0;

//    for (int j = 0; j < cols; j = j + 1) {
//        int sum = 0;
//        for (int i = 0; i < rows; i = i + 1) {
//            sum = sum + arr[i][j];
//        }
//        if (sum > max_sum) {
//            max_sum = sum;
//            max_col = j;
//        }
//    }

//    cout << "\nМаксимальна сума елементів у стовпчику: " << max_sum << "\n";
//    cout << "Це стовпець номер: " << max_col << "\n";

//    for (int i = 0; i < rows; i = i + 1) {
//        delete[] arr[i];
//    }
//    delete[] arr;

//    return 0;
// }
// 5.a

// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// using namespace std;

// int main() {
//    int rows = 5;
//    int cols = 5;

//    int** arr = new int* [rows];
//    for (int i = 0; i < rows; i = i + 1) {
//        arr[i] = new int[cols];
//    }
//    srand(time(0));



// Сьоме Завдання: 

// #include <iostream>
// #include <string>
// using namespace std;

// struct Car {
//     string brand;
//     string model;
//     int year;
//     double engineVolume;
// };

// Car createCar() {
//     Car c;
//     cout << "Введіть марку автомобіля: ";
//     getline(cin, c.brand);
//     cout << "Введіть модель: ";
//     getline(cin, c.model);
//     cout << "Введіть рік випуску: ";
//     cin >> c.year;
//     cout << "Введіть об'єм двигуна (в літрах): ";
//     cin >> c.engineVolume;
//     cin.ignore(); 
//     return c;
// }

// void printCar(const Car& c) {
//     cout << "Марка: " << c.brand << ", Модель: " << c.model
//          << ", Рік: " << c.year << ", Об'єм двигуна: " << c.engineVolume << " л\n";
// }

// void printAllCars(Car cars[], int size) {
//     cout << "\nВсі автомобілі:\n";
//     for (int i = 0; i < size; i = i + 1) {
//         cout << i << ": ";
//         printCar(cars[i]);
//     }
// }

// void printCarAt(Car cars[], int size, int index) {
//     if (index < 0 || index >= size) {
//         cout << "Неправильний індекс!\n";
//         return;
//     }
//     cout << "\nАвтомобіль під індексом " << index << ":\n";
//     printCar(cars[index]);
// }

// int main() {
//     int n = 2;
//     Car* cars = new Car[n];

//     for (int i = 0; i < n; i = i + 1) {
//         cout << "Введіть дані для автомобіля #" << i << ":\n";
//         cars[i] = createCar();
//     }

//     printAllCars(cars, n);

//     int index;
//     cout << "\nВведіть індекс автомобіля, який хочете побачити: ";
//     cin >> index;
//     cin.ignore();
//     printCarAt(cars, n, index);
//     int newSize = n + 1;
//     Car* newCars = new Car[newSize];

//     for (int i = 0; i < n; i = i + 1) {
//         newCars[i] = cars[i];
//     }

//     cout << "\nСтворіть нового автомобіля:\n";
//     newCars[newSize - 1] = createCar();

//     delete[] cars;
//     cars = newCars;
//     n = newSize;

//     printAllCars(cars, n);

//     delete[] cars;
//     return 0;
// }

