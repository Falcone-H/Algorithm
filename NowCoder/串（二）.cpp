#include<bits/stdc++.h>

#define int long long
using namespace std;
int dp[1000005][3];
int mod = 1000000007;

/*
 * dp[i][0] 表示长度为 i，不含 u 的字符串个数
 * dp[i][1] 表示长度为 i，含 u ，但不含 us 的字符串个数
 * dp[i][2] 表示长度为 i，含 us 的字符串个数
 *
 * 那么
 * dp[i][0] = dp[i - 1][0] * 25
 * dp[i][1] = dp[i - 1][0] + dp[i - 1][1] * 25
 * dp[i][2] = dp[i][2] * 26 + dp[i][1]
 */

signed main() {
    dp[1][0] = 25;
    dp[1][1] = 1;
    dp[1][2] = 0;
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = (dp[i - 1][0] * 25) % mod;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * 25) % mod;
        dp[i][2] = (dp[i - 1][2] * 26 + dp[i - 1][1]) % mod;

        sum += dp[i][2];
        sum %= mod;
    }
    cout << sum << endl;
    return 0;
}