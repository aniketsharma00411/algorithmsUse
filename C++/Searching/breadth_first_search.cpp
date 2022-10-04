// Program to print BFS traversal from a given 
// source vertex. BFS(int s) traverses vertices 
// reachable from s. 
#include<iostream> 
#include <list> 

using namespace std; 

// This class represents a directed graph using 
// adjacency list representation 
class Graph 
{ 
	int V; // No. of vertices 

	// Pointer to an array containing adjacency 
	// lists 
	list<int> *adj; 
public: 
	Graph(int V); // Constructor 

	// function to add an edge to graph 
	void addEdge(int v, int w); 

	// prints BFS traversal from a given source s 
	void BFS(int s); 
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

void Graph::BFS(int s) 
{ 
	// Mark all the vertices as not visited 
	bool *visited = new bool[V]; 
	for(int i = 0; i < V; i++) 
		visited[i] = false; 

	// Create a queue for BFS 
	list<int> queue; 

	// Mark the current node as visited and enqueue it 
	visited[s] = true; 
	queue.push_back(s); 

	// 'i' will be used to get all adjacent 
	// vertices of a vertex 
	list<int>::iterator i; 

	while(!queue.empty()) 
	{ 
		// Dequeue a vertex from queue and print it 
		s = queue.front(); 
		cout << s << " "; 
		queue.pop_front(); 

		// Get all adjacent vertices of the dequeued 
		// vertex s. If a adjacent has not been visited, 
		// then mark it visited and enqueue it 
		for (i = adj[s].begin(); i != adj[s].end(); ++i) 
		{ 
			if (!visited[*i]) 
			{ 
				visited[*i] = true; 
				queue.push_back(*i); 
			} 
		} 
	} 
} 

// Driver program to test methods of graph class 
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
        cout<<"You want to add new edge press 1\n";
        cin>>ch;
    }
    while(ch==1);
        int bfs_node;
    cout<<"Enter BFS starting vertex";
    cin>>bfs_node;
    	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex "<<bfs_node<<")"<<"\n"; 
	g.BFS(bfs_node); 
 
	return 0; 
}
