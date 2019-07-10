#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#define maxn 1010

using namespace std;
int n, m, w[maxn], dg[maxn];
vector<int> adj[maxn];

struct Node{
	int i, c;
};

vector<Node> cost;

bool cmp(Node n1, Node n2){
	return w[n1.i] < w[n2.i];
}

int main(){
	//readin data
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &w[i]);
	}
	for(int i = 1; i <= m; i++){
		int a,b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
		dg[a]++; dg[b]++;
	}

	for(int i = 1; i <= n; i++){
		int sum = 0;
		for(int j = 0; j < adj[i].size(); j++){
			sum += w[adj[i][j]];
		}
		Node x;
		x.i = i; x.c = sum;
		cost.push_back(x);
	}

	int sum = 0;
	int cnt = n;
	while(cnt > 0){
		sort(cost.begin(), cost.end(), cmp);
		Node ne = cost.back(); cost.pop_back();
		sum += ne.c;
		int index = ne.i;
		for(int j = 0; j < cost.size(); j++){
			for(int k = 0; k < adj[index].size(); k++){
				if(cost[j].i == adj[index][k]){
					cost[j].c -= w[index];
					dg[cost[j].i] --;
				} 
			}
		}
		cnt --;
	}

	cout << sum;
	return 0;
}