#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <climits>
#define maxn 205

using namespace std;
int n, arr[maxn], fma[maxn][maxn], fmi[maxn][maxn], sum[maxn];

inline int d(int i,int j){return sum[j]-sum[i-1];}
int main(){
	//readin data
	cin >> n;
	for(int i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
		sum[i] = sum[i-1] + arr[i];
	}
	//前缀和需要绕过来
	for(int i = n + 1; i <= 2*n; ++i){
		sum[i] = sum[i-1] + arr[i - n];
	}

	//start 区间dp
	//i 是区间长度，j是起始点，k是分割点
	for(int i = 1; i < n; i++){
		for(int j = 1; j <= 2*n-i; j++){
			fmi[j][j+i] = INT_MAX;
			for(int k = j; k < j + i; k++){
				fmi[j][j+i] = min(fmi[j][j+i],(fmi[j][k] + fmi[k+1][j+i] + d(j,j+i)));
				fma[j][j+i] = max(fma[j][j+i],(fma[j][k] + fma[k+1][j+i] + d(j,j+i)));
			}
		}
	}
	//find max answer
	int answer1 = -1;
	int answer2 = 99999999;
	for(int i = 1; i <= n; i++){
		answer1 = max(answer1, fma[i][i+n-1]);
		answer2 = min(answer2, fmi[i][i+n-1]);
	}

	cout << answer2<< endl;
	cout << answer1;

	return 0;
}