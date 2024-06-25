#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <iomanip>

// Основной класс для фигур
class Figure{
public:
        virtual std::string Name(){}
        virtual float Perimeter(){}
        virtual float Area(){}
};

// клас треугольник
class Triangle: public Figure{
private:
        std::string _shape;
        int _a, _b, _c;
public:
        Triangle(std::string shape, int a, int b, int c): _shape(shape), _a(a), _b(b), _c(c) {}
        std::string Name() override {
                return _shape;
        }
        float Area() override {
                float perimeter = (_a+_b+_c)/2;
                return sqrt(perimeter*(perimeter - _a)*(perimeter - _b)*(perimeter - _c));
        }
        float Perimeter() override{
                return float(_a)+float(_b)+float(_c);
        }
};

// класс круг
class Circle: public Figure{
private:
        std::string _shape;
        int _r;
public:
        Circle(std::string shape, int r): _shape(shape), _r(r){}
        std::string Name() override {
                return _shape;
        }
        float Area() override {
                return 3.14*pow(_r,2);
        }
        float Perimeter() override{
                return 2*3.14*_r;
        }
};

// класс прямоугольник
class Rect: public Figure{
private:
        std::string _shape;
        int _width, _heigth;
public:
        Rect(std::string shape, int width, int heigth): _shape(shape), _width(width), _heigth(heigth){}
        std::string Name() override {
                return _shape;
        }
        float Area() override {
                return float(_width)*float(_heigth);
        }
        float Perimeter() override{
                return 2*(float(_width) + float(_heigth));
        }
};

// функция CreateFigure для получения данных
std::shared_ptr<Figure> CreateFigure(std::istringstream &is){
        std::string shape;
        is >> shape;
        if(shape == "RECT"){
                int width, heigth;
                is >> width >> heigth;
                std::shared_ptr<Rect> rect(new Rect(shape, width, heigth));
                return rect;
        }

        if(shape == "TRIANGLE"){
                int a,b,c;
                is >> a >> b >> c;
                std::shared_ptr<Triangle> triangle(new Triangle(shape, a, b, c));
                return triangle;
        }

        if(shape == "CIRCLE"){
                int radius;
                is >> radius;
                std::shared_ptr<Circle> circle(new Circle(shape, radius));
                return circle;

        }
}

int main() {
  std::vector<std::shared_ptr<Figure>> figures;
  for (std::string line; std::getline(std::cin, line); ) {
    std::istringstream is(line);

    std::string command;
    is >> command;
    if (command == "ADD") {
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        std::cout << std::fixed << std::setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << std::endl;
      }
    }
  }
  return 0;
}