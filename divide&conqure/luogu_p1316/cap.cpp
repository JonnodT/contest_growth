#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int a, b, arr[100005];


//要达到n需要移走多少个瓶盖
int check(int n){
	int cnt = 0;
	int prev = arr[1];
	for(int i = 2; i <= a; i++){
		if(arr[i] - prev < n){
			cnt ++;
		}else{
			prev = arr[i];
		}
	}
	return cnt;
}


int main(){

	//read in data
	scanf("%d%d", &a, &b);
	for(int i = 1; i <= a; i++){
		scanf("%d", &arr[i]);
	}

	sort(arr + 1, arr + 1 + a);
	int l = 1, r = arr[a] - arr[1];
	while(l <= r){
		int mid = l + (r - l)/2;
		if(check(mid) > a - b) r  = mid - 1;
		else l = mid + 1;
	}

	cout << r;



	return 0;
}