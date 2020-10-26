// 算法：动态规划
// 思路：https://www.jianshu.com/p/a66d5ce49df5
// dp二维数组的行代表每一件物品，列代表这个小的背包容量所能获得的最大价值
// 对每一行进行遍历，代表对每一件物品进行选择。

#include<bits/stdc++.h>

using namespace std;
int n, m;   // n为物品个数，m为背包最大容量
int w[105], v[105];
int dp[105][10005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (j >= w[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            printf("%5d", dp[i][j]);
        }
        printf("\n");
    }
    return 0;
}