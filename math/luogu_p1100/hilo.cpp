#include <iostream>
#include <cstring>
#include <deque>
#include <cstdio>
#define lli long long int

using namespace std;
lli n;
lli ans;
deque<int> v;


int main(){
	scanf("%lld", &n);
	// to bin
	while(n){
		v.push_front(n&1);
		n >>= 1;
	}
	for(int i = v.size(); i < 32; ++i){
		v.push_front(0);
	}

	for(int j = 16; j <= 31; j++){
		ans <<= 1;
		ans += v[j];
	}
	for(int i = 0; i <= 15; i++){
		ans <<= 1;
		ans += v[i];
	}

	

	cout << ans;
	return 0;
}