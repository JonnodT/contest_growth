#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <unordered_map>
#define maxn 100005

using namespace std;

int n, d[maxn], dp[maxn];



int main(){

	//读取数据并离散化处理
	unordered_map<int, int> map;
	scanf("%d", &n);
	if(n==0){
		cout << 0;
		return 0;
	}
	for(int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		map.insert(make_pair(a, i+1));
	}
	for(int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		d[i] = map[a];
	}


	//nlogn最长上升子序列
	dp[0] = d[0];
	int len = 0;
	for(int i = 1; i < n; i++){
		if(d[i] > dp[len]){
			dp[++len] = d[i];
		}else{
			int index = lower_bound(dp, dp + len + 1, d[i]) - dp;
			dp[index] = d[i];
		}
	}	
	cout << len + 1; 


	return 0;
}