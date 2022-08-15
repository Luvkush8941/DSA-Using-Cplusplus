/*



                -----           -----                -----
                | 0 |-----------| 4 |--------------- | 2 |
                -----           -----                -----
                                 |                     |
                                 |                     |
                                -----                  |
                                | 1 |                  |
                                -----                  |
                                  |                    |
                                -----                 -----
                                | 5 |---------------- | 3 |
                                -----                 -----


                              ----------- Graph -----------

            In case of BFS we have to traverse all the adjacent nodes of a particular node.
            BFS : 0 4 2 1 3 5

            But in case of DFS 
            DFS : 0 4 2 3 5 1


            
                -----           -----                -----
                | 0 |-----------| 4 |--------------- | 2 |
                -----           -----                -----
                                 |                     |
                                 |                     |
                                -----                  |
                                | 1 |                  |
                                -----                  |
                                  |                    |
                                -----                 -----
                                | 5 |---------------- | 3 |
                                -----                 -----


                    In case of DFS ---> We traverse level - wise.

                    First 0 will be printed i.e level-1
                    Then, 4 will be printed i.e level-2

                    Then we have two choices whether we have to go on 2 or else we have to go on 5. Let's say i choose 2

                    2 will be printed i.e level-3
                    Then 3 will be printed 
                    Then 5 and at the end 1.



*/

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <set>

using namespace std;


void dfs(int node , unordered_map <int , bool > &visited , unordered_map<int, list<int>> &adjList , vector<int> &component){

         // Jo bhi node abhi aayii hain usse component main store kardo.
          component.push_back(node);
        
        // Jo bhi node abhi ayyi hain usse visited kardo.
           visited[node] = true;

        // har connected node yaani adjacent node k liye recursive call kardo.

        for(auto i : adjList[node]){ // getting adjacent node of i

            if( ! visited[i]){

                dfs(i , visited , adjList , component);
            }
        }

}

vector<vector<int>> DFS(int V , int E , vector<vector <int>> &edges){

  //prepare adjlist for undirected graph.
  unordered_map<int, list<int>> adjList;

  for(int i = 0; i < E ; i++){
         
         // Accessing nodes from the edges.
         int u = edges[i][0];
         int v = edges[i][1];
        
        // Making a edge from u to v and from v to u.
         adjList[u].push_back(v);
         adjList[v].push_back(u);
  }

  vector<vector<int>> ans;
  unordered_map <int , bool > visited;
  
  // Since graph is disconnected so, we have to call for every node.
  // For all node call dfs , if not visited
  for(int i = 0; i < V ; i++){

        if( ! visited[i]){  // if node is not visited
             
             vector<int> component; 
             // We will get one component traversal from the below line.
             // Since graph is disconnected i.e we will get component's traversal.
             dfs(i , visited , adjList , component);

             ans.push_back(component);
        }
  }

return ans;

}



int main(){

   cout << endl << "\n**************** Program for DFS ****************\n" << endl;

   int TotalNodes = 5;
   vector<vector <int>> edges = {{0,2},{0,1},{1,2},{3,4}};

   
   vector<vector<int>> dfsAns = DFS(TotalNodes , 4 , edges);

   cout << "Total Disconnected Componenets : " << dfsAns.size() << endl;

   for(auto i : dfsAns){

      for(auto j : i){

        cout << j << " ";
      }
      cout << endl;
   }

   cout << endl << "\n------------------ FINISH ------------------\n" << endl;

   return 0;
}

