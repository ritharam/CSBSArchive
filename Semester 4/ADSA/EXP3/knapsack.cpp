#include <iostream>
using namespace std;
struct object
{
    double W, P, PW;
};
int main()
{
    int n;
    cout << "Enter the number of elements :";
    cin >> n;
    object obj[n], temp, selected[n], sample;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Weight " << i + 1 << " :";
        cin >> obj[i].W;
        cout << "Enter Profit " << i + 1 << " :";
        cin >> obj[i].P;
        obj[i].PW = obj[i].P / obj[i].W;
    }

    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < n; i++)
        {
            if (obj[i].PW < obj[i + 1].PW)
            {
                temp = obj[i];
                obj[i] = obj[i + 1];
                obj[i + 1] = temp;
            }
        }
    }
    int m = 0, C;
    cout << "Enter the capacity of the Knapsack :";
    cin >> C;
    for (int i = 0; i < n; i++)
    {
        if (C == 0)
        {
            cout << "Capacity is Zero !!!";
            break;
        }
        else
        {
            if (obj[i].W <= C)
            {
                selected[m] = obj[i];
                m++;
                C -= obj[i].W;
            }
            else
            {
                sample = obj[i];
                sample.W = C;
                sample.P *= sample.W / obj[i].W;
                selected[m] = sample;
                m++;
                C = 0;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << "Weight " << i + 1 << " :" << selected[i].W << " ";
        cout << "Profit " << i + 1 << " :" << selected[i].P << "\n";
    }
}