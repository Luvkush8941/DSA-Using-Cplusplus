// We will use the logic of topological sort concept.
// Since topological sort is only valid for directed acyclic graph.
// So, if for cyclic graph it gives us invalid topological sort.

// ------------ We will use Kahn's Algorithm --------------


// Time complexity is : O(V + E)
// Space complexity is : O(V + E)

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>

using namespace std;

int detectCycleInDirectedGraph(int n , vector<pair<int,int>> &edges){
        
         unordered_map<int , list<int>> adj;

        // ---------- Adjacency List Creation --------------
        for(int i = 0; i < edges.size() ; i++){

            int u = edges[i].first;
            int v = edges[i].second;
            
            // Directed graph i.e edge from u to v.
            adj[u].push_back(v);
        }

        // --------- Find all indegrees -----------
        vector<int> indegree(n);

        for(auto i : adj){

            for(auto j : i.second){

                indegree[j]++;
            }
        }

        // ----- 0 indegrees waalo ko push kardo -----
        queue<int> q;
        for(int i = 1; i <= n ; i++){

            if(indegree[i] == 0){

                q.push(i);

            }
        }

        // ----------- Do BFS ------------
        int count = 0;

        while(!q.empty()){

            int front = q.front();
            q.pop();
            
            // Increamenting count
            count++;

            // Neighbours indegree update
            for(auto neighbour : adj[front]){
                
                // Decreamenting indegrees of neighbour.
                indegree[neighbour]--;

                if(indegree[neighbour] == 0){

                    q.push(neighbour);
                }
            }


        }
        
        // In case of valid topological sort. count == n i.e acyclic graph.
        if(count == n){

            return 0;

        }else{ // invalid topological sort.

            return 1;
        }
}

int main(){

    cout << "\n************ Kahn's Algorithm ************\n" << endl;
    
    int TotalVertices = 5;
    int TotalEdges = 6;
    vector<pair<int,int>> edges = {{1,2},{4,1},{2,4},{3,4},{5,2},{1,3}};
    
    int ans = detectCycleInDirectedGraph(TotalVertices , edges);

    cout << ans << endl;
    
    cout << "\n********** FINISH **********\n" << endl;
    return 0;
}