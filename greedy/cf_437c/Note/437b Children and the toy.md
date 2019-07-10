On Children's Day, the child got a toy from Delayyy as a present. However, the child is so naughty that he can't wait to destroy the toy.

The toy consists of n parts and m ropes. Each rope links two parts, but every pair of parts is linked by at most one rope. To split the toy, the child must remove all its parts. The child can remove a single part at a time, and each remove consume an energy. Let's define an energy value of part i as vi. The child spend vf1 + vf2 + ... + vfk energy for removing part i where f1, f2, ..., fk are the parts that are directly connected to the i-th and haven't been removed.

Help the child to find out, what is the minimum total energy he should spend to remove all n parts.

* 这道题是个贪心，以后做题注意不要显示算法标签，因为其实贪心最大的挑战就是下决心贪心。但是遗憾的是虽然知道了贪心，但是还是还是没有找到greedy strategy
    * 我的思路其实是卡在一个维度上 — 剪掉一个node的cost从大到小/从小到大，到后来死活做不出来甚至还考虑了union - find
    * 但是其实greedy strategy很简单，从value大的开始删就可以，因为我们知道要把所有的边都删掉，这是毋庸置疑的，如果从最大的点开始删，那么对于每条边来说的cost都是小的那一条边，所以总体就是minimum

* AC代码

```c
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#define maxn 1010

using namespace std;
int n, m, w[maxn], dg[maxn];
vector<int> adj[maxn];

struct Node{
	int i, c;
};

vector<Node> cost;

bool cmp(Node n1, Node n2){
	return w[n1.i] < w[n2.i];
}

int main(){
	//readin data
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &w[i]);
	}
	for(int i = 1; i <= m; i++){
		int a,b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
		dg[a]++; dg[b]++;
	}

	for(int i = 1; i <= n; i++){
		int sum = 0;
		for(int j = 0; j < adj[i].size(); j++){
			sum += w[adj[i][j]];
		}
		Node x;
		x.i = i; x.c = sum;
		cost.push_back(x);
	}

	int sum = 0;
	int cnt = n;
	while(cnt > 0){
		sort(cost.begin(), cost.end(), cmp);
		Node ne = cost.back(); cost.pop_back();
		sum += ne.c;
		int index = ne.i;
		for(int j = 0; j < cost.size(); j++){
			for(int k = 0; k < adj[index].size(); k++){
				if(cost[j].i == adj[index][k]){
					cost[j].c -= w[index];
					dg[cost[j].i] --;
				} 
			}
		}
		cnt --;
	}

	cout << sum;
	return 0;
}
```