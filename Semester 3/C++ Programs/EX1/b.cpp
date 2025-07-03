// PIN verification 

#include <iostream>
using namespace std;

int main() 
{
    int pin = 1234; // Set the correct PIN here
    int enteredPin;
    int maxAttempts = 3;
    for (int attempt = 1; attempt <= maxAttempts; ++attempt) 
    {
        cout << "Enter your PIN : ";
        cin >> enteredPin;
        if (enteredPin == pin) 
        {
            cout << "Pin Verified" << endl;
            cout << "Welcome" << endl;
            return 0;
        } 
        else 
        {
            cout << "Incorrect PIN.";
            int attemptsRemaining = maxAttempts - attempt;
            if (attemptsRemaining > 0) 
            {} 
            else 
            {
                cout << "Limit expired." << endl;
                return 0;
            }
        }
    }
    return 0;
}