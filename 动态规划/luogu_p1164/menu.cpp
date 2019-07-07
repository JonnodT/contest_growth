#include <iostream>
#include <algorithm>

using namespace std;

int m, n, arr[105], f[10005];

int main(){
	// readin data
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}

	f[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= arr[i]; j--){
			f[j] += f[j-arr[i]];
		}
	}

	cout << f[m];

	return 0;
}