#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include <stdio.h>
#include <algorithm>
#define maxn 55

//Floyd + 倍增

using namespace std;

int m,n;
int adj[maxn][maxn]; // adjacency matrix
bool d[maxn][maxn][maxn];

int main(){
	scanf("%d%d", &n, &m);
	//这里不能设置127，否则merge两条路的时候会爆掉
	memset(adj,62,sizeof(adj));
	for(int i = 1; i <= m; i++){
		int a, b; scanf("%d%d", &a, &b);
		d[a][b][0] = true;
		adj[a][b] = 1;
	}

	for(int k = 1; k <= 30; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				for(int t= 1; t <= n; t++){
					if(d[i][t][k-1] && d[t][j][k-1]){
						d[i][j][k] = true; adj[i][j] = 1;
					}
				}
			}
		}
	}

	//floyd
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}

	cout << adj[1][n];

	return 0;
}