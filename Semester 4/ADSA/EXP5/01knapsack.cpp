#include<iostream>
using namespace std;

int main()
{
	int n, C;
	cout << "Number of elements : ";
	cin >> n;
	int W[n+1], P[n+1];
	W[0] = 0;
	P[0] = 0;
	for (int i=1;i<=n;i++)
	{
		cin >> W[i] >> P[i];
	}
	cout << "Enter the Capacity : ";
	cin >> C;
	int M[n+1][C+1];
	for (int i=0;i<n+1;i++)
	{
		for (int j=0;j<C+1;j++)
		{	
			M[i][j] = 0;
		}
	}
	for (int j=0;j<=C;j++)
	{
		M[0][j] = 0;
	}
	for (int i=0;i<=n;i++)
	{
		M[i][0] = 0;
	}
	for (int i=1;i<=n;i++)
	{	
		for (int j=1;j<W[i];j++)
		{	
			M[i][j] = M[i-1][j];	
		}
		for (int j=W[i];j<=C;j++)
		{
			if ((M[i-1][j]) > (P[i] + M[i-1][j-W[i]]))
				M[i][j] = M[i-1][j];
			else
				M[i][j] = P[i] + M[i-1][j-W[i]];
		}
	}
	cout << "Knapsack : " << endl;
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=C;j++)
		{	
			cout << M[i][j] << " ";
		}
	cout << endl;
	}
	return 0;
} 