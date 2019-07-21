#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <cstdio>
#define N 205
#define INF -2100000000

using namespace std;

int m,n, a[N][N], f[N][N], s;

void init(){
	scanf("%d%d",&m, &n); s = n/2;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			scanf("%d",&a[i][j]);
		}
	}
	//base case
	for(int i = 0; i < n; i++){
		if(i == s || i == s-1 || i == s+1){
			f[m-1][i] = a[m-1][i];
		}else{
			f[m-1][i] = INF;
		}
	}
}

void dp(){
	for(int i = m-2; i >= 0; i--){
		for(int j = 0; j < n; j++){
			int best = INF;
			if(j-1 >= 0) best = max(best, f[i+1][j-1] + a[i][j]);
			if(j+1 < n) best = max(best, f[i+1][j+1] + a[i][j]);
			best = max(best,f[i+1][j] + a[i][j]);
			f[i][j] = best;
		}
	}


}

int main(){
	init();
	dp();
	int ans = INF;
	for(int i = 0; i < n; i++){
		ans = max(ans, f[0][i]);
	}
	cout << ans;
	return 0;
}