#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define N 15
int arr[N][N],n,dp[N][N][N][N];

int main(){
	//read in data
	scanf("%d",&n);
	int a = -1, b = -1, c = -1;
	while(a != 0){
		scanf("%d%d%d",&a,&b,&c);
		arr[a][b] = c;
	}


	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <=n; k++){
				for(int l = 1; l <=n; l++){
					dp[i][j][k][l] = max(dp[i-1][j][k-1][l],max(dp[i][j-1][k][l-1],max(dp[i][j-1][k-1][l],dp[i-1][j][k][l-1])));
					if(i==k&&j==l){
						dp[i][j][k][l] += arr[i][j];
					}else{
						dp[i][j][k][l] += (arr[i][j] + arr[k][l]);
					}
				}
			}
		}
	}

	cout << dp[n][n][n][n] <<endl;
	return 0;
}