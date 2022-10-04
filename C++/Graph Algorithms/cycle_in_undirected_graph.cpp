/*
    given an undirected graph, check whether the undirected graph has cycle
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Graph{

    int V;
    list<int> *adj;
    bool isCyclicUtil(int v, bool visited[], int parent);


public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isCyclic();
};

Graph::Graph(int V){
    this -> V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool Graph::isCyclicUtil(int v, bool visited[], int parent){
    visited[v] = true;

    list<int>::iterator it;

    for(it = adj[v].begin(); it != adj[v].end(); it++){
        if(!visited[*it]){
            if(isCyclicUtil(*it, visited, v))
                return true;
        }

        else if(*it != parent) {
            return true;
        }
    }
    return false;
}

bool Graph::isCyclic(){
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++){
        visited[i] = false;
    }

    for(int u = 0; u < V; u++){
        if(!visited[u]){
            if(isCyclicUtil(u, visited, -1))
                return true;
        }
    }
    return false;
}

int main(){
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 

    if(g1.isCyclic()){
        cout<<"graph has cycle\n";
    }
    else{
        cout<<"graph has no cycle\n";
    }
    return 0;
}
