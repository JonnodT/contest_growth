//二分查找版本的答案

#include <iostream>
#include <vector>
#include <set>
#include <stdio.h>
#include <algorithm>
#define maxn 505

using namespace std;
int m, k, arr[maxn];
int ans;

bool check(int mid){
	int sum = 0, cnt = 1;
	for(int i = m; i > 0; i--){
		if(sum + arr[i] <= mid){
			sum += arr[i];
		}else{
			cnt ++;
			sum = arr[i];
		}
	}
	return cnt <= k;
}
//？？？
void print(int l, int r) { 
    int sum = 0;
    for(int i = r; i >= l; i--) {
        if(sum + arr[i] > ans) {
            print(l, i); 
            cout << i+1 << ' ' << r << endl;
            return;
        }
        sum += arr[i];
    }
    cout << 1 << ' ' << r << endl; 
}

int main(){
	//readin data
	int l = 1e9, r = 0;
	scanf("%d%d", &m, &k);
	if(m == 0) return 0;
	for(int i = 1; i <= m; i++){
		scanf("%d", arr + i);
		l = min(l, arr[i]);
		r += arr[i];
	}
	//x是什么？ f(X)又是什么？
	//x是最长那一段的页数。 f(x)是需要的人数
	//二分查找找到的应该是超过最大人数之前的第一个
	while(l <= r){
		int mid = l + (r-l)/2;
		if(check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	ans = r + 1;
	print(1,m);
	return 0;
}