/*

BFS : Breadth first search

 *  It is a traversal technique.

 *  BFS of a graph is an algorithm used to visit all the nodes of a given graph. In this traversal 
 algorithm, one node is selected, and then all of the adjacent nodes are visited one by one.

 * An undirected graph is a graph where all the edges are bidirectional i.e. they point from source to destination
 and destination to source.

 * A graph is disconnected if at least two vertices of the graph are not connected by a path.


*/

// Given an undirected disconnected graph print it's BFS

/*

Input format :

                                      Number of Nodes  -----------------     -----------------  Number of Edges                                                                
                                                                       |     |
                                                                       V     V
The first line of input contains two integers that denote the value of V and E.
Each of the following E lines contains space-separated two integers that denote an edge between 
vertex A and B.

Where 'V' is the number of vertices/ nodes, 'E' is the number of edges, 'A' and 'B' are the vertex numbers.

Sample Input 1: 
4 4
0 1
0 3
1 2
2 3

Sample output 2:
0 1 3 2


                                   0
                                 /  |
                                /   |
                               /    |
                              1----------2
                                    |   /
                                    |  /
                                    | /
                                    3


Sample Input 2: 
4 3
0 1
0 3
1 3

Sample output 2:
0 1 3 2



                                   
                                    0
                                 /   |
                                /    |
                               /     |
                              1      |      2
                               \     |   
                                \    |  
                                 \   | 
                                   \ 3

*/

#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
#include<list>
#include<set>

using namespace std;


//                                      ------------ We are using set in place of List so, that our answer will stored in the sorted way. Since set stored values in the sorted mannner.
//                                      |            We can also use list inplace of set. It depends on the platform if that platform wants answer in the sorted manner then we have to use set otherwise we can use list.
//                                      v
void prepareAdjList(unordered_map<int, set<int>> &adjList, vector<pair <int,int>> &edges){

                 for(int i = 0; i < edges.size(); i++){
                      
                      // Where u and v are the nodes and we have to connect these 
                      int u = edges[i].first;
                      int v = edges[i].second;
                      
                      // Since graph is undirected i.e making path from both the nodes.
                      adjList[u].insert(v);
                      adjList[v].insert(u);

                 }

}
        
        
void bfs(unordered_map<int, set<int>> &adjList , unordered_map<int,bool> &visited , vector<int> &ans , int node){
               
               // Used to store visited nodes
               queue<int> q;

               q.push(node);
               visited[node] = true;

               while( !q.empty()){

                   int frontNode = q.front();
                   q.pop();

                   // Store front node into ans
                   ans.push_back(frontNode);

                   // Traverse all neighbours of frontNode i.e
                   // if neighbour of frontNode is not visited then push it in the queue else not.

                   for(auto neighbour : adjList[frontNode]){ 
                       
                       if(!visited[neighbour]){
                           
                           q.push(neighbour);
                           visited[neighbour] = true;
                       }
                   }
               }
}
 

vector<int> BFS (int vertex, vector<pair <int,int>> edges){
        
        unordered_map<int, set<int>> adjList;
        vector<int> ans;
        unordered_map<int,bool> visited;

        prepareAdjList(adjList ,edges);

        // Since graph is disconnected and we have to check all the components i.e 
        // traversing through all the nodes one by one using for loop.

        // Traverse all componenets of a graph
        for(int i = 0; i < vertex ; i++){ // If disconnected graph is not there then no need to use for loop.

            if(!visited[i]){  // If node1 is not visisted
                 
                bfs(adjList, visited, ans,i);

            }
        }
       
       return ans;
}


int main(){

   cout << endl << "\n**************** Program for BFS ****************\n" << endl;

   int TotalNodes = 4;
   vector<pair <int,int>> edges = {{0,1},{0,3},{1,2},{2,3}};

   
   vector<int> bfs = BFS(TotalNodes , edges);

   for(auto val : bfs){

     cout << val << " ";
   }

   cout << endl << "\n------------------ FINISH ------------------\n" << endl;

   return 0;
}

