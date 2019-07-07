#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
//不要去想combination
//注意，input总共最多有50*10000个字符
//就算每个字符都添加一个新节点，我们也最多只会用到这么多节点，所以够了
#define maxn 500005 

using namespace std;

int n,m;
char temp[55];

struct Trie{
	//data每一层都是一个节点，data[i][j]存的是下一个节点的位置
	//第一层是根节点
	int sz, val[maxn], data[maxn][26];
	//初始化字典树，sz是1原因是0层是根节点，后面的节点从1开始
	Trie(){
		sz = 1; 
		memset(val, 0, sizeof(val));
		memset(data, 0, sizeof(data));
	}
	//简单的得到字符index的函数
	int index(char a){return a - 'a';}

	//插入新字符操作
	void insert(char* str){
		//str是从1开始存的，所以strlen需要从起始指针+1的位置开始
		int curr = 0; int len = strlen(str + 1);
		//遍历字符串
		for(int i = 1; i <= len; i++){
			int t = index(str[i]);
			if(data[curr][t] == 0){
				//如果目前还没有这个节点，我们需要创建一个新节点
				data[curr][t] = sz++; 
			}
			curr = data[curr][t]; //往下一个节点走
		}
	}

	int search(char* str){
		int curr = 0; int len = strlen(str + 1);
		for(int i = 1; i <= len; i++){
			int t = index(str[i]);
			if(data[curr][t] == 0){
				return 0; // 0 means string not found
			}
			curr = data[curr][t];
		}
		//如果运行到这都没有return 0，说明这个字符是存在的
		if(val[curr] == 0){
			//返回1说明字符存在，且只查询了一次
			//查询过一次之后标记上，下次查询就会返回2，说明repeat了
			val[curr] = 1; return 1; 
		}
		return 2;
	}
}tree;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%s", temp + 1);
		tree.insert(temp);
	}
	scanf("%d", &m);
	for(int i = 1; i <= m; i++){
		scanf("%s", temp + 1);
		int res = tree.search(temp);
		if(res == 0){
			cout << "WRONG" << endl;
		}else if(res == 1){
			cout << "OK" << endl;
		}else{
			cout << "REPEAT" << endl;
		}
	}
	return 0;
}