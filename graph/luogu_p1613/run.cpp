#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <climits>
#define maxn 55
#define ll long long
#define DLIMIT 2147483647

using namespace std;

int n,m;
ll dis[maxn];
vector<int> adj[maxn];
set<ll> ps;
bool vis[maxn];

int main(){
	//build the graph
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int a,b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
	}

	ll temp = 1;
	while(temp < DLIMIT){
		ps.insert(temp);
		temp = temp * 2;
	}


	//start BFS
	queue<int> q;
	q.push(1); vis[1] = true;
	while(!q.empty()){
		int t = q.front(); q.pop();
		for(int i = 0; i < adj[t].size(); ++i){
			if(!vis[adj[t][i]]){
				vis[adj[t][i]] = true;
				dis[adj[t][i]] = dis[t] + 1;
				q.push(adj[t][i]);
			}
		}
	}
	ll tgt = dis[n];
	cout << tgt<<endl;
	if(ps.find(tgt) != ps.end()){
		cout << 1;
	}else{
		cout << 2;
	}



	return 0;
}