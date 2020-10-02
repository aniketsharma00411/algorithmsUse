/* 

	Kosaraju's algorithm to find  number of strongly connected components.
	Strongly connected components are those edges in a graph whose removal disconnects 
	the graph.

*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/

#include<bits/stdc++.h>
using namespace std;


//Reversing the adjacency List
void reverseList(int V, vector<int>adj[], vector<int>reverse[])
{
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<adj[i].size(); j++)
        {
            reverse[adj[i][j]].push_back(i);
        }
    }
}


//depth first search algorithm function
void dfs(int src, vector<int>adj[], vector<bool>&visit, stack<int>&s)
{
    visit[src] = true;
    for(int i=0 ; i<adj[src].size(); i++)
    {
        if(visit[adj[src][i]]==false)
        {
            dfs(adj[src][i],adj,visit,s);
        }
    }
    s.push(src);
}


//Reverse depth first search function for reverse adjacency lsit
void revdfs(int src, vector<int>revadj[], vector<bool>&visit, vector<int>&temp)
{
    visit[src] = true;
    temp.push_back(src);
    
    for(int i=0 ; i<revadj[src].size(); i++)
    {
        if(visit[revadj[src][i]]==false)
        {
            revdfs(revadj[src][i], revadj, visit,temp);
        }
    }
}


//Kosaraju function implemented
int kosaraju(int V, vector<int> adj[])
{
	//creating visited vertex vector
    vector<bool> visit(V,false);
    //using stack 
    stack<int>s;
    
    for(int i=0; i<V; i++)
    {
        if(visit[i] == false)
        {
            dfs(i,adj,visit,s);
        }
    }
    
    vector<int>reverse[V];
    vector<bool>vis(V,false);
    vector<vector<int> >result;
 
 //reversing the adj list   
    reverseList(V,adj,reverse);
    
    while(!s.empty())
    {
    	
        int src = s.top();
        s.pop();
        vector<int>temp;
        if(vis[src] == false)    
        {
            revdfs(src, reverse, vis, temp);
            result.push_back(temp);
        }
        
    }
    return result.size();
}

int main(){
	
	int Vertex,Edges;
	cin>>Vertex>> Edges;
	
	//m : edge start from 
	//n : edge end to
	int m,n;
	
	//adj[]  stores the edges of the given graph 
	vector<int> adj[Vertex+1];
	
	for(int i=0; i<Edges ; i++){
		
		cin>>m>>n;
		adj[m].push_back(n);
		
	}
	
	//kosaraju function will return the no of strongly connected components
	int stronglyConnectedComponents  = kosaraju(Vertex, adj);
	
	cout<<"The total number of stringly connected components are : "<< stronglyConnectedComponents <<endl;
	
	return 0;
}
