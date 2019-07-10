#include <iostream>
#include <string>

using namespace std;


void pre_order(string in, string post){
	if(in.length()>0){
		char root = post[post.length()-1];
		size_t index = in.find(root);
		cout << root;
		pre_order(in.substr(0,index),post.substr(0,index));
		pre_order(in.substr(index+1),post.substr(index,post.length()-index-1));
	}
	return;
}

int main(){
	string in, post;
	cin >> in >> post;
	pre_order(in,post);
	cout << endl;
	return 0;
}