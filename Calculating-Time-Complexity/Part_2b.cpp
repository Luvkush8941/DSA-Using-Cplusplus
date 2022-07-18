#include<iostream>
using namespace std;

// N > 10^5

int main(){

    int n = 1e5; // O(1) operation
    // cin >> n; // O(1) operation

    int count = 0; // O(1) operation
    while(n > 0){
        n = n/2; // This will not run for n times

        count++; // Counts that how many times while loop runs
    }

    // let n = 10
    // when while loop runs 1st time : 10/2 = 5
    // when while loop runs 2nd time : 5/2 = 2
    // when while loop runs 3rd time : 2/2 = 1 
    // when while loop runs for 4th time : 1/2 = 0 now loop ends and we donot count this
    // So, you can see that for n=10 loop runs for 3 times only not n times

    // Similarly :
    // let n = 8
    // when while loop runs 1st time : 8/2 = 4
    // when while loop runs 2nd time : 4/2 = 2
    // when while loop runs 3rd time : 2/2 = 1
    // when while loop runs 3rd time : 1/2 = 0 now loop ends and we donot count this
    // So, you can see that for n=8 loop runs for 3 times only not n times

    // So, we cannot predict the time complexity of above code directly to n
    // It means for any n value loop runs a times where a can be 1,2,3,4,...
    // In the above cases a = 3.
    
    // i.e loop ends when n/2^a  comes.
    // i.e when n = 2^a then loop ends.
    // taking log base 2 both the sides

    // log(2^a) = log(n) 
    // alog(2) = log(n) 
    // a = log(n) where a is the value of the counter
    // count = log(n) base 2 and this is the time complexity of the whole code.

    cout << "Above code takes " << count << " iterations." << endl;

    // Time complexity of the above code is : O(1) + O(1) + O(1) + O(log(n))
    // Combined time complexity is O(log(n))


    // as max n = 10^5.
    // if n = 8 then time complexity is :
    // log(8) to the base 2 is 3log(2) i.e 3 iterations.

    // So, max iterations taken by the code when n=10^5 is
    // No. of iterations = log(10^5) base 2
    // No. of iterations = 5log(10) base 2
    // No. of iterations = 5 * 3.32192809489 => 16.6096404744
    
    // Maximum iterations that our code can take for N = 10^5 is 16.6096404744
    // And maximum iterations allowed to us are 10^5.
    // You can see the power of log(n) complexity.



    return 0;
}
