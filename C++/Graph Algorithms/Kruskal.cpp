//Minimum Spanning Tree Algorithm (MST)
// Time Complexity: O(ElogE)
#include <iostream>
#include <algorithm>

using namespace std;

struct t_edge{
    int dis;
    int x, y;
};

bool comp(t_edge a, t_edge b){ return a.dis < b.dis; }

//--------------------
#define MAXN 50500
#define MAXM 200200

int n, m; // number of nodes and edges
t_edge edges[MAXM];

// for the union find
int father[MAXN];

// the tree
t_edge mst[MAXM];
//--------------------

// union find functions
int find(int x){
    if(father[x] == x) return x;
    return father[x] = find(father[x]);
}

void join(int a, int b){
    
    a = find(a);
    b = find(b);
    
    father[a] = b;
    
}


int main(){
    
    // input
    cin >> n >> m;
    
    for(int i = 1;i <= m;i++)
        cin >> edges[i].x >> edges[i].y >> edges[i].dis;
    
    
    // initialize parents to union-find
    for(int i = 1;i <= n;i++) father[i] = i;
    
    // order ther edges
    sort(edges+1, edges+m+1, comp);
    
    int size = 0;
    for(int i = 1;i <= m;i++){
        
        if( find(edges[i].x) != find(edges[i].y) ){ //if they are in separate components
            join(edges[i].x, edges[i].y);
            
            mst[++size] = edges[i];
        }
        
    }
    
    // print the MST
    for(int i = 1;i < n;i++){
        cout << mst[i].x << " " << mst[i].y << " " << mst[i].dis << "\n";
    }
    
    return 0;
}