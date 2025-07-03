// Inline Function

#include <iostream>

// Inline function to calculate the square of a number
inline int square(int num) 
{
    return num * num;
}

int main() 
{
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    // Calling the inline function
    int result = square(number);
    std::cout << "Square of " << number << " is: " << result << std::endl;
    return 0;
}