#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#define maxn 100005

using namespace std;
int n, cnt[maxn], f[maxn],mx=-1;

void init(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int t;
		scanf("%d", &t);
		mx = max(mx, t);
		cnt[t]++;
	}
}


//Dynamic Programming Function
void dp(){
	//base case
	f[1] = cnt[1];
	for(int i = 2; i <= n; i++){
		f[i] = max(f[i-1], f[i-2] + cnt[i]*i);
	}
}

int main(){
	init();
	dp();
	cout << f[mx] << endl;
	return 0;
}