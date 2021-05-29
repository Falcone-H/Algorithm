// https://www.luogu.com.cn/problem/P1020
// 第一问求最长不上升子序列的长度，第二问求最长上升子序列的长度
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int a[N];
int dp[N];
int cnt;


int solve1() {
    for(int i = 0; i <= cnt; i++)
        dp[i] = -INT_MAX;
    for(int i = 0; i < cnt; i++) {
        int pos = upper_bound(dp, dp + cnt, a[i], greater<>()) - dp;
        dp[pos] = a[i];
    }
    int len = 0;
    for(int i = 0; i <= cnt; i++) {
        if(dp[i] == -INT_MAX)
            break;
        len++;
    }
    return len;
}

int solve2() {
    for(int i = 0; i <= cnt; i++)
        dp[i] = INT_MAX;
    for(int i = 0; i < cnt; i++)
        *lower_bound(dp, dp + cnt, a[i]) = a[i];
    return lower_bound(dp, dp + cnt, INT_MAX) - dp;
}

signed main() {
    int x;
    while(cin >> x) {
        a[cnt++] = x;
    }
    int ans1 = solve1();
    cout << ans1 << endl;
    int ans2 = solve2();
    cout << ans2 << endl;
    return 0;
}
