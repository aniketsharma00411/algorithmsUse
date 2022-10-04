/*
HAMILTONIAN PATH AND CYCLE:

A Hamiltonian path, is a path in an undirected or directed graph that visits each vertex exactly once. 
Given an undirected graph  the task is to check if a Hamiltonian path is present in it or not.

**** Difference between Hamiltonian Path And Hamiltonian Cycle

In Hamiltonian Cycle every vertex must be traversed exactly once without the edges being repeated. Starting and ending vertices must be same.
In Hamiltonian Path every vertex must be traversed exactly once without the edges being repeated. Starting and ending vertices may be different.

*/

#include <bits/stdc++.h>
using namespace std;

//isSafe function to check the path and position is valid or not
bool isSafe(int **graph, int v, int path[], int pos, int V)
{

    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
    {
        if (path[i] == v)
            return false;
    }

    return true;
}

//Hamiltonian Path function
bool Hamilton(int **graph, int path[], int pos, int V)
{

    if (pos == V)
        return true;

    for (int v = 0; v < V; v++)
    {
        if (isSafe(graph, v, path, pos, V))
        {
            path[pos] = v;
            if (Hamilton(graph, path, pos + 1, V))
                return true;
            path[pos] = -1;
        }
    }

    return false;
}

//Hamiltonian Cycle function
void HamiltonCycle(int **graph, int V)
{

    //path array to check if the same path is not visited again
    int path[V];
    memset(path, -1, sizeof(path));

    for (int i = 0; i < V; i++)
    {
        path[0] = i;

        if (Hamilton(graph, path, 1, V))
        {
            cout << 1;
            return;
        }
    }

    cout << 0;
    return;
}

//main function
int main()
{

    //vertex : no of vertices and edges = no of edges
    int vertex, edges;

    //input vertex and edges
    cin >> vertex >> edges;

    int **graph = new int *[vertex];

    for (int i = 0; i < vertex; i++)
        graph[i] = new int[vertex];

    for (int i = 0; i < edges; i++)
    {

        int x, y;
        cin >> x >> y;
        graph[x - 1][y - 1] = 1;
        graph[y - 1][x - 1] = 1;
    }

    HamiltonCycle(graph, vertex);

    cout << endl;

    return 0;
}
