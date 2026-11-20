#pragma once
#include "Array.h"

class Fraction : public Array {
private:
    int fracDigits;
    char sign; // '+' або '-'

public:
    Fraction();
    Fraction(int totalDigits, int fracDigits, char sign = '+', unsigned char initVal = 0);
    Fraction(const string& numStr);
    Fraction(const Fraction& other);
    ~Fraction() override;

    int getFracDigits() const;
    void setFracDigits(int f);
    char getSign() const;
    void setSign(char s);

    double toDouble() const;
    static Fraction fromDouble(double val, int fracDigits);

    Fraction& operator=(const Fraction& other);
    operator string() const override;

    // Операції з присвоюванням
    Fraction& operator+=(const Fraction& other);
    Fraction& operator-=(const Fraction& other);
    Fraction& operator*=(const Fraction& other);

    // Арифметичні операції
    friend Fraction operator+(const Fraction& a, const Fraction& b);
    friend Fraction operator-(const Fraction& a, const Fraction& b);
    friend Fraction operator*(const Fraction& a, const Fraction& b);

    // Операції порівняння
    friend bool operator==(const Fraction& a, const Fraction& b);
    friend bool operator!=(const Fraction& a, const Fraction& b);
    friend bool operator<(const Fraction& a, const Fraction& b);
    friend bool operator>(const Fraction& a, const Fraction& b);
    friend bool operator<=(const Fraction& a, const Fraction& b);
    friend bool operator>=(const Fraction& a, const Fraction& b);

    // Ввід та вивід
    friend ostream& operator<<(ostream& out, const Fraction& f);
    friend istream& operator>>(istream& in, Fraction& f);
};