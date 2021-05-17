// https://www.acwing.com/problem/content/889/
// 证明：https://zhuanlan.zhihu.com/p/116698264
#include<bits/stdc++.h>

#define int long long
using namespace std;
int p;

int qp(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        n >>= 1;
    }
    return res;
}

int C(int a, int b) {
    if(b > a)   return 0;
    int res = 1;
    for(int i = a, j = 1; j <= b; i--, j++) {
        res = (res * i) % p;
        res = (res * qp(j, p - 2)) % p;
    }
    return res % p;
}

int Lacus(int a, int b) {
    if (a < p && b < p)
        return C(a, b);
    else
        return C(a % p, b % p) * Lacus(a / p, b / p) % p;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b >> p;
        cout << Lacus(a, b) << "\n";
    }
    return 0;
}