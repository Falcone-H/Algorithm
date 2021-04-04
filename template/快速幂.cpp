#include<bits/stdc++.h>

#define int long long
using namespace std;

int quick_pow(int base, int pow) {
    int a = base;
    int res = 1;
    while (pow) {
        if (pow & 1) {
            res *= a;
        }
        pow = pow >> 1;
        a = a * a;
    }
    return res;
}

signed main() {
    int base, pow;
    cin >> base >> pow;
    cout << quick_pow(base, pow) << endl;
    return 0;
}