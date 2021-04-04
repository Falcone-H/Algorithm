// https://ac.nowcoder.com/acm/contest/12548/L
// 思路：求出因为逆序对之间的颜色各不相同，因此，求出最长递减子序列的长度，就是这个图中的颜色种数
// 然后，在进行寻找最长递减子序列的过程中，每个元素在序列中的位置，就是它的颜色

#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N], b[N];
int dp[N];
int n;
int maxv;
void solve() {
    for(int i = 0; i < n; i++) {
        dp[i] = INT_MAX;
    }
    for(int i = n - 1; i >= 0; i--) {
        int temp = lower_bound(dp, dp + n, a[i]) - dp;
        b[i] = temp + 1;
        maxv = max(maxv, b[i]);
        dp[temp] = a[i];
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        maxv = -1;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve();
        cout << maxv << "\n";
        for(int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}