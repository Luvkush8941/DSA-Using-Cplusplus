/*

Question:

Given T test cases and an array of 
Size N. Print sum of array in each test
case.
Constraints:
1 <= T <= 1000
1 <= N <= 1000
1 <= arr[i] <= 1000


*/


#include<iostream>
using namespace std;


int main(){

    int t;
    cin >> t;
    int counter = 0;
    while(t--){
         int n;
         cin >> n;
         int sum = 0;
         for(int i=0 ; i<n ; i++){
           int x;
           cin >> x;
           sum += x;

           counter++;
         }

         cout << sum << endl;
    }

    cout << counter << endl;

    return 0;
}

// ---------------------------- Important ------------------------------------

// Time complexity of the code is O(T*N)
// We have to give the time complexity in single variable not in a multiple variable.

// Since, T and N are same i.e O(N^2)
// Total iterations = 10^6

// But if this, is given :-

/*

Case-1:

1 <= T <= 100000
1 <= N <= 100000

then, Total iterations = 10^10 it means our code will not run.


Important :

Case-2:
1 <= T <= 100000
1 <= N <= 100000

Sum of N over all Test cases is 10^7 (given)

Then our, code will run :

------------- How -------------------

Let's say for testcase-0(t0) , N is n1
          for testcase-1(t1) , N is n2
          .
          .
          .
          .
          for testcase-(t) , N is n(t)

According to this : Sum of N over all Test cases is 10^7--->

n1 + n2 + ........ + n(t) = 10^7
counter <= 10^7

Total no. of iterations <= 10^7 so, our code will run in 1sec

And time complexity of above code is O(counter) = O(10^7)

Now, our code time complexity has changed to O(10^7) in place of O(10^10).

--------It means a single line has changed our time complexity-----------

So, if we remove that single line then our code will not run within the time.

*/
