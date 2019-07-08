#include <iostream>
#include <set>
#include <cstring>

using namespace std;

int arr[10][10];

int main(int argc, char const *argv[])
{
	memset(arr,127,sizeof(arr));
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j ++){
			cout << arr[i][j] <<  " ";
		}
		cout << endl;
	}
	return 0;
}