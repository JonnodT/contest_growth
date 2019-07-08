#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <cmath>
#include <queue>
#define maxn 2505

using namespace std;

int n,m, sum[maxn], f[maxn], last = 1;

int main(){
	//read data
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		int a; scanf("%d", &a);
		if(a == 1){
			sum[i] = sum[i-1]+1;
		}else{
			sum[i] = sum[i-1]-1;
		}
	}


	memset(f+1,127,sizeof(f)); //坑，如果是f而不是f+1不对，因为用到了j-1
	f[1] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			if(abs(sum[i]- sum[j-1])==i-j+1 || abs(sum[i] - sum[j-1]) <= m){
				f[i] = min(f[i], f[j-1] + 1);
			}
		}
	}
	cout << f[n];
	

	return 0;
}