// https://ac.nowcoder.com/acm/problem/25184
// 思路：01背包
#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    int a[1000];
    int dp[80005];
    while (t--) {
        int n, time;
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));
        cin >> n >> time;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        for (int i = 0; i < n - 1; i++) {
            for (int j = time - 1; j >= a[i]; j--) {
                dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
            }
        }
        cout << dp[time - 1] + a[n - 1] << endl;
    }
    return 0;
}