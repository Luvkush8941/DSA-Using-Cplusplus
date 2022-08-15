
/*

Cycle detection in Undirected Graph Using BFS

Let's say we have a graph having two components C1 and C2 i.e graph is disconnected.

   
   1----- 2                       4 ------ 5 ------ 6
          |                       |        |
          |                       7 ------ 8
          3                                 \
                                             9
                          
       C1                            C2

    |                                          |
    --------------------------------------------
                      |
             Combined to give a graph (G)           


           Step - 1 : Make a Adjacency List

           1 ----> 2
           2 ----> 1 , 3
           3 ----> 2
           4 ----> 5
           5 ----> 4 , 6 , 7
           6 ----> 5 , 8
           7 ----> 5 , 8
           8 ----> 6 , 7 , 9
           9 ----> 8 


           Step - 2 : Form a data structure for Visited Nodes. In the starting we have to map all the 
                      nodes with false i.e still not visited.

           
           Step - 3 : Build a Queue data structure. In which we will push our nodes.

           Algorithm :-

           Hamne 1 visit kiyaa koi bhi cycle nhi hain. Fir 1 kaa adjacent 2 push ho gaya queue main

           Hamne 2 visit kiyaa koi bhi cycle nhi hain. Fir 3 push kiyaa queue as 1 is allready visited so, we will
           not push that.

           Hamne 3 bhi visit kiyaa koi bhi cycle nhi hain. Fir 3 ke non-visited neighbours push kar diye queue main.
           Since 3 has no non-visited neighbours i.e We will move to the next node.

           Hamne 4 visit kiyaa koi bhi cycle nhi hain. Fir hamne 4 ke non-visited neighbour push kare jo kii 5 hain only.

           Hamne 5 visit kiyaa koi bhi cycle nhi hain. Fir hamne 5 ke non-visited neighbour jo kii 6 and 7 hain push kiye
           queue main.

           Fir hamne 6 visit kiyaa koi bhi cycle nhi hain. Fir hamne 7 visit kiyaa aur 6 ke non-visited neighbours yaani
           8 ko push kiyaa.

           Hamne 8 visit kiyaa. Aur 6 ko push karne kii kosis kari par woh visited thhaa isliye nhi hua.
           Fir hamne 7 check kiyaa toh woh bhi visited thaa. Abb hame pata chala kii 8 par cycle hain.


           Note : We will make another data structure which will tracks the parent node.


           Dry Run :-

           Run - 1 : Since 1 has no parent i.e map it with -1.

                                      Parent Storing Data Structure     Visited Node Data Structure

              Queue                         |  1 --> -1 |                | 1 ---> true |          
           -------------------              |           |                |             |
           |   1    |        |              |           |                |             | 
           -------------------              -------------                --------------- 
          

            Run - 2 : Pop 1 and push it's adjacent neighbours from adjacency List.

                                     Parent Storing Data Structure     Visited Node Data Structure

              Queue                         |  1 --> -1 |                | 1 ---> true |          
           -------------------              |  2 --> 1  |                | 2 ---> true |
           |   2    |        |              |           |                |             | 
           -------------------              -------------                --------------- 

           
           Run - 3 : Pop 2 and Push it's adjacent neighbours from adjacency list.
           
                                     Parent Storing Data Structure     Visited Node Data Structure

                                            |           |                |             |
                                            |           |                |             |
              Queue                         |  1 --> -1 |                | 1 ---> true |          
           -------------------              |  2 --> 1  |                | 2 ---> true |
           |   3    |        |              |  3 --> 2  |                | 3 ---> true | 
           -------------------              -------------                --------------- 


           Run - 4 : Pop 3 and Push it's adjacent neighbours from adjacency list. Since 2 is already visited 
                     So, neglect this.

           Condition For neglecting a node : It should be visited and it is a parent.
           
                                     Parent Storing Data Structure     Visited Node Data Structure

                                           
              Queue                         |  1 --> -1 |                | 1 ---> true |          
           -------------------              |  2 --> 1  |                | 2 ---> true |
           |        |        |              |  3 --> 2  |                | 3 ---> true | 
           -------------------              |           |                |             |
                                            -------------                ---------------

           
           Run - 5 : Move to the next component which is satrting from 4. So, Push 4 in queue.
                     Mark it as true in Visited data structure.


                                  Parent Storing Data Structure     Visited Node Data Structure

                                            |  1 --> -1 |                | 1 ---> true |
                                            |  2 --> 1  |                | 2 ---> true |
              Queue                         |  3 --> 2  |                | 3 ---> true |          
           -------------------              |  4 --> -1 |                | 4 ---> true |
           |   4    |        |              |           |                |             | 
           -------------------              -------------                --------------- 


           Run - 6 : Push all the non-visited adjacent nodes of 4 in the queue and pop 4 from the queue.


                                  Parent Storing Data Structure     Visited Node Data Structure

                                            |  1 --> -1 |                | 1 ---> true |
                                            |  2 --> 1  |                | 2 ---> true |
              Queue                         |  3 --> 2  |                | 3 ---> true |          
           -------------------              |  4 --> -1 |                | 4 ---> true |
           |   5    |        |              |  5 --> 4  |                | 5 ---> true | 
           -------------------              -------------                --------------- 


           Run - 7 : Push all the non-visited adjacent nodes of 5 in the queue and mark them as true in the visited data 
                     structure and pop 4 from the queue.
                     Since 4 follows the neglecting node Condition i.e we will not push 4 in the queue.

           
                                      Parent Storing Data Structure     Visited Node Data Structure

                                            |  1 --> -1 |                | 1 ---> true |
                                            |  2 --> 1  |                | 2 ---> true |
                                            |  3 --> 2  |                | 3 ---> true |          
      Queue                                 |  4 --> -1 |                | 4 ---> true |
---------------------                       |  5 --> 4  |                | 5 ---> true | 
|  6     |     7    |                       |  6 --> 5  |                | 6 ---> true |
---------------------                       |  7 --> 5  |                | 7 ---> true |
                                            |           |                |             |
                                            |           |                |             |
                                            -------------                ---------------

          Run - 8 :  Push all the non-visited adjacent nodes of 6 in the queue and mark them as true in the visited data 
                     structure and pop 6 from the queue.
                     Since 5 follows the neglecting node Condition i.e we will not push 5 in the queue again.

           
                                      Parent Storing Data Structure     Visited Node Data Structure

                                            |  1 --> -1 |                | 1 ---> true |
                                            |  2 --> 1  |                | 2 ---> true |
                                            |  3 --> 2  |                | 3 ---> true |          
      Queue                                 |  4 --> -1 |                | 4 ---> true |
---------------------                       |  5 --> 4  |                | 5 ---> true | 
|  7     |     8    |                       |  6 --> 5  |                | 6 ---> true |
---------------------                       |  7 --> 5  |                | 7 ---> true |
                                            |  8 --> 6  |                | 8 ---> true |
                                            |           |                |             |
                                            -------------                ---------------
          
         
         Run - 9 :  Push all the non-visited adjacent nodes of 7 in the queue and mark them as true in the visited data 
                     structure and pop 7 from the queue.
                     Since 5 follows the neglecting node Condition i.e we will not push 5 in the queue again.

                     But 8 does not follow the neglecting node condition since it is not the parent of 7.

         It means jab kisi kaa visited --> true aa jaaye aur woh node != parent of current node ho toh
         In this case cycle is present.

         return true;



           
                                      Parent Storing Data Structure     Visited Node Data Structure

                                            |  1 --> -1 |                | 1 ---> true |
                                            |  2 --> 1  |                | 2 ---> true |
                                            |  3 --> 2  |                | 3 ---> true |          
      Queue                                 |  4 --> -1 |                | 4 ---> true |
---------------------                       |  5 --> 4  |                | 5 ---> true | 
|  8     |          |                       |  6 --> 5  |                | 6 ---> true |
---------------------                       |  7 --> 5  |                | 7 ---> true |
   ^                                        |  8 --> 6  |                | 8 ---> true |
   |                                        |           |                |             |
 Return true                                -------------                ---------------

         
          
*/
         
          



