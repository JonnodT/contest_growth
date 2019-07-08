#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#define maxn 10005

using namespace std;

struct Edge{
	int to,w,f;
};

//used to store position of edges
struct Pos{
	Pos(){};
	Pos(int a, int b){
		x = a; y = b;
	}
	int x,y;
};

vector<Edge> adj[maxn];
int n,m,s,t;
Pos path[maxn];
bool vis[maxn];


//send flow 
void send(int btn){
	cout << "insend" << endl;
	int temp = t;
	while(temp != s){
		adj[path[temp].x][path[temp].y].f = btn;
		//update
		temp = path[temp].x;
	}
}

int bottleneck(){
	cout << "bottleneck" << endl;
	int minn = INT_MAX;
	int temp = t;
	while(temp != s){
		minn = min(minn, adj[path[temp].x][path[temp].y].w);
		temp = path[temp].x;
	}
	return minn;
}

void flush(){
	cout << "inflush" << endl;
	memset(vis, 0, sizeof(vis));
	Pos temp = Pos(-1,-1);
	for(int i = 1; i <= n; i++){
		path[i] = temp;
	}
}

//return true if there is a path from s to t
bool bfs(){
	cout << "inbfs" << endl;
	flush();
	//initialize
	queue<int> q; q.push(s); vis[s] = true;
	while(!q.empty()){
		int temp = q.front(); q.pop();
		cout << "inwhile" << endl;
		for(unsigned int i = 0; i < adj[temp].size(); ++i){
			cout << "infor" << endl;
			Edge te = adj[temp][i];
			if(!vis[te.to]){
				vis[te.to] = true; 
				path[te.to] = Pos(temp,i);
			}
		}
	} 	
	return vis[t];
}

void aug(int a, int b, int f){
	cout << "inaug" << endl;
	for(int i = 0; i < adj[a].size(); i++){
		if(adj[a][i].to == b){
			adj[a][i].w += f;
			return;
		}
	}
	Edge e; e.to = b; e.w = f;
	adj[a].push_back(e);

}

void residue(){
	cout << "inresidue" << endl;
	for(int i = 1; i <= n; i++){
		vector<Edge> ng;
		for(unsigned int j = 0; j < adj[i].size(); j++){
			if(adj[i][j].f == 0) continue;
			aug(j, i, adj[i][j].f);
			adj[i][j].w = adj[i][j].w - adj[i][j].f;
			adj[i][j].f = 0;
			if(adj[i][j].f - adj[i][j].w != 0){
				ng.push_back(adj[i][j]);
			}
		}
		adj[i] = ng;
	}
}


int main(){
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for(int i = 1; i <= m; i++){
		int a,b,c;
		scanf("%d%d%d", &a, &b, &c);
		Edge n; n.to = b; n.w = c; n.f = 0;
		adj[a].push_back(n);
	}

	/*
	maxflow algo.
	while(there is a path){
		find bottleneck
		build residue graph
	}
	maxflow = sum of incoming edges of t node
	*/

	while(bfs()){
		send(bottleneck());
		residue();
	}
	int maxflow = 0;

	for(unsigned int i = 0; i <= adj[t].size(); ++i){
		maxflow += adj[t][i].f;
	}

	cout << maxflow;
	return 0;
}