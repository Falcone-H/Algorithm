#include<bits/stdc++.h>

using namespace std;
int w[105], v[105], m[105];
int n, weight;
int dp[105][1000005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i] >> m[i];
    }
    cin >> weight;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= weight; j++) {
            for (int k = 0; k <= m[i] && k * w[i] <= j; k++) {
                dp[i + 1][j] = max(dp[i][j], dp[i][j - k * w[i]] + k * v[i]);
            }
        }
    }
}