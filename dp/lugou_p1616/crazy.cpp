#include <iostream>
#include <algorithm>

using namespace std;

int t,m, dp[100000][2];

struct herb{
	int c, v;
}arr[10005];



int main(){
	scanf("%d%d", &t, &m);
	for(int i = 0; i < m; i++){
		scanf("%d%d",&arr[i].c, &arr[i].v);
	}

	//fill in the base case, mind the boundary
	int cost = arr[0].c;
	int value = arr[0].v;
	for(int i = 0; i <= t; i++){
		if(i-cost >= 0){
			dp[i][0] = value + dp[i-cost][0];
		}
	}

	//fill in the dp array, only keeps 2 columns to save memory
	for(int i = 0; i <= t; i++){
		for(int j = 1; j < m; j++){
			int dp_i = j%2;
			int ofs = (dp_i == 0)?(1):(-1);
			int opt = -1;
			opt = max(opt, dp[i][dp_i+ofs]);
			if(i-arr[j].c>=0){
				opt = max(opt, dp[i-arr[j].c][dp_i+ofs]+arr[j].v);
				opt = max(opt, dp[i-arr[j].c][dp_i]+arr[j].v);
			}
			dp[i][dp_i] = opt;
		}	
	}


	cout << max(dp[t][0],dp[t][1]);


	return 0;
}