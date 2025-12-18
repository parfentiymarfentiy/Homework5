
// TASK 1 TASK 1 TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1TASK 1

//using System;

//class Program
//{
//    static void DrawSquare(int sideLength, char symbol)
//    {
//        for (int i = 0; i < sideLength; i++)
//        {
//            for (int j = 0; j < sideLength; j++)
//            {
//                Console.Write(symbol + " ");
//            }
//            Console.WriteLine();
//        }
//    }

//    static void Main()
//    {
//        Console.Write("Введите длину стороны квадрата: ");
//        int length = int.Parse(Console.ReadLine());

//        Console.Write("Введите символ для рисовфания: ");
//        char symbol = Console.ReadKey().KeyChar;
//        Console.WriteLine();

//        DrawSquare(length, symbol);
//    }
//}

// TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2TASK 2

//using System;

//class Program
//{
//    static bool IsPalindrome(int number)
//    {
//        int originalNumber = number;
//        int reversedNumber = 0;

//        while (number > 0)
//        {
//            int digit = number % 10;
//            reversedNumber = reversedNumber * 10 + digit;
//            number /= 10;
//        }

//        return originalNumber == reversedNumber;
//    }

//    static void Main()
//    {
//        Console.Write("Введите число: ");
//        int number = int.Parse(Console.ReadLine());

//        bool result = IsPalindrome(number);
//        Console.WriteLine($"Число {number} является палиндромом: {result}");
//    }
//}

// TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3TASK 3

//using System;
//using System.Linq;

//class Program
//{
//    static int[] FilterArray(int[] originalArray, int[] filterArray)
//    {
//        return originalArray.Where(item => !filterArray.Contains(item)).ToArray();
//    }

//    static void Main()
//    {
//        int[] original = { 1, 2, 6, -1, 88, 7, 6 };
//        int[] filter = { 6, 88, 7 };

//        int[] result = FilterArray(original, filter);

//        Console.WriteLine("Результат: " + string.Join(" ", result));
//    }
//}

// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4// TASK 4

//using System;

//class Program
//{
//    static int CalculateExpression(string expression)
//    {
//        try
//        {
//            if (string.IsNullOrWhiteSpace(expression))
//                throw new ArgumentException("Выражение не может быть пустым");

//            string[] parts = expression.Split('*');

//            int result = 1;

//            foreach (string part in parts)
//            {
//                if (int.TryParse(part.Trim(), out int number))
//                {
//                    result *= number;
//                }
//                else
//                {
//                    throw new FormatException($"Некорректное число: '{part}'");
//                }
//            }

//            return result;
//        }
//        catch (Exception ex)
//        {
//            Console.WriteLine($"Ошибка: {ex.Message}");
//            return 0;
//        }
//    }

//    static void Main()
//    {
//        Console.Write("Введите математическое выражение: ");
//        string expression = Console.ReadLine();

//        int result = CalculateExpression(expression);
//        Console.WriteLine($"Результат: {result}");
//    }
//}

// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5// TASK 5

// ne sdelal :(