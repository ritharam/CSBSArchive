#include<iostream>
#include<ctime>
#include<cstdlib>
#include<tuple>
using namespace std;

int count1 = 0;
int count2 = 0;

void msa_bruteforce(int arr[], int n)
{
    int s,e, mSum = 0;
    s = e = -1;
    for (int i=0;i<n;i++)
    {
        count1++;
        int sum = 0;
        int j;
        for (j=i;j<n;j++)
        {
            count1++;
            sum += arr[j];
        }
        if (sum > mSum)
        {
            s = i;
            e = j;
            mSum = sum;
        }
    }
    cout << count1 << endl;
    cout << "Vertex : " << s+1 << e  << endl;
    cout << "Sum : " << mSum  << endl;
}

tuple<int, int, int> msa_cross(int arr[], int l, int m, int h)
{
    int lSum = arr[m], 
        lMaxIndex = m;
    int Sum = arr[m];
    for (int i=m-1;i>=l;i--)
    {
        count2++;
        Sum += arr[i];
        if (Sum > lSum)
        {
            lSum = Sum;
            lMaxIndex = i;
        }
    }
    int rSum = arr[m+1], 
        rMaxIndex = m+1;
    Sum = arr[m+1];
    for (int i=m+2;i<=h;i++)
    {
        count2++;
        Sum += arr[i];
        if (Sum > rSum)
        {
            rSum = Sum;
            rMaxIndex = i;
        }
    }
    return make_tuple(lMaxIndex,rMaxIndex,lSum+rSum);  
}

tuple<int, int, int> msa_dc(int arr[],int l,int h)
{
    if (l==h)
    {
        return make_tuple(l, h, arr[l]);
    }   
    int m = (l+h)/2;
    int low1,high1,sum1,low2,high2,sum2,low3,high3,sum3;
    tie(low1, high1, sum1) = msa_dc(arr, l, m);
    tie(low2, high2, sum2) = msa_dc(arr, m+1, h);
    tie(low3, high3, sum3) = msa_cross(arr, l, m, h);
    if (sum1>sum2 && sum1>sum3) 
        return make_tuple(low1, high1, sum1); 
    else if (sum2 > sum3) 
        return make_tuple(low2, high2, sum2); 
    else 
        return make_tuple(low3, high3, sum3); 
}

int main()
{
    int n, *arr;
    cout << "Enter number of values in the array : ";
    cin >> n;
    arr = new int[n];
    for (int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    // arr={3,-5,8,-4,2,-6,2,9,-2,1};
    // srand((long int)clock());
    // for (int i=0;i<n;i++)
    // {
    //     arr[i] = rand();
    // }

    cout << "Number of active operations" << endl;
    cout << "Brute force (O(n³)) | ";
    msa_bruteforce(arr, n);
    cout << "Divide & Conquer (O(nlogn)) | " << endl;
    int l, h, sum;
    tie(l,h,sum) = msa_dc(arr,0,n);
    cout << "Vertex" << l << h << endl;
    cout << "Sum : " << sum;
    return 0;
}