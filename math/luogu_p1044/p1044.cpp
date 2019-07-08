//
//  
//
//  Created by 谭康民 on 2018/8/24.
//

#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int n, f[30];
    cin >> n;
    memset(f,0,sizeof(f));
    f[0] = 1;
    f[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < i; j++){
            f[i]+=(f[j]*f[i-j-1]);
        }
    }
    cout << f[n];
}
