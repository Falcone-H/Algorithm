// https://ac.nowcoder.com/acm/contest/9983/J
// 思路：因为这种玩法相当于每次消除一个数，所以一共会操作 n - 1 次。因此当 n 为奇数时，最后一个操作的人是牛妹，那么，无论剩下的两个数是什么，都可以变成一个偶数
// 如果 n 为偶数，那么牛妹一共会操作 (n - 2) / 2次，也就是说最多消除 n - 2 个奇数（每次最多消除两个）。因此，当 n 为偶数，且奇数个数大于 n - 2，则牛牛获胜，反之，牛妹获胜
// 最后，特判 n 等于 1 的情况
#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000010];
signed main()
{
    int n;
    cin >> n;
    int even = 0;
    int odd = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 0)
            even++;
        else
            odd++;
    }
    if (n == 1)
    {
        cout << (odd == 1 ? "NiuNiu" : "NiuMei") << endl;
        return 0;
    }
    if (n % 2 == 1)
    {
        cout << "NiuMei" << endl;
    }
    else
    {
        if (odd > (n - 2))
            cout << "NiuNiu" << endl;
        else
            cout << "NiuMei" << endl;
    }
    return 0;
}