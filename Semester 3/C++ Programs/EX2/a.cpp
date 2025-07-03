// Multiply elements in an array

#include <iostream>
using namespace std;

int main() 
{
    int arr[50],mul = 1, n;
    cout << " Enter number of elements to input: ";
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> arr[i];
    for (int i = 0;i<n;i++)
        mul = mul*arr[i];
    cout << "Multiplied elements : " << mul;
    cout << endl;
    return 0;
}