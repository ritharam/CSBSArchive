// Calculator 

#include <iostream>
using namespace std;

int main() 
{
    float num1, num2;
    char op;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter an operator (+, -, *, /) :" ;
    cin >> op;
    cout << "Enter second number: ";
    cin >> num2;
    float result;
    switch (op) 
    {
        case '+':
            result = num1 + num2;
            break;
    case '-':
            result = num1 - num2;
            break;
    case '*':
            result = num1 * num2;   
            break;
    case '/':
            if (num2 != 0) 
            {
                result = num1 / num2;
            } 
            else 
            {
                cout << "Error: Division by zero is not allowed!" << endl;
                return 1; // Return with an error code
            }
            break;  
    default:
            cout << "Error: Invalid operator!" << endl;
            return 1; // Return with an error code
    }
    cout << "Result:" << result << endl;
    return 0;
}