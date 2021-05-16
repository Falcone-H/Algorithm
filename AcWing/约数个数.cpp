// https://www.acwing.com/activity/content/problem/content/939/1/
#include<bits/stdc++.h>
using namespace std;
unordered_map<int, int> m;
const int mod = 1e9 + 7;
void solve(int x) {
    for(int i = 2; i <= x / i; i++) {
        while(x % i == 0) {
            x /= i;
            m[i]++;
        }
    }
    if(x > 1)   m[x]++;
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        solve(x);
    }
    long long res = 1;
    for(auto i : m) {
        res = res * (i.second + 1) % mod;
    }
    cout << res << endl;
    return 0;
}