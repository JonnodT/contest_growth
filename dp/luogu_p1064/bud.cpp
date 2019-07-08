/*WA30分代码*/
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <set>
#define maxm 65
#define maxn 32010

using namespace std;

//v = value p = importance q = type
int n,m, v[maxm], p[maxm], q[maxm], od[maxm], f[maxm][maxn];
int ch[maxm];

bool cmp(int a, int b){
	return q[a] < q[b];
}


void init(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		v[i] = a; p[i] = b; q[i] = c;
		od[i] = i;
	}
	// Sort the objects to make sure that type main comes first
	sort(od+1, od+1+m, cmp);
}	

int main(){
	init();

	int last = -1; //last main item
	int tp = -1;
	for(int i = 1; i <= m; i++){
		if(q[od[i]]==0){
			tp = od[i];
		}else{
			last = tp;
			break;
		}
	}

	//Start dp
	for(int i = 1; i <= m; i++){
		int k = od[i]; // The index of the object to consider
		int value = (q[k] == 0)?(p[k]*v[k]):(ch[q[k]]*p[k]*v[k]); //Compute value according to cost
		for(int j = 1; j <= n; j++){
			if(j >= v[k]){
				f[i][j] = max(f[i-1][j - v[k]]+value,f[i-1][j]);
				
			}else{
				f[i][j] = f[i-1][j];
			}
		}
		if(k == last){ //reconstruct the path
			int pos = n;
			for(int c = i; c > 0; c--){
				if(f[c][pos] != f[c-1][pos]){
					ch[c] = 1;
					pos = pos - v[od[c]];
				}
			}
		}
	}

	//answer
	cout << f[m][n];
	return 0;
}
