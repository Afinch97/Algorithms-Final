//Unbounded Knapsack using Brute Force or Exhaustive Search
//Try all possible combination of items and choose the best one
#include<stdio.h>
#include<iostream>
#include<chrono>
#include<string.h>
#include<vector>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n) {
	//The best case scenario
	if (n == 0 || W == 0) {
		return 0;
	}
	//If the weight of the nth item is more than Capacity W,
	//This can't be in optimal solution
	if (wt[n - 1] > W) {
		//cout << val[n] << " dollar bill Weight: " << wt[n]<<endl;
		return knapSack(W, wt, val, n - 1);

	}
	else {
		return max(val[n - 1] + knapSack(W - wt[n - 1],wt, val, n),
			knapSack(W, wt, val, n - 1));
	}
}

int main(){
	int val[] = { 1, 2, 5, 10, 20, 50 , 100  };
	int wt[] = { 1, 3, 5, 9, 17, 44, 80 };
	int W = 10;
	int n = sizeof(val) / sizeof(val[0]);
	cout << "Brute Forced Knapsack Capacity: " << W << endl;
	auto start = std::chrono::high_resolution_clock::now();
	//ios_base::sync_with_stdio(false);
	for (int i=0; i<10; i++){ cout <<"Run "<<i << " Value: " << knapSack(W, wt, val, n) << endl; }
	cout << "Value: "<<knapSack(W, wt, val, n)<<endl;
	auto end = std::chrono::high_resolution_clock::now();
	double time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	cout << "Time taken by program is: " << time << " microseconds" << endl;
	cout << "Average time is: " << time/10 << " microseconds\n\n" << endl;
	
	 W = 50;
	cout << "Brute Forced Knapsack Capacity: " << W << endl;
	 start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 10; i++) { cout << "Run " << i << " Value: " << knapSack(W, wt, val, n) << endl; }
	 end = std::chrono::high_resolution_clock::now();
	 time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	cout << "Time taken by program is: " << time << " microseconds" << endl;
	cout << "Average time is: " << time / 10 << " microseconds" << endl;
	 W = 100;
	cout << "Brute Forced Knapsack Capacity: " << W << endl;
	 start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 10; i++) { cout << "Run " << i << " Value: " << knapSack(W, wt, val, n) << endl; }
	 end = std::chrono::high_resolution_clock::now();
	 time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	cout << "Time taken by program is: " << time << " microseconds" << endl;
	cout << "Average time is: " << time / 10 << " microseconds" << endl;

	
	return 0;
}