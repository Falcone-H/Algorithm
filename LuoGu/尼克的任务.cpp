// https://www.luogu.com.cn/problem/P1280
// 思路：从后往前做DP

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false)
using namespace std;
const int N = 1e4 + 10;
int n, k;
vector<pair<int, int>> v;
int dp[N];
int sum[N];
int cnt;

int main() {
    IOS;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        v.emplace_back(x, x + y);
        sum[x]++;
    }
    sort(v.begin(), v.end(), greater<>());
    for (int i = n; i > 0; i--) {
        if (sum[i] == 0)
            dp[i] = dp[i + 1] + 1;
        else {
            while (sum[i]--) {
                dp[i] = max(dp[i], dp[v[cnt].second]);
                cnt++;
            }
        }
    }
    cout << dp[1] << endl;
    return 0;
}