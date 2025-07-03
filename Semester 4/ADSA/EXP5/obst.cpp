#include<iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter number of keys : " << endl;
	cin >> n;
	int Q[n+1];
	int Keys[n+1];
	int P[n+1];
	cout << "Enter Keys P:" << endl;
	for (int i = 0;i < n;i++)
	{
		cin >> Keys[i];
	}
	for (int i = 0;i < n;i++)
	{
		cin >> P[i];
	}
	cout << "Enter Q :" << endl;
	for (int i = 0;i <= n;i++)
	{
		cin >> Q[i];
	}
	for (int i = 0;i <= n;i++)
	{
		cout << "Keys :" << Keys[i] << " " << endl;
	}
	for (int i = 0;i <= n;i++)
	{
		cout << "P :" << P[i] << " " << endl;
	}
	for (int i = 0;i <= n;i++)
	{
		cout << "Q :" << Q[i] << " " << endl;
	}

	int C[n+1][n+1], W[n+1][n+1], R[n+1][n+1];
	
	for (int len = 1;len<=n+1;len++)
	{
		for (int i = 0;i <= (n+1)-len;i++)
		{
			int j = i + len - 1;
			if (i == j)
				W[i][j] = Q[i];
			else
				W[i][j] = W[i][j-1] + P[j-1] + Q[j];
		}
	}
	for (int len = 1;len<=n+1;len++)
	{
		for (int i = 0;i <= (n+1)-len;i++)
		{
			int j = i + len - 1;
			if (i == j)
				C[i][j] = R[i][j] = 0;
			else
			{
				int min = 99999;
				int mink = -1;
				for (int k=i+1;k<=j;k++)
				{
					int sum = C[i][k-1] + C[k][j] + W[i][j];
					if (sum < min)
					{
						min = sum;
						mink = k;
					}
				}
			C[i][j] = min;
			R[i][j] = mink;
			}
		}
	}

	for (int i=0;i<=n+1;i++)	
	{	
		for (int j=0;j<=n-i+1;j++)
		{
			cout << W[i][j] << " "; 
		}
		cout << " " << endl;
	} 
	for (int i=0;i<=n+1;i++)	
	{	
		for (int j=0;j<=n-i+1;j++)
		{
			cout << C[i][j] << " ";
		}
		cout << " " << endl;
	} 
	for (int i=0;i<=n+1;i++)	
	{	
		for (int j=0;j<=n-i+1;j++)
		{
			cout << R[i][j] << " ";
		}
		cout << " " << endl;
	} 
	return 0;
}
