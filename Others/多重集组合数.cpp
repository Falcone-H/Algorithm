#include<bits/stdc++.h>

using namespace std;
int n, m;
int a[1005];
int dp[1005][1005];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j - 1 - a[i] >= 0) {
                dp[i + 1][j] = dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - a[i]];
            } else {
                dp[i + 1][j] = dp[i + 1][j - 1] + dp[i][j];
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            printf("%5d", dp[i][j]);
        }
        printf("\n");
    }
    return 0;
}