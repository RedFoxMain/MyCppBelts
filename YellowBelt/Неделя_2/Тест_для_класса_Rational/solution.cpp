#include <iostream>
#include <cassert>
#include <sstream>
#include "RationalClass.hpp"

class TestRunner{
	int test = 1;

  public:
	template <typename A, typename B>
	void assertEqual(A a, B b){
		std::ostringstream os;
		if (a != b){
			os << a << " != " << b << " Тест: " << std::to_string(test);
			throw std::runtime_error(os.str());
		}
		test++;
	}
};

// тест для пустого конструктора
void TestDefaultFraction(TestRunner &tr){
	Rational fraction;
	std::string test_NullFraction = std::to_string(fraction.numerator) + "/" + std::to_string(fraction.denominator);

	tr.assertEqual(test_NullFraction, "0/1");
}
// тест знаков у дроби
void TestFraction(TestRunner &tr, Rational &fraction){
	std::string test_Fraction = std::to_string(fraction.numerator) + "/" + std::to_string(fraction.denominator);
	tr.assertEqual(test_Fraction, "-2/3");
}
// тест сокращения дроби
void TestReducation(TestRunner &tr, Rational fraction){
	std::string testReducationFraction = std::to_string(fraction.Numerator()) + "/" + std::to_string(fraction.Denominator());
	tr.assertEqual(testReducationFraction, "5/1");
}
void StartTest(){
	TestRunner tr;

	Rational fraction(-2, 3);
	Rational fraction2(2, -3);
	Rational fraction3(100, 20);

	// тест дефолтной дроби
	TestDefaultFraction(tr);

	// тест знаков у дробей
	TestFraction(tr, fraction);
	TestFraction(tr, fraction2);

	// тест сокращения дроби
	TestReducation(tr, fraction3);

	std::cout << "Ok" << std::endl;
}

int main(){
	StartTest();
}