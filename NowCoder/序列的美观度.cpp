// https://ac.nowcoder.com/acm/contest/9983/I
// 思路：
/*
 * if (a[i] == a[j])
 *  dp[i] = max(dp[i], dp[j] + 1)
 * esle
 *  dp[i] = max(dp[i], dp[j]);
 * 
 * 但是这种方法会超时，所以要想办法优化。
 * 
 * 首先，当 a[i] 不等于 a[j] 时，可以记录从 1 到 i - 1 的最大值 maxv，dp[i] = maxv
 * 当 a[i] 与 a[j] 相等时，可以记录下当一个与 a[i] 相等的元素的位置 j = pos[a[i]]，那么 dp[i] = max(dp[pos[a[i]]], maxv)
*/
#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int dp[1000005];
int pos[1000005];
int main()
{
    int n;
    int maxv = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (!pos[a[i]])
            dp[i] = maxv;
        else
            dp[i] = max(maxv, dp[pos[a[i]]] + 1); // maxv 为从 1 到 i - 1 的最大 dp 值， pos[a[i]] 为上一个与 a[i] 相等的元素的位置
        maxv = max(maxv, dp[i]);
        pos[a[i]] = i;
    }
    cout << maxv << endl;
    return 0;
}