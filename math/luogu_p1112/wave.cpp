#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

int s,t,a,b,d,x,c, q[10000005];

void init(){
	scanf("%d%d%d%d%d",&s, &t, &a, &b, &d);
}


int main(){
	init();
	for(int i = s; i <= t; i++){
		//在每个进制下构造波浪数 jkjkjkjk....
		for(int j = 1; j <= i-1; j++){
			//显然, 第一个数不能为0
			for(int k = 0; k <= i-1; k++){
				//第二个数可以为0
				if(j != k){
					//x储存构造出的i进制波浪数对应的10进制下的数
					//c用来交替后缀j k
					x = 0; c = 0;
					while(x <= b){
						if(c%2 == 0){
							x = x*i + j;
						}else{
							x = x*i + k;
						}
						c++;
						//判断是否在范围内
						if(x>=a && x <= b) q[x]++;
					}
				}
			}
		}
	}
	//遍历，查看满足重数的数
	for(int i = a; i <= b; i++){
		if(q[i] == d) cout << i << endl;
	}
	return 0;
}