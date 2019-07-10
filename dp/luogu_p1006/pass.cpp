#include <algorithm>
#include <iostream>

using namespace std;
#define N 55

int m,n,arr[N][N];
int f[2*N][N][N];
int main(){
	//readin data
	scanf("%d%d",&m,&n);
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d",arr[i]+j);
		}
	}

	for(int i = 3; i < m+n; i++){
		for(int j = 1; j < i - 1; j++){
			for(int k = j+1; k <= i - 1; k++){
				int best = f[i][j][k];
				if(f[i-1][j][k] > best) best = f[i-1][j][k]; //both come from above
				if(f[i-1][j-1][k-1] > best) best = f[i-1][j-1][k-1]; //both come from left
				if(f[i-1][j][k-1] > best) best = f[i-1][j][k-1];
				if(f[i-1][j-1][k] > best) best = f[i-1][j-1][k];
				f[i][j][k] = best + arr[i-j][j] + arr[i-k][k];
 			}
		}
	}

	cout << f[m+n-1][n-1][n] << endl;

	return 0;
}