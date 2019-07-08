#include <isotream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <set>
#include <queue>
#include <climits>
#define MOD 9987
#define maxn 1005
#define INF INT_MAX

using namespace std;

struct Edge{
	int to, w;
};

int n, m, dis[maxn];
vector<Edge> adj[maxn];

int main(){
	//read data
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int x,y,z; scanf("%d%d%d", &x, &y, &z);
		Edge e; e.to = y;
		//to deal with multiply instead of addition
		//don't forget to add this 1 back 
		e.w = z - 1;
		adj[i].push_back(e);
	}
	fill(dis, dis + maxn, INF);

	//use Dijkstra to find sssp
	dis[1] = 0;
	int next = 1;
	while(fi.size()!=n){
		for(int i = 0; i < adj[next].size(); i++){
			Edge t = adj[next][i];
			if(fi.find(t.to)!=fi.end()){
				if(t.w + dis[next] < dis[t.to]){
					dis[t.to] = t.w + dis[next];
 				} 
			}
		}
		fi.insert(next);
		int min = INF; min_i = -1;
		for(int i = 1; i <= n; i++){
			if(dis[i] < min){
				min = dis[i];
				min_i = i;
			} 
		}
		next = min_i;
	}

	return 0;
}