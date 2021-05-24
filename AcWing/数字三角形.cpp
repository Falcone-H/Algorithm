// https://www.acwing.com/problem/content/900/
#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int dp[N];
int a[N];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cin >> a[j];
        }
        for(int j = i; j >= 1; j--) {
            if(j == i)
                dp[j] = dp[j - 1] + a[j];
            else if (j == 1)
                dp[j] = dp[j] + a[j];
            else
                dp[j] = max(dp[j] + a[j], dp[j - 1] + a[j]);
        }
    }
    int ans = -5000005;
    for(int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}