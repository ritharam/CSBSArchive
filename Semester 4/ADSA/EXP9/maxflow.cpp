#include <iostream>
#include <vector>

#define MAX 20
#define INF 99999
using namespace std;

enum MyColor{ W, G, B };

struct Vertex
{
    vector<int> AdjList; // To store the indices of vertex
    int Value;           // For easy understanding, the index will be stored as vertex value
    MyColor Color;       // Flag used to represent a vertex is visited or not
    int Dist;            // Stores the shortest distance from the starting vertex to current vertex
    int Parent;          // Index of the parent vertex in the resultant BFS tree
};

// This function is to perform BFS on graph and obtaining best path in Path[] array
int PathBFS(int b[][MAX], int n, int s, int t, int Path[])
{
    Vertex *V;
    int size;
    size = n;
    V = new Vertex[size];
    for (int i = 0; i < size; i++)
    {
        V[i].Value = i;
        V[i].Color = W;
        V[i].Dist = 9999; // Assumed as Infinity
        V[i].Parent = -1;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (b[i][j] != 0)
            {
                V[i].AdjList.insert(V[i].AdjList.end(), j);
            }
        }
    }
    // Visit the starting vertex
    V[s].Color = G;
    V[s].Dist = 0;
    V[s].Parent = -1;
    // Create an empty queue & Insert the starting node(index) into the Queue
    vector<int> Q;
    Q.push_back(s);
    int c;
    int u;
    while (Q.size() > 0)
    {
        // Popping an Element
        c = Q.at(0);
        Q.erase(Q.begin());
        for (int p = 0; p < V[c].AdjList.size(); p++)
        {
            u = V[c].AdjList[p];
            if (V[u].Color == W)
            {
                V[u].Color = G;
                V[u].Dist = V[c].Dist + 1;
                V[u].Parent = c;
                Q.push_back(u);
            }
        }
        V[c].Color = B;
    }
    // Optaining Path (in reverse: t to s)
    int cnt = 0;
    Path[cnt++] = t;
    while (V[t].Parent != -1)
    {
        Path[cnt++] = V[t].Parent;
        t = V[t].Parent;
    }
    // Reversing path to obtain original path: s to t
    for (int i = 0, j = cnt - 1; i < j; i++, j--)
    {
        t = Path[i];
        Path[i] = Path[j];
        Path[j] = t;
    }
    return cnt;
}

int MaxFlow(int b[][MAX], int n, int s, int t) 
{
    int Path[MAX], cnt, u, v, i;
    int maxFlow, minCap;
    maxFlow = 0;
    // Check for a path is exist from s to t
    while ((cnt = PathBFS(b, n, s, t, Path)) > 1)
    {
        minCap = INF;
        cout << "\n\n\tBest Path by BFS: ";
        for (i = 0; i < cnt - 1; i++)
        {
            u = Path[i];
            v = Path[i + 1];
            cout << Path[i] << " --> ";
            if (b[u][v] < minCap)
                minCap = b[u][v];
        }
        cout << Path[i];
        cout << "\n\tMinCap: " << minCap;
        maxFlow += minCap;
        for (i = 0; i < cnt - 1; i++)
            {
                u = Path[i];
                v = Path[i + 1];
                b[u][v] = b[u][v] - minCap;
                b[v][u] = b[v][u] + minCap;
            }
    }
    return maxFlow;
}

int main() 
{
    int n;
    /* n=8;
  int b[][MAX]={ {0,4,0,0,0,6,2,0},
  {0,0,3,0,0,0,0,6},
  {0,0,0,4,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,4,0,0,3,0},
  {0,0,0,0,10,0,0,0},
  {0,0,0,0,0,0,0,3},
  {0,0,0,4,0,0,0,0} };
  */
    n = 10;
    int b[][MAX] = {{0, 12, 0, 0, 0, 20, 0, 3, 0, 0},
                    {0, 0, 5, 0, 0, 0, 0, 0, 6, 0},
                    {0, 0, 0, 13, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 12, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 10, 0, 5, 0, 0, 0},
                    {0, 0, 0, 0, 3, 0, 0, 0, 0, 5},
                    {0, 0, 0, 0, 0, 0, 4, 0, 4, 0},
                    {0, 0, 3, 0, 0, 0, 0, 0, 0, 3},
                    {0, 0, 0, 10, 0, 0, 0, 0, 0, 0}};
    /* //Input Graph-1
        n=6;
        int b[][MAX]={ {0,4,0,0,0,3},
        {0,0,3,0,0,0},
        {0,0,0,2,0,3},
        {0,0,0,0,0,0},
        {0,0,0,6,0,0},
        {0,0,0,0,6,0} };*/
    cout << "\n\n\tMaximum Flow From 0 to 3:"<<MaxFlow(b,n,0,3);
}