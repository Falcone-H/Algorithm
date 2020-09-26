#include<bits/stdc++.h>

#define int long long
using namespace std;
int f[70];

signed main() {
    int n, d;
    cin >> n >> d;
    if (n == 0 || n == 1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= d + 1; i++) {
        f[i] = i;
    }
    for (int i = d + 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 1 - d] + 1;
    }
    int res = ((int) 1 << n - 1) - 1 - f[n - 1 - d];
    cout << res << endl;
    return 0;
}