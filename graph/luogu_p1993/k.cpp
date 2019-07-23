#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define maxn 10005

using namespace std;

struct Edge{
	int to, w;
};
int n,m, dis[maxn], ecnt;
vector<Edge> adj[maxn];
bool inq[maxn];
queue<int> q;


void add_edge(int f, int t , int wt){
	adj[f].push_back((Edge){t,wt});
	ecnt++;
}	

void init(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int x,a,b,c; scanf("%d%d%d",&x, &a, &b);
		if(x==1){
			scanf("%d", &c);
			add_edge(b,a,-c);
		}else if(x==2){
			scanf("%d", &c);
			add_edge(b,a,c);
		}else{
			add_edge(a,b,0);
			add_edge(b,a,0);
		}
	}
	for(int i = 1; i <= n ;i++){
		add_edge(0,i,0);
	}
}

bool spfa(){
	memset(dis, 127, sizeof(dis));
	q.push(0); inq[0] = true; dis[0] = 0;int cnt = 0;
	while(!q.empty()){
		int t = q.front(); q.pop();
		inq[t] = false;
		for(int i = 0; i < adj[t].size(); ++i){
			int tp = adj[t][i].to;
			if(dis[tp] > dis[t] + adj[t][i].w){
				dis[tp] = dis[t] + adj[t][i].w;
				if(!inq[tp]){
					inq[tp] = true;
					q.push(tp);
					cnt++;
					if(cnt > ecnt){
						return false;
					}
				}
			}
		}
	}
	return true;
}

int main(){
	init();
	bool res = spfa();
	if(res){
		cout << "Yes";
		return 0;
	}
	cout << "No";
	return 0;
}