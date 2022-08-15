/*

Cycle detection in Undirected Graph Using BFS

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

bool isCyclic(int src , unordered_map<int, bool> &visited , unordered_map<int, list<int> > &adj){

        // ---------- Creating Parent Data Structure --------------
        // It will store the parents of a node.
        // Like parent of 2 is 1 , parent of 1 is -1 i.e null

        unordered_map <int , int > parent;

        parent[src] = -1; // Mark source node's parent as -1.
        visited[src] = true;

        queue<int> q; // It will store the node's data
        q.push(src); // Pushing source node for the first time.

        while(!q.empty()){

            int front = q.front(); // Accessing front node's data from the queue.
            q.pop();

            for(auto neighbour : adj[front]){ // Accessing all the neighbours of front
                 
                 // Condition for cycle.
                 if(visited[neighbour] == true && neighbour != parent[front]){

                    return true;

                 }else if(!visited[neighbour]){ // If that node is not visited yet than push it in the queue. And mark it as visited.

                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = front;

                 }

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
             
             bool ans = isCyclic(i , visited , adj);

             if(ans){

                return "YES";
             }

        }

     }

   // --------- At the end after traversing all the nodes if we are unable to get the cycle in the graph then --------

   return "NO";
    
}

int main(){

    cout << "\n******************* Cycle Detection Code Using BFS *******************\n" << endl;
    
    vector<vector <int> > edges = {{1,2},{2,3},{1,3}};
    int TotalVertices = 3;
    int E = edges.size();

    string check = cycleDetection(edges , TotalVertices , E);

    cout << check << endl;

    cout << "\n-------------------------- Program Finishes --------------------------\n" << endl;

    return 0;
}