#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mod 100000000
#define maxn 15

using namespace std;

int gd[maxn][maxn], cnt[maxn], st[maxn][5000], sm[maxn][5000];
int f[maxn][5000];
int n, m;

void init(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int tmp;
			scanf("%d", &tmp);
			gd[i][j] = tmp;
		}
	}
}

void dfs(int r, int curr, int sum, int deci){
	if(curr >= m){
		st[r][++cnt[r]] = deci;
		sm[r][cnt[r]] = sum;
		return;
	}
	//Can only pick this if there it's 1
	if(gd[r][curr]) dfs(r, curr+2, sum+1, deci+(1<<curr));
	dfs(r, curr+1, sum, deci);
}

void get_states(){
	for(int i = 0; i < n; i++) dfs(i,0,0,0);
}

int main(){
	init();
	get_states();
	//start dp
	for(int i = 1; i <= cnt[0]; ++i) f[0][i] = 1;
	for(int i = 1; i < n; i++){
		for(int j = 1; j <= cnt[i]; j++){
			for(int k = 1; k <= cnt[i-1]; k++){
				if(st[i][j]&st[i-1][k]) continue;
				f[i][j] += f[i-1][k];
			}
		}
	}
	long long ans = 0;
	for(int i = 1; i <= cnt[n-1]; i++){
		ans += f[n-1][i];
		ans %= mod;
	}
	cout << ans;
	return 0;
}