#include <bits/stdc++.h> 
using namespace std; 
 
#define INF 99999  
#define V 4
void printSolution(int dist[][V]);  
  
// All-pairs shortest path problem using Floyd Warshall algorithm  
void floydWarshall (int graph[][V])  
{
    int dist[V][V], i, j, k;  
    for (i = 0; i < V; i++)  
        for (j = 0; j < V; j++)  
            dist[i][j] = graph[i][j];  
  
    for (k = 0; k < V; k++)  
    {  
        // Select all vertices as source one by one  
        for (i = 0; i < V; i++)  
        {  
            // Select all vertices as destination for the  above picked source  
            for (j = 0; j < V; j++)  
            {  
                // If vertex k is an intermediate edge on the shortest path from i to j, then update the value of dist[i][j]  
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }  
  
    printSolution(dist);  
}  
  
void printSolution(int dist[][V])  
{  
    cout<<"Shortest distances between every pair of vertices \n";  
    for (int i = 0; i < V; i++)  
    {  
        for (int j = 0; j < V; j++)  
        {  
            if (dist[i][j] == INF)  
                cout<<"INF"<<"     ";  
            else
                cout<<dist[i][j]<<"     ";  
        }  
        cout<<endl;  
    }  
}  
  
int main()  
{  
    
    int graph[V][V] = { {0, 5, INF, 10},  
                        {INF, 0, 3, INF},  
                        {INF, INF, 0, 1},  
                        {INF, INF, INF, 0}  
                    };  
    floydWarshall(graph);  
    return 0;  
}  