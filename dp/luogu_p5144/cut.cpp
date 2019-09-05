#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <climits>
#include <cstring>
#define maxn 1005
#define maxm 105

using namespace std;
int n,m, w[maxn];
//Dynamic Programming Array
int f[maxn][maxm];

int sum[maxn];

void init(){
	memset(f,-1, sizeof(f));
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", w+i);
	}
	//compute Xor in sum
	sum[1] = w[1];
	for(int i = 2; i <= n; i++){
		sum[i] = sum[i-1]^w[i];
	}
	for(int i = 1; i <= n; i++){
		f[i][1] = sum[i];
	}
}

void dp(){
	for(int i = 2; i <= m; i++){
		// 这里j的起始点是j，因为这个wa了很久
		for(int j = 2; j <= n; j++){
			for(int k = 1; k < j; k++){
				f[j][i] = max(f[j][i], f[k][i-1] + (sum[j]^sum[k]));
			}
		}
	}
}

int main(){
	init();
	dp();
	cout << f[n][m] << endl;
	return 0;}
