#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>



const int maxn = 50005;
int m, n, ll, arr[maxn];

using namespace std;

int check(int mid){
	int cnt = 0, dis = 0;
	for(int i = 1; i <= n; i++){
		if(arr[i] - dis < mid){
			cnt ++;
		}else{
			dis = arr[i];
		} 
	}
	return cnt;
}

int main(){
	//read in data
	scanf("%d%d%d", &ll, &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}
	arr[n+1] = ll;


	//单调函数 -- f(x) 
	// x ~ 最短跳跃距离
	// f(x) ~ 需要移走的最小石块数量

	int l = 0;
	int r = ll;
	while(l <= r){
		int mid = l + (r-l)/2;
		int res = check(mid);
		if(res > m) r = mid - 1;
		else l = mid + 1;
	}
	cout << r;

	return 0;
}