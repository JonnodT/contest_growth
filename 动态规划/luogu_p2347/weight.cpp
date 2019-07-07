#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int w[6] = {1,2,3,5,10,20};
int arr[10], sum;
bool dp[1005];

int main(){
	for(int i = 0; i < 6; i++){
		int a; scanf("%d", &a);
		arr[i] = a;
		sum += w[i] * a;
	}

	dp[0] = true;
	for(int i = 6; i >= 0; i--){
		for(int j = arr[i]; j > 0; j--){
			int k = 0;
			while(k <= sum){
				if(dp[k]){
					if(dp[k + w[i]] > sum){
						break;
					}else{
						if(dp[k+w[i]]){
							k += w[i];
						}else{
							dp[k+w[i]] = true;
							k += w[i];
							k++;
						}
					}
				}
			}
			for(int k = 0; k <= sum; k++){
				if(dp[k]){
					if(dp[k + w[i]] > sum) break;
					dp[k+w[i]] = true;
				}
			}
		}
	}

	int cnt = 0;
	for(int i = 1; i <= sum; i++){
		if(dp[i]) cnt ++;
	}
	cout <<"Total=" << cnt;

	return 0;
}