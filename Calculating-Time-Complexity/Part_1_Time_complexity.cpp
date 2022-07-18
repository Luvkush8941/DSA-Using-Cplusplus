/*

iteration : Writing a single statement in a code known to be as 1 iteration.

*/

#include<iostream>
using namespace std;


int main(){

   int x; // single iteration

   int sum = 0; // 2nd iteration

   sum = x + x; // 3rd iteration

   // Number of iterations = 3
   // All these single units combined iteration are known to be a constant time opeation.
   // Time Complexity of above code is O(3) i.e O(no. of iterations)

   int n; // 4th iteration
   cin >> n; // 5th iteration

   for(int i=0; i<n ;i++){
     int y;
     y=5;
     y++; 
   }

   // 1 time loop running takes 3 iterations
   // n time loop running takes 3*n

   // Time complexity till now is : O(3 + 2) + O(3 * n)
   // i.e O(5) + O(3 * n)

   // Given constraint :
   // n < 100000

   // Neglect constant terms 

   // So, our final time complexity is O(n)

   return 0;
}



/*

1. O(N) + O(N) = O(N)

2. O(K * N) = O(N)

3. O(2) = O(5) = O(1)

-------------In Online programming websites -----------------

Important :

Number of iterations in 1 sec is :-
10^7 - 10^8 but generally takes it as 10^7


So, find the time complexity of the code then find the number of iterations in a 
code and if the number of iterations are less than or equal : 10^7 then our code 
will run otherwise it will show TLE.

Let's say :

10^7 iterations takes  1 sec
10^8 iterations takes 10 sec
10^9 iterations takes 100 sec
10^10 iterations takes 1000 sec
10^11 iterations takes 10000 sec





*/
