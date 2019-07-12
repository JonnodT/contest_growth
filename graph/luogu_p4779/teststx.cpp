/*用来测试struct的骚操作*/
#include <iostream>

using namespace std;

struct s
{
	int a,b,c;

};

int main(){
	s t = (s){1,3,4};
	cout << t.b << endl;
	return 0;
}