#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <stdio.h>
#include <map>
#include <algorithm>
#define maxn 105
#define debug cout << "Here" << endl;

using namespace std;

struct Edge{
	int to,w;
};

struct Pos{
	Pos(){};
	Pos(int & a, int & b){x = a; y = b;}
	int x, y;
};

int n,m, prd[maxn], prn[maxn], dis[maxn], org_dis;
bool inq[maxn];
vector<Edge> adj[maxn]; 
Pos path[maxn];
vector<Pos> poss;
vector<int> diff;


int spfa(){
	memset(dis, 127, sizeof(dis));
	memset(inq, false, sizeof(inq));
	memset(prd, 0, sizeof(prd));
	memset(prn, 0, sizeof(prn));
	queue<int> q; q.push(1); inq[1] = true; dis[1] = 0;
	while(!q.empty()){
		int t = q.front();
		q.pop();
		inq[t] = false;
		for(int i = 0; i < adj[t].size(); i++){
			Edge te = adj[t][i];
			if(dis[te.to] > dis[t] + te.w){
				prn[te.to] = t; prd[te.to] = te.w; path[te.to] = Pos(t,i);
				dis[te.to] = dis[t] + te.w;
				if(!inq[te.to]){q.push(te.to); inq[te.to] = true;}
			}
		}
	}

	int curr = n, res = 0;
	while(curr != 1){
		res += prd[curr];
		curr = prn[curr];
	}

	return res;
}


int main(){
	//read data
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int a,b,c; scanf("%d%d%d", &a, &b, &c);
		Edge ea; ea.to  = b; ea.w = c;
		Edge eb; eb.to = a; eb.w = c;
		adj[a].push_back(ea); adj[b].push_back(eb);
	}
	//start first round of spfa to find initial path
	memset(dis, 127, sizeof(dis));
	queue<int> q; q.push(1); inq[1] = true; dis[1] = 0;
	while(!q.empty()){
		int t = q.front();
		q.pop();
		inq[t] = false;
		for(int i = 0; i < adj[t].size(); i++){
			Edge te = adj[t][i];
			if(dis[te.to] > dis[t] + te.w){
				prn[te.to] = t; prd[te.to] = te.w; path[te.to] = Pos(t,i);
				dis[te.to] = dis[t] + te.w;
				if(!inq[te.to]){q.push(te.to); inq[te.to] = true;}
			}
		}
	}

	int curr = n;
	while(curr != 1){
		org_dis += prd[curr];
		poss.push_back(path[curr]);
		curr = prn[curr];
	}
	//now we have original shortest path stored in org_dis
	//try to double every edge on the path 
	for(unsigned int i = 0; i < poss.size(); ++i){
		Pos t = poss[i];
		adj[t.x][t.y].w *= 2;
		int res = spfa();
		diff.push_back(res - org_dis);
		adj[t.x][t.y].w /= 2;
	}

	sort(diff.begin(), diff.end());
	cout << diff[diff.size() - 1];
	return 0;
}