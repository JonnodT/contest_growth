#include <queue>
#include <iostream>
#include <vector>

using namespace std;

struct Node{
	int x, y;
	Node(int a, int b){x = a; y = b;}
	bool operator < (const Node & a) const{
		//min heap
		//如果把这里改成大于可以变成maxheap
		return a.x < x;
	}
};

int main(){
	priority_queue<Node> pq;
	pq.push(Node(2,6));
	pq.push(Node(5,1));
	pq.push(Node(1,9));
	pq.push(Node(10,3));
	
	while(!pq.empty()){
		Node t = pq.top(); pq.pop();
		cout << "Node " << t.x << " " << t.y <<endl;
	}
	
	
	return 0;
}