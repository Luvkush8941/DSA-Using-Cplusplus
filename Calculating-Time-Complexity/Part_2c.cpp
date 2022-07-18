#include<iostream>
using namespace std;

// N < 10^5

int main(){

    int n;
    cin >> n;

    int counter = 0;

    for(int i=0; i<=n ; i++){
        for(int j=0 ; j<i ; j++){
             counter++;
        }
    }

    cout << "No. of iterations taken by the code if N = 10^5 : " << counter << endl;
    
    // when i=0 nested for loop runs 0 time
    // when i=1 nested for loop runs 1 time
    // when i=2 nested for loop runs 2 times
    // when i=n nested for loop runs n times

    // So, total iterations taken by the above code is :
    // 0 + 1 + 2 + 3 + ....... + n

    // i.e n(n+1)/2
    // i.e n^2/2 + n/2
    
    // Time complexity is O(n^2/2) + O(n/2)

    // Time complexity is O(n^2/2) [.. Ignoring O(n/2)]
    // As , 10^10 >>>>>> ..> 10^5 i.e ignoring it.

    // Final time complexity is : O(n^2) [.. Neglecting 2]

    
    

    return 0;
}
