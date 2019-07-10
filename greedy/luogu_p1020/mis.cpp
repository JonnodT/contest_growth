#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;
#define N 100005

int arr[N], dp1[N], dp2[N];

int main(){

	//read in data

	stringstream ss;
	string t;
	getline(cin,t);
	ss << t;
	int temp;
	int n = 0;
	while(ss >> temp){
		arr[n] = temp;
		n++;
	}

	//Compute longest non-increasing sequence
	//and longest increasing sequence at the same time
	arr[n] = -1;
	dp2[n] = 0;
	dp1[n] = 0;
	for(int j = n-1; j >= 0; j--){

		int best = 0;
		int best_i = n;
		for(int k = j + 1; k <= n; k++){
			if(arr[k] <= arr[j]){
				if(dp1[k] > best){
					best = dp1[k];
					best_i = k;
				}
			}
		}
		dp1[j] = 1 + dp1[best_i];


		int best2 = 0;
		int best2_i = n;
		for(int k = j + 1; k <= n; k++){
			if(arr[k] > arr[j]){
				if(dp2[k] > best2){
					best2 = dp2[k];
					best2_i = k;
				}
			}
		}
		dp2[j] = 1 + dp2[best2_i];
	}

	int best = -100;
	for(int i = 0; i < n; i++){
		if(dp1[i] > best){
			best = dp1[i];
		}
	}
	cout << best <<endl;


	int best2 = 1;
	for(int i = 0; i < n; i++){
		if(dp2[i] > best2){
			best2 = dp2[i];
		}
	}
	cout << best2;
	return 0;
}