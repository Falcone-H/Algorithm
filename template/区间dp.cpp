// https://www.acwing.com/problem/content/284/
#include<bits/stdc++.h>
using namespace std;
const int N = 310;
int a[N];
int s[N];   // 前缀和
int dp[N][N];   // dp[i][j] 表示区间从 i 到 j 合并成一堆的最小代价
int n;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for(int len = 2; len <= n; len++) { // 枚举区间的长度
        for(int i = 0; i + len - 1 <= n; i++) { // 枚举区间的起点
            int l = i, r = i + len - 1;
            dp[l][r] = INT_MAX;
            for(int k = l; k < r; k++) {    // 枚举要分开的位置
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}