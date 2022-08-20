#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <limits.h>

using namespace std;

// Time complexity : O(n^2)

// Pair in the vector has a pair of u and v and an integer value i.e weight.
vector<pair<pair<int , int> , int>> calculatePrimMST(int n , int m , vector<pair<pair<int,int>,int>> &g){


        // -------------- Adjacency List Creation --------------
        unordered_map<int, list<pair<int,int> > > adj;

        for(int i = 0; i < g.size() ; i++){
             
             int u = g[i].first.first;
             int v = g[i].first.second;
             int w = g[i].second;
             
             adj[u].push_back(make_pair(v,w));
             adj[v].push_back(make_pair(u,w));

        }
        
        // Making three data structures 
        // Where each index represents a node.

        vector<int> key(n+1); // Tracks the min weight b/w two vertices.

        vector<bool> mst(n+1);

        vector<int> parent(n+1);

        // ---------- Initializing all the keys with INT_MAX , mst with false and parent as -1 --------------
        for(int i = 0 ; i <= n ; i++){ 
            // 0th index is not used we will consider indexes from 1 to n
            // Since index represents a node here and our node starts from 1 not from 0.

            key[i] = INT_MAX;
            parent[i] = -1;
            mst[i] = false;
        }

        // ----------- let's start the algo -------------
        
        // initializing the src node key as 0 and parent as -1 and mst as true.
        key[1] = 0;
        parent[1] = -1;
        
        for(int i = 1; i < n ; i++){ // Since node val starts from 1 
              
              // Here we will track the minimum value from the key which has mst as false.
             // Finding minimum waali node.

              int mini = INT_MAX;
              int u; // Node that has minimum key and mst as false.

              for(int i = 1; i<=n ; i++){ // where v is the vertex.

                  if(mst[i] == false && key[i] < mini){

                      u = i;
                      mini = key[i];
                  }
                  
              }

              

             // Mark min node as true 
             mst[u] = true;
            
             // check it's adjacent node
             for(auto it : adj[u]){

                   int v = it.first;
                   int w = it.second;
                   if(mst[v] == false && w < key[v]){

                      parent[v] = u;
                      key[v] = w;
                  }
             }
        }

        vector<pair<pair<int , int> , int>> result;

        for(int i = 2 ; i <= n; i++){ // Since i = 1 is 1 itself which has parent as -1 and key as 0 so, we will not push that in the result.

            result.push_back({{parent[i] , i},key[i]});
        }
    
    return result;
        
}

int main(){

    cout << "\n$$$$$$$$$$$$$ Prim's Algorithm ( For Min Spanning Tree) $$$$$$$$$$$$$\n" << endl;

    
    
    // Testcase - 1

    int vertices = 5;
    int edges = 14;

    vector<pair<pair<int,int>, int>> vec = {{{1,2},2},{{1,4},6},{{2,1},2},{{2,3},3},{{2,4},8},{{2,5},5},{{3,2},3},
                                           {{3,5},7},{{4,1},6},{{4,2},8},{{4,5},9},{{5,2},5},{{5,3},7},{{5,4},9}};

    
    
    /*
    
    // Testcase - 2

    int vertices = 5;
    int edges = 15;

    vector<pair<pair<int,int>, int>> vec = {{{1,2},21},{{1,4},16},{{2,1},12},{{2,3},13},{{2,4},18},{{2,5},15},{{3,2},13},
                                           {{3,5},17},{{4,1},16},{{4,2},18},{{4,5},19},{{5,1},18},{{5,2},15},{{5,3},17},{{5,4},19}};

    */

   vector<pair<pair<int , int> , int>> ans = calculatePrimMST(vertices , edges , vec);

   for(auto pr : ans){

       cout << "u = " << pr.first.first << " and v = " << pr.first.second << " , ----> w = " << pr.second << endl;
   }

    
  
    cout << "\n*************** Program Finish ***************\n" << endl;

    return 0;

}

// Output - 1:
/*

1 2 2
1 4 6
2 3 3
2 5 5

*/