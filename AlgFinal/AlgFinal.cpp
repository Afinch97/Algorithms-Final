
// C++ program to find maximum achievable value
// with a knapsack of weight W and multiple
// instances allowed.
#include<stdio.h>
#include<iostream>
#include<chrono>
#include<string.h>
#include<vector>
using namespace std;
//Time Complexity of O(N*W).
// Auxilary Space of O(W). Since a 1-D vector is used
// Returns the maximum value with knapsack of
// W capacity
vector<int>a;
int unboundedKnapsack(int W, int n,int val[], int wt[]){
    // dp[i] is going to store maximum value
    // with knapsack capacity i.
    vector<int>dp(W+1);


    // Fill dp[] using above recursive formula
    for (int i = 0; i <= W; i++) {
        for (int j = 0; j < n; j++) {
            if (wt[j] <= i) {
                dp[i] = max(dp[i], dp[i - wt[j]] + val[j]);
                

            }
        }
    }

    return dp[W];
}

// Driver program
int main()
{
    
    int val[] = { 1, 2, 5, 10, 20, 50 , 100 };
    int wt[] = { 1, 3, 5, 9, 17, 44, 80 };
    int W = 10;
    int n = sizeof(val) / sizeof(val[0]);
   // unboundedKnapsack(W, n, val, wt);

    cout << "Dynamic Knapsack Capacity: " << W << endl;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i=0; i<10; i++){ cout <<"Run "<<i << " Value: " << unboundedKnapsack(W, n, val, wt) << endl; }
    cout << unboundedKnapsack(W, n, val, wt)<<endl;
    auto end = std::chrono::high_resolution_clock::now();
    double time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    cout << "Time taken by program is: " << time << " microseconds\n\n" << endl;


    W = 50;
    cout << "Dynamic Knapsack Capacity: " << W << endl;
    start = std::chrono::high_resolution_clock::now();
    for (int i=0; i<10; i++){ cout <<"Run "<<i << " Value: " << unboundedKnapsack(W, n, val, wt) << endl; }
    cout << unboundedKnapsack(W, n, val, wt) << endl;
    end = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    cout << "Time taken by program is: " << time << " microseconds" << endl;

    W = 100;
    cout << "Dynamic Knapsack Capacity: " << W << endl;
    start = std::chrono::high_resolution_clock::now();
    for (int i=0; i<10; i++){ cout <<"Run "<<i << " Value: " << unboundedKnapsack(W, n, val, wt) << endl; }
    cout << unboundedKnapsack(W, n, val, wt) << endl;
    end = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    cout << "Time taken by program is: " << time << " microseconds" << endl;
    
  
    return 0;
}