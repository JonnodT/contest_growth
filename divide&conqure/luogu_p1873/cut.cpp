#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdio.h>
#include <algorithm>
#define ll long long
const int maxn = 1e6+10;

using namespace std;

ll m;
ll n;
ll arr[maxn];

using namespace std;


ll check(ll mid){
	ll ans = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] > mid) ans += arr[i] - mid;
	}
	return ans;
}


int main(){
	scanf("%lld%lld", &n, &m);
	ll maxh = -1;
	for(int i = 0; i < n; i++){
		scanf("%lld", arr+i);
		maxh = max(maxh, arr[i]);
	}

	ll l = 1;
	ll r = maxh;

	while(l <= r){
		ll mid = l + (r-l)/2;
		ll res = check(mid);
		/*
		if(res == m){
			cout << mid;
			return 0;
		}
		*/
		if(res < m) r = mid - 1;
		else l = mid + 1;
	}
	cout << r;




	return 0;
}
