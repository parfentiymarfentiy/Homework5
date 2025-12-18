using System;

class Program
{
    static Student[] students = new Student[100];
    static int studentCount = 0;

    static void Main()
    {
        while (true)
        {
            Console.Clear();
            Console.WriteLine("=== МЕНЮ СТУДЕНТІВ ===");
            Console.WriteLine("1. Додати студента");
            Console.WriteLine("2. Видалити студента");
            Console.WriteLine("3. Показати всіх студентів");
            Console.WriteLine("4. Додати оцінку студенту");
            Console.WriteLine("5. Показати середній бал");
            Console.WriteLine("6. Вийти");
            Console.Write("Ваш вибір: ");

            string choice = Console.ReadLine();

            switch (choice)
            {
                case "1":
                    AddStudent();
                    break;
                case "2":
                    DeleteStudent();
                    break;
                case "3":
                    ShowAllStudents();
                    break;
                case "4":
                    AddGrade();
                    break;
                case "5":
                    ShowAverage();
                    break;
                case "6":
                    return;
                default:
                    Console.WriteLine("Невірний вибір!");
                    Console.ReadKey();
                    break;
            }
        }
    }

    static void AddStudent()
    {
        Console.Write("Прізвище: ");
        string lastName = Console.ReadLine();
        Console.Write("Ім'я: ");
        string firstName = Console.ReadLine();
        Console.Write("По-батькові: ");
        string middleName = Console.ReadLine();
        Console.Write("Група: ");
        string group = Console.ReadLine();
        Console.Write("Вік: ");
        int age = int.Parse(Console.ReadLine());

        students[studentCount] = new Student(lastName, firstName, middleName, group, age);
        studentCount++;
        Console.WriteLine("Студента додано!");
        Console.ReadKey();
    }

    static void DeleteStudent()
    {
        ShowAllStudents();
        Console.Write("Введіть номер студента для видалення: ");
        int index = int.Parse(Console.ReadLine()) - 1;

        if (index >= 0 && index < studentCount)
        {
            for (int i = index; i < studentCount - 1; i++)
            {
                students[i] = students[i + 1];
            }
            studentCount--;
            Console.WriteLine("Студента видалено!");
        }
        else
        {
            Console.WriteLine("Невірний номер!");
        }
        Console.ReadKey();
    }

    static void ShowAllStudents()
    {
        Console.WriteLine("\n=== СПИСОК СТУДЕНТІВ ===");
        for (int i = 0; i < studentCount; i++)
        {
            Console.WriteLine($"{i + 1}. {students[i]}");
        }
        if (studentCount == 0) Console.WriteLine("Студентів немає");
        Console.ReadKey();
    }

    static void AddGrade()
    {
        ShowAllStudents();
        Console.Write("Виберіть студента: ");
        int index = int.Parse(Console.ReadLine()) - 1;

        if (index >= 0 && index < studentCount)
        {
            Console.WriteLine("1. Програмування");
            Console.WriteLine("2. Адміністрування");
            Console.WriteLine("3. Дизайн");
            Console.Write("Предмет: ");
            int subject = int.Parse(Console.ReadLine()) - 1;

            Console.Write("Скільки оцінок додати? ");
            int count = int.Parse(Console.ReadLine());

            int[] newGrades = new int[count];
            for (int i = 0; i < count; i++)
            {
                Console.Write($"Оцінка {i + 1}: ");
                newGrades[i] = int.Parse(Console.ReadLine());
            }

            students[index].AddGrades(subject, newGrades);
            Console.WriteLine("Оцінки додано!");
        }
        else
        {
            Console.WriteLine("Невірний номер!");
        }
        Console.ReadKey();
    }

    static void ShowAverage()
    {
        ShowAllStudents();
        Console.Write("Виберіть студента: ");
        int index = int.Parse(Console.ReadLine()) - 1;

        if (index >= 0 && index < studentCount)
        {
            Console.WriteLine("1. Програмування");
            Console.WriteLine("2. Адміністрування");
            Console.WriteLine("3. Дизайн");
            Console.Write("Предмет: ");
            int subject = int.Parse(Console.ReadLine()) - 1;

            double avg = students[index].GetAverageGrade(subject);
            Console.WriteLine($"Середній бал: {avg:F2}");
        }
        else
        {
            Console.WriteLine("Невірний номер!");
        }
        Console.ReadKey();
    }
}

class Student
{
    private string lastName;
    private string firstName;
    private string middleName;
    private string group;
    private int age;
    private int[] progGrades;
    private int[] adminGrades;
    private int[] designGrades;

    public Student(string lastName, string firstName, string middleName, string group, int age)
    {
        this.lastName = lastName;
        this.firstName = firstName;
        this.middleName = middleName;
        this.group = group;
        this.age = age;
        progGrades = new int[0];
        adminGrades = new int[0];
        designGrades = new int[0];
    }

    public void AddGrades(int subject, int[] grades)
    {
        if (subject < 0 || subject > 2) return;

        switch (subject)
        {
            case 0:
                AddToArray(ref progGrades, grades);
                break;
            case 1:
                AddToArray(ref adminGrades, grades);
                break;
            case 2:
                AddToArray(ref designGrades, grades);
                break;
        }
    }

    private void AddToArray(ref int[] array, int[] newGrades)
    {
        int oldLength = array.Length;
        Array.Resize(ref array, oldLength + newGrades.Length);
        Array.Copy(newGrades, 0, array, oldLength, newGrades.Length);
    }

    public double GetAverageGrade(int subject)
    {
        int[] grades;
        switch (subject)
        {
            case 0: grades = progGrades; break;
            case 1: grades = adminGrades; break;
            case 2: grades = designGrades; break;
            default: return 0;
        }

        if (grades.Length == 0) return 0;

        double sum = 0;
        foreach (int grade in grades)
        {
            sum += grade;
        }
        return sum / grades.Length;
    }

    public override string ToString()
    {
        return $"{lastName} {firstName} {middleName}, {group}, {age} років. " +
               $"Оцінки: Прог({progGrades.Length}), Адмін({adminGrades.Length}), Дизайн({designGrades.Length})";
    }
}