// https://www.acwing.com/activity/content/problem/content/940/1/
#include<bits/stdc++.h>

#define int long long
using namespace std;
unordered_map<int, int> m;
const int mod = 1e9 + 7;

void solve(int x) {
    for (int i = 2; i <= x / i; i++) {
        while (x % i == 0) {
            x /= i;
            m[i]++;
        }
    }
    if (x > 1) m[x]++;
}

signed main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        solve(x);
    }
    int res = 1;
    for (auto i : m) {
        int p = i.first;
        int d = i.second;
        int tmp = 1;
        while (d--) {
            tmp = (tmp * p + 1) % mod;
        }
        res = (res * tmp) % mod;
    }
    cout << res << endl;
    return 0;
}