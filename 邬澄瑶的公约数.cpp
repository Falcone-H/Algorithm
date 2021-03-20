// https://ac.nowcoder.com/acm/contest/9984/J
// 思路：因为每一个数都可以用几个素数的k次方相乘得到，
// 那么，几个数的最小公约数，就是他们之间共有的素数的k次方相乘
#include <bits/stdc++.h>

#define int long long
using namespace std;
int x[10005];
int p[10005];
int n;
int prime[10005];
int is_pri[10005];
int res[10005];
int len = 0;
int mod = 1e9 + 7;

void sieve()
{
    for (int i = 0; i <= 10005; i++)
        is_pri[i] = true;
    is_pri[0] = is_pri[1] = false;
    for (int i = 2; i <= 10005; i++)
    {
        if (is_pri[i])
        {
            prime[len++] = i;
            for (int j = 2 * i; j <= 10005; j += i)
                is_pri[j] = false;
        }
    }
}

void count(int x, int p)
{
    for (int i = 0; i < len; i++)
    {
        int t = 0;
        if (x >= prime[i])
        {
            while (x % prime[i] == 0)
            {
                t++;
                x /= prime[i];
            }
            res[prime[i]] = min(res[prime[i]], t * p);
        }
        else
        {
            res[prime[i]] = 0;
        }
    }
}

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
    return res;
}

signed main()
{
    cin >> n;
    sieve();
    for (int i = 0; i < 10005; i++)
        res[i] = 99999;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
    {
        count(x[i], p[i]);
    }
    int ans = 1;
    for (int i = 0; i < len; i++)
    {
        ans = (ans * quick_power(prime[i], res[prime[i]])) % mod;
    }
    cout << ans << endl;
    return 0;
}