#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#define maxn 60

using namespace std;
int n, g[maxn][maxn],mx, deg[maxn], start;
char t[5];
stack<int> s;

int cp(char c){
	if(isupper(c)){
		return c-'A';
	}else{
		return c-'a'+26;
	}
}

char cc(int i){
	if(i < 26){
		return 'A' + i;
	}else{
		return 'a' + (i-26);
	}
}

void init(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%s", t);
		int x, y; x = cp(t[0]); y = cp(t[1]);
		g[x][y]++; g[y][x]++;
		deg[x]++; deg[y]++;
	}
	start = 1;
}

int find_start(){
	int cnt=1, ans=-1;
	bool flag = false;
	for(int i = 0; i < 52; i++){
		if(deg[i]&1){
			flag = true;
			ans = i;
			break;
		}
	}
	if(flag){
		//if there is at least one odd degree node
		for(int i = ans + 1; i < 52; i++){
			if(deg[i]&1){
				cnt++;
			}
		}
		if(cnt != 2){
			return -1;
		}else{
			return ans;
		}
	}else{
		//if all vertices have even degree
		for(int i = 0; i < 52; i++){
			//Return the smallest node as starting point
			if(deg[i]) return i;		
		}
	}
}

void hierholzer(int fr){
	for(int i = 0; i < 52; i++){
		if(g[fr][i]){
			g[fr][i]--; g[i][fr]--;
			hierholzer(i);
		}
	}
	s.push(fr);
}

void prt(){
	while(!s.empty()){
		cout << cc(s.top()); s.pop();
	}
}




int main(){
	init();
	if(n==0){
		cout << "No Solution" << endl;
		return 0;
 	}
 	start = find_start();
 	if(start == -1){
 		cout << "No Solution" << endl;
 		return 0;
 	}
 	hierholzer(start);
 	prt();


 	
	return 0;
}