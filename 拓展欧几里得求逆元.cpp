//https://zhuanlan.zhihu.com/p/86561431
#include <bits/stdc++.h>
#define int long long
using namespace std;
int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
signed main()
{
    int a, b;
    cin >> a >> b; // 求 a 关于 b 的逆元，ax + by = 1，即 ax + by = gcd(a, b);  a, b互质
    int x = 0;
    int y = 0;
    exgcd(a, b, x, y);
    cout << (x % b + b) % b << endl; // 防止出现负数
    return 0;
}