#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

bool comp(int a, int b){return a > b;}

int main(){
	int in[12] = {1,1,2,2,3,3,4,4,5,6,7,8};
	int de[12] = {7,6,5,5,4,3,3,3,3,2,2,1};

	int index = lower_bound(de,de+12,2,comp) -  de;
	cout << index;


	return 0;
}