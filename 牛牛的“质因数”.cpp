// https://ac.nowcoder.com/acm/contest/9982/I
// 思路：利用埃氏筛，寻找每个数的最大质因数，然后将最大质因数合并到原来的值后面
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 4000005;
const int mod = 1e9 + 7;
bool is_pri[MAXN];
int f[MAXN];

void sieve(int n)
{
    for (int i = 0; i <= n; i++)
        is_pri[i] = true;

    is_pri[0] = 0;
    is_pri[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        if (is_pri[i])
        {
            f[i] = i;
            for (int j = 2 * i; j <= n; j += i)
            {
                is_pri[j] = false;
                int temp = 10;
                while (f[i] / temp != 0)
                {
                    temp *= 10;
                }
                f[j] = (f[j / i] * temp % mod + f[i]) % mod;
            }
        }
    }
}

signed main()
{
    int n;
    cin >> n;
    sieve(n);
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        ans = (ans + f[i]) % mod;
    }
    cout << ans << endl;
    return 0;
}