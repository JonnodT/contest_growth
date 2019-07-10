Vasya has found a strange device. On the front panel of a device there are: a red button, a blue button and a display showing some positive integer. After clicking the red button, device multiplies the displayed number by two. After clicking the blue button, device subtracts one from the number on the display. If at some point the number stops being positive, the device breaks down. The display can show arbitrarily large numbers. Initially, the display shows number n.

Bob wants to get number m on the display. What minimum number of clicks he has to make in order to achieve this result?

* 这道题中再一次见到了一个很重要的REVERSE的思想，就是把题目中的某个条件翻转过来，类似于求补集，然后把题目简单化，以前也遇到过，比如
  * 洛谷 丢瓶盖，选m个瓶盖相当于丢掉n-m个瓶盖
  * 求非升子序列的最小划分，相当于求最长上升子序列
  * 这道题我想到了用类似于贪心的策略去做，但是奇数除2会导致不work，除已经想到了，但是没想到可以把题目整体reverse一下
  * 所以这道题把乘2，减1，变成除2，加1\. 也就是如果第二个数是偶数且大于第一个数就除2，否则加1

```c
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
```