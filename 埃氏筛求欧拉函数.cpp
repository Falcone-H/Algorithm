#include<bits/stdc++.h>
#define int long long
using namespace std;
int phi[100000];
void euler(int n) {
    for(int i = 1; i <= n; i++)
        phi[i] = i;
    for(int i = 2; i <= n; i++) {
        if(phi[i] == i) {   // 代表 i 是质数
            for(int j = i; j <= n; j+= i) {
                phi[j] = phi[j] / i * (i - 1);  // 把 i 的倍数更新掉
            }
        }
    }
}
signed main() {
    euler(8);
    for(int i = 1; i <= 8; i++) {
        cout << phi[i] << endl;
    }
    return 0;
}