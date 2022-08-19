#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

// Time complexity is : O(N + E)
// Space complexity is : O(N + E)

// We have to find the shortest path from s to t.
// Where n is the totalVertices and m is the total edges.

vector<int> shortestPath(vector<pair<int,int>> edges , int n , int m , int s , int t){

         // ------- Adjacency List Creation ---------
         unordered_map<int , list<int>> adj;
         for(int i = 0; i < edges.size() ; i++){

            int node1 = edges[i].first;
            int node2 = edges[i].second;

            // indirected graph i.e edge from both the sides.
            adj[node1].push_back(node2);

            adj[node2].push_back(node1);

         }

         // ---------- do BFS ------------
         unordered_map<int,bool> visited;
         unordered_map<int,int> parent;

         queue<int> q;
         q.push(s); // Pushing source node in the queue

         visited[s] = true;
         parent[s] = -1;

         while(!q.empty()){

            int frontNode = q.front();
            q.pop();

            for(auto neighbour : adj[frontNode]){

                if(!visited[neighbour]){

                    visited[neighbour] = true;
                    parent[neighbour] = frontNode;
                    q.push(neighbour);

                }
            }
         }
    
    // ----------- Prepare shortest Path -----------
    vector<int> ans;

    int currentNode = t; // Destination Node.
    ans.push_back(currentNode);
    
    // Loop will run till we our current Node becomes our source node.
    while(currentNode != s){
         
         currentNode = parent[currentNode];
         ans.push_back(currentNode);

    }
    
    // Since we get vector from destination to source and we want from source to destination
    // i.e reverse the vector.
    reverse(ans.begin(),ans.end());

    return ans;
}

int main(){

    cout << "\n********* Shortest Path Using BFS *********\n" << endl;

    int TotalVertices = 8;
    int TotalEdges = 9;

    vector<pair <int,int>> edges = {{1,2},{1,4},{1,3},{2,5},{5,8},{4,6},{6,7},{3,8},{8,7}};

    int source = 5;
    int destination = 7;

    vector<int> ans = shortestPath(edges , TotalVertices , TotalEdges , source , destination);

    for(auto val : ans){

        cout << val << " ";
    }

    cout << "\n********** Program FINISH ************\n" << endl;
}