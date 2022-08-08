#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

class garph{

   public:
     unordered_map<int, list<int>> adj;


     void addEdge(int node1, int node2, bool direction){
        
        // Direction = 0 ----> undirected graph
        // Direction = 1 ----> directed graph

        //  Create an edge from node1 to node2
        adj[node1].push_back(node2);
        
        // It means undirected graph so edge from node2 to node1 is also possible.
        if(direction == 0){

            adj[node2].push_back(node1);
        }

     }

     void printAdjList(){

        for(auto i : adj){

            cout << i.first << "->";
            for(auto lst : i.second){

                cout << lst << ", ";
            }

            cout << endl;
        }
     }



};

int main(){

    cout << endl << "\n**************** Program for Adjacency List ****************\n" << endl;
   
   int n,m;

   cout << "Enter the number of nodes : " << endl;
   cin >> n;

   cout << "Enter the number of edges : " << endl;
   cin >> m;

   garph g;

   for(int i = 0; i < m; i++){
       
       int node1,node2;
       cin >> node1 >> node2;
       g.addEdge(node1,node2,0); // Creating an undirected graph
   }
   
   // Printing the graph
   cout << endl << "\n-------------------- Printing the Graph ------------------------\n";
   g.printAdjList();

   cout << endl << "\n------------------ FINISH ------------------\n" << endl;

   return 0;
}

/*

Enter the number of nodes :
5
Enter the number of edges : 
6
0 1 
1 2
2 3
3 1
3 4
0 4


-------------------- Printing the Graph ------------------------
4->3, 0, 
3->2, 1, 4,
2->1, 3,
0->1, 4,
1->0, 2, 3,








*/