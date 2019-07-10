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

int n, p[maxn], l[maxn], r[maxn], dist[maxn], pren[maxn], pred[maxn];
bool inq[maxn];
long long spsum[maxn];

using namespace std;

vector<Edge> adj[maxn];



int main(){
	//read in data
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int x,y,z;
		scanf("%d%d%d", &x, &y, &z);
		p[i] = x; l[i] = y; r[i] = z;
	}
	//build a graph with bi-directional edges
	for(int i = 1; i <= n; i++){
		if(l[i]!=0){
			int t = l[i];
			Edge e; e.to = t; e.w = p[t];
			adj[i].push_back(e);
			Edge e2; e2.to = i; e.w = p[i];
			adj[t].push_back(e2);
		}
		if(r[i]!=0){
			int t = r[i];
			Edge e; e.to = t; e.w = p[t];
			adj[i].push_back(e);
			Edge e2; e2.to = i; e.w = p[i];
			adj[t].push_back(e2);
		}
	}

	//Start spfa
	for(int i = 1; i <= n; i++){
		memset(dist, 127, sizeof(dist));
		memset(pren, 0, sizeof(pren));
		memset(pred, 0, sizeof(pred));
		memset(inq, 0, sizeof(inq));
		queue<int> q;
		q.push(i); inq[i] = true;
		dist[i] = 0;
		while(!q.empty()){
			print;
			int t = q.front(); q.pop();
			inq[t] = false;
			cout << "Size: " << adj[t].size() << endl;
			for(int j = 0; j < adj[t].size(); j++){
				Edge te = adj[t][j];
				// shrink successfully
				if(dist[te.to] > dist[t] + te.w){
					dist[te.to] = dist[t] + te.w;
					pred[te.to] = te.w;
					pren[te.to] = t;
					if(!inq[te.to]){ q.push(te.to); inq[te.to] = true;}
				}
			}
		}

		for(int i = 1; i <= n; i++){
			cout << pren[i] << endl;
		}
		long long sum = 0;
		for(int j = 1; j <= n; j++){
			int start = j;
			while(start != i){
				print;
				sum += pred[start];
				start = pren[start];
			}
		}
		spsum[i] = sum;	
	}
	//find min element
	int minn = spsum[1];
	for(int i = 2; i <= n; i++){
		if(spsum[i] < minn) minn = spsum[i];
	}
	for(int i = 1; i <= n; i++){
		cout << spsum[i] <<  " ";
	}

	cout << minn;
	return 0;
}