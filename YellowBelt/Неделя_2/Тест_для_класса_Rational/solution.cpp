#include <iostream>
#include <cassert>
#include <sstream>
#include "RationalClass.hpp"

using namespace std;
class TestRunner{
	int test = 1;

  public:
	template <typename A, typename B>
	void assertEqual(A a, B b){
		ostringstream os;
		if (a != b){
			os << a << " != " << b << " Тест: " << to_string(test);
			throw runtime_error(os.str());
		}
		test++;
	}
};

// тест для пустого конструктора
void TestDefaultFraction(TestRunner &tr){
	Rational fraction;
	string test_NullFraction = to_string(fraction.numerator) + "/" + to_string(fraction.denominator);

	tr.assertEqual(test_NullFraction, "0/1");
}
// тест знаков у дроби
void TestFraction(TestRunner &tr, Rational &fraction){
	string test_Fraction = to_string(fraction.numerator) + "/" + to_string(fraction.denominator);
	tr.assertEqual(test_Fraction, "-2/3");
}
// тест сокращения дроби
void TestReducation(TestRunner &tr, Rational fraction){
	string testReducationFraction = to_string(fraction.Numerator()) + "/" + to_string(fraction.Denominator());
	tr.assertEqual(testReducationFraction, "5/1");
}
void StartTest(){
	TestRunner tr;
	
	Rational fraction(-2,3);
	Rational fraction2(2,-3);
	Rational fraction3(100, 20);
	
	// тест дефолтной дроби
	TestDefaultFraction(tr);

	// тест знаков у дробей
	TestFraction(tr, fraction);
	TestFraction(tr, fraction2);
	
	// тест сокращения дроби
	TestReducation(tr, fraction3);
	
	cout << "Ok" << endl;
}

int main(int argc, char *argv[])
{
	StartTest();
}
