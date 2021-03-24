// https://blog.csdn.net/LJD201724114126/article/details/80663855
// 一个长度为n的整数序列，从中找出一段不超过m的连续子序列，使得整个序列的和最大。
#include <bits/stdc++.h>
using namespace std;
int n, m;
int nums[10000];
int sum[10000];
int q[10000]; // 保留范围内的最小值，使得 sum[i] - sum[q[left]] 最大，也就是区间和最大
int ans;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        sum[i] = nums[i] + sum[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << sum[i] << " ";
    }
    cout << endl;
    int left = 0, right = -1;
    for (int i = 1; i <= n; i++)
    {
        while (left <= right && i - q[left] > m) // 超出范围，就将之前的数出队
            left++;
        ans = max(ans, sum[i] - sum[q[left]]);
        while (left <= right && sum[q[right]] >= sum[i]) // 队列中保留最小值
            right--;
        right++;
        q[right] = i; // 进队
    }
    cout << ans << endl;
    return 0;
}