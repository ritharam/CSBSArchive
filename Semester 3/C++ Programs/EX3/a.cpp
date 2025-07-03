// Return by Value, Return by Reference

#include <iostream>
using namespace std; 

// Function to return by value
int returnByValue(int& x) 
{
    int result = x * 2;
    return result; // Returns a copy of 'result'
}

// Function to return by reference
int& returnByReference(int& x) 
{
    x *= 3;
    return x; // Returns a reference to 'x'
}

int main()
{
    int a = 5;
    std::cout << "Original value of 'a': " << a << std::endl;
    int b = returnByValue(a); // Returns a copy of 'result'
    std::cout << "Original value of 'a': " << a << std::endl;
    int c = returnByReference(a); // Returns a reference to 'a'
    std::cout << "Value returned by value: " << b << std::endl; // Copy of 'result'
    std::cout << "Value returned by reference: " << c << std::endl; // Modified by reference
    std::cout << "Original value of 'a': " << a << std::endl; // Modified by reference
    return 0;
}