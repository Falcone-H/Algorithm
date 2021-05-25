// https://www.acwing.com/problem/content/904/
#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int dp[N][N];   // dp[i][j] 表示对 S1 的前 i 个字符，转换成 S2 的前 j 个字符的最短编辑距离。
int n, m;
int main() {
    string s1, s2;
    cin >> n >> s1;
    cin >> m >> s2;
    for(int i = 0; i <= n; i++)
        dp[i][0] = i;
    for(int j = 0; j <= m; j++)
        dp[0][j] = j;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else {
                int t = 2000;
                t = min(t, dp[i - 1][j] + 1);   // 删除
                t = min(t, dp[i][j - 1] + 1);   // 插入
                t = min(t, dp[i - 1][j - 1] + 1);   // 替换
                dp[i][j] = t;
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}