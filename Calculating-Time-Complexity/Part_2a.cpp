#include<iostream>
using namespace std;

// N < 100000
// arr[i] < 100000


int main(){

    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n ;i++){
        cin >> arr[i];
    }

    // Time complexity of above code is :
    // O(1) + O(1) + O(1) + O(1*n)
    
    // since 1<<<<n so, neglecting constant time complexity.
    // So, overall TC is O(n)

    // So, number of iterations = n = 10^5 it means our code will run within 1sec
    
    // Adding three for loops more.

    for(int i=0; i<n ;i++){
        cin >> arr[i];
    }

    for(int i=0; i<n ;i++){
        cin >> arr[i];
    }

    for(int i=0; i<n ;i++){
        cin >> arr[i];
    }

    // Still Time complexity is : O(n) + O(n) + O(n) + O(n)
    // Equivalent time complexity is O(n)

    // If we use n for loops then time comlexity reaches to nO(n).
    // i.e for loop-1 + for loop-2 + for loop-3 + ....+ for loop-n
    //        TC           TC             TC                TC

    // and if we use loops less than n then our code will run within 1 sec.
    
    int N = 1e5; // i.e 10^5
    int counter = 0; // count the numbe rof iterations

    for(int i=0; i<N ;i++){
        for(int j=0;j<N;j++){

            // runs n^2 times

            counter++;
        }
    }

    cout << "No. of iterations taken by the code if N = 10^5 : " << counter << endl;
    
// ---Method-1 to find the expected time our code will take : Using counter
    // so, counter = 1410065408
    // it means our code will take 1410065408 iterations
    // 10^7 iterations take 1 sec
// So, 1410065408 iterations will take 1410065408/10^7 i.e 141.0065408 sec

    /*

// ---Method-2 to find the expected time our code will take : Direct method-----

    When outside for loop runs 1 time then nested for loop runs n times
So, When outside for loop runs n times then nested for loop runs n^2 times

// Final TC of all the statements till now is : O(n) + O(n^2)
// i.e O(n^2)

// So, number of iterations our code will take is n^2 i.e 10^10

// And 10^7 iterations takes 1 sec 
// so, 10^10 iterations takes 10^3 sec i.e 1000 sec and 16.6666666666 min

// Hence TLE will come 


    */

    return 0;
}
