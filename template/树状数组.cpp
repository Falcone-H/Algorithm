// https://vjudge.net/problem/HDU-1166
// 树状数组
#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false)
using namespace std;
const int N = 50005;
int n;
int a[N], c[N]; // 对应原数组和树状数组

int lowbit(int x)
{
    return x & (-x);
}

void update(int i, int k)
{
    // 在 i 位置加上 k
    while (i <= n)
    {
        c[i] += k;
        i += lowbit(i);
    }
}

int getSum(int i)
{
    // A[1 ~ i] 的和
    int res = 0;
    while (i > 0)
    {
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}

signed main()
{
    IOS;
    int t, k = 1;
    cin >> t;
    while (k <= t)
    {
        cout << "Case " << k << ":\n";
        memset(a, 0, sizeof(a));
        memset(c, 0, sizeof(c));
        k++;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            update(i, a[i]);
        }
        string s;
        int x, y;
        while (true)
        {
            cin >> s;
            if (s == "End")
                break;
            cin >> x >> y;
            if (s == "Add")
            { // 在 a[x] 上加 y
                update(x, y);
            }
            if (s == "Sub")
            { // 在 a[x] 上减 y
                update(x, -y);
            }
            if (s == "Query")
            { // 求区间 x ~ y 的和
                cout << getSum(y) - getSum(x - 1) << "\n";
            }
        }
    }
    return 0;
}