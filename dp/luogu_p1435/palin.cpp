//Think about sequence alignment
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#define maxn 1010

using namespace std;
char a[maxn], b[maxn];
int dp[maxn][maxn];
int n;

void reverse(){
	
	int j = 1;
	for(int i = strlen(a+1); i >= 1; i--){
		b[j] = a[i];
		j++;
	}
}

int main(){
	//read in data
	scanf("%s", a + 1);
	n = strlen(a+1);
	reverse();
	//strlen函数的坑


	//最长公共子序列
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i] == b[j]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}			
		}
	}
	cout << n - dp[n][n];
	return 0;
}