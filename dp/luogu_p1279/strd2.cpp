/*
My attempt 2 to solve this problem.
AC
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
int kt, f[maxn][maxn],m,n;

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

	for(int i = 0; i < m; i++){
		f[i][0] = i*kt;
	}
	for(int i = 0; i < n; i++){
		f[0][i] = i*kt;
	}
	for(int i = 1; i < m; i++){
		for(int j = 1; j <n; j++){
			//k是slot数
			//slots从二者最大的开始，到两者的和
			f[i][j] = min(f[i-1][j-1]+dist(a[i],b[j]), min(f[i-1][j], f[i][j-1])+kt);
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
	cout << f[m-1][n-1] << endl;


	return 0;
}