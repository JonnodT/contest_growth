/*
My attempt 1 to solve this problem.
TLE 50
*/

#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iostream>
#include <iomanip>
#define maxn 2005
using namespace std;
#define db cout << "Here" << endl;

char a[maxn], b[maxn];
int kt, f[2][maxn][maxn*2],m,n;

void init(){
	scanf("%s%s",a+1,b+1);
	a[0] = ' ';
	b[0] = ' ';
	m = strlen(a);
	n = strlen(b);
	scanf("%d", &kt);
}

// Computer distance
int dist(char a, char b){
	if(a == ' '|| b == ' '){
		if(a == ' '&& b == ' ') return 0;
		else return kt; 
	}else{
		return abs(a-b);
	}
}

int main(){
	init();
	int i,j;
	for(i = 0; i < m; i++){
		for(j = 0; j <n; j++){
			//k是slot数
			//slots从二者最大的开始，到两者的和
			int now = i%2;
			for(int k = max(i,j); k <= i+j; k++){
				int best = INT_MAX;
				if(i == 0 && j == 0) break;
				//总共应该分为四种情况
				if(i > 0 && j > 0){
					//上下都有
					best = min(best, f[now^1][j-1][i+j-2] + dist(a[i],b[j]));
					// if(i == 1&& j == 1 && k == 2){cout << best;}
				}
				if(i < k && j < k){
					//上下皆无
					best = min(best, f[now][j][k-1]);
					// if(i == 1&& j == 1 && k == 2){cout << best;}
				}
				if(i < k && j > 0){
					//上无下有
					best = min(best, f[now][j-1][i+j-1]+dist(' ',b[j]));
					// if(i == 1&& j == 1 && k == 2){cout << best;}
				}
				if(i > 0 && j < k){
					//上有下无
					best = min(best, f[now^1][j][i+j-1]+dist(a[i],' '));
					// if(i == 1&& j == 1 && k == 2){cout << best;}
				}
				f[now][j][k] = best;
				//debug
				// if(i == 1){
				// 	cout << 1 << " " << j  << " " << best << endl;
				// }
			}
		}
	}

	// for(int t = 0; t < 2; t++){
	// 	for(int tt = 0; tt < n; tt++){
	// 		for(int ttt = 0; ttt < m+n-2; ttt++){
	// 			cout << setw(10) << f[t][tt][ttt] << " ";
	// 		}
	// 		cout << endl;
	// 	}
	// 	cout << endl;
	// }
	cout << f[(i-1)%2][j-1][i+j-2] << endl;


	return 0;
}