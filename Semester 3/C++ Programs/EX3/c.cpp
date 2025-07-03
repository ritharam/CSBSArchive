// Function Overloading

#include <iostream>

// Function to find the sum of two integers
int add(int a, int b) {
return a + b;
}
// Function to find the sum of three integers
int add(int a, int b, int c) {
return a + b + c;
}
// Function to find the sum of two double numbers
double add(double a, double b) {
return a + b;
}
int main() {
int sum1 = add(5, 7);
int sum2 = add(3, 9, 2);
double sum3 = add(3.5, 2.7);
std::cout << "Sum of 5 + 7: " << sum1 << std::endl;
std::cout << "Sum of 3 + 9 + 2: " << sum2 << std::endl;
std::cout << "Sum of 3.5 + 2.7: " << sum3 << std::endl;
return 0;
}