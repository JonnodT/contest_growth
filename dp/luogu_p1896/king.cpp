#include <iostream>
#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <cstdlib>


using namespace std;
int n,k;
/*
This array stores all the possible states in a line
Notice that the number of states is for sure less than 2 to the 9th.(n <= 9)
Actual number would be much less than this since a king would fix the states
of its adjacenty nodes. 
*/
int sts[2000], cnt = -1;

//This array stores the number of kings in a particular line state
int ks[2000];

//dp array
long long f[10][2000][90];

//Generate all possible states
void dfs(int deci, int sum, int curr){
	//decimal is the decimal number of this state
	//sum is the sum of kings in this state
	//curr is the current block we are at 
	if(curr >= n){
		//Find a new state
		sts[++cnt] = deci;
		ks[cnt] = sum;
		return;
	}
	//Place king in this block or skip this block

	//Place a king
	dfs(deci, sum, curr+1);
	dfs(deci+(1<<curr), sum+1, curr+2);
	
}


void init(){
	scanf("%d%d", &n, &k);
}

int main(){
	init();
	dfs(0,0,0); //generate all states

	//The first layer only has 1 possible way because each place is a way.
	for(int i = 0; i <= cnt; i++){
		f[1][i][ks[i]] = 1;
	}

	for(int i = 2; i <= n; i++){
		for(int j = 0; j <= cnt; j++){
			for(int p = 0; p <= cnt; p++){
				if(sts[j]&sts[p]) continue;
				if(sts[j]&(sts[p]<<1)) continue;
				if(sts[j]&(sts[p]>>1)) continue;
				//Otherwise this status works for this 2 lines
				for(int c = k; c >= ks[j]; c--){
					f[i][j][c] += f[i-1][p][c-ks[j]];
				} 
			}
		}
	}

	long long ans = 0;
	for(int i = 0; i <= cnt; i++){
		ans += f[n][i][k];
	}

	cout << ans;
	return 0;
}