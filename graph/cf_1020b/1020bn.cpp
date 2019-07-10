#include <iostream>
#include <queue>
#define maxn 1005

using namespace std;

int n, arr[maxn], deg[maxn], ans[maxn];


int res(int i){
	return (i == ans[i] ? i : ans[i] = res(ans[i]));
}

int main(){
	
	scanf("%d",&n);
	for(int i = 1; i <=n; i++){
		scanf("%d",arr+i);
		deg[arr[i]]++;
	}

	for(int i = 1; i <= n; ++i) ans[i] = i;

	queue<int> q;
	for(int i = 1; i <= n; ++i){
		if(deg[i] == 0){
			q.push(i);
		}
	}

	while(!q.empty()){
		int t = q.front(); q.pop();
		--deg[arr[t]]; ans[t] = arr[t];
		if(deg[arr[t]] == 0) q.push(arr[t]);
	}

	for(int i = 1; i <= n; i++){
		printf("%d ", res(i));
	}
	return 0;

}