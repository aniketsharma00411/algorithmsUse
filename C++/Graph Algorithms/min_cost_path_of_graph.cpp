/*

Minimum Cost Path in given graph:

TIME COMPLEXITY : O(n^2)

Given a square grid of size N, each cell of which contains integer cost which represents a cost to traverse through that cell,
we need to find a path from top left cell to bottom right cell by which total cost incurred is minimum. 
You can move in 4 directions : up, down, left an right.

output a single integer depecting the minimum cost to reach the destination.

Example: 

Grid is:
31, 100, 65, 12, 18,
10, 13, 47, 157, 6,
100. 113, 174, 11, 33,
88, 124, 41, 20, 140,
99, 32, 111, 41, 20
A cost grid is given in below diagram, minimum
cost to reach bottom right from top left
is 327 (31 + 10 + 13 + 47 + 65 + 12 + 18 + 6 + 33 + 11 + 20 + 41 + 20)

*/

#include<bits/stdc++.h>
using namespace std;

//valid directions to move in 
int rowN[] = {-1,1,0,0};
int colN[] = {0,0,1,-1};


//min Cost path in a graph
int minCostPath(int **graph, int **dist, int n)
{
	//queue 
    queue<pair<int,int>> q;
    
    dist[0][0] = graph[0][0];
    q.push({0,0});
    
    while(!q.empty())
    {
        pair<int,int> p = q.front();
        
        int a = p.first;
        int b = p.second;
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            int x = a + rowN[i];
            int y = b + colN[i];
            
            if(x>=0 && x<n && y>=0 && y<n && dist[x][y]>dist[a][b]+graph[x][y])
            {
                dist[x][y] = dist[a][b] + graph[x][y];
                q.push({x,y});
            }
        }
        
    }
    //return the min cost to reach from top left [0][0] to bottom right [n-1][n-1]
    return dist[n-1][n-1];    
}

//main function
int main()
 {    
 	//n is dimensions of graph matrix 
        int n;
        cin>>n;
        
        //graph matrix with cost 
        int **graph=new int*[n];
        
        //input matrix
        for(int i=0;i<n;i++){
            graph[i]=new int[n];
            
            for(int j=0;j<n;j++){
            	//input costs
                cin>>graph[i][j];
            }
        }
       
	   //distance matrix to store the min cost to reach any node in graph 
        int **dist=new int*[n];
        
        for(int i = 0; i<n; i++){
            dist[i]=new int[n];
            
            for(int j=0; j<n; j++){
                dist[i][j] = INT_MAX;
            }
        }
        
	//output the minimum cost path from top left to bottom right corner of matrix        
    cout<< minCostPath(graph,dist,n)<<endl;
        
	return 0;
}
