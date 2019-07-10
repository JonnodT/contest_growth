#include <algorithm>
#include <stdio.h>
#include <iostream>

using namespace std;

int m, n;

int main(){
	scanf("%d%d", &n, &m);

	if(n >= m){
		cout <<  n - m;
		return 0;
	}

	int cnt = 0;
	while(m != n){
		if(m%2 == 0 && m >= n){
			m/=2;
		}else{
			m += 1;
		}
		cnt ++;
	}
	cout << cnt;

	return 0;
}