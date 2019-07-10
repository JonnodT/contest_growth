//区间dp版本的答案
#include <iostream>
#include <vector>
#include <set>
#include <stdio.h>
#include <algorithm>
#include <climits>
#define maxn 505

using namespace std;
int n, k, arr[maxn], dp[maxn][maxn], sum[maxn], ans;


void pt(int l, int r){
	int sum = 0;
	for(int i = r; i >= l; i--){
		if(sum + arr[i] > ans){
			pt(l, i);
			cout << i+1 << " " << r << endl;
			return;
		}
		sum += arr[i];
	}
	cout << 1 << " " << r <<endl;
}


int main(){
	//readin data
	scanf("%d%d", &n, &k);
	if(n == 0) return 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", arr + i);
		//维护前缀和数组
		sum[i] = sum[i - 1] + arr[i];
	}	


	for(int i = 1; i <= n; i++){
		dp[1][i] = sum[i];
	}

	for(int i = 2; i <= k; i++){
		for(int j = 1; j <= n; j++){
			dp[i][j] = INT_MAX;
			for(int k = 1; k <= j; k++){
				dp[i][j] = min(dp[i][j], max(dp[i-1][k-1],sum[j]-sum[k-1]));
			}
		}
	}
	ans = dp[k][n];
	pt(1,n);



	return 0;
}