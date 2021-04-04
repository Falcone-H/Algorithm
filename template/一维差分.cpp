#include <bits/stdc++.h>

using namespace std;
int a[100]; // 原数组
int d[100]; // 差分数组
/* 差分数组 d[k] = a[k] - a[k - 1]
 * 在区间[l..r]上加x，等于在差分数组d[l]加上x，d[r + 1]减去x
 * 即 d[l] += x; d[r + 1] -= x;
 * 改变后的 a[k] = d[1] + d[2] + d[3] + ... + d[k]
 */
int main()
{
    for (int i = 1; i <= 50; i++)
    {
        a[i] = 1;
        d[i] = a[i] - a[i - 1];
    }
    int left = 1;
    int right = 10;
    d[left] += 5;
    d[right + 1] -= 5;
    int sum = 0;
    for (int i = 1; i <= 11; i++)
    {
        sum += d[i];
    }
    cout << sum << endl;
    return 0;
}