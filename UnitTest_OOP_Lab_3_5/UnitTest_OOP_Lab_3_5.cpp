#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_Lab_3_5/Array.cpp"
#include "../OOP_Lab_3_5/Fraction.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestOOPLab35
{
	TEST_CLASS(UnitTestOOPLab35)
	{
	public:
        // Перевірка індексування та rangeCheck у базовому класі Array
        TEST_METHOD(TestArrayIndexingAndRangeCheck)
        {
            Array a(4, 2); // 2222
            a[0] = 7;
            Assert::AreEqual((unsigned char)7, a[0]);
            Assert::IsTrue(a.rangeCheck(3));
            Assert::IsFalse(a.rangeCheck(4));
            Assert::IsFalse(a.rangeCheck(-1));
            Assert::AreEqual(string("2227"), string(a));
        }

        // Перевірка ініціалізації Fraction та приведення до string
        TEST_METHOD(TestFractionInitAndString)
        {
            Fraction f1("-12.75");
            Assert::AreEqual('-', f1.getSign());
            Assert::AreEqual(2, f1.getFracDigits());
            Assert::AreEqual(string("-12.75"), string(f1));

            Fraction f2(4, 2, '+', 5); // 55.55
            Assert::AreEqual(string("55.55"), string(f2));
        }

        // Перевірка арифметичних операцій (+, -, *)
        TEST_METHOD(TestFractionArithmetic)
        {
            Fraction a("12.50");
            Fraction b("-2.25");

            Assert::AreEqual(string("10.25"), string(a + b));
            Assert::AreEqual(string("14.75"), string(a - b));
            Assert::AreEqual(string("-28.13"), string(a * b)); // -28.125 округлено до 2 знаків
        }

        // Перевірка операцій з присвоюванням (+=, -=, *=)
        TEST_METHOD(TestFractionCompoundAssignment)
        {
            Fraction f("10.00");
            f += Fraction("2.50");
            Assert::AreEqual(string("12.50"), string(f));

            f -= Fraction("4.25");
            Assert::AreEqual(string("8.25"), string(f));

            f *= Fraction("2.00");
            Assert::AreEqual(string("16.50"), string(f));
        }

        // Перевірка операцій порівняння
        TEST_METHOD(TestFractionComparisons)
        {
            Fraction a("5.50");
            Fraction b("5.50");
            Fraction c("-1.25");

            Assert::IsTrue(a == b);
            Assert::IsTrue(a != c);
            Assert::IsTrue(a > c);
            Assert::IsTrue(c < a);
        }
    };
}