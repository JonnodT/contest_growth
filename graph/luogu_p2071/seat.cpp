#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#define maxn 4005

using namespace std;
int a[maxn][4], ans;
int ym[maxn];
int n, rn;
bool used[maxn];
vector<int> tmp;

void init(){
	memset(ym, 0, sizeof(ym));
	scanf("%d", &rn);
	n = 2 * rn;;
	for(int i = 1; i <= n; i++){
		tmp.clear();
		int x,y; scanf("%d%d", &x, &y);
		tmp.push_back(x); tmp.push_back(y);
		tmp.push_back(x+rn); tmp.push_back(y+rn);
		sort(tmp.begin(), tmp.end());
		//一排能坐两个人，所以一个人选两排总共有四个位置可以坐
		a[i][0] = tmp[0]; a[i][1] = tmp[1];
		a[i][2] = tmp[2]; a[i][3] = tmp[3];
	}
}

bool hungarian(int s){
	for(int i = 0; i < 4; i++){
		int t = a[s][i];
		if(!used[t]){
			used[t] = true;
			if(!ym[t] || hungarian(ym[t])){
				ym[t] = s;
				return true;
			}
		}
	}
	return false;
}

int main(){
	init();
	for(int i = 1; i <= n; i++){
		memset(used, 0, sizeof(used));
		if(hungarian(i)) ans++;
	}
	
	cout << ans;
	return 0;
}