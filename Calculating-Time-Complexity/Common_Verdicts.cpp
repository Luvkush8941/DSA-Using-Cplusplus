/*

1. Runtime Error(RE) or segmentation fault :
   if we have an array of size n and let's say i am accessing the 
   arr[n+2] element i.e out of bound index value  which is not available then 
   it gives RE. 
   If a pointer is pointing to the undefined memory.



2. Memory Limit Exceeded(MLE)
3. Time Limit Exceeded(TLE)
5. TLE and RE in Recursions





*/


// ****************** Gives Segmentation/ Run time Error *********************

#include<iostream>
using namespace std;


class Node{


    public:
      int data;
      Node* next;

      Node(int data){
        this -> data = data;
        this -> next = nullptr;


      }
};


int main(){

   Node * start = new Node(5);
   
   // We are accessing the data which is not defined
   cout << (start -> next) -> data << endl; // 2nd node is not available and we are accessing it's data.
   return 0;
}

