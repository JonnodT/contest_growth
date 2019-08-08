#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define maxn 205

using namespace std;
int n,m, ans, ym[maxn];
bool g[maxn][maxn], used[maxn];


void init(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		int x; scanf("%d", &x);
		for(int j = 1; j <= x; j++){
			int d; scanf("%d", &d);
			g[i][d] = true;
		}
	}
}

bool hungarian(int s){
	for(int i = 1; i <= m; i++){
		if(g[s][i] && !used[i]){
			//把true设置在这里意思是这个点要腾
			used[i] = true;
			if(ym[i] == 0 || hungarian(ym[i])){
				ym[i] = s;
				return true;
			}
		}
	}
	return false;
}

int main(){
	init();
	for(int i = 1; i <= n; i++){
		memset(used, 0, sizeof(used));
		if(hungarian(i)) ans++; 
	}
	cout << ans;
	return 0;
}