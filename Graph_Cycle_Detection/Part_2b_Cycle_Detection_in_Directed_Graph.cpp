#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>

using namespace std;

// Time complexity is O(N + E)
// and Space complexity is Linear.

bool checkCycleDFS(int node, unordered_map<int,bool> &visited , unordered_map<int, bool> &dfsVisited, 
unordered_map<int,list<int>> &adj){

      // Pehla kaam jo bhi node aa rahi hain usse true mark kardo.
      visited[node] = true;
      dfsVisited[node] = true;


      for(auto neighbour : adj[node]){

        if(!visited[neighbour]){
            
            // Agar neighbour visited nhi hain toh aagye ke liye call kardo.
            bool cycleDetected = checkCycleDFS(neighbour , visited , dfsVisited , adj);

            if(cycleDetected)
                return true;
            

        }else if(dfsVisited[neighbour]){ // If node is visited and dfsVisited is also true.

            return true;
        }
      }
     
     // Jab sabhi neighbour visited ho gaye node ke aur ham return karengye 
     // jab dfsVisited ko baapis false mark kardena.
     dfsVisited[node] = false; // Jab bhi recursive call se baapas aaye.
     return false;

}

string detectCycleInDirectedGraph(int n , vector<pair<int,int>> &edges){

    // ---------Adjacency List Creation -----------
    unordered_map<int, list<int>> adj;
    for(int  i = 0; i < edges.size() ; i++){

        int node1 = edges[i].first;
        int node2 = edges[i].second;
        
        // Directed graph i.e edge from node1 to node2 only.
        adj[node1].push_back(node2);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    // --------- Call Dfs for all Components ----------
    for(int i = 1; i <= n ; i++){ // Nodes from 1 to n

             if(!visited[i]){

                 bool cycleFound = checkCycleDFS(i , visited , dfsVisited , adj);

                 if(cycleFound){

                    return "YES";

                 }
             }
    }

   return "NO";

}

int main(){

    cout << "\n************************** Cycle Detection in Directed Graph Using Dfs **************************\n" << endl;

    int TotalVertices = 4;
    int TotalEdges = 6;

    vector<pair<int,int>> edges = {{0,1},{0,2},{1,2},{2,0},{2,3},{3,3}};

    string ans = detectCycleInDirectedGraph(TotalVertices , edges);

    cout << ans << endl;

    cout << "\n&&&&&&&&&&&&&& FINISH &&&&&&&&&&&&&&\n" << endl;

    return 0;

}

/*

Ex - 1

 n = 4
 E = 6
 0 1
 0 2
 1 2
 2 0
 2 3
 3 3

Output : YES

Ex - 3

n = 4
 E = 4
 0 1
 0 2
 1 2
 2 3

Output : NO


*/

      











