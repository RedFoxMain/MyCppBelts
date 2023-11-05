#include <iostream>

using namespace std;

class Rational
{
  public:
        int numerator;
        int denominator;
        int res;
        Rational(){
        	this->numerator = 0;
        	this->denominator = 1;
        }
        Rational(int numerator, int denominator)
        {
                if (denominator == 0)
                {
                        throw invalid_argument("invalid_argument 0");
                }
                if(denominator < 0 && numerator > 0){
                	this->numerator = numerator*-1;
                	this->denominator = denominator*-1;
                }
                else if(denominator < 0 && numerator < 0){
                    this->numerator = numerator;
                	this->denominator = denominator*-1;
                }else{
               	 this->numerator = numerator;
               	 this->denominator = denominator;
                }
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
        friend bool operator==(Rational &a, Rational &b){
                return a.numerator==b.numerator && a.Denominator()==b.Denominator();
        }
        // overload operator !=
        friend bool operator!=(Rational &a, Rational &b){
                return a.numerator!=b.numerator || a.Denominator()!=b.Denominator();
        }
        // overload operator <<
        friend ostream& operator<<(ostream &os, Rational &a){
                os << a.numerator << "/" << a.denominator << endl;
                return os;
        }
        // Sum
        static double Add(Rational &a, Rational &b)
        {
                return double(a.numerator) / double(a.denominator)+double(b.numerator)/double(b.denominator);
        }
        // Sub
        static double Subdivide(Rational &a, Rational &b)
        {
                return double(b.numerator)/double(b.denominator) - double(a.numerator) / double(a.denominator);
        }
        // Multiply
        static double Multiply(Rational &a, Rational &b)
        {
                return double(a.numerator*b.Numerator())/double(b.denominator*a.denominator);
        }
        // Divide
        static double Divide(Rational &a, Rational &b)
        {
                return double(b.numerator*a.denominator) / double(a.numerator*b.denominator);
        }
        // equal
        static bool Equal(Rational &a, Rational &b){
                return a==b;
        }
        // not equal
        static bool NotEqual(Rational &a, Rational &b){
                return a!=b;
        }
        // Reduce fractals
        static double Reduce(double num){
                return round(num*100)/100;
        }
};

int main(int argc, char *argv[])
{
        Rational NullFraction;
        cout << NullFraction << endl;
        
        Rational fraction(3, 5);
        Rational fraction2(1, 4);
        //cout << fraction.Numerator() << endl;
        //cout << fraction.Denominator() << endl;
        cout << "Сложение: "<< Rational::Add(fraction, fraction2) << endl;
        cout << "Вычитание: " << Rational::Subdivide(fraction, fraction2) << endl;
        cout << "Умножение: " << Rational::Reduce(Rational::Multiply(fraction, fraction2)) << endl;
        cout << "Деление: "<< Rational::Reduce(Rational::Divide(fraction, fraction2)) << endl;
        cout << "Равны: "<< Rational::Equal(fraction, fraction2) << endl;
        cout << "Не равны: "<< Rational::NotEqual(fraction, fraction2) << endl;

        // overloaded << 
        cout << fraction;
        cout << fraction2;
        
}
