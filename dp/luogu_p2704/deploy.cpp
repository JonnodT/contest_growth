#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int n,m, a[105], sum[(1<<10)],f[3][(1<<10)][(1<<10)];
char t[15];

int count_one(int i){
	int cnt = 0;
	while(i){
		if(i&1) cnt++;
		i >>= 1;
	}
	return cnt;
}

void init(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%s", &t);
		for(int j = 0; j < m; j++){
			a[i] <<= 1;
			a[i] += (t[j] == 'H' ? 1 : 0);
		}
	}
}



int main(){
	init();
	for(int i = 0; i < (1<<m); ++i){
		sum[i] = count_one(i);
	}
	//初始化前两行
	for(register int i = 0; i < (1<<m); ++i){
		for(register int j = 0; j < (1<<m); ++j){
			if(!( (i&j) || (i&(i<<1)) || (i&(i<<2)) || (j&(j<<1)) || (j&(j<<2)) || (i&a[0]) || (j&a[1])))
			f[1][i][j] = sum[i] + sum[j];
		}
	}
	for(register int i = 2; i < n; i++){
		for(register int j = 0; j <(1<<m);++j){
			if( (j&(j<<1)) || (j&(j<<2)) || (j&a[i-1])) continue;
			for(register int k = 0; k <(1<<m); ++k){
				if( (k&(k<<1)) || (k&(k<<2)) || k&a[i] || k&j) continue;
				for(register int c = 0; c <(1<<m); ++c){
					if( c&j || k&c || (c&(c<<1)) || (c&(c<<2)) || (c&a[i-2])) continue;
					f[i%3][j][k] = max(f[(i-1)%3][c][j] + sum[k], f[i%3][j][k]);
				}
			}
		}
	}
	int best = -1;
	for(register int i = 0; i < (1<<m); ++i){
		for(register int j = 0; j < (1<<m); ++j){
			best = max(best, f[(n-1)%3][i][j]);
		}
	}

	cout << best;



	return 0;
}
