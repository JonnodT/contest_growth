#include <iostream>
#include <string>

using namespace std;

#define i long long


i x,y=0;


//perform the extended euclidean algorithm
void exeuc(i a, i b){
	//base case
	if(b==0){
		x = 1; //对这道题是这样，因为a b互质
		y = 0;
		return;
	}
	//recursion
	exeuc(b, a%b);

	//这一步是推导出来的
	//ax + by = gcd(a,b) = gcd(b,a%b) = bx2 + (a - (a/b)*b)y2
	//第二个等号是因为euclidean，第三个等号是因为取模运算 a % b等于 a - （a/b）*b
	//bx2 + (a - (a/b)*b)y2 = bx2 + ay2 - (a/b)*b*y2 = ay2 + b(x2-(a/b)y2)
	//当我们把a，b提出来的时候，就不难发现这个相等关系
	//x = y2  y = x2 - （a/b）y2
	//因为我们知道gcd(a,b) = gcd(b,a%b)
	i temp = x; //存一下 x原本的值
	x = y;
	y = temp - a/b*y;
}

int main(){
	i a,b;
	cin >> a >> b;
	exeuc(a,b);

	while(x < 0) x += b;
	x %= b;
	cout << x;
	return 0;

}