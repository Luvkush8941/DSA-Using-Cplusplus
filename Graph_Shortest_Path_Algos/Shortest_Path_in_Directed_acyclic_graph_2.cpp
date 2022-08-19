#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>

using namespace std;

class Graph{

     public:
       unordered_map<int ,list<pair<int,int> > > adj; // stores node and list conatins neighbour and edge weight.

       void addEdge(int u , int v , int weight){

            pair<int,int> p = make_pair(v , weight);
            adj[u].push_back(p);

       }
       
       /*
       void printAdj(){

        for(auto i : adj){
            
            cout << i.first << " -> ";
            for(auto j : i.second){

                cout << "{" << j.first << "," << j.second << "}, ";
            }

            cout << endl;

        }

       }

       */

       void dfs(int node, unordered_map<int,bool> &visited , stack<int> &topo){

             visited[node] = true;

             for(auto pr : adj[node]){

                auto neighbour = pr.first; // since pr.second is the weight.

                if(! visited[neighbour]){

                    dfs(neighbour , visited , topo);
                }
             }

             // ---- push returned node in the stack ----
             topo.push(node);
       }

       void getShortestPath(int source , vector<int> &dist , stack<int> &topo){

         // -------- Initialize distance[src] = 0 ---------

        dist[source] = 0;

        while(!topo.empty()){

            int Top = topo.top();
            topo.pop();

            if(dist[Top] != INT_MAX){

                // Processing starts

                for(auto i : adj[Top]){
                    
                    // ------ Updating the distance vector ---------
                    if(dist[Top] + i.second < dist[i.first]){

                        dist[i.first] = dist[Top] + i.second;
                    }
                }
            }
    }
           
    }


};

int main(){
    
    cout << "\n********** Shortest Path in Directed acyclic graph ************\n" << endl;

    Graph g; // Objcet creation

    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    // g.printAdj();

    int n = 6; // total number of nodes.

    // --------------- topological sort function ------------------
    unordered_map<int,bool > visited;
    stack<int> s;

    for(int i = 0; i < n ; i++){

        if(!visited[i]){
            g.dfs(i , visited , s);
        }
    }
    
    int source = 1;
    vector<int> distance(n);

    for(int i = 0; i < n ; i++){

        distance[i] = INT_MAX; // i.e initializing distance vector with infinite distances.
    }


    g.getShortestPath(source , distance , s);

    cout << "Answer is :-" << endl;
    
    cout << "{";
    for(int i = 0; i < distance.size() ; i++){

        cout << distance[i] << " , ";
    }

    cout << "}" << endl;

    cout << "\n Where : 2147483647  is infinite distance." << endl;

    cout << "\n&&&&&&&&&&&&&& Program FINISH &&&&&&&&&&&&&&\n" << endl;

    return 0;
}