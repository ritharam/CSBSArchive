#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
using namespace std;

int count = 0;

void InsertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        count++;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            count++;
        }
        arr[j + 1] = key;
    }
}

void merge(int *array, int l, int m, int r)
{
    int i, j, k, nl, nr;
    nl = m - l + 1;
    nr = r - m;
    int L[nl], R[nr];
    for (i = 0; i < nl; i++)
    {
        count++;
        L[i] = array[l + i];
    }
    for (j = 0; j < nr; j++)
    {
        count++;
        R[j] = array[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < nl && j < nr)
    {
        count++;
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < nl)
    {
        array[k] = L[i];
        i++;
        k++;
        count++;
    }
    while (j < nr)
    {
        array[k] = R[j];
        j++;
        k++;
        count++;
    }
}
void MergeSort(int *array, int l, int r)
{
    int m;
    if (l < r)
    {
        int m = l + (r - l) / 2;
        count++;
        MergeSort(array, l, m);
        MergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }
}

int main()
{
    int i, j, t;

    ofstream outf;
    ifstream inf;

    int n;
    int *a;

    cout << "\nEnter n:";
    cin >> n;
    a = new int[n];

    // Loading numbers to input file
    outf.open("in.txt");
    srand((long int)clock());
    for (int i = 0; i < n; i++)
    {
        outf << "\t" << rand() % n;
    }
    outf.close();

    // Analysis of Insertion Sort
    cout << "\n\nAnalysis of Insertion Sort\n";
    cout << setfill('-') << setw(80) << "-";
    // Reading input in array from input file
    inf.open("in.txt");
    for (int i = 0; i < n; i++)
    {
        inf >> a[i];
    }
    inf.close();

    // Insertion Sort - Unordered Array
    // The array contains random elements

    count = 0;
    InsertionSort(a, n);
    // Writing sorted numbers to output file
    outf.open("InsertOut1.txt");
    for (int i = 0; i < n; i++)
    {
        outf << "\t" << a[i];
    }
    outf.close();
    cout << "\nInsertion Sort - No. of Operations - Random Order: " << count;

    // Insertion Sort - Sorted Array (Ascending)
    // Now the array a contains numbers in ascending order

    count = 0;
    InsertionSort(a, n);
    // Writing sorted numbers to output file
    outf.open("InsertOut2.txt");
    for (int i = 0; i < n; i++)
    {
        outf << "\t" << a[i];
    }
    outf.close();
    cout << "\nInsertion Sort - No. of Operations - Sorted Array (Ascending): " << count;

    // Insertion Sort - Sorted Array (Descending)

    // Reverse the content of a
    for (i = 0, j = n - 1; i < j; i++, j--)
    {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    // Now the array a contains numbers in descending order
    count = 0;
    InsertionSort(a, n);
    // Writing sorted numbers to output file
    outf.open("InsertOut3.txt");
    for (int i = 0; i < n; i++)
    {
        outf << "\t" << a[i];
    }
    outf.close();
    cout << "\nInsertion Sort - No. of Operations - Sorted Array (Descending): " << count;

    // Analysis of Merge Sort
    cout << "\n\nAnalysis of Merge Sort\n";
    cout << setfill('-') << setw(80) << "-";
    // Reading input in array from input file

    inf.open("in.txt");
    for (int i = 0; i < n; i++)
    {
        inf >> a[i];
    }
    inf.close();

    // Merge Sort - Unordered Array
    // The array contains random elements

    count = 0;
    MergeSort(a, 0, n - 1);
    // Writing sorted numbers to output file
    outf.open("MergeOut1.txt");
    for (int i = 0; i < n; i++)
    {
        outf << "\t" << a[i];
    }
    outf.close();
    cout << "\nMerge Sort - No. of Operations - Random Order: " << count;

    // Merge Sort - Sorted Array (Ascending)
    // Now the array a contains numbers in ascending order

    count = 0;
    MergeSort(a, 0, n - 1);
    // Writing sorted numbers to output file
    outf.open("MergeOut2.txt");
    for (int i = 0; i < n; i++)
    {
        outf << "\t" << a[i];
    }
    outf.close();
    cout << "\nMerge Sort - No. of Operations - Sorted Array (Ascending): " << count;

    // Merge Sort - Sorted Array (Descending)

    // Reverse the content of a
    for (i = 0, j = n - 1; i < j; i++, j--)
    {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    // Now the array a contains numbers in descending order
    count = 0;
    MergeSort(a, 0, n - 1);
    // Writing sorted numbers to output file
    outf.open("MergeOut3.txt");
    for (int i = 0; i < n; i++)
    {
        outf << "\t" << a[i];
    }
    outf.close();
    cout << "\nMerge Sort - No. of Operations - Sorted Array (Descending): " << count;

    delete (a);
}
