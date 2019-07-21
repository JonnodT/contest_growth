#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 1005

using namespace std;
//a原始数据 s前缀和 ans答案
int a[maxn][maxn], s[maxn][maxn],n,m,r,c,ans;

//读取	
void init(){
	scanf("%d%d%d%d", &n, &m, &r, &c);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int t; scanf("%d", &t);
			a[i][j] = t;
		}
	}
}

void psum(){
	/*计算前缀和*/
	//base case;
	s[0][0] = a[0][0];
	for(int i = 1; i < m; i++){
		s[0][i] = a[0][i] + s[0][i-1];
	}
	for(int i = 1; i < n; i++){
		s[i][0] = a[i][0] + s[i-1][0];
	}
	//compute first 2d pre-sum
	for(int i = 1; i < n; i++){
		for(int j = 1; j < m; j++){
			s[i][j] = a[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
		}
	}


	/*计算最大rxc子矩阵和*/
	ans = -1;
	//compute seconde 2d pre-sum
	for(int i = r-1; i < n; i++){
		for(int j = c-1; j < m; j++){
			if(i-r >= 0 && j-c >= 0){
				ans = max(ans,s[i][j] - s[i-r][j] - s[i][j-c] + s[i-r][j-c]);
			}else if(i-r >= 0){
				ans = max(ans, s[i][j] - s[i-r][j]);
			}else if(j-c >= 0){
				ans = max(ans, s[i][j] - s[i][j-c]);
			}else{
				ans = max(ans,s[i][j]);
			}
		}
	}
}

int main(){
	init();
	psum();
	cout << ans;
	return 0;
}