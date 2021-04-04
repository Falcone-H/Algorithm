// 在后序序列中，若 一个结点的左侧 没有 在先序序列中 排在该结点后面的结点，那么这个结点必然没有孩子。
// 在先序序列中，若 根结点的下一个位置上的结点 在 后序序列中的位置 在后序序列根结点的 左边一个位置，那么说明树不唯一，树的个数与出现这种情况相关(2^n)。

#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1e9 + 5;
int front[100005];
int back[100005];
map<int, int> m;
int n;

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
    int cnt = 0;
    for (int i = 0; i < n; i++)
        cin >> front[i];
    for (int i = 0; i < n; i++)
    {
        cin >> back[i];
        m[back[i]] = i;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int index = m[front[i]];
        if (index != 0 && front[i + 1] == back[index - 1])
            cnt++;
    }
    cout << quick_power(2, cnt) << endl;
    return 0;
}