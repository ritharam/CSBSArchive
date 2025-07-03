#include <iostream>
using namespace std;
#define max 999999

void optimalBST(int keys[], int p[], int q[], int n)
{
	int w[n + 1][n + 1];
	int c[n + 1][n + 1];
	int r[n + 1][n + 1];

	for (int len = 1; len <= n + 1; len++)
	{
		for (int i = 0; i <= (n + 1) - len; i++)
		{
			int j = i + len - 1;
			if (i == j)
			{
				w[i][j] = q[i];
			}
			else
			{
				w[i][j] = w[i][j - 1] + p[j - 1] + q[j];
			}
		}
	}

	for (int len = 1; len <= n + 1; len++)
	{
		for (int i = 0; i <= (n + 1) - len; i++)
		{
			int j = i + len - 1;
			if (i == j)
			{
				c[i][j] = r[i][j] = 0;
			}
			else
			{
				int min = max;
				int minK = -1;
				for (int k = i + 1; k <= j; k++)
				{
					int sum = c[i][k - 1] + c[k][j] + w[i][j];
					if (sum < min)
					{
						min = sum;
						minK = k;
					}
				}
				c[i][j] = min;
				r[i][j] = minK;
			}
		}
	}

	cout << "Weight Matrix: " << endl;
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			if (i <= j)
			{
				cout << "\t" << w[i][j];
			}
		}
		cout << endl;
	}

	cout << "Cost Matrix: " << endl;
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			if (i <= j)
			{
				cout << "\t" << c[i][j];
			}
		}
		cout << endl;
	}

	cout << "Root Matrix: " << endl;
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			if (i <= j)
			{
				cout << "\t" << r[i][j];
			}
		}
		cout << endl;
	}
}

int main()
{
	int keys[4] = {10, 20, 30, 40};
	int p[4] = {3, 3, 1, 1};
	int q[5] = {2, 3, 1, 1, 1};
	int n;

	cout << "Enter the number of keys: ";
	cin >> n;
	/*
		cout<<"Enter the keys: "<<endl;
		for(int i = 0; i < n; i++)
		{
		 cin>>keys[i];
		}

		cout<<"Enter the successful probabilities: "<<endl;
		for(int i = 0; i < n; i++)
		{
		 cin>>p[i];
		}

		cout<<"Enter the unsuccessful probabilities: "<<endl;
		for(int i = 0; i < n+1; i++)
		{
		 cin>>q[i];
		}*/

	optimalBST(keys, p, q, n);
	return 0;
}