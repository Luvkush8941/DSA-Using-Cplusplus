/*



Cycle detection in Undirected Graph Using BFS

Let's say we have a graph having two components C1 and C2 i.e graph is disconnected.

   
   1----- 2             4 ------- 5 ------ 6 
          |                       |        |
          |                       7 ------ 8
          3                                 \
                                             9
                          
       C1                            C2

    |                                          |
    --------------------------------------------
                      |
             Combined to give a graph (G)           


  Dry Run :-

  Pehle 1 par gaye kya cycle present hain --> Nhi
  Fir 2 par gaye kya cycle present hain --> Nhi
  Fir 3 par gaye kya cycle present hain --> Nhi aur component khatam ho gaya.

  Agle Component kii pehl node par gaye i.e 4 kay cycle present hain ---> Nhi.
  Fir 5 par gaye kya cycle present hain --> Nhi
  Fir 6 par gaye kya cycle present hain --> Nhi
  Fir 8 par gaye kya cycle present hain --> Nhi
  Fir 9 par gaye kya cycle present hain --> Nhi

  Fir 9 se return hue 8 par aur 8 se gaye 7 par.
  Kya cycle present hain nhi.
  Fir 7 se jab 5 par jaane kii kosis kari toh dekha kii 5 toh 7 kaa parent nhi hain.
  8 is the parent of 7. It means cycle is present.


  Run-1 : 
      
      Parent                  Visited                  Function Call(C-1)       Function Call(C-2)
      1 ---> -1               1 ---> true               DFS(1,-1)
      2 ---> 1                2 ---> true               DFS(2,1)
      3 ---> 2                3 ---> true               DFS(3,2)

      4 ---> -1               4 ---> true                                          DFS(4,-1)
      5 ---> 4                5 ---> true                                          DFS(5,4)
      6 ---> 5                6 ---> true                                          DFS(6,5)------> After Cycle detection return true. And this will go till DFS(1,-1) and then DFS(1,-1) returns true at the end.
      8 ---> 6                8 ---> true                                          DFS(8,6)------> After returning to 8 DFS(7,8)    
      9 ---> 8                9 ---> true                                          DFS(9,8)                                |
      7 ---> 8                7 ---> true                                                                                  V
                                                                                                                         DFS(5,7)
                                                                                                                      5 is already Visited
                                                                                                                      and 5 is not the parent of 7.
                                                                                                                      return true   





*/

/*

Cycle detection in Undirected Graph Using DFS

You have been given an undirected graph with "N" vertices and "M" edges. The vertices are labelled from
1 to "N".

Your task is to find if the graph contains a cycle or not.

A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called cycle.

*/

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>

using namespace std;


bool isCyclicDFS(int node , int parent , unordered_map<int, bool> &visited , unordered_map<int, list<int> > &adj){

              visited[node] = true;

              for(auto neighbour : adj[node]){

                    if(!visited[node]){

                        bool cycleDetected = isCyclicDFS(neighbour , node , visited , adj);

                        if(cycleDetected){

                            return true;

                        }
                    }else if(neighbour != parent){
                        
                        // Cycle present
                        return true;
                    }
              }

              return false;
         
}

string cycleDetection (vector< vector <int>> &edges , int n , int m){

     // --------- Adjacency List Creation -----------
     unordered_map<int, list<int> > adj;
     for(int i = 0; i < m ; i++){

        int node1 = edges[i][0]; // Vertex - 1
        int node2 = edges[i][1]; // Vertex -2

        adj[node1].push_back(node2);

        // Since graph is undirected so, their will be an edge from node2 to node1 as well.
        adj[node2].push_back(node1);
     }
     
     // ---------- Tracks whether a particular node is visited or not ----------
     unordered_map<int, bool> visited;


     // --------- To handle disconnected components ----------
     for(int i = 0; i < n; i++){ // Covers all the nodes.
        
        if( !visited[i]){
             
             bool ans = isCyclicDFS(i , -1 , visited , adj); // In the starting of every component node has it's parent as -1.

             if(ans){

                return "YES";
             }

        }

     }

   // --------- At the end after traversing all the nodes if we are unable to get the cycle in the graph then --------

   return "NO";
    
}

int main(){

    cout << "\n******************* Cycle Detection Code Using DFS *******************\n" << endl;
    
    vector<vector <int> > edges = {{1,2},{2,3},{1,3}};
    int TotalVertices = 3;
    int E = edges.size();

    string check = cycleDetection(edges , TotalVertices , E);

    cout << check << endl;

    cout << "\n-------------------------- Program Finishes --------------------------\n" << endl;

    return 0;
}