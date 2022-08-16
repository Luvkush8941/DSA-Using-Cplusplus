/*
   
    
    Given a DAG consisting of "V" vertices and "E" edges, you need to find out any topological sorting
    of this DAG. Return an array of size "V" representing the topological sort of the vertices of the given
    DAG.

    Ex : 1 -> 2
         2 -> 3
         3 -> 1

     Sequence checking :-

     1 2 3

     1 se 2 ke liye edge hain toh sequence main 1 , 2 se pehle aana chaiye. Jo kii hain.
     2 se 3 ke liye edge hain toh yaani sequence main 2 , 3 se pehle aana chaiye. Jo kii hain.
     3 se 1 ke liye edge hain yaani sequence main 3 , 1 se pehle anna chaiye. Jo kii galat hain 1 -> 3 se pehle hain

     Invalid topological sort. 
     
     Important :-

     We can use topological sort in case of cycle detection also. If graph has valid topological sort it means
     graph donot contains cycle. 


                                                                   
*/

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <unordered_map>

using namespace std;

void topoSort(int node , unordered_map<int,bool> &visited , stack<int> &s , unordered_map<int,list<int>> &adj){

        // ----- Pehla kaam node ko visited kardo -----
        visited[node] = true;

        for(auto neighbour : adj[node]){

             if(!visited[neighbour]){ // Agar neighbour visited nhi hain toh

                  topoSort(neighbour , visited , s , adj); // Uske liye function call kardo.

             }
        }

        // ------- Jab bhi ham call se baapis aayengye toh stack main push kardengye uss node ko -------

        s.push(node); // Imp
        
}

vector<int> topologicalSort(vector<vector<int>> &edges , int v , int e){
      
      // ------- Adjacency List Creation -------
      unordered_map<int, list<int>> adj;
      for(int i = 0; i < e ; i++){

        int u = edges[i][0];
        int v = edges[i][1];
        
        // Since graph is directed so, only one edge from u to v.
        adj[u].push_back(v);

      }
      
      // -------- Call dfs topological sort util function for all components --------
      unordered_map<int, bool> visited;
      stack<int> s; // stores returned nodes.
      
      // Since nodes starting from 0 i.e we start i from 0.
      for(int i = 0; i < v ; i++){

           if(!visited[i]){

              topoSort(i , visited ,s, adj);
           }
      }

      // ------- Accessing data from the stack -------

      vector<int> ans;

      while( !s.empty()){
          
          int val = s.top();
          s.pop();
          ans.push_back(val);
      }
     
     return ans;
}

int main(){

    cout << "\n$$$$$$$$$$$$$$$$$ Topological Sort Using DFS $$$$$$$$$$$$$$$$$\n" << endl;

    // int TotalVertices = 4;
    // int TotalEdges = 3;

    // vector<vector<int>> edges = {{1,0},{2,0},{3,0}};

    // int TotalVertices = 6;
    // int TotalEdges = 6;

    // vector<vector<int>> edges = {{5,0},{5,2},{2,3},{1,3},{4,1},{4,0}};

    int TotalVertices = 4;
    int TotalEdges = 4;

    vector<vector<int>> edges = {{0,1},{0,3},{1,2},{3,2}};


    vector<int> ValidSequence = topologicalSort(edges , TotalVertices , TotalEdges);

    for(auto i : ValidSequence){

        cout << i << " ";
    }

    cout << endl;

    cout << "\n************************** FINISH **************************\n" << endl;

    return 0;
}

/*

TestCase - 2 :

int TotalVertices = 6;
int TotalEdges = 6;

vector<vector<int>> edges = {{5,0},{5,2},{2,3},{1,3},{4,1},{4,0}};


Output :-

5 , 4 , 2 , 1 , 3 , 0
*/