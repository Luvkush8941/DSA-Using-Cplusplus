/*

Using BFS Algorithm / Kahn's algorithm

*/

// Time complexity is : O(V + E)
// Space complexity is : O(V + E)

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>

using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v , int e){
        
         unordered_map<int , list<int>> adj;

        // ---------- Adjacency List Creation --------------
        for(int i = 0; i < e ; i++){

            int u = edges[i][0];
            int v = edges[i][1];
            
            // Directed graph i.e edge from u to v.
            adj[u].push_back(v);
        }

        // --------- Find all indegrees -----------
        vector<int> indegree(v);

        for(auto i : adj){

            for(auto j : i.second){

                indegree[j]++;
            }
        }

        // ----- 0 indegrees waalo ko push kardo -----
        queue<int> q;
        for(int i = 0; i < v ; i++){

            if(indegree[i] == 0){

                q.push(i);

            }
        }

        // ----------- Do BFS ------------
        vector<int> ans;

        while(!q.empty()){

            int front = q.front();
            q.pop();

            // ans store
            ans.push_back(front);

            // Neighbours indegree update
            for(auto neighbour : adj[front]){
                
                // Decreamenting indegrees of neighbour.
                indegree[neighbour]--;

                if(indegree[neighbour] == 0){

                    q.push(neighbour);
                }
            }


        }

        return ans;
}

int main(){

    cout << "\n************ Kahn's Algorithm ************\n" << endl;
    
    int TotalVertices = 4;
    int TotalEdges = 4;
    vector<vector<int>> edges = {{0,1},{0,3},{1,2},{3,2}};
    
    vector<int> ans = topologicalSort(edges , TotalVertices , TotalEdges);

    for(auto val : ans){

        cout << val << " ";
    }

    cout << endl;


    cout << "\n********** FINISH **********\n" << endl;
    return 0;
}