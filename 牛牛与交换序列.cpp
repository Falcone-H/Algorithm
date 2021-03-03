// https://ac.nowcoder.com/acm/contest/9982/F
// 思路：找到最小的，与原位置不匹配的数，该数与原位置的距离就是区间的长度
#include <bits/stdc++.h>

using namespace std;
int num[100005];
int n;

void flip(int index, int step)
{
    int end = index + step - 1;
    int start = index;
    for (int i = 0; i < step / 2; i++)
    {
        swap(num[start + i], num[end - i]);
    }
}

int main()
{
    cin >> n;
    int m = 0, k = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (num[i] != i)
        {
            m = i;
            break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (num[i] == m)
        {
            k = i - m + 1;
            break;
        }
    }
    if (m == 0)
    {
        cout << "yes" << endl;
        cout << 1 << endl;
        return 0;
    }
    int i;
    for (i = m; i <= n - k + 1; i++)
    {
        if (num[i] != i)
        {
            flip(i, k);
            if (num[i] != i) // 注意：这里翻转之后，可能还不是原数，所以还要判断一次
            {
                cout << "no" << endl;
                return 0;
            }
        }
    }
    for (; i <= n; i++)
    {
        if (num[i] != i)
        {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    cout << k << endl;
    return 0;
}