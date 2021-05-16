// https://www.acwing.com/problem/content/875/
#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(int x) {
    int r = x;
    unordered_map<int, int> m;
    for(int i = 2; i <= x / i; i++) {
        if(x % i == 0) {
            while(x % i == 0) {
                x /= i;
            }
            r = r / i * (i - 1);
        }

    }
    if(x > 1)
        r = r / x * (x - 1);
    cout << r << "\n";
    return ;
}

signed main() {
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        solve(x);
    }
    return 0;
}