In Summer Informatics School, if a student doesn't behave well, teachers make a hole in his badge. And today one of the teachers caught a group of 

𝑛n students doing yet another trick. 

Let's assume that all these students are numbered from 11 to 𝑛n. The teacher came to student 𝑎a and put a hole in his badge. The student, however, claimed that the main culprit is some other student 𝑝𝑎pa.

After that, the teacher came to student 𝑝𝑎pa and made a hole in his badge as well. The student in reply said that the main culprit was student 𝑝𝑝𝑎ppa.

This process went on for a while, but, since the number of students was finite, eventually the teacher came to the student, who already had a hole in his badge.

After that, the teacher put a second hole in the student's badge and decided that he is done with this process, and went to the sauna.

You don't know the first student who was caught by the teacher. However, you know all the numbers 𝑝𝑖pi. Your task is to find out for every student 𝑎a, who would be the student with two holes in the badge if the first caught student was 𝑎a.

* 这道题可以brutal force，也能过，O(n^2)
* 有一个技巧可以让算法复杂度达到线性 — 利用拓扑排序把cycle分离出来
  * 这道题有一个特点，就是一定只有一个cycle，然后如果某个节点在cycle上，他一定最后回到他自己
  * 如果这个节点不在cycle中，那么如果从它开始得到的答案是他离的最近的一个在cycle上的节点
  * 所以利用拓扑排序可以分离出唯一的一个cycle

* AC 代码

```c
#include <iostream>
#include <queue>
#define maxn 1005

using namespace std;

int n, arr[maxn], deg[maxn], ans[maxn];


int res(int i){
  //如果条件满足，说明这个节点在cycle内，如果不满足，递归调用，直到找到第一个cycle上的节点
	return (i == ans[i] ? i : res(ans[i]));
}

int main(){
	//读数据
	scanf("%d",&n);
	for(int i = 1; i <=n; i++){
		scanf("%d",arr+i);
		//各个节点indegree的count
		deg[arr[i]]++;
	}
  
  //初始化ans，默认每个节点都在cycle中
	for(int i = 1; i <= n; ++i) ans[i] = i;
  
  //Top sort初始化，把degree是0的压入队列
	queue<int> q;
	for(int i = 1; i <= n; ++i){
		if(deg[i] == 0){
			q.push(i);
		}
	}
  
  //queue空了说明所有不在queue中节点都遍历完了
	while(!q.empty()){
		int t = q.front(); q.pop();
		--deg[arr[t]]; ans[t] = arr[t];
		if(deg[arr[t]] == 0) q.push(arr[t]);
	}

  //print answer
	for(int i = 1; i <= n; i++){
		printf("%d ", res(i));
	}
	return 0;

}
```