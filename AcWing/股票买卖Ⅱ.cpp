// https://www.acwing.com/problem/content/description/1057/
// 思路：https://www.acwing.com/activity/content/code/content/1131954/

#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N = 1e5 + 5;
int a[N];
int dp[N];
int n;

signed main() {
    cin >> n;
    dp[0] = 0;
    int maxv = -INT_MAX;    // 记录最大的 dp[j] - a[j]
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = dp[i - 1];  // 第一、二种情况
        dp[i] = max(dp[i], maxv + a[i]);    // 第三种情况
        maxv = max(maxv, dp[i] - a[i]);
    }
    cout << dp[n] << "\n";
    return 0;
}
