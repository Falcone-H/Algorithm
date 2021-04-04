// https://ac.nowcoder.com/acm/contest/9981/J
// https://fanfansann.blog.csdn.net/article/details/113528164

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAX_SIZE = 8e+7;
int Mark[MAX_SIZE];
int prime[MAX_SIZE];
const int mod = 1e9 + 7;
int cnt;

int quick_power(int base, int n)
{
    int a = base;
    int res = 1;
    while (n)
    {
        if (n & 1)
        {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        n >>= 1;
    }
    return res % mod;
}

void Prime(int n)
{
    int index = 0;
    for (int i = 2; i < n; i++)
    {
        if (Mark[i] == 0)
        {
            prime[index++] = i;
        }
        for (int j = 0; j < index && prime[j] * i < n; j++)
        {
            Mark[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
    cnt = index;
}

signed main()
{
    int n;
    cin >> n;
    if (n < 6)
    {
        cout << "empty" << endl;
        return 0;
    }
    Prime(n / 2 + 1);
    int ans = 1;
    int maxn = n / 3; // 能取到的最大的数
    int p = 2;        // 当前的素数
    int times = 0;    // 能取到的最大幂次
    while (maxn >= p)
    {
        maxn /= p;
        times++;
    }
    ans *= quick_power(p, times); // 乘上当前素数的最大幂次
    ans %= mod;
    for (int i = 1; i < cnt; i++)
    { // 其他素数同样操作
        p = prime[i];
        maxn = n / 2;
        times = 0;
        while (maxn >= p)
        {
            maxn /= p;
            times++;
        }
        ans *= quick_power(p, times);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}