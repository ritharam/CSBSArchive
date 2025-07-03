#include <vector>
#include <iostream>
#define MAXN 50
#define MAXM 100
#define INF 9999
using namespace std;
struct Node
{
    int Vertex;
    int Visited[MAXN];
    int nVisited;
    int Path[MAXN];
    int CostMatrix[MAXN][MAXN];
    int Cost;
    bool Alive;
};
void Copy(int a[][MAXN], int b[][MAXN], int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            b[i][j] = a[i][j];
}
void Initialize(Node S[], int i, int n)
{
    int j;
    S[i].Alive = true;
    S[i].Cost = INF;
    for (int j = 1; j <= n; j++)
    {
        S[i].Visited[j] = false;
    }
    S[i].nVisited = 0;
}
int ReduceMatrix(int Cost[][MAXN], int n)
{
    int i, j;
    int totalCost = 0, min;
    for (i = 1; i <= n; i++)
    {
        min = Cost[i][1];
        for (j = 2; j <= n; j++)
        {
            if (Cost[i][j] < min)
                min = Cost[i][j];
        }
        for (j = 1; j <= n; j++)
        {
            if (min != INF && Cost[i][j] != INF)
                Cost[i][j] -= min;
        }
        if (min != INF)
            totalCost += min;
    }
    for (j = 1; j <= n; j++)
    {
        min = Cost[1][j];
        for (i = 2; i <= n; i++)
        {
            if (Cost[i][j] < min)
                min = Cost[i][j];
        }
        for (i = 1; i <= n; i++)

        {
            if (min != INF && Cost[i][j] != INF)
                Cost[i][j] -= min;
        }
        if (min != INF)
            totalCost += min;
    }
    return totalCost;
}
int LeastCost(Node S[MAXN], int C)
{
    int c = INF;
    int lc = -1;
    for (int i = 1; i <= C; i++)
    {
        if (S[i].Alive && S[i].Cost < c)
        {
            c = S[i].Cost;
            lc = i;
        }
    }
    return lc;
}
void ShowMatrix(int m[][MAXN], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\n";
        for (int j = 0; j < n; j++)
        {
            cout << "\t" << m[i][j];
        }
    }
}
void KillNodes(Node S[], int C, int cost)
{
    for (int i = 1; i <= C; i++)
    {
        if (S[i].Alive)
        {
            if (S[i].Cost > cost)
            {
                S[i].Alive = false;
            }
        }
    }
}
Node TSP(int Cost[][MAXN], int n, int s)
{
    Node S[MAXM];
    int C, i, j, k, u, v, costReduced;
    int nUnVisited;
    int sNode = 0;
    C = 0;
    C++;
    Initialize(S, C, n);
    S[C].Vertex = s;
    S[C].Path[S[C].nVisited++] = s;
    S[C].Visited[s] = true;
    Copy(Cost, S[C].CostMatrix, n);
    S[C].Cost = ReduceMatrix(S[C].CostMatrix,n);
    while ((i = LeastCost(S, C)) != -1)
    {
        S[i].Alive = false;
        nUnVisited = 0;
        for (j = 1; j <= n; j++)
        {
            if (!S[i].Visited[j])
            {
                nUnVisited++;
                u = S[i].Vertex;
                v = j;
                C++;
                S[C] = S[i];
                S[C].Alive = true;
                S[C].Vertex = v;
                S[C].Path[S[C].nVisited++] = v;
                S[C].Visited[v] = true;
                for (k = 1; k <= n; k++)
                {
                    S[C].CostMatrix[u][k] = INF;
                    S[C].CostMatrix[k][v] = INF;
                }
                S[C].CostMatrix[v][s] = INF;
                costReduced = ReduceMatrix(S[C].CostMatrix, n);
                S[C].Cost = S[i].Cost + costReduced + S[i].CostMatrix[u][v];
            }
        }
        // If no more nodes to visit for ith node
        if (nUnVisited == 0)
        {
            KillNodes(S, C, S[i].Cost);
            S[i].Path[S[i].nVisited++] = s;
            sNode = i;
        }
    }
    return S[sNode];
}

int main()
{
    // Cost: 28
    /* int n=5;
    int s=3;
    int CostMatrix[MAXN][MAXN] = { {0,0, 0, 0, 0, 0},
                                {0,INF, 20, 30, 10, 11},
                                {0,15, INF, 16, 4, 2},
                                {0,3, 5, INF, 2, 4},
                                {0,19, 6, 18, INF, 3},
                                {0,16, 4, 7, 16, INF}};*/
    /*
    // Cost 34
    int n=5;
    int s=3;
    int CostMatrix[MAXN][MAXN] = {
    { 0, 0, 0, 0, 0, 0 },
    { 0, INF, 10, 8, 9, 7 },
    { 0, 10, INF, 10, 5, 6 },
    { 0, 8, 10, INF, 8, 9 },
    { 0, 9, 5, 8, INF, 6 },
    { 0, 7, 6, 9, 6, INF }};
    */
    /*
    //Cost: 16
    int n=5;
    int s=1;
    int CostMatrix[MAXN][MAXN] = {
    { 0, 0, 0, 0, 0, 0 },
    {0, INF, 3, 1, 5, 8},
    {0, 3,INF, 6, 7, 9},
    {0, 1, 6, INF, 4, 2},
    {0, 5, 7, 4, INF, 3},
    {0, 8, 9, 2, 3, INF}};*/
    /*
    //Cost: 8
    int n=4;
    int s=2;
    int CostMatrix[MAXN][MAXN] = {{0, 0,0, 0, 0 },
                                {0, INF, 2, 1, INF},
    {0, 2,INF, 4, 3},
    {0, 1,4, INF, 2},
    {0, INF,3, 2, INF}};*/
    // Cost: 8
    int n = 4;
    int s = 1;
    int CostMatrix[MAXN][MAXN] = {{0, 0,0, 0, 0},
                                  {0, INF,4, 12, 7},
                                  {0, 5,INF, 0, 18},
                                  {0, 11,0, INF, 6},
                                  {0, 10,2, 3, INF}};
    Node sNode = TSP(CostMatrix, n, s);
    cout << "\n\n\tTravelling Salesperson Problem : \n ";
    cout << "\n\tNumber of Vertices: " << n << "[1.. "<<n<<"] ";
    cout << "\n\tStarting Vertex: " << s << "\n";
    cout << "\n\tTour Cost: " << sNode.Cost;
    cout << "\n\tTour: ";
    for (int i = 0; i < sNode.nVisited; i++)
        cout << " " << sNode.Path[i];
    return 0;
}
