#include<bits/stdc++.h>

#define int long long
using namespace std;
int n, m;
int w[105], v[105];
int dp[105][10005];

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(j >= w[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i]);
            }  else {
                dp[i][j] = dp[i - 1][j];
            }
            
        }
    }
    return 0;
}

/*
空间优化:
for(int i = 1; i <= n; i++){
    for(int j = w[i]; j <= m; j++){     //必须正序枚举,更新前面的状态
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
}
*/