#include <iostream>
#include <string>

class Animal {
public:
    Animal(std::string name): Name(name){}
    const std::string Name;
};

class Dog: public Animal {
public:
    // ваш код
    Dog(std::string name = "Dog"): Animal(name){} 
    void Bark() {
        std::cout << Name << " barks: woof!" << std::endl;
    }
};

int main(){
        Dog d;
        d.Bark();
}