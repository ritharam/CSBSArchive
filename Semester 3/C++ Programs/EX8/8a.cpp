/*Create a class named LIVING_BEINGS that has a private data member – Type_id(integer type; 1 - PLANTS, 
2 -ANIMALS). Include parameterized constructor to initialize this data member. Declare a member function 
whoAmI() that has to be overridden in the derived classes to display the details of the object. Derive a 
class named PLANTS that has data members – Name(String), Flower_Color(string) and EdibleOrNot(bool). Include 
default and parameterized constructors to initialize the values for data members. Invoke parent constructor 
to initialize the parent data member also. Include member functions – myColor(string) – that displays the 
details of the PLANTS objects of a particular Flower_Color (user input). Derive another class named ANIMALS 
that has a data member – Name (String). Include parameterized constructor with 2 arguments - a string and an 
integer. Assign the string input to Name and invoke the base class constructor with integer argument. Include 
member functions – (i) length() - to return the length of the Name member, (ii) overload &gt; operator to 
compare the lengths of Name member and return the Name member of the object whose length is longer. Create 
objects of PLANTS and ANIMALS in main() method, invoke the member functions and demonstrate their functions.*/

#include <iostream>
#include <string>

using namespace std;

class LIVING_BEINGS {
private:
    int Type_id;

public:
    LIVING_BEINGS(int type) : Type_id(type) {}

    virtual void whoAmI() {
        cout << "I am a living being of Type_id " << Type_id << endl;
    }
};

class PLANTS : public LIVING_BEINGS {
private:
    string Name;
    string Flower_Color;
    bool EdibleOrNot;

public:
    PLANTS() : LIVING_BEINGS(1), Name(""), Flower_Color(""), EdibleOrNot(false) {}

    PLANTS(int type, string name, string color, bool edible)
        : LIVING_BEINGS(type), Name(name), Flower_Color(color), EdibleOrNot(edible) {}

    void whoAmI() override {
        cout << "I am a plant named " << Name << " of Flower Color " << Flower_Color << endl;
    }

    void myColor(string color) {
        if (Flower_Color == color) {
            cout << "I am a plant named " << Name << " with Flower Color " << Flower_Color << endl;
        }
    }
};

class ANIMALS : public LIVING_BEINGS {
private:
    string Name;

public:
    ANIMALS(string name, int type) : LIVING_BEINGS(type), Name(name) {}

    int length() {
        return Name.length();
    }

    bool operator>(ANIMALS &other) {
        return Name.length() > other.Name.length();
    }
};

int main() {
    PLANTS plant1(1, "Rose", "Red", true);
    PLANTS plant2(1, "Tulip", "Yellow", true);

    ANIMALS animal1("Lion", 2);
    ANIMALS animal2("Elephant", 2);

    plant1.whoAmI();
    plant2.whoAmI();
    plant1.myColor("Red");

    cout << "Animal 1 Name Length: " << animal1.length() << endl;
    cout << "Animal 2 Name Length: " << animal2.length() << endl;

    if (animal1 > animal2) {
        cout << "Animal 1 has a longer name: " << animal1.length() << endl;
    } else {
        cout << "Animal 2 has a longer name: " << animal2.length() << endl;
    }

    return 0;
}