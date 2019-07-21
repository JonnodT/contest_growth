#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>
#define maxn 505

using namespace std;

int n;
int g[maxn][maxn];
int deg[maxn], start, mx;
stack<int> s;

void init(){
	//Read input
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int x,y; scanf("%d%d",&x, &y);
		mx = max(mx,max(x,y));
		g[x][y]++;
		g[y][x]++;
		deg[x]++; deg[y]++;
	}
	start = 1;
}

void find_start(){
	//Find starting point for hierholzer.
	//If there is no odd degree vertex, start from 1
	//If there are 2 odd degree vertex(guaranteed by the problem), start
	//from the smaller one.
	for(int i = 1; i <= mx; i++){
		if(deg[i]&1){ //Same as deg[i]%2, but faster.
			//If this node has odd degree
			start = i;
			break;
		}
	}
}

void hierholzer(int fr){
	//Hierholzer's algrithm for finding A euler path.
	for(int j = 1; j <= mx; j++){
		if(g[fr][j]){
			g[fr][j]--; g[j][fr]--;
			hierholzer(j);
		}
	}
	s.push(fr);
}

void prt(){
	//Print answer
	while(!s.empty()){
		cout << s.top() << endl;
		s.pop();
	}
}

int main(){
	init();
	find_start();
	hierholzer(start);
	prt();
	return 0;
}