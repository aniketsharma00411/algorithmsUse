/*
given directed graph, check whether the graph contains a cycle or not.
*/
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Graph {
    int V;
    list<int> *adj;
    bool isCyclicUtil(int v, bool visited[], bool* rs);

public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isCyclic();
};

Graph::Graph(int V){
    this -> V = V;
    adj = new list<int> [V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

bool Graph::isCyclicUtil(int v, bool visited[], bool* rs){
    if(visited[v] == false){
        visited[v] = true;
        rs[v] = true;

        list<int>::iterator it;

        for(it = adj[v].begin(); it != adj[v].end(); it++){
            if(!visited[*it] && isCyclicUtil(*it, visited, rs))
                return true;
            else if(rs[*it])
                return true;
        }
    }
    rs[v] = false;
    return false;
}

bool Graph::isCyclic(){
    bool* visited = new bool[V];
    bool* rs = new bool[V];

    for(int i = 0; i < V; i++){
        visited[i] = false;
        rs[i] = false;
    }

    for(int i = 0; i < V; i++){
        if(isCyclicUtil(i, visited, rs))
            return true;
        return false;
    }
}

int main(){
    Graph g(4);
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 

    if(g.isCyclic())
        cout<<"This graph has cycle\n";
    else
    {
        cout<<"this graph doesn't contain a cycle\n";
    }
    return 0;
}