// https://ac.nowcoder.com/acm/contest/9983/G
// 思路：并查集
// 将所有有关系的小朋友连起来，那么他们每个人获得糖果的数量，就是他们之间最大的a[i]，将他们视为一个集合
// 然后，计算有多少个集合，并且他们各自最大的a[i]是多少，那么就能得到答案。
#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000010];
int par[1000010];

int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

signed main()
{
    int n, m;
    int u, v;
    map<int, int> cnt;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        par[i] = i;
    }
    while (m--)
    {
        cin >> u >> v;
        int x1 = find(u);
        int x2 = find(v);
        if (a[x1] > a[x2])
            swap(x1, x2);
        par[x1] = x2;
    }
    for (int i = 1; i <= n; i++)
    {
        int x = find(i);
        cnt[a[x]]++;
    }
    int sum = 0;
    for (auto &i : cnt)
    {
        sum += i.first * i.second;
    }
    cout << sum << endl;
    return 0;
}