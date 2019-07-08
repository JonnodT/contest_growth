#include <iostream>
#include <cstdio>
#include <cmath>
#include <stack>

using namespace std;
int k, N;
long long ans = 0;
stack<int> S;

int main()
{
	cin >> k >> N;
	while(N){
		S.push(N & 1); N >>= 1; 
	}
	while(!S.empty()){
		ans += S.top()*pow(k, S.size()-1); S.pop();
	}
	cout << ans;
	return 0;
}