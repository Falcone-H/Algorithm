class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int dp[n + 1][n + 1];
        int maxv = 1;
        int begin = 0;
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l < n; l++) {
                int r = l + len - 1;
                if (r >= n) break;
                if (s[l] == s[r]) {
                    if (len > 2) {
                        dp[l][r] = dp[l + 1][r - 1];
                    } else {
                        dp[l][r] = 1;
                    }
                    if (dp[l][r] && len > maxv) {
                        maxv = len;
                        begin = l;
                    }
                } else {
                    dp[l][r] = 0;
                }

            }

        }
        return s.substr(begin, maxv);
    }
};