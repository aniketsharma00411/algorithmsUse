#include <iostream>
#include <unordered_map>
#include <list>
#include <climits>
#include <set>
using namespace std;
template<typename t>
class Graph
{
    unordered_map<t,list<pair<t,int>>> adjList;
    public:
    void addEdge(t u,t v,int dist,bool biDir=true)
    {
        adjList[u].push_back(make_pair(v,dist));
        if(biDir)
        {
            adjList[v].push_back(make_pair(u,dist));
        }
    }
    void printAdj()
    {
        for(auto x:adjList)
        {
            cout<<x.first<<" ->";
            for(auto y:x.second)
            {
                cout<<" "<<y.first<<" "<<y.second<<",";
            }
            cout<<"\n";
        }
    }
    void Dijsktrassssp(t src)
    {
        unordered_map<t,int>dist;
        for(auto x:adjList)
        {
            dist[x.first] = INT_MAX;
        }
        //the dist(int) is kept first because set sorts o the basis of first element in case
        //of a pair
        set<pair<int,t>>s;
        dist[src] = 0;
        s.insert(make_pair(0,src));
        while(!s.empty())
        {
            auto p = *(s.begin());
            t node  = p.second;
            int child_dist = p.first;
            s.erase(s.begin());
            //iterate over neighbour of current node
            for(auto x:adjList[node])
            {
                if(child_dist + x.second<dist[x.first])
                {
                    //since updation is not possible in set or priority queue
                    //we have to remove the old pair and insert again with new dist
                    t dest =  x.first;
                    auto f = s.find(make_pair(dist[dest],dest));
                    if(f!=s.end())
                    {
                        s.erase(f);
                    }
                    //inserting the new pair
                    dist[dest] = child_dist+x.second;
                    s.insert(make_pair(dist[dest],dest));
                }
            }

        }
        //printing the distance to all other nodes from source
        for(auto x:dist)
        {
            cout<<x.first<<" is located from a distance of "<<x.second<<"from the source"<<"\n";
        }
    }
};
int main() {
    /*Graph<int>g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);
    g.printAdj();
    g.Dijsktrassssp(1);*/
    Graph<string>g;
    g.addEdge("Amritsar","Delhi",1);
    g.addEdge("Amritsar","Jaipur",4);
    g.addEdge("Jaipur","Delhi",2);
    g.addEdge("Jaipur","Mumbai",8);
    g.addEdge("Mumbai","Bhopal",3);
    g.addEdge("Bhopal","Agra",2);
    g.addEdge("Agra","Delhi",1);
    //g.printAdj();
    g.Dijsktrassssp("Amritsar");
    return 0;
}