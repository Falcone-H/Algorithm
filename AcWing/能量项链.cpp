// https://www.acwing.com/problem/content/322/
// 区间dp
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 305;
int n;
int a[N];
int dp[N][N];

signed main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    for(int len = 3; len <= n + 1; len++) {
        for(int l = 1; l + len - 1 <= 2 * n; l++) {
            int r = l + len - 1;
            for(int k = l + 1; k < r; k++) {
                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + a[l] * a[k] * a[r]);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dp[i][i + n]);
    }
    cout << ans << "\n";
    return 0;
}