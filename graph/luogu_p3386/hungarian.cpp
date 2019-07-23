#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 1005

using namespace std;

int n,m,e,ans;

bool g[maxn][maxn];//邻接矩阵

//used 用于记录在一轮递归协商中被要求“腾”的，或者“腾”不出来的右侧节点，每走一轮左侧节点需要清空一次
//ym[i]是右侧第i个节点目前匹配的左侧节点号
int used[maxn], ym[maxn];

void init(){
	scanf("%d%d%d", &n, &m, &e);
	for(int i = 1; i <= e; i++){
		int u,v; scanf("%d%d", &u, &v);
		// 题目说数据有坑，这里过滤一下
		if(u <= n && v <= m){
			//注意这里只加一侧边就行， 因为我们的算法是单侧的
			g[u][v] = true;
		}
	}
}

bool hungarian(int s){
	for(int i = 1; i <= m; i++){
		// 如果有边连接着，而且这个点不是上层递归要求“腾出来”的节点
		if(g[s][i]&& used[i] == -1){
			used[i] = 1;
			//如果这个右侧节点还没有被匹配任何左侧节点(为默认值0)
			//或者可以通过递归协商被“腾”出来
			if(ym[i] == 0 || hungarian(ym[i])){
				ym[i] = s;
				return true;
			}
			//如果没进if，说明这个点“腾”不出来，以后也就别费功夫看了。
		}
	}
	return false;
}

int main(){
	init();
	for(int i = 1; i <= n; i++){
		// 清空匹配标记数组
		memset(used, -1, sizeof(used));
		if(hungarian(i)) ans++;
	}
	cout << ans;
	return 0;
}