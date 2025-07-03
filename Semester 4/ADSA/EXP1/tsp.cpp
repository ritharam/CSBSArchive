#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

#define V 5
#define MAX 1000000

int tsp(int graph[][V], int s, vector<int>& min_path)
{
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
        {
            vertex.push_back(i);
        }
    int min_cost = MAX;
    while (next_permutation(vertex.begin(), vertex.end()))
    {
        int current_cost = 0;
        int j = s;
        for (int i = 0; i < vertex.size(); i++)
        {
            current_cost += graph[j][vertex[i]];
            j = vertex[i];
        }
        current_cost += graph[j][s];
        if (current_cost < min_cost)
        {
            min_cost = current_cost;
            min_path.clear();
            min_path.push_back(s);
            for (int i = 0; i < vertex.size(); i++)
            {
                min_path.push_back(vertex[i]);
            }
            min_path.push_back(s);
        }
    }
    return min_cost;
}

void printPath(vector<int>& path)
{
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] + 1 << " ";
    }
    cout << endl;
}

int main()
{
    int graph[][V] ={{ 0, 20, 30, 10, 11 },
					{ 15, 0, 16, 4, 2 },
					{ 3, 5, 0, 2, 4 },
					{ 14, 6, 18, 0, 3 },
					{ 16, 4, 7, 16, 0} };
    int s = 0;
    vector<int> min_path;
    int min_cost = tsp(graph, s, min_path);
    cout << "Minimum Cost: " << min_cost << endl;
    cout << "Path: ";
    printPath(min_path);
    return 0;
}
