#include<bits/stdc++.h>

using namespace std;
int n, m;
int dp[1005][1005];

int main() {
    cin >> n >> m;
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j < i)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - i];     // (m - 1划分) 加上 (n - m 的 m 划分)
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}