using System;

class Program
{
    static void Main()
    {
        Console.WriteLine("Введіть кількість рядків:");
        int rows = int.Parse(Console.ReadLine());

        Console.WriteLine("Введіть кількість стовпців:");
        int cols = int.Parse(Console.ReadLine());

        Matrix m = new Matrix(rows, cols);

        while (true)
        {
            Console.WriteLine("\nМЕНЮ:");
            Console.WriteLine("1. Показати матрицю");
            Console.WriteLine("2. Максимальне значення");
            Console.WriteLine("3. Мінімальне значення");
            Console.WriteLine("4. Помножити на число");
            Console.WriteLine("5. Помножити на матрицю 3x3");
            Console.WriteLine("6. Транспонувати");
            Console.WriteLine("7. Вийти");
            Console.Write("Ваш вибір: ");

            int choice = int.Parse(Console.ReadLine());

            switch (choice)
            {
                case 1:
                    m.Show();
                    break;
                case 2:
                    Console.WriteLine("Максимум: " + m.GetMax());
                    break;
                case 3:
                    Console.WriteLine("Мінімум: " + m.GetMin());
                    break;
                case 4:
                    Console.Write("Введіть число: ");
                    int num = int.Parse(Console.ReadLine());
                    Matrix r = m.Multiply(num);
                    Console.WriteLine("Результат:");
                    r.Show();
                    break;
                case 5:
                    if (rows == 3 && cols == 3)
                    {
                        Console.WriteLine("Введіть другу матрицю 3x3:");
                        Matrix other = new Matrix(3, 3);
                        Console.WriteLine("Друга матриця:");
                        other.Show();
                        Matrix res = m.MultiplyMatrix(other);
                        Console.WriteLine("Результат множення:");
                        res.Show();
                    }
                    else
                    {
                        Console.WriteLine("Можна тільки для матриць 3x3!");
                    }
                    break;
                case 6:
                    Matrix t = m.Transpose();
                    Console.WriteLine("Транспонована матриця:");
                    t.Show();
                    break;
                case 7:
                    return;
            }
        }
    }
}

class Matrix
{
    private int[,] table;
    private int rows;
    private int cols;

    public Matrix(int r, int c)
    {
        rows = r;
        cols = c;
        table = new int[rows, cols];

        Random rand = new Random();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                table[i, j] = rand.Next(1, 10);
            }
        }
    }

    public void Show()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                Console.Write(table[i, j] + " ");
            }
            Console.WriteLine();
        }
    }

    public int GetMax()
    {
        int max = table[0, 0];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (table[i, j] > max) max = table[i, j];
            }
        }
        return max;
    }

    public int GetMin()
    {
        int min = table[0, 0];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (table[i, j] < min) min = table[i, j];
            }
        }
        return min;
    }

    public Matrix Multiply(int number)
    {
        Matrix result = new Matrix(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.table[i, j] = table[i, j] * number;
            }
        }
        return result;
    }

    public Matrix MultiplyMatrix(Matrix other)
    {
        if (rows != 3 || cols != 3 || other.rows != 3 || other.cols != 3)
        {
            Console.WriteLine("Помилка: тільки матриці 3x3!");
            return this;
        }

        Matrix result = new Matrix(3, 3);

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int sum = 0;
                for (int k = 0; k < 3; k++)
                {
                    sum += table[i, k] * other.table[k, j];
                }
                result.table[i, j] = sum;
            }
        }

        return result;
    }

    public Matrix Transpose()
    {
        Matrix result = new Matrix(cols, rows);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.table[j, i] = table[i, j];
            }
        }

        return result;
    }
}