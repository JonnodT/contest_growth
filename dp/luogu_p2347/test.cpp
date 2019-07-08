#include <iostream>
#include <bitset>
#include <stdio.h>

using namespace std;

bitset<1010> res;
int w[6] = {1,2,3,5,10,20};
int arr[10];

int main(){
	for(int i = 0; i < 6; i++){
		int a; cin >> a;
		arr[i] = a;
	}
	res[0] = 1;
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < arr[i]; j++){
			res |= res << w[i];
		}
	}
	cout << "Total=" << res.count() - 1;
	return 0;	
}