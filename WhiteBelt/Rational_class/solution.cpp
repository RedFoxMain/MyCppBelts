#include <iostream>

class Rational{
public:
        int numerator;
        int denominator;
        int res;
        Rational(): numerator(0), denominator(1) {}
        Rational(int numerator, int denominator){
                if (denominator == 0){
                        throw std::invalid_argument("invalid_argument 0");
                }
                if (denominator < 0 && numerator > 0){
                        this->numerator = numerator * -1;
                        this->denominator = denominator * -1;
                }
                else if (denominator < 0 && numerator < 0){
                        this->numerator = numerator;
                        this->denominator = denominator * -1;
                }
                else{
                        this->numerator = numerator;
                        this->denominator = denominator;
                }
        }
        
public:
        int Numerator(){
                return numerator/NOD(numerator, denominator);
        }

        int Denominator(){
                return denominator/NOD(denominator, numerator);
        }
        
        int NOD(int a, int b){
                int c = a;
                while (a % c != 0 || b % c != 0){ c--; }
                return c;
        }
        // overload operator +
        friend Rational operator+(Rational &a, Rational &b){
                return Rational((a+b).Numerator(), (a+b).Denominator());
        }
        // overload operator -
        friend Rational operator-(Rational &a, Rational &b){
                return Rational((a-b).Numerator(), (a-b).Denominator());
        }
        // overload operator *
        friend Rational operator*(Rational &a, Rational &b){
                return Rational((a*b).Numerator(), (a*b).Denominator());
        }
        // overload operator /
        friend Rational operator/(Rational &a, Rational &b){
                return Rational((a/b).Numerator(), (a/b).Denominator());
        }
        // overload operator ==
        friend bool operator==(Rational &a, Rational &b){
                return ((a.numerator == b.numerator) && (a.Denominator() == b.Denominator()));
        }
        // overload operator !=
        friend bool operator!=(Rational &a, Rational &b){
                return ((a.numerator != b.numerator) || (a.Denominator() != b.Denominator()));
        }
        // overload operator <<
        friend std::ostream &operator<<(std::ostream &os, Rational &a){
                os << a.Numerator() << "/" << a.Denominator() << std::endl;
                return os;
        }
        // Sum
        static double Add(Rational &a, Rational &b){
                return double(b.numerator) / double(b.denominator) + double(a.numerator) / double(a.denominator);
        }
        // Sub
        static double Subdivide(Rational &a, Rational &b){
                return double(b.numerator) / double(b.denominator) - double(a.numerator) / double(a.denominator);
        }
        // Multiply
        static double Multiply(Rational &a, Rational &b){
                return double(a.numerator * b.Numerator()) / double(b.denominator * a.denominator);
        }
        // Divide
        static double Divide(Rational &a, Rational &b){
                return double(b.numerator * a.denominator) / double(a.numerator * b.denominator);
        }
        // equal
        static bool Equal(Rational &a, Rational &b){
                return a == b;
        }
        // not equal
        static bool NotEqual(Rational &a, Rational &b){
                return a != b;
        }
        // Reduce fractals
        static double Reduce(double num){
                return round(num * 100) / 100;
        }
};

int main(){
        Rational NullFraction;
        std::cout << NullFraction << std::endl;

        Rational fraction(3, 5);
        Rational fraction2(1, 4);
        //std::cout << fraction.Numerator() << std::endl;
        //std::cout << fraction.Denominator() << std::endl;
        std::cout << "Сложение: "<< Rational::Add(fraction, fraction2) << std::endl;
        std::cout << "Вычитание: " << Rational::Subdivide(fraction, fraction2) << std::endl;
        std::cout << "Умножение: " << Rational::Reduce(Rational::Multiply(fraction, fraction2)) << std::endl;
        std::cout << "Деление: "<< Rational::Reduce(Rational::Divide(fraction, fraction2)) << std::endl;
        std::cout << "Равны: "<< Rational::Equal(fraction, fraction2) << std::endl;
        std::cout << "Не равны: "<< Rational::NotEqual(fraction, fraction2) << std::endl;

        // overloaded << 
        std::cout << fraction;
        std::cout << fraction2;

}