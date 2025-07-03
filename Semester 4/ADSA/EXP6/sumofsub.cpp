#include <iostream>
#include <vector> 
using namespace std;

void SumofSubset(int i, int n, int set[], int targetSum, vector<int>& subset)
{
	if (targetSum == 0)
	{
		for (int i=0;i<subset.size();i++)
		{
			cout << subset[i] << " ";
		}
        cout << endl;
		return;
	}
	if (i == n)
	{
		return;
	}
    SumofSubset(i+1,n,set,targetSum,subset);
	if (set[i] <= targetSum)
	{
        subset.push_back(set[i]);
        SumofSubset(i+1,n,set,targetSum - set[i],subset);
        subset.pop_back();
	}
}

int main()
{
	int n,sum;
	cout << "Enter number of elements : ";
	cin >> n;
	int set[n];
	cout << "Enter the subset : " << endl;
	for (int i=0;i<n;i++)
	{
		cin >> set[i];
	}
	cout << "Enter sum value : ";
	cin >> sum;
	vector <int> subset;
	cout << "Subsets are : " << endl;
	SumofSubset(0,n,set,sum,subset);
	return 0;
}