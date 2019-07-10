#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

#define maxn 1005

int n, arr[maxn], ans[maxn];

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d",arr+i);
	}

	for(int i = 1; i <= n; i++){
		set<int> vis;
		vis.insert(i);
		int curr = arr[i];
		while(vis.find(curr) == vis.end()){
			vis.insert(curr);
			curr = arr[curr];
		}
		ans[i] = curr;
	}

	for(int i = 1; i <= n; i++){
		cout << ans[i] << " ";
	}
	return 0;
}