// 算法：动态规划

#include<bits/stdc++.h>

using namespace std;
int dp[105][105];

int main() {
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < t.size(); j++) {
            if (s[i] == t[j]) {
                if (i - 1 == 0 || j - 1 == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < t.size(); j++) {
            printf("%5d", dp[i][j]);
        }
        printf("\n");
    }
    return 0;
}