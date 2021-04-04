// https://ac.nowcoder.com/acm/contest/9981/I
// 因为 k <= n / 2，而 n 个数中，偶数有 n / 2 个, 则偶数共有 num = n / 2 - 1 对
// 这里可以分两种情况：
// 第一种，k == num，则刚好所有偶数排列在前面，所有奇数放后面就可以。
// 第二种，k == num - 1， 则需要先把 6 拿出来，与 3 放在一起，增加一对。
#include <bits/stdc++.h>

using namespace std;
int book[100005];

int main()
{
    int n, k;
    cin >> n >> k;
    int num = n / 2; // 偶数的个数
    if (k <= num - 1)
    {
        for (int i = 2; i <= (k + 1) * 2; i += 2)
        {
            cout << i << " ";
            book[i] = 1;
        }
    }
    else
    {
        if (n < 6)
        {
            cout << -1 << endl;
            return 0;
        }
        else
        {
            for (int i = 2; i <= n; i += 2)
            {
                book[i] = 1;
                if (i == 6)
                    continue;
                cout << i << " ";
            }
            book[3] = 1;
            cout << 6 << " " << 3 << " ";
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!book[i])
        {
            cout << i << " ";
        }
    }
    return 0;
}