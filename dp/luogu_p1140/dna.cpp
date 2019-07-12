#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#define maxn 105

using namespace std;

int n,m, f[maxn][maxn];
int sim[5][5] = {{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,-99999}};
char a[maxn],b[maxn];
map<char, int> mp;

int dist(char x, char y){
	return sim[mp[x]][mp[y]];
}

void init(){
	scanf("%d%s%d%s", &n, a+1, &m, b+1);
	a[0] = b[0] = ' '; n++; m++;
	mp.insert(make_pair('A',0));
	mp.insert(make_pair('C',1));
	mp.insert(make_pair('G',2));
	mp.insert(make_pair('T',3));
	mp.insert(make_pair(' ',4));
	f[0][0] = 0;
	for(int i = 1; i < m; i++){
		f[0][i] = dist(' ',b[i]) + f[0][i-1];
	}
	for(int i = 1; i < n; i++){
		f[i][0] = dist(' ',a[i]) + f[i-1][0];
	}
}



void dp(){
	for(int i = 1; i < n; i++){
		for(int j = 1; j < m; j++){
			f[i][j] = max(max(f[i-1][j] + dist(' ',a[i]), f[i][j-1] + dist(' ',b[j])), f[i-1][j-1] + dist(a[i],b[j]));
		}
	}
}

int main(){
	init();
	dp();
	cout << f[n-1][m-1];
	return 0;
}