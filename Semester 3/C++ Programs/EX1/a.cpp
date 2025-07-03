//  Prime number generation

#include <iostream>
using namespace std;

int main() 
{
    int start, end;
    cout<< "Enter the starting interval: " ;
    cin>> start;
    cout << "Enter the ending interval: ";
    cin >> end;
    cout << "Prime numbers between " << start << "and" << end << "are : ";
    for (int num = start; num <= end; ++num) 
    {
        if (num > 1) 
        {
            bool isPrime = true;
            for (int i = 2; i * i <= num; ++i) 
            {
                if (num % i == 0) 
                {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime)
            {
                cout << num << " ";
            }
        }
    }
    cout << endl;
    return 0;
}