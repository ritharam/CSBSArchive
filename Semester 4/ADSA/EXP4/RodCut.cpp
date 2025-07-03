#include <iostream>
using namespace std;

int CutRod1_DC(int P[], int n)
{
    if (n == 0)
        return 0;
    int maxRev = -99999;
    for (int i = 0; i < n; i++)
    {
        int Rev = CutRod1_DC(P, n - i - 1);
        if ((P[i] + Rev) > maxRev)
            maxRev = P[i] + Rev;
    }
    return maxRev;
}

int MCR(int P[], int n, int *R[]);

int CutRod2_TDM(int P[], int n)
{
    int *R = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        R[i] = -99999;
    }
    return MCR(P, n, &R);
}

int MCR(int P[], int n, int *R[])
{
    if ((*R)[n] >= 0)
        return (*R)[n];
    if (n == 0)
    {
        (*R)[0] = 0;
        return 0;
    }
    int q = -99999;
    for (int i = 0; i < n; i++)
    {
        int r = MCR(P, n - i - 1, R);
        if ((P[i] + r) > q)
        {
            q = P[i] + r;
        }
    }
    (*R)[n] = q;
    return q;
}

int CutRod3_DP(int P[], int n)
{
    int *R;
    R = new int[n + 1];
    R[0] = 0;
    for (int j = 1; j <= n; j++)
    {
        int maxRev = -99999;
        for (int i = 0; i < j; i++)
        {
            int Rev = R[j - i - 1];
            if ((P[i] + Rev) > maxRev)
            {
                maxRev = P[i] + Rev;
            }
        }
        R[j] = maxRev;
    }
    return R[n];
}

int main()
{
    int n, *P;
    cout << "Enter n: " << endl;
    cin >> n;
    P = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> P[i];
    }
    cout << "Rod Cutting (Top Down-Recursive) : ";
    int x = CutRod1_DC(P, n);
    cout << x << endl;
    cout << "Rod Cutting (Dynamic Programming) : ";
    int y = CutRod3_DP(P, n);
    cout << y << endl;
    cout << "Rod Cutting (Top Down Memorization) : ";
    int z = CutRod2_TDM(P, n);
    cout << z << endl;
    return 0;
}