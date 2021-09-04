// https://www.acwing.com/problem/content/3818/
// 思路：将 x 做因数分解，即 x = p1^a1 * p2^a2 * p3^a3 ...
// 那么，最大且符合条件的约数 ans = p1 * p2 * p3 ...
#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        int res = 1;
        for(int i = 2; i <= x / i; i++) {
            if(x % i == 0) {
                res *= i;
                while(x % i == 0)
                    x /= i;
            }
        }
        res *= x;
        cout << res << "\n";
    }
    return 0;
}