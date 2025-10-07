#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Функція для спрощення дробу
    void simplify() {
        if (denominator == 0) {
            throw std::invalid_argument("Знаменник не може бути нулем");
        }

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        int common = gcd(abs(numerator), abs(denominator));
        numerator /= common;
        denominator /= common;
    }

public:
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        simplify();
    }
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    Fraction operator+(const Fraction& other) const {
        int new_num = numerator * other.denominator + other.numerator * denominator;
        int new_den = denominator * other.denominator;
        return Fraction(new_num, new_den);
    }

    Fraction operator-(const Fraction& other) const {
        int new_num = numerator * other.denominator - other.numerator * denominator;
        int new_den = denominator * other.denominator;
        return Fraction(new_num, new_den);
    }

    Fraction operator*(const Fraction& other) const {
        int new_num = numerator * other.numerator;
        int new_den = denominator * other.denominator;
        return Fraction(new_num, new_den);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Ділення на нуль");
        }
        int new_num = numerator * other.denominator;
        int new_den = denominator * other.numerator;
        return Fraction(new_num, new_den);
    }

    Fraction operator+(int value) const {
        return *this + Fraction(value);
    }

    Fraction operator-(int value) const {
        return *this - Fraction(value);
    }

    Fraction operator*(int value) const {
        return *this * Fraction(value);
    }

    Fraction operator/(int value) const {
        return *this / Fraction(value);
    }
