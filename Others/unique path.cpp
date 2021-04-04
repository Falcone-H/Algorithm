#include<bits/stdc++.h>

using namespace std;

int uniquePaths(int n, int m) {
    int dp[m + 2][n + 2];
    dp[1][1] = 1;
    int i, j;
    for (i = 1; i <= m; i++) {  //����ÿ��
        for (j = 1; j <= n; j++) {  //����ÿ��
            if (i == 1 || j == 1) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];     //��Զ��ֻ��Ҫ����ߺ��ϱߵ�·����
            }
        }
    }
    return dp[m][n];
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << uniquePaths(n, m) << endl;
}