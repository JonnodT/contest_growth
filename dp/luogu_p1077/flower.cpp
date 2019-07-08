#include <iostream>
#include <vector>
#include <set>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define maxn 105
#define MOD 1000007

using namespace std;

int n,m, arr[maxn], f[maxn][maxn];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}
	//fill in the base cases
	for(int i = 1; i <= n; i++) f[i][0] = 1;
	f[0][0] = 1;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			for(int k = 0; k <= min(j, arr[i]); k++){
				f[i][j] += f[i-1][j-k];
				f[i][j] %= MOD;
			}
		}
	}

	cout << f[n][m] <<endl;





	return 0;
}