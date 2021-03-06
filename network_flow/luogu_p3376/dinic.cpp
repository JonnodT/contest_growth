#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#define maxn 10020
#define maxm 200020

using namespace std;
struct Edge{
	int to, w, next;
};
int n,m,s,t,head[maxn], depth[maxn],cnt = -1;
Edge arr[maxm];

//return 1 if t is reachable
//return 0 if t is not reachable
int bfs(){
	queue<int> q;
	memset(depth, 0, sizeof(depth));
	q.push(s); depth[s] = 1;
	while(!q.empty()){
		int t = q.front(); q.pop();
		for(int i = head[t]; i != -1; i = arr[i].next){
			Edge e = arr[i];
			if(depth[e.to]==0 && e.w != 0){
				depth[e.to] = depth[t] + 1;
				q.push(e.to);
			}
		}
	}
	if(depth[t] == 0)return 0;
	else return 1;
}

int dfs(int node, int flow){
	if(node == t) return flow;
	for(int i = head[node]; i != -1; i = arr[i].next){
		Edge e = arr[i];
		if(e.w != 0 && depth[e.to] == depth[node] + 1){
			int inc = dfs(e.to, min(flow, e.w));
			if(inc > 0){
				arr[i].w -= inc;
				arr[i^1].w += inc;
				return inc;
			}
		}
	}
	return 0;
}

int dinic(){
	int ans = 0;
	while(bfs()){
		while(int i = dfs(s, INT_MAX)){
			ans += i;
		}
	}
	return ans;
}


int main(){
	//initialize graph
	memset(head, -1, sizeof(head));
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for(int i = 1; i <= m; i++){
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		Edge e; e.to = y; e.w = z; 
		arr[++cnt] = e;
		arr[cnt].next = head[x];
		head[x] = cnt;
		Edge re; re.to = x; e.w = 0; //反向边
		arr[++cnt] = re;
		arr[cnt].next = head[y];
		head[y] = cnt;
	}
	cout << dinic();
	return 0;
}