// https://www.luogu.com.cn/problem/P1040
// 思路：区间DP，dp[l][r] = dp[l[k - 1] * dp[k + 1][r] + dp[k][k]

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 105;
int a[N];
int dp[N][N];
int root[N][N];
int n;

void printr(int l, int r) {
    if(l > r)   return;
    cout << root[l][r] << " ";
    if(l == r)  return;
    printr(l, root[l][r] - 1);
    printr(root[l][r] + 1, r);
}

signed main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i][i] = a[i];
        dp[i][i - 1] = 1;
        root[i][i] = i;
    }
    for(int len = 1; len <= n; len++) {
        for(int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            for(int k = l; k < r; k++) {
                if(dp[l][r] < dp[l][k - 1] * dp[k + 1][r] + dp[k][k]) {
                    dp[l][r] = dp[l][k - 1] * dp[k + 1][r] + dp[k][k];
                    root[l][r] = k;
                }
            }
        }
    }
    cout << dp[1][n] << endl;
    printr(1, n);
    return 0;
}