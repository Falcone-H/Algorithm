// 卡特兰数 ans = C(n, 2n) - C(n - 1, 2n) = C(n, 2n) / (n + 1)
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int qp(int a, int n, int p) {
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

signed main() {
    int n;
    int res = 1;
    cin >> n;
    for(int i = 2 * n; i > 2 * n - n; i--) {
        res = (res * i) % mod;
    }
    for(int i = 1; i <= n; ++i) {
        res = (res * qp(i, mod - 2, mod)) % mod;
    }
    res = (res * qp(n + 1, mod - 2, mod)) % mod;
    cout << res << endl;
    return 0;
}