#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <vector>
#define maxn 105
#define print cout << "here" << endl

struct Edge{
	int to, w;
};

int n, p[maxn], l[maxn], r[maxn], dist[maxn];
bool vis[maxn];
long long spsum[maxn];

using namespace std;

vector<int> adj[maxn];



int main(){
	//read in data
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int x,y,z;
		scanf("%d%d%d", &x, &y, &z);
		p[i] = x; l[i] = y; r[i] = z;
	}
	
	//build a graph
	for(int i = 1; i <= n; i++){
		if(l[i] != 0){
			adj[i].push_back(l[i]);
			adj[l[i]].push_back(i);
		}
		if(r[i] != 0){
			adj[i].push_back(r[i]);
			adj[r[i]].push_back(i);
		}
	}

	//bfs
	for(int i = 1; i <=n; i++){
		memset(dist, 0, sizeof(dist));
		memset(vis, 0, sizeof(vis));
		queue<int> q;
		q.push(i); vis[i] = true;
		while(!q.empty()){
			int t = q.front(); q.pop();
			for(int j = 0; j < adj[t].size(); j++){
				if(!vis[adj[t][j]]){
					vis[adj[t][j]] = true;
					dist[adj[t][j]] = dist[t] + 1;
					q.push(adj[t][j]);
				}
			}
		}
		long long sm = 0;
		for(int k = 1; k <= n; k++){
			sm += p[k] * dist[k];
		}
		spsum[i] = sm;
	}

	int minn = spsum[1];
	for(int i = 2; i <= n; i++){
		if(spsum[i] < minn) minn = spsum[i];
	}
	cout << minn;

	return 0;
}