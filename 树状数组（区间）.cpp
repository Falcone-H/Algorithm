// 树状数组
// 区间更新，区间查询
#include <bits/stdc++.h>

#define int long long
using namespace std;
const int N = 50005;
int n;
int sum1[N]; // D[1] + D[2] + ... + D[n]
int sum2[N]; // 1*D[1] + 2*D[2] + ... + n*D[n]
int a[N];

int lowbit(int x)
{
    return x & (-x);
}

void update(int i, int k)
{
    int x = i;
    while (i <= n)
    {
        sum1[i] += k;
        sum2[i] += k * (x - 1);
        i += lowbit(i);
    }
}

int getSum(int i)
{
    // 求前缀和
    int res = 0, x = i;
    while (i > 0)
    {
        res += x * sum1[i] - sum2[i];
        i -= lowbit(i);
    }
    return res;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(i, a[i] - a[i - 1]);
    }

    int x, y, k; // [x, y] 区间内加上 k
    cin >> x >> y >> k;
    update(x, k);
    update(y + 1, k);

    // 求 [x, y] 区间和
    int sum = getSum(y) - getSum(x - 1);
    cout << sum << "\n";
    return 0;
}
