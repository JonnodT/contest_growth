#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
#define N 100005

int arr[N], dp1[N], dp2[N], n = 0;

bool comp1(int a, int b){
	return a > b;
}

bool comp2(int a, int b){
	return a <= b;
}

int main(){

	//read in data

	while(cin >> arr[n++]){}
	n--; //读数据骚操作

	int l1 = 0, l2 = 0;
	dp1[0] = arr[0];
	dp2[0] = arr[0];
	for(int i = 1; i < n; i++){
		if(arr[i] <= dp1[l1]){
			dp1[++l1] = arr[i];
		}else{
			int index = upper_bound(dp1,dp1+l1+1,arr[i],comp1) - dp1;
			dp1[index] = arr[i];
		}

		if(arr[i] > dp2[l2]){
			dp2[++l2] = arr[i];
		}else{
			int index = lower_bound(dp2,dp2+l2+1,arr[i]) - dp2;
			dp2[index] = arr[i];
		}
	}

	cout << l1+1 << endl << l2 + 1;
	return 0;
}