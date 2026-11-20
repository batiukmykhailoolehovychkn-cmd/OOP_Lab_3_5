#pragma once
#include <iostream>
#include <string>

using namespace std;

class Array {
public:
    static const int MAX_SIZE = 100;

private:
    unsigned char data[MAX_SIZE];
    int size;

public:
    Array();
    Array(int n, unsigned char initVal = 0);
    Array(const Array& other);
    virtual ~Array();

    int getSize() const;
    void setSize(int n);
    unsigned char getElement(int index) const;
    void setElement(int index, unsigned char val);

    bool rangeCheck(int index) const;

    unsigned char& operator[](int index);
    const unsigned char& operator[](int index) const;

    Array& operator=(const Array& other);
    virtual operator string() const;

    friend ostream& operator<<(ostream& out, const Array& arr);
    friend istream& operator>>(istream& in, Array& arr);
};