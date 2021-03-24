// http://10.191.65.243:5000/contest/problem?id=274&pid=6
// 思路：单调队列，即维护一个区间的最值
#include <bits/stdc++.h>

using namespace std;
const int N = 2000010;
int n;
int p[N], d[N]; // 得到的油数，和到下一站的距离
long long s[N]; // 前缀和
int q[N];       // 单调队列
bool ans[N];    // 答案

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) // 输入
    {
        cin >> p[i] >> d[i];
    }
    for (int i = 1; i <= n; i++) // 顺时针走，计算 p[i] - d[i]，即能否到达下一个点
    {
        s[n + i] = s[i] = p[i] - d[i];
    }
    for (int i = 1; i <= 2 * n; i++) // 前缀和
    {
        s[i] += s[i - 1];
    }
    int left = 0, right = -1; // 单调队列
    for (int i = 2 * n; i > 0; i--)
    {
        while (left <= right && q[left] - i >= n)
            left++;
        while (left <= right && s[i] <= s[q[right]]) // 找到最小的前缀和
            right--;
        right++;
        q[right] = i;
        if (i <= n && s[i - 1] <= s[q[left]]) // 就比如 1 2 3 4 5 6，如果需要计算 2 到 5 的 p[i] - d[i]，就将 2 到 5 的值加起来。又因为他们是前缀和，所以需要减去 1 的值，得到最终结果。所以这里是 s[i - 1]
            ans[i] = true;
    }

    d[0] = d[n];
    for (int i = 1; i <= n; i++)
    {
        s[n + i] = s[i] = p[i] - d[i - 1];
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        s[i] += s[i - 1];
    }
    left = 0, right = -1;
    for (int i = 1; i <= 2 * n; i++)
    {
        while (left <= right && i - q[left] >= n)
            left++;
        if (i > n && s[i] >= s[q[left]]) // 1 2 3 4 5 6，因为是逆时针，要计算 6 走到 4 ，根据前缀和，就需要 s[6] - s[4]，得到他们之间的 p[i] - d[i - 1] 之和。所以这里是 s[i]
            ans[i - n] = true;
        while (left <= right && s[i] >= s[q[left]])
            right--;
        right++;
        q[right] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        if (ans[i])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}