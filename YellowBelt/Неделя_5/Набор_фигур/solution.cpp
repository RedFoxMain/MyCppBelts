#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <iomanip>
using namespace std;

// Основной класс для фигур
class Figure{
public:
	
	virtual string Name(){}
	virtual float Perimeter(){}
	virtual float Area(){}
};

// клас треугольник
class Triangle: public Figure{
	string shape;
	int a,b,c;
public:
	Triangle(string shape, int a, int b, int c){
		this->shape = shape;
		this->a = a;
		this->b = b;
		this->c = c;
	}
	string Name() override {
		return shape;
	}
	float Area() override {
		float p = (a+b+c)/2;
		return sqrt(p*(p-a)*(p-b)*(p-c));
	}
	float Perimeter() override{
		return float(a)+float(b)+float(c);
	}
};

// класс круг
class Circle: public Figure{
	string shape;
	int r;
public:
	Circle(string shape, int r){
		this->shape = shape;
		this->r = r;
	}
	string Name() override {
		return shape;
	}
	float Area() override {
		return 3.14*pow(r,2);
	}
	float Perimeter() override{
		return 2*3.14*r;
	}
};

// класс прямоугольник
class Rect: public Figure{
	string shape;
	int width, heigth;
public:
	Rect(string shape, int width, int heigth){
		this->shape = shape;
		this->width = width;
		this->heigth = heigth;
	}
	string Name() override {
		return shape;
	}
	float Area() override {
		return float(width)*float(heigth);
	}
	float Perimeter() override{
		return 2*(float(width) + float(heigth));
	}
};

// функция CreateFigure для получения данных
shared_ptr<Figure> CreateFigure(istringstream &is){
	string shape;
	is >> shape;
	if(shape == "RECT"){
		int width, heigth;
		is >> width >> heigth;
		shared_ptr<Rect> r(new Rect(shape, width, heigth));
		return r;
	}
	
	if(shape == "TRIANGLE"){
		int a,b,c;
		is >> a >> b >> c;
		shared_ptr<Triangle> t(new Triangle(shape, a, b, c));
		return t;
	}
	
	if(shape == "CIRCLE"){
		int radius;
		is >> radius;
		shared_ptr<Circle> c(new Circle(shape, radius));
		return c;
		
	}
}

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
