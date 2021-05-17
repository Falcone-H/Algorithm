// C(a, b) = a! / (b! * (a - b)!)
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100010;
const int mod = 1e9 + 7;
int fac[N], infac[N];

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

void init() {
    fac[0] = 1;
    infac[0] = 1;
    for(int i = 1; i <= 100005; i++) {
        fac[i] = (fac[i - 1] * i) % mod;
        infac[i] = (infac[i - 1] * fermat(i, mod)) % mod;
    }
}

signed main() {
    init();
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        cout << ((fac[a] * infac[a - b]) % mod * infac[b]) % mod << "\n";
    }
    return 0;
}