#include<iostream>
#include<string>
#include<iomanip>
#include<stdio.h>
#define maxn 355
#define maxc 44

using namespace std;

int n,m,c[5],r[maxn],dp[maxc][maxc][maxc][maxc];

void init(){
	scanf("%d%d",&n, &m);
	//read road
	for(int i = 1; i <= n; i++){
		scanf("%d", &r[i]);
	}
	//read cards
	for(int i = 1; i <= m; i++){
		int num;
		scanf("%d",&num);
		c[num]++;
	}

	//Initialize score of the starting point
	dp[0][0][0][0] = r[1];
}

int main(){
	init();

	for(int i = 0; i <= c[1]; i++){
		for(int j = 0; j <= c[2]; j++){
			for(int k = 0; k <= c[3]; k++){
				for(int d = 0; d <= c[4]; d++){
					int sc = r[1+i + j*2 + k*3 + d*4];
					if(d!=0) dp[i][j][k][d] = max(dp[i][j][k][d], dp[i][j][k][d-1] + sc);
					if(k!=0) dp[i][j][k][d] = max(dp[i][j][k][d], dp[i][j][k-1][d] + sc);
					if(j!=0) dp[i][j][k][d] = max(dp[i][j][k][d], dp[i][j-1][k][d] + sc);
					if(i!=0) dp[i][j][k][d] = max(dp[i][j][k][d], dp[i-1][j][k][d] + sc);
				}
			}
		}
	}
	cout << dp[c[1]][c[2]][c[3]][c[4]]<< endl;
}	
