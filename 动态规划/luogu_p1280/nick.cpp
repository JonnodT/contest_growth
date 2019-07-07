#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxn 10010

using namespace std;

int n, m, f[maxn];
// Store tasks that starts at a certain moment
vector<int> tag[maxn];

struct tk{
	int p, t;
}a[maxn];

bool cmp(tk t1, tk t2){
	return t1.p < t2.p;
}

void init(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		a[i].p = x; a[i].t = y;
	}
	//sort task according to start time
	sort(a+1, a+m+1, cmp);

	for(int i = 1; i <= m; i++){
		int st = a[i].p;
		tag[st].push_back(i);
	}
}


int main(){
	init();
	// Verify sorting
	// for(int i = 1; i <= m; i++){
	// 	cout << a[i].p << " ";
	// }

	//Base case
	f[n+1] = 0;
	// Start at time i
	for(int i = n; i >= 1; i--){
		if(tag[i].empty()){
			//if nothing starts at this moment
			f[i] = f[i+1] + 1;
		}else{
			//If there are task that starts at this moment
			f[i] = -1;
			for(vector<int>::iterator it = tag[i].begin(); it!=tag[i].end(); ++it){
				f[i] = max(f[i], f[i+a[*it].t]);
			}
		}
	}
	cout << f[1] << endl;
	return 0;
}