#include <iostream>

class Base {
public:
    virtual void show() = 0; // Pure Virtual Function
};

class Derived : public Base {
public:
    void show() {
        std::cout << "Implementation of Virtual Function in Derived class" << std::endl;
    }
};

int main() {
    // Base obj; // This line should be commented out since Base is an abstract class.

    Base *b;
    Derived d;
    b = &d;
    b->show(); // Calls the show() function of the Derived class.
   
    return 0;
}