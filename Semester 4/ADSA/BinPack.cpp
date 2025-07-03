#include <iostream>
#include <math.h>
#define MAXN 20 // Maximum number of Objects
#define MAXM 20 // Maximum number of Bins
using namespace std;
struct Item
{
    int iNo;      // Item number
    float weight; // Weight
};
struct Bin
{
    float C;           // Bin Capacity
    int Objects[MAXN]; // Selected objects' index
    int nObjects;      // number of objects
    float bc;          // balance capacity
    float uc;          // used capacity
};
int ChooseFirstFitBin(Bin B[], int &m, float weight)
{
    for (int j = 1; j <= m; j++)
    {
        if (B[j].bc >= weight)
        {
            return j;
        }
    }
    m++;
    return m;
}
int ChooseBestFitBin(Bin B[], int &m, float weight)
{
    int s = 0;
    float minbc = 9999;
    for (int j = 1; j <= m; j++)
    {
        if (B[j].bc >= weight)
        {
            if (B[j].bc < minbc)
            {
                s = j;
                minbc = B[j].bc;
            }
        }
    }
    if (s != 0)
        return s;
    m++;
    return m;
}
int BinPackingFF(Item Objects[], int n, Bin B[])
{
    int j, m = 0;
    for (int i = 1; i <= n; i++)
    {

        j = ChooseFirstFitBin(B, m,
                              Objects[i].weight);
        B[j].Objects[B[j].nObjects++] =
            Objects[i].iNo;
        B[j].uc += Objects[i].weight;
        B[j].bc -= Objects[i].weight;
    }
    return m;
}
int BinPackingBF(Item Objects[], int n, Bin B[])
{
    int j, m = 0;
    for (int i = 1; i <= n; i++)
    {
        j = ChooseBestFitBin(B, m,
                             Objects[i].weight);
        B[j].Objects[B[j].nObjects++] =
            Objects[i].iNo;
        B[j].uc += Objects[i].weight;
        B[j].bc -= Objects[i].weight;
    }
    return m;
}
void SortDOrder(Item DOrderedObjects[], int n)
{
    Item t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {

            if (DOrderedObjects[j].weight > DOrderedObjects[i].weight)
            {
                t = DOrderedObjects[j];
                DOrderedObjects[j] =
                    DOrderedObjects[i];
                DOrderedObjects[i] = t;
            }
        }
    }
}
int BinPackingFFD(Item Objects[], int n, Bin B[])
{
    Item DOrderedObjects[MAXN];
    for (int i = 1; i <= n; i++)
        DOrderedObjects[i] = Objects[i];
    SortDOrder(DOrderedObjects, n);
    return BinPackingFF(DOrderedObjects, n, B);
}
int BinPackingBFD(Item Objects[], int n, Bin B[])
{
    Item DOrderedObjects[MAXN];
    for (int i = 1; i <= n; i++)
        DOrderedObjects[i] = Objects[i];

    SortDOrder(DOrderedObjects, n);
    return BinPackingBF(DOrderedObjects, n, B);
}
void InitializeBins(Bin B[], float C)
{
    for (int i = 1; i <= MAXM; i++)
    {
        B[i].C = C;
        B[i].nObjects = 0;
        B[i].bc = C;
        B[i].uc = 0;
    }
}
void ShowBins(Bin B[], int m)
{
    cout << "\n\tNumber of Bins Required: " << m;
    cout << "\n\tObjects Packed in different Bins:";

    for (int i = 1; i <= m; i++)
    {
        cout << "\n\t\tBin-" << i << ": {";
        for (int j = 0; j < B[i].nObjects; j++)
        {
            cout << B[i].Objects[j] << ", ";
        }
        cout << "\b\b}";
    }
}
int main()
{
    int n = 6;
    float C = 10;
    Item Objects[MAXN] = { {0, 0},
                           {1, 5},
                           {2, 6},
                           Bin{3,1},
                               {4, 7},
                               {5, 5},
                               {6, 4}};
    /*
    int n=9;
    float C=1;
    Item Objects[MAXN] = { {0, 0},
    {1, 0.5},
    {2, 0.7},
    {3, 0.5},
    {4, 0.2},
    {5, 0.4},
    {6, 0.2},
    {7, 0.5},
    {8, 0.1},
    {9, 0.6} };
    */
    Bin B[MAXM];
    int m;

    // Finding Lower Bound
    int minBins;
    float tWeight = 0;
    for (int i = 1; i < n; i++)
        tWeight += Objects[i].weight;
    minBins = ceil(tWeight / C);
    cout << "\n\n\tOptimum number of Bins Required:" << minBins;

    // Initialize Bins
    InitializeBins(B, C);
    m = BinPackingFF(Objects, n, B);
    cout << "\n\n\tApproximation - First Fit: ";
    cout << "\n\t***************************";
    ShowBins(B, m);
    // Initialize Bins
    InitializeBins(B, C);
    m = BinPackingBF(Objects, n, B);
    cout << "\n\n\tApproximation - Best Fit: ";
    cout << "\n\t***************************";
    ShowBins(B, m);
    // Initialize Bins
    InitializeBins(B, C);
    m = BinPackingFFD(Objects, n, B);

    cout << "\n\n\tApproximation - First Fit Decreasing : ";
    cout  << "\n\t****************************************";
    ShowBins(B, m);
    // Initialize Bins
    InitializeBins(B, C);
    m = BinPackingBFD(Objects, n, B);
    cout << "\n\n\tApproximation - Best Fit Decreasing : ";
    cout << "\n\t****************************************";
    ShowBins(B, m);
}