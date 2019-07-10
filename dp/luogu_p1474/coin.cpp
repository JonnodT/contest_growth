#include <iostream>
#include <algorithm>
#define maxn 30

using namespace std;

int v,n, arr[maxn];
long long dp[10005];

int main(){
	scanf("%d%d",&v,&n);
	for(int i = 1; i <= v; i++){
		scanf("%d",arr+i);
	}

	dp[0] = 1;
	for(int i = 1; i <= v; i++){
		for(int j = arr[i]; j <= n; j++){
			dp[j] += dp[j - arr[i]];
		}
	}

	cout << dp[n] <<endl;
	return 0;
}
