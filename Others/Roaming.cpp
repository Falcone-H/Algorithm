// AtCoder E-Roaming
// 思路：k次操作之后，最多有min(k, n - 1)个0
//      然后，使用插板法，往n个数里面插入n-m-1个板，结果代表剩下的n-m个数的可能
// https://blog.csdn.net/FrostMonarch/article/details/104582177?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-3.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-3.control

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 2e5 + 10;
int fact[MAXN];
int quick_pow(int a, int b) {   // 快速幂
    a %= mod;
    int ret = 1;
    while(b) {
        if(b & 1)
            ret *= a;
        ret %= mod;
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ret;
}
int C(int n, int r) {   // 乘法逆元求C ^m _n
    return fact[n] * (quick_pow((fact[n - r] * fact[r]), mod - 2)) % mod;
}
signed main() {
    int n, k;
    cin >> n >> k;
    fact[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    int sum = 0;
    for(int i = 0; i < min(k, n - 1); i++) {
        sum += C(n, i) * C(n - 1, n - 1 - i);
        sum %= mod;
    }
    cout << sum << endl;
    return 0;
}
