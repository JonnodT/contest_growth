#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
#define maxn 1005

using namespace std;
//a数组存骨牌的点数
//sum 存上点数和与下点数和
//diff是预处理后上下点数和的差值，同时也是我们背包最大的value值
//f是dp数组
int n, a[maxn][2], sum[2], diff, cnt, f[maxn][maxn*6];
bool can[maxn][maxn*6];

//如果预处理中翻了骨牌i，f[i] = -1, 反之f[i] = 1
int flip[maxn]; 

//每个骨牌的value，即翻转带来的上下差值的减小值
int vl[maxn];

void init(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) flip[i] = 1;
	for(int i = 1; i <= n; i++){
		int x,y; scanf("%d%d", &x, &y);
		if(x < y){
			// 大的在上小的在下
			a[i][0] = y; a[i][1] = x;
			sum[0] += y; sum[1] += x;
			flip[i] = -1;
			cnt++;
			vl[i] = 2*(y-x);
			continue;
		}
		sum[0] += x; sum[1] += y; 
		a[i][0] = x; a[i][1] = y;
		vl[i] = 2*(x-y);
	}
	diff = sum[0] - sum[1];
}

void dp(){
	//value: 翻转得到的差值减少, 想让value最大， value = diff我们就得到了0差值
	//cost: 1 -1 我们想让差值最小，初始cost为cnt，也就是已经翻转的骨牌数量，我们想让差值最小，最小为0，不可能再小，因为每个骨牌只能选一次
	
	//base case
	f[0][0] = cnt; 
	can[0][0] = true;
	
	
	for(int i = 1; i <= n; ++i){
		//考虑前i个骨牌（前i个物品）
		for(int j = 0; j <= diff; ++j){
			can[i][j] = true;
			if(j >= vl[i]){
				if(!can[i-1][j] && !can[i-1][j-vl[i]]){
					//两个都取不到
					can[i][j] = false;
					continue;
				}else if(!can[i-1][j]){
					f[i][j] = f[i-1][j-vl[i]] + flip[i];
				}else if(!can[i-1][j-vl[i]]){
					f[i][j] = f[i-1][j];
				}else{
					//两个都能取到
					f[i][j] = min(f[i-1][j],f[i-1][j-vl[i]] + flip[i]);
				}
			}else{
				if(!can[i-1][j]){
					can[i][j] = false;
					continue;
				}else{
					f[i][j] = f[i-1][j];
				}
			}
		}
	}
}

int main(){
	init();
	dp();
	for(int i = diff; i >= 0; i--){
		if(can[n][i]){
			cout << f[n][i];
			return 0;
		}
	}
	cout << "No Solution";
	return 0;
}