#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <unordered_map>

using namespace std;

// Time complexity : O(Elog(V)) where E is the no. of edges and V is the number of vertices.
// Space complexity : O(V + E)

vector<int> dijkstras(vector<vector<int>> &vec , int vertices , int edges ,int source){

      // --------- Adjacency List Creation ------------
      unordered_map<int , list<pair<int,int>>> adj; // Where pair contains the neighbour of a node with it's weight.
      for(int i = 0; i < edges ; i++){

          int u = vec[i][0]; // Node - 1
          int v = vec[i][1]; // Node - 2
          int w = vec[i][2]; // Weight of edge from u to v

          pair<int,int> p1 = make_pair(v,w); // pair of neighbour with it's weight.

          adj[u].push_back(p1);

          // In case of undirected graph a edge from v to u also exists.
          pair<int,int> p2 = make_pair(u,w);

          adj[v].push_back(p2);
      }

      vector<int> dist(vertices); // Making distance vector.
      
      // Initializing distance vector with infinite values.
      for(int i = 0; i < vertices ; i++){

          dist[i] = INT_MAX;
      }
      
      // Creation of set on basis (distance , node)
      set<pair<int,int>> st;


      
      // ------------- Initializing distance and set with source node  ------------
      dist[source] = 0;
      st.insert(make_pair(dist[source] , source)); // insering pair of dist. of node and node.


      while(! st.empty()){

          // ----- fetch top record -----
          pair<int,int> top = *(st.begin());

          int nodeDistance = top.first;
          int topNode = top.second;
          
          // --- Deleting top data from the set ---
          st.erase(st.begin());

          // ------------ traverse on neighbours -------------
          for(auto lst : adj[topNode]){
               
               pair<int,int> neighbour = lst; // Where neighbour contains the neighbour node with weight

               if(nodeDistance + neighbour.second < dist[neighbour.first]){
                   
                   auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                   
                   // If record found then delete that record and fill new record in place of it.
                   if(record != st.end()){
                      
                       st.erase(record);
                   }

                   // ----------- Distance update ------------
                   dist[neighbour.first] = nodeDistance + neighbour.second;

                   // ----------- push record in set ----------
                   st.insert(make_pair(dist[neighbour.first] , neighbour.first));
               }
          }
      }


     return dist;
}


int main(){

    cout << "\n******************** Dijkstras Algorithm Code **********************\n" << endl;
    
    // ------------------------- Testcase - 1 -----------------------
    int vertices = 5;
    int edges = 7;

    vector<vector<int>> vec = {{0,1,7},{0,2,1},{0,3,2},{1,2,3},{1,3,5},{1,4,1},{3,4,7}};

    // ------------------------- Testcase -2 ------------------------
    // int vertices = 4;
    // int edges = 5;
    // vector<vector<int>> vec = {{0,1,5},{0,2,8},{1,2,9},{1,3,2},{2,3,6}};

    // Here in this {0,1,5} 0 is u , 1 is v and 5 is the weight of the edge from u to v.

    int source = 0;

    vector<int> ShortestDistance = dijkstras(vec , vertices , edges , source);
    
    cout << "{ ";
    for(auto val : ShortestDistance){

        cout << val << " ";
    }

    cout << "}" << endl;

    cout << "\n&&&&&&&&&&&&&&&&&&&&&&&&&&& Program Finishes &&&&&&&&&&&&&&&&&&&&&&&&&&&&\n" << endl;


    return 0;
}

// Output - 1 : 0 4 1 2 5
// Output - 2 : 0 5 8 7