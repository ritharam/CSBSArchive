#include<vector>
#include<iostream>
#define MAXM 100
#define MAXN 50
using namespace std;

bool isSafe(int board[][MAXN], int n, int row, int col)
{
	int i, j;
	for(i = 0; i < row; i++)
	{
		if(board[i][col])
		{
			return false;
		}
	}
	for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
	{
		if(board[i][j])
		{
			return false;
		}
	}
	for(i = row, j = col; i >= 0 && j < n; i--, j++)
	{
		if(board[i][j])
		{
			return false;
		}
	}
	return true;
}

bool PlaceQueen(int board[MAXM][MAXN], int n, int r, int Solutions[MAXM][MAXN], int &m)
{
	if(r == n)
	{
		int k = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(board[i][j] == 1)
				{
					Solutions[m][k++] = j+1;
				}
			}
		}
		m++;
		return true;
	}
	int c;
	bool res = false;
	for(c = 0; c < n; c++)
	{
		if(isSafe(board, n, r, c))
		{
			board[r][c] = 1;
			res = PlaceQueen(board, n, r+1, Solutions, m) || res;
			board[r][c] = 0;
		}
	}
	return res;
}

bool nQueen(int n, int Solutions[MAXM][MAXN], int &m)
{
	int board[MAXN][MAXN];
	int row;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			board[i][j] = 0;
		}
	}
	row = 0;
	return PlaceQueen(board, n, row, Solutions, m);
}

int main()
{
	int n;
	cout<<"Enter the number of queens: ";
	cin>>n;
	int Solutions[MAXM][MAXN];
	int m = 0;
	
	cout<<"Number of Queens: "<<n;
	if(!nQueen(n, Solutions, m))
	{
		cout<<"\nCannot be solved...";
		return 0;
	}
	int i,j;
	cout<<"\nNumber of Solutions Found: "<<m;
	for(i = 0; i < m; i++)
	{
		cout<<"\n"<<i+1<<".[";
		for(j = 0; j < n; j++)
		{
			cout<<Solutions[i][j]<<" ";
		}
		cout<<"]";
	}
	cout<<"\n";
	return 0;
}
