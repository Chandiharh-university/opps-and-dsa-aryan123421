#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {
        cout << "Animals make sounds!" << endl;
    }
};
class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks: Woof Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows: Meow Meow!" << endl;
    }
};

int main() {
    Animal* animal;    
    Dog dog;
    Cat cat;           

    
    animal = &dog;
    animal->sound();
    animal = &cat;
    animal->sound();

    return 0;
}
