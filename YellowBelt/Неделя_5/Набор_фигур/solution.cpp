#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <memory>

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
        std::string shape_;
        int a_, b_, c_;
public:
        Triangle(std::string shape, int a, int b, int c): shape_(shape), a_(a), b_(b), c_(c) {}
        std::string Name() override {
                return shape_;
        }
        float Area() override {
                float perimeter = (a_+b_+c_)/2;
                return sqrt(perimeter*(perimeter - a_)*(perimeter - b_)*(perimeter - c_));
        }
        float Perimeter() override{
                return float(a_)+float(b_)+float(c_);
        }
};

// класс круг
class Circle: public Figure{
private:
        std::string shape_;
        int r_;
public:
        Circle(std::string shape, int r): shape_(shape), r_(r){}
        std::string Name() override {
                return shape_;
        }
        float Area() override {
                return 3.14*pow(r_,2);
        }
        float Perimeter() override{
                return 2*3.14*r_;
        }
};

// класс прямоугольник
class Rect: public Figure{
private:
        std::string shape_;
        int width_, heigth_;
public:
        Rect(std::string shape, int width, int heigth): shape_(shape), width_(width), heigth_(heigth){}
        std::string Name() override {
                return shape_;
        }
        float Area() override {
                return float(width_)*float(heigth_);
        }
        float Perimeter() override{
                return 2*(float(width_) + float(heigth_));
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