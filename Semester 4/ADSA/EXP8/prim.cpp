#include<iostream>
#include<iomanip>
#include<vector>
#define MAX 20
using namespace std;

enum myColor {w,b};

struct vertex
{
    vector<int> adjList;
    int value;
    myColor color;
    int parent;
    int key;
};

class graph
{
    vertex *v;
    int size;
public:
    graph(int);
    void addEdge(int, int);
    void prims(int [][MAX], int);
    bool extractMin(int &);
    void showSpanningTree();
};

graph::graph(int n)
{
    size = n;
    v = new vertex[n];
    for(int i = 0; i < n; i++)
    {
        v[i].value = i;
        v[i].color = w;
        v[i].parent = -1;
        v[i].key = 9999;
    }
}

bool graph::extractMin(int &u)
{
    int min = 9999;
    for(int i = 0; i < size; i++)
    {
        if(v[i].color == w && v[i].key < min)
        {
            min = v[i].key;
            u = i;
        }
    }
    if(min == 9999)
        return false;
    else
        return true;
}

void graph::showSpanningTree()
{
    int minCost = 0;
    cout<<"\n\n\tMinimum Spanning Tree Edges: ";
    for(int i = 0; i < size; i++)
    {
        if(v[i].parent == -1)
            continue;
        cout<<"\n\t";
        cout<<v[i].parent<<"--"<<v[i].value<<":Cost-"<<v[i].key;
        minCost += v[i].key; // Accumulate the minimum cost
    }
    cout<<"\n\n\tMinimum Cost: "<<minCost;
}

void graph::prims(int weigh[][MAX], int r)
{
    v[r].key = 0;
    v[r].parent = -1;
    int u; 
    int c;
    while(extractMin(c))
    {
        for(int p = 0; p < v[c].adjList.size(); p++)
        {
            u = v[c].adjList[p];
            if(v[u].color == w && weigh[c][u] < v[u].key)
            {
                v[u].parent = c;
                v[u].key = weigh[c][u];
            }
        }
        v[c].color = b;
    }
}

void graph::addEdge(int from, int to)
{
    // v[from].adjList.push_back(to);
    v[from].adjList.insert(v[from].adjList.end(), to);
}

int main()
{
    int n;
    n = 9;
    int b[][MAX]={ {0,4,0,0,0,0,0,8,0},
                   {4,0,8,0,0,0,0,11,0},
                   {0,8,0,7,0,4,0,0,2},
                   {0,0,7,0,9,14,0,0,0},
                   {0,0,0,9,0,10,0,0,0},
                   {0,0,4,14,10,0,2,0,0},
                   {0,0,0,0,0,2,0,1,6},
                   {8,11,0,0,0,0,1,0,7},
                   {0,0,2,0,0,0,6,7,0}};
    graph g(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(b[i][j] != 0)
            {
                g.addEdge(i,j);
            }
        }
    }
    g.prims(b,0);
    cout<<"\n\tPrim's Result: ";
    g.showSpanningTree();
    return 0;    
}

