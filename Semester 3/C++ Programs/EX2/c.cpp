// Weather in two cities 

#include <iostream>
using namespace std;

int main() 
{
    int C=2, W=7, temp[C][W];
    int i,j;
    for (i=0;i<C;i++)
    {
    for (j=0;j<W;j++)
    {
        cout << "City " << i+1 << "Day " << j+1;
        cin >> temp[i][j];
    }}
    for (i=0;i<C;i++)
        for (j=0;j<W;j++)
            cout << "City " << i+1 << "Day " << j+1 << " : " << temp[i][j] << endl;
}