
#include <iostream>
#include <cassert>
#include <sstream>
#include "RationalClass.hpp"

using namespace std;
class TestRunner
{
	int test = 1;
	public:
	template <typename A, typename B>
	void assertEqual(A a, B b)
	{
		ostringstream os;
		if (a != b)
		{
			os << a << " != " << b << " Тест: " << to_string(test);
			throw runtime_error(os.str());
		}
		test++;
	}
};

// тест сложения двух дробей
void TestAdd(TestRunner &tr, Rational &fraction1, Rational &fraction2){
	tr.assertEqual(Rational::Add(fraction1, fraction2), 0.85); // тестируем сложение дробей
}
// тест вычитания двух дробей
void TestSubdivide(TestRunner &tr, Rational &fraction1, Rational &fraction2){
	tr.assertEqual(Rational::Subdivide(fraction1, fraction2), -0.35);
}
// тест умножения двух дробей
void TestMultiply(TestRunner &tr, Rational &fraction1, Rational &fraction2){
	tr.assertEqual(Rational::Multiply(fraction1, fraction2), 0.15);
}
// // тест деления двух дробей
void TestDivide(TestRunner &tr, Rational &fraction1, Rational &fraction2){
	tr.assertEqual(Rational::Reduce(Rational::Divide(fraction1, fraction2)), 0.42);
}
// тест для пустого конструктора
void TestDefaultFraction(TestRunner &tr){
	Rational fraction;
	string test_NullFraction = to_string(fraction.numerator) + "/" + to_string(fraction.denominator);
	
	tr.assertEqual(test_NullFraction, "0/1");
}

void TestFraction(TestRunner &tr){
	Rational fraction(-2,-3);
	Rational fraction2(7,3);
	
	string test_Fraction = to_string(fraction.numerator) + "/" + to_string(fraction.denominator);
	string test_Fraction2 = to_string(fraction2.numerator) + "/" + to_string(fraction2.denominator);
	
	tr.assertEqual(test_Fraction, "-2/3");
	tr.assertEqual(test_Fraction2, "7/3");
}
void StartTest()
{
	TestRunner tr;
	
	Rational fraction1(3, 5);
	Rational fraction2(1, 4);
	
	// тест математических операций
	TestAdd(tr, fraction1, fraction2);
	TestSubdivide(tr, fraction1, fraction2);
	TestMultiply(tr, fraction1, fraction2);
	TestDivide(tr, fraction1, fraction2);
	
	// тест дефолтной дроби
	TestDefaultFraction(tr);
	
	// тест знаков у дробей
	TestFraction(tr);
	
	cout << "Ok" << endl;
}

int main(int argc, char *argv[])
{
	StartTest();
}