#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <cstring>
#define maxn 10005
#define MOD 9987


using namespace std;

int n,m, dis[maxn],pren[maxn], prew[maxn];
bool inq[maxn]; // whether a node is in queue

struct Edge{
	int to, w;
};
queue<int> q;
vector<Edge> adj[maxn];

int main(){
	//read in data
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int x,y,z;
		scanf("%d%d%d", &x, &y, &z);
		Edge e; e.to = y; e.w = z;
		adj[x].push_back(e);
	}
	//set distance to infinity
	//注意127是正值max的最大值，128就变成负的了
	memset(dis, 127, sizeof(dis));

	//start SPFA
	dis[1] = 0; q.push(1); inq[1] = true;
	while(!q.empty()){
		int t = q.front(); q.pop();
		inq[t] = false; //出队
		//遍历这个node的所有边
		for(int i = 0; i < adj[t].size(); i++){
			Edge te = adj[t][i];
			if(dis[t] + te.w - 1 < dis[te.to]){
				//如果可以松弛

				//更新距离
				dis[te.to] = dis[t] + te.w - 1;
				pren[te.to] = t; prew[te.to] = te.w;
				//如果更新了距离且不在队内，入队
				if(!inq[te.to]){q.push(te.to); inq[te.to] = true;};
			}
		}
	}

	int ans = 1, now = n;
	while(now != 1){
		ans  = ((prew[now] % MOD) * ans) % MOD;
		now = pren[now];
	}
	cout << ans;
	return 0;	
}