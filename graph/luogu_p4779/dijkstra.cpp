#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
#include <cstring>
#define maxn 100005
#define maxm 200005

using namespace std;
struct Edge{
	int to, w;
};
struct Node{
	int pos, dist;
	bool operator< (const Node & n) const{
		return dist > n.dist;
	}
}nds[maxn];
int n,m,s;
int dist[maxn];
vector<Edge> adj[maxn];
priority_queue<Node> q;


void init(){
	memset(dist,127,sizeof(dist));
	scanf("%d%d%d",&n,&m,&s);
	for(register int i = 1; i <= m; i++){
		int x,y,z;
		scanf("%d%d%d", &x, &y, &z);
		adj[x].push_back((Edge){y,z});
	}
}

void dijkstra(){
	dist[s] = 0; q.push((Node){s,0});
	while(!q.empty()){
		Node tmp = q.top(); q.pop();
		int curr = tmp.pos; 
		if(dist[curr] != tmp.dist) continue;
		for(register int i = 0; i < adj[curr].size(); ++i){
			if(dist[adj[curr][i].to] > dist[curr] + adj[curr][i].w){
				dist[adj[curr][i].to] = dist[curr] + adj[curr][i].w;
				q.push((Node){adj[curr][i].to,dist[adj[curr][i].to]});
			}
		}
	}
}

int main(){
	init();
	dijkstra();
	for(register int i = 1; i <= n; i++){
		cout << dist[i] << " ";
	}
	return 0;
}