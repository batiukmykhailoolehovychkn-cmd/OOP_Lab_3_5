#include "Array.h"
#include <cstdlib>

Array::Array() {
    setSize(1);
    setElement(0, 0);
}

Array::Array(int n, unsigned char initVal) {
    setSize(n);
    for (int i = 0; i < getSize(); ++i) {
        setElement(i, initVal);
    }
}

Array::Array(const Array& other) {
    setSize(other.getSize());
    for (int i = 0; i < getSize(); ++i) {
        setElement(i, other.getElement(i));
    }
}

Array::~Array() {}

int Array::getSize() const {
    return size;
}

void Array::setSize(int n) {
    if (n < 1 || n > MAX_SIZE) {
        cerr << "Помилка: некоректний розмір масиву (" << n << "). Допустимо: 1.." << MAX_SIZE << endl;
        exit(1);
    }
    size = n;
}

bool Array::rangeCheck(int index) const {
    return index >= 0 && index < size;
}

unsigned char Array::getElement(int index) const {
    if (!rangeCheck(index)) {
        cerr << "Помилка: індекс " << index << " виходить за межі масиву!" << endl;
        exit(1);
    }
    return data[index];
}

void Array::setElement(int index, unsigned char val) {
    if (!rangeCheck(index)) {
        cerr << "Помилка: індекс " << index << " виходить за межі масиву!" << endl;
        exit(1);
    }
    if (val > 9) {
        cerr << "Помилка: значення елемента (" << (int)val << ") не є десятковою цифрою (0..9)!" << endl;
        exit(1);
    }
    data[index] = val;
}

unsigned char& Array::operator[](int index) {
    if (!rangeCheck(index)) {
        cerr << "Помилка: індекс " << index << " виходить за межі масиву!" << endl;
        exit(1);
    }
    return data[index];
}

const unsigned char& Array::operator[](int index) const {
    if (!rangeCheck(index)) {
        cerr << "Помилка: індекс " << index << " виходить за межі масиву!" << endl;
        exit(1);
    }
    return data[index];
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        setSize(other.getSize());
        for (int i = 0; i < getSize(); ++i) {
            setElement(i, other.getElement(i));
        }
    }
    return *this;
}

Array::operator string() const {
    string res = "";
    for (int i = getSize() - 1; i >= 0; --i) {
        res += static_cast<char>('0' + getElement(i));
    }
    return res;
}

ostream& operator<<(ostream& out, const Array& arr) {
    out << string(arr);
    return out;
}

istream& operator>>(istream& in, Array& arr) {
    string s;
    in >> s;
    arr.setSize(static_cast<int>(s.length()));
    for (int i = 0; i < arr.getSize(); ++i) {
        char c = s[arr.getSize() - 1 - i];
        if (c < '0' || c > '9') {
            cerr << "Помилка: введено недопустимий символ '" << c << "'!" << endl;
            exit(1);
        }
        arr.setElement(i, static_cast<unsigned char>(c - '0'));
    }
    return in;
}