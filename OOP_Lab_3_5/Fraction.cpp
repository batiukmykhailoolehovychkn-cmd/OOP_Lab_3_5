#include "Fraction.h"
#include <cmath>
#include <cstdlib>

Fraction::Fraction() : Array(2, 0) {
    setFracDigits(1);
    setSign('+');
}

Fraction::Fraction(int totalDigits, int fracDigits, char sign, unsigned char initVal)
    : Array(totalDigits, initVal) {
    setFracDigits(fracDigits);
    setSign(sign);
}

Fraction::Fraction(const string& numStr) : Array(1, 0) {
    if (numStr.empty()) {
        cerr << "Помилка: порожній рядок для Fraction!" << endl;
        exit(1);
    }

    size_t pos = 0;
    char s = '+';
    if (numStr[0] == '-' || numStr[0] == '+') {
        s = numStr[0];
        pos = 1;
    }

    string digits = "";
    int dotCount = 0;
    int fDigits = 0;

    for (size_t i = pos; i < numStr.length(); ++i) {
        if (numStr[i] == '.' || numStr[i] == ',') {
            dotCount++;
            if (dotCount > 1) {
                cerr << "Помилка: зайва десяткова крапка у числі!" << endl;
                exit(1);
            }
            fDigits = static_cast<int>(numStr.length() - 1 - i);
        }
        else if (numStr[i] >= '0' && numStr[i] <= '9') {
            digits += numStr[i];
        }
        else {
            cerr << "Помилка: недопустимий символ '" << numStr[i] << "' у числі!" << endl;
            exit(1);
        }
    }

    if (digits.empty() || fDigits >= static_cast<int>(digits.length())) {
        cerr << "Помилка: некоректний формат дробового числа!" << endl;
        exit(1);
    }

    setSize(static_cast<int>(digits.length()));
    setFracDigits(fDigits);
    setSign(s);

    for (int i = 0; i < getSize(); ++i) {
        setElement(i, static_cast<unsigned char>(digits[getSize() - 1 - i] - '0'));
    }
}

Fraction::Fraction(const Fraction& other) : Array(other) {
    setFracDigits(other.getFracDigits());
    setSign(other.getSign());
}

Fraction::~Fraction() {}

int Fraction::getFracDigits() const {
    return fracDigits;
}

void Fraction::setFracDigits(int f) {
    if (f < 0 || f >= getSize()) {
        cerr << "Помилка: кількість дробових цифр (" << f
            << ") має бути в межах 0.." << (getSize() - 1) << "!" << endl;
        exit(1);
    }
    fracDigits = f;
}

char Fraction::getSign() const {
    return sign;
}

void Fraction::setSign(char s) {
    if (s != '+' && s != '-') {
        cerr << "Помилка: знак має бути '+' або '-'!" << endl;
        exit(1);
    }
    sign = s;
}

double Fraction::toDouble() const {
    double val = 0.0;
    double power = 1.0;
    for (int i = 0; i < getSize(); ++i) {
        val += getElement(i) * power;
        power *= 10.0;
    }
    val /= pow(10.0, getFracDigits());
    return (getSign() == '-') ? -val : val;
}

Fraction Fraction::fromDouble(double val, int fDigits) {
    char s = (val < 0.0) ? '-' : '+';
    double absVal = fabs(val);
    unsigned long long scaled = static_cast<unsigned long long>(absVal * pow(10.0, fDigits) + 0.5);

    if (scaled == 0) {
        s = '+';
    }

    string digits = to_string(scaled);
    while (static_cast<int>(digits.length()) <= fDigits) {
        digits = "0" + digits;
    }

    Fraction res(static_cast<int>(digits.length()), fDigits, s, 0);
    for (int i = 0; i < res.getSize(); ++i) {
        res.setElement(i, static_cast<unsigned char>(digits[res.getSize() - 1 - i] - '0'));
    }
    return res;
}

Fraction& Fraction::operator=(const Fraction& other) {
    if (this != &other) {
        Array::operator=(other);
        setFracDigits(other.getFracDigits());
        setSign(other.getSign());
    }
    return *this;
}

Fraction::operator string() const {
    string res = (getSign() == '-') ? "-" : "";
    for (int i = getSize() - 1; i >= 0; --i) {
        res += static_cast<char>('0' + getElement(i));
        if (getFracDigits() > 0 && i == getFracDigits()) {
            res += ".";
        }
    }
    return res;
}

Fraction& Fraction::operator+=(const Fraction& other) {
    *this = *this + other;
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& other) {
    *this = *this - other;
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& other) {
    *this = *this * other;
    return *this;
}

Fraction operator+(const Fraction& a, const Fraction& b) {
    int fDigits = (a.getFracDigits() > b.getFracDigits()) ? a.getFracDigits() : b.getFracDigits();
    return Fraction::fromDouble(a.toDouble() + b.toDouble(), fDigits);
}

Fraction operator-(const Fraction& a, const Fraction& b) {
    int fDigits = (a.getFracDigits() > b.getFracDigits()) ? a.getFracDigits() : b.getFracDigits();
    return Fraction::fromDouble(a.toDouble() - b.toDouble(), fDigits);
}

Fraction operator*(const Fraction& a, const Fraction& b) {
    int fDigits = (a.getFracDigits() > b.getFracDigits()) ? a.getFracDigits() : b.getFracDigits();
    return Fraction::fromDouble(a.toDouble() * b.toDouble(), fDigits);
}

bool operator==(const Fraction& a, const Fraction& b) {
    return fabs(a.toDouble() - b.toDouble()) < 1e-9;
}

bool operator!=(const Fraction& a, const Fraction& b) {
    return !(a == b);
}

bool operator<(const Fraction& a, const Fraction& b) {
    return a.toDouble() < b.toDouble() - 1e-9;
}

bool operator>(const Fraction& a, const Fraction& b) {
    return a.toDouble() > b.toDouble() + 1e-9;
}

bool operator<=(const Fraction& a, const Fraction& b) {
    return (a < b) || (a == b);
}

bool operator>=(const Fraction& a, const Fraction& b) {
    return (a > b) || (a == b);
}

ostream& operator<<(ostream& out, const Fraction& f) {
    out << string(f);
    return out;
}

istream& operator>>(istream& in, Fraction& f) {
    string s;
    in >> s;
    f = Fraction(s);
    return in;
}