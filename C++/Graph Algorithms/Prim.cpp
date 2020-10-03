// Minimum Spanning Tree (MST) - Prim 
// Time Complexity: O(MlogN)
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;   
//---------------------
#define MAXN 10100
// As there is no Infinite on the computer, we will use a very large number
#define INFINITY 999999999

int n, m;                      // number of nodes and edges
int dist[MAXN];           // distances to font
int processed[MAXN];          // if the node was processed
vector<pii> neighbors[MAXN];    //The first element of pair is the distance and the second the node
//---------------------

int Prim(){
	
	for(int i = 1;i <= n;i++) dist[i] = INFINITY; // we define all distances as infinite, except for S = 1.
	dist[1] = 0;                                  // Thus, we guarantee that the first selected node will be 1 itself.
	
	priority_queue< pii, vector<pii>, greater<pii> > queue; // Created a priority queue where the smallest is at the top.
	queue.push( pii(dist[1], 1) );                     // As you can see, we put the first element as the distance from the
	                                                       // node in the Minimum Generation Tree and the second as the vertex itself
	
	while(true){ // run "endlessly"
		
		int actual = -1;
		
		// we select the nearest node
		while(!queue.empty()){
			
			int current = queue.top().second;
			queue.pop();
			
			if(!processed[current]){ // we can use this node because it hasn't been processed yet
				actual = current;
				break;
			}
			
			// if not, we keep looking
		}
		
		if(actual == -1) break; // if not found anyone, it's the end of the algorithm
		
		processed[actual] = true; // we mark to not go back to this node
		
		//now, we'll try to update the distances
		for(int i = 0;i < (int)neighbors[actual].size();i++){
			
			int distV  = neighbors[actual][i].first;
			int current = neighbors[actual][i].second;
			
			// The new possible distance is distV.
			// We compare this with dist[current].
			// However, it is important to check if the current node has not been processed yet
			
			if( dist[current] > distV && !processed[current]){  // we see if it is worth using the actual node
				dist[current] = distV;                         // update the distance
				queue.push( pii(dist[current], current) );       // add to the priority queue
			}
		}
	}
	
	int tree_cost = 0;
	for(int i = 1;i <= n;i++) tree_cost += dist[i];
	
	return tree_cost;
}

int main(){
	
	cin >> n >> m;
	
	for(int i = 1;i <= m;i++){
		
		int x, y, weight;
		cin >> x >> y >> weight;
		
		neighbors[x].push_back( pii(weight, y) );
		neighbors[y].push_back( pii(weight, x) );
	}
	
	cout << Prim() << endl; // print the answer
	
	return 0;
}
