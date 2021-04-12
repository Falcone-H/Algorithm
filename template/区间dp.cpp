// 朴素区间dp
// https://vjudge.net/problem/51Nod-1021
#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int stone[N];
int dp[N][N];   // dp[i][j]表示把第 i 堆和第 j 堆合起来的最小花费
int sum[N];
int n;

void init() {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == j)
                dp[i][j] = 0;
            else
                dp[i][j] = INT_MAX;
        }
    }
}

int main() {
    cin >> n;
    init();
    for(int i = 1; i <= n; i++) {
        cin >> stone[i];
        sum[i] = sum[i - 1] + stone[i];
    }
    for(int len = 1; len <= n; len++) {     // 枚举长度
        for(int j = 1; j + len <= n + 1; j++) {     // 枚举起点，ends <= n
            int ends = j + len - 1;
            for(int i = j; i < ends; i++) {     // 枚举分割点
                // j~i 与 i+1~ends 合并，等于 （原来的， 分割点 i 左边部分重量 + 分割点 i 右边部分重量 + 合并后的重量）
                dp[j][ends] = min(dp[j][ends], dp[j][i] + dp[i + 1][ends] + sum[ends] - sum[j - 1]);
            }
        }
    }
    cout << dp[1][n] << "\n";
    return 0;
}