// https://ac.nowcoder.com/acm/contest/9981/A
// 首先，定义dp[i - 1]为 长度为i - 1的字符串中，含有us的字符串的个数
// 那么，dp[i] 包含 dp[i - 1] * 26, 即在后面随便添加一个字母
// 另外，dp[i] 也包含 26^(i - 1) - 25^(i - 1) - dp[i - 1]，即 长度为 i - 1 的所有字符串总数 - 没有 u 的字符串的总数 - 含有us的字符串的个数
// 得到的，就是有 u , 但是不含 us 的字符串
// 这时，给有 u , 但是不含 us 的字符串后面加上 s , 就是含有 us 的字符串
// 因此，把含有 us 的字符串个数， 加上 有 u , 但是不含 us 的字符串个数， 就是 dp[i]
// 即 dp[i] = 26^(i - 1) - 25^(i - 1) + 25 * dp[i - 1]
#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[1000005];
int mod = 1000000007;

int quick_power(int base, int n)
{
    int a = base;
    int res = 1;
    while (n)
    {
        if (n & 1)
        {
            res *= a;
            res %= mod;
        }
        a = a * a;
        a = a % mod;
        n = n >> 1;
    }
    return res % mod;
}

signed main()
{
    dp[2] = 1;
    int n;
    cin >> n;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (quick_power(26, i - 1) - quick_power(25, i - 1) + mod) % mod + (25 * dp[i - 1]) % mod;
        dp[i] %= mod;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += dp[i];
        sum %= mod;
    }
    cout << sum << endl;
    return 0;
}