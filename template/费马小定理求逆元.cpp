// 这种方法只能在 P 为质数的情况下使用
#include<bits/stdc++.h>
#define int long long
using namespace std;

int quick_power(int base, int n, int p) {
    int a = base % p;
    int res = 1;
    while(n) {
        if(n & 1) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        n >>= 1;
    }
    return res;
}

int fermat(int b, int p) {  // (a | b) % p = a * fermat(b) % p
    return quick_power(b, p - 2, p);
}

signed main() {
    int n;
    cin >> n;
    while(n--) {
        int b, p;
        cin >> b >> p;
        if(b % p)   cout << fermat(b, p) << "\n";   // 如果 b 能整除 p，那么逆元不存在
        else cout << "impossible\n";
    }
    return 0;
}