// C++ program to print DFS traversal from 
// a given vertex in a given graph 
#include<bits/stdc++.h> 
using namespace std; 

// Graph class represents a directed graph 
// using adjacency list representation 
class Graph 
{ 
	int V; // No. of vertices 

	// Pointer to an array containing 
	// adjacency lists 
	list<int> *adj; 

	// A recursive function used by DFS 
	void DFSUtil(int v, bool visited[]); 
public: 
	Graph(int V); // Constructor 

	// function to add an edge to graph 
	void addEdge(int v, int w); 

	// DFS traversal of the vertices 
	// reachable from v 
	void DFS(int v); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); // Add w to v’s list. 
} 

void Graph::DFSUtil(int v, bool visited[]) 
{ 
	// Mark the current node as visited and 
	// print it 
	visited[v] = true; 
	cout << v << " "; 

	// Recur for all the vertices adjacent 
	// to this vertex 
	list<int>::iterator i; 
	for (i = adj[v].begin(); i != adj[v].end(); ++i) 
		if (!visited[*i]) 
			DFSUtil(*i, visited); 
} 

// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil() 
void Graph::DFS(int v) 
{ 
	// Mark all the vertices as not visited 
	bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 

	// Call the recursive helper function 
	// to print DFS traversal 
	DFSUtil(v, visited); 
} 


int main() 
{ 


int n=100,ch=1;
    cout<<"Enter n.o of vertices\n";
    cin>>n;
    Graph g(n);
    do
    {   int a,b;
        cout<<"Enter 2 vertices between which you want to add edge\n";
        cin>>a>>b;
        g.addEdge(a,b);
        cout<<"You want to add new edge press 1 \n";
        cin>>ch;
    }
    while(ch==1);
    int dfs_node;
    cout<<"Enter DFS starting vertex";
    cin>>dfs_node;
    	cout << "Following is Depth First Traversal "
		<< "(starting from vertex "<<dfs_node<<")"<<"\n"; 
	g.DFS(dfs_node); 
	return 0; 
}
