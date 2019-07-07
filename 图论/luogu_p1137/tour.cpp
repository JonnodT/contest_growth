#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <vector>
#include <stdio.h>
#include <queue>
#define maxn 100005

using namespace std;

vector<int> adj[maxn];
vector<int> pos;
int cnt[maxn];
int n,m,f[maxn];

int dfs(int s){
	//base case
	if(adj[s].size() == 0){
		f[s] = 1;
		return 1;
	}

	if(f[s]!=-1){
		return f[s];
	}

	for(int i = 0; i < adj[s].size(); ++i){
		int res = dfs(adj[s][i]) + 1;
		if(res > f[s]) f[s] = res;
	}
	return f[s];
}

int main(){
	//read data and build graph
	memset(f,-1,sizeof(f));

	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		adj[b].push_back(a);
		cnt[a]++;
	}
	//loop over possible starting point
	for(int i = 1; i <= n; i++)
		if(cnt[i]==0)
			//if the node has no incoming edges
			pos.push_back(i);

	for(int i = 0; i < pos.size(); ++i){
		dfs(pos[i]);
	}

	//print answer
	for(int i = 1; i <= n; i++){
		cout << f[i] << endl;
	}
	return 0;
}