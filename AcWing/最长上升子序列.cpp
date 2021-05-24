// https://www.acwing.com/problem/content/897/
#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int n;
int a[N];
int dp[N];  // dp[i] 表示以 a[i] 结尾的最长序列
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = 1;
        for(int j = 1; j < i; j++) {
            if(a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int ans = -1;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}