#include <iostream>
#include <vector>

using namespace std;

class Rational
{
  public:
	int numerator;
	int denominator;
	int res;
	Rational(){}
	Rational(int numerator, int denominator)
	{
		if (denominator == 0)
		{
			throw invalid_argument("invalid_argument 0");
		}
		this->numerator = numerator;
		this->denominator = denominator;
	}

	int Numerator()
	{
		return numerator;
	}

	int Denominator()
	{
		return denominator;
	}
	// overload operator +
	friend Rational operator+(Rational &a, Rational &b)
	{
		Rational c;
		c.numerator = a.numerator + b.numerator;
		c.denominator = a.denominator + b.denominator;
		return c;
	}
	// overload operator -
	friend Rational operator-(Rational &a, Rational &b)
	{
		Rational c;
		c.numerator = a.numerator - b.numerator;
		c.denominator = a.denominator - b.denominator;
		return c;
	}
	// overload operator *
	friend Rational operator*(Rational &a, Rational &b)
	{
		Rational c;
		c.numerator = a.numerator * b.numerator;
		c.denominator = a.denominator * b.denominator;
		return c;
	}
	// overload operator /
	friend Rational operator/(Rational &a, Rational &b)
	{
		Rational c;
		c.numerator = a.numerator / b.numerator;
		c.denominator = a.denominator / b.denominator;
		return c;
	}
	// overload operator %
	friend Rational operator%(Rational &a, Rational &b)
	{
		Rational c;
		c.numerator = a.numerator % b.numerator;
		c.denominator = a.denominator % b.denominator;
		return c;
	}
	// overload operator ==
	friend bool operator==(Rational a, Rational b){
		return a.Numerator()==b.Numerator() && a.Denominator()==b.Denominator();
	}
	// overload operator !=
	friend bool operator!=(Rational a, Rational b){
		return a.Numerator()!=b.Numerator() || a.Denominator()!=b.Denominator();
	}
	// overload operator <<
	friend void operator<<(ostream &os, Rational a){
		os << a.Numerator() << "/" << a.Denominator() << endl;
	}
	// Sum
	static double sum(Rational &a, Rational &b)
	{
		return double(a.Numerator()) / double(a.Denominator())+double(b.Numerator())/double(b.Denominator());
	}
	// Sub
	static double sub(Rational &a, Rational &b)
	{
		return double(a.Numerator()) / double(a.Denominator())-double(b.Numerator())/double(b.Denominator());
	}
	// Multiply
	static double mul(Rational &a, Rational &b)
	{
		return double(a.Numerator()*b.Numerator())/double(b.Denominator()*a.Denominator());
	}
	// Divide
	static double div(Rational &a, Rational &b)
	{
		return double(a.Numerator()*b.Denominator())/double(b.Numerator()*a.Denominator());
	}
	// equal
	static bool Equal(Rational a, Rational b){
		return a==b;
	}
	// not equal
	static bool NotEqual(Rational a, Rational b){
		return a!=b;
	}
	// Reduce fractals
	static double Reduce(double num){
		return round(num*100)/100;
	}
};

int main(int argc, char *argv[])
{
	Rational fraction(1, 4);
	Rational fraction2(1, 2);
	//cout << fraction.Numerator() << endl;
	//cout << fraction.Denominator() << endl;
	cout << "Сложение: "<< Rational::sum(fraction, fraction2) << endl;
	cout << "Вычитание: " << Rational::sub(fraction, fraction2) << endl;
	cout << "Умножение: " << Rational::Reduce(Rational::mul(fraction, fraction2)) << endl;
	cout << "Деление: "<< Rational::div(fraction, fraction2) << endl;
	cout << "Равны: "<< Rational::Equal(fraction, fraction2) << endl;
	cout << "Не равны: "<< Rational::NotEqual(fraction, fraction2) << endl;
	
	// overloaded << 
	cout << fraction;
	cout << fraction2;
}
