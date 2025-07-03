#include <iostream>
#include <cctype>

template <typename T>
T findMax(const T &a, const T &b) 
{
    return (a > b) ? a : b;
}

template <>
char findMax(const char &a, const char &b) 
{
    char ca = std::tolower(a);
    char cb = std::tolower(b);
    return (ca > cb) ? a : b;
}
int main() 
{
    int intA = 10, intB = 20;
    int maxInt = findMax(intA, intB);
    std::cout << "Max of " << intA << " and " << intB << " is: "<< maxInt << std::endl;
    double doubleA = 12.34, doubleB = 45.67;
    double maxDouble = findMax(doubleA, doubleB);
    std::cout << "Max of " << doubleA << " and " << doubleB <<" is: " << maxDouble << std::endl;
    char charA = 'A', charB = 'b';
    char maxChar = findMax(charA, charB);
    std::cout << "Max of " << charA << " and " << charB << "(case-insensitive) is: " << maxChar << std::endl;
    return 0;
}