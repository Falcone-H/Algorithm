// https://www.acwing.com/problem/content/3420/
// 思路：01背包，dp[i][j]表示当前面临选择第 i 件砝码，且两边砝码重量之差为 j
// 假设放在左边是减去重量， 放在右边是增加重量
// 面对 dp[i][j]，由三个状态转移过来
// 第一个是第 i 个物品放在右边，即重量加 a[i]，因此，由 dp[i - 1][abs(j - a[i])]转移过来
// 第二个是第 i 个物品放在左边，即重量减 a[i]，因此，由 dp[i - 1][j + a[i]]转移过来
// 第三个是不选择第 i 个物品，即和 dp[i - 1][j] 相同

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int dp[105][N];
int a[105];
int n;
int maxv;
int ans;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        maxv += a[i];
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= maxv; j++) {
            dp[i][j] = dp[i - 1][j];
            dp[i][j] |= dp[i - 1][abs(j - a[i])];
            if(j + a[i] <= maxv)
                dp[i][j] |= dp[i - 1][j + a[i]];
        }
    }
    for(int i = 0; i <= maxv; i++) {
        ans += dp[n][i];
    }
    cout << ans - 1 << "\n";
    return 0;
}