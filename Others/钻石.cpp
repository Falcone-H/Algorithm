// http://oj.saikr.com/contest/1/problem/C
// 思路：贪心；将每一个钻石按照体积升序排列，将袋子容量也升序排列。
// 然后枚举每一个袋子的容量，把它能装下的钻石都加入一个优先队列（降序），再从中选出一个价格最高的；

#include <bits/stdc++.h>
#define int long long
using namespace std;
int r[300005];
struct diamond
{
    int a;
    int s;
} d[300005];

bool cmp(diamond a, diamond b)
{
    return a.a < b.a;
}

priority_queue<int> q;

signed main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i].a >> d[i].s;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> r[i];
    }
    sort(d, d + n, cmp);
    sort(r, r + m);
    int cur = 0;
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        while (cur < n && d[cur].a <= r[i])
        {
            q.push(d[cur].s);
            cur++;
        }
        if (!q.empty())
        {
            ans += q.top();
            q.pop();
        }
    }
    cout << ans << endl;
    return 0;
}