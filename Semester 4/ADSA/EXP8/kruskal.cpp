#include<iostream>
#define MAX 20
using namespace std;

enum myColor {w,b};

struct edge
{
    int u,v;
    int cost;
    myColor color;
};

struct vertex
{
    int value;
    int set;
};

class graph
{
    edge *E;
    vertex *V;
    int nv, ne;
public:
    graph(int, int, int[][MAX]);
    void kruskals();
    void sortEdges();
    void showSpanningTree();
};

void graph::sortEdges()
{
    edge t;
    for(int i = 0; i < ne; i++)
    {
        for(int j = i+1; j < ne; j++)
        {
            if(E[j].cost < E[i].cost)
            {
                t = E[j];
                E[j] = E[i];
                E[i] = t;
            }
        }
    }
}

graph::graph(int e, int v, int weigh[][MAX])
{
    ne = e;
    nv = v;
    E = new edge[ne];
    V = new vertex[nv];
    
    int k = 0;
    for(int i = 0; i < nv; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(weigh[i][j] != 0)
            {
                E[k].u = i;
                E[k].v = j;
                E[k].cost = weigh[i][j];
                E[k].color = w;
                k++;
            }
        }
        V[i].value = i;
        V[i].set = i;
    }
}

void graph::showSpanningTree()
{
    int minCost = 0;
    cout<<"\n\n\tMinimum Spanning Tree Edges:";
    for(int i = 0; i < ne; i++)
    {
        if(E[i].color == b)
        {
            cout<<"\n\t";
            cout<<E[i].u<<"--"<<E[i].v<<":Cost-"<<E[i].cost;
            minCost += E[i].cost;
        }
    }
    cout<<"\n\n\tMinimum Cost: "<<minCost;
}

void graph::kruskals()
{
    sortEdges();
    for(int i = 0; i < ne; i++)
    {
        if(V[E[i].u].set != V[E[i].v].set)
        {
            E[i].color = b;
            for(int j = 0; j < nv; j++)
            {
                if(V[j].set == V[E[i].u].set)
                    V[j].set = V[E[i].v].set;
            }
        }
    }
}

int main()
{
    int nv = 9;
    int ne = 14;
    int b[][MAX]={ {0,4,0,0,0,0,0,8,0},
                   {4,0,8,0,0,0,0,11,0},
                   {0,8,0,7,0,4,0,0,2},
                   {0,0,7,0,9,14,0,0,0},
                   {0,0,0,9,0,10,0,0,0},
                   {0,0,4,14,10,0,2,0,0},
                   {0,0,0,0,0,2,0,1,6},
                   {8,11,0,0,0,0,1,0,7},
                   {0,0,2,0,0,0,6,7,0}};
    graph g(ne, nv, b);
    g.kruskals();
    cout<<"\n\tKruskal's Result: ";
    g.showSpanningTree();
    return 0;
}