// http://10.191.65.243:5000/contest/problem?id=274&pid=7
// 思路：https://socoding.cn/t/topic/438
/*
取所有平行于 x 轴的边，和所有平行于 y 轴的边相加，得到的和就是整个图形的周长
*/
#include <bits/stdc++.h>

#define int long long
using namespace std;
const int N = 5005;
int n;
struct Rectangle
{
    pair<int, int> a; // 左下角
    pair<int, int> b; // 右下角
} rec[N];

int get()
{
    vector<int> x;
    for (int i = 0; i < n; i++)
    {
        x.emplace_back(rec[i].a.first);
        x.emplace_back(rec[i].b.first);
    }
    sort(x.begin(), x.end());
    int res = 0;
    for (int i = 0; i < x.size() - 1; i++)
    {
        int left = x[i], right = x[i + 1]; // 得到一个长度为 right - left 的区间

        // 接下来是计算该区间在 y轴上有多少段
        vector<pair<int, int>> seg;
        for (int j = 0; j < n; j++)
        {
            if (rec[j].a.first <= left && rec[j].b.first >= right)
            {
                seg.emplace_back(rec[j].a.second, rec[j].b.second);
            }
        }
        sort(seg.begin(), seg.end());
        int maxv = -20000;
        int cnt = 0;
        for (auto [x, y] : seg)
        {
            if (x > maxv)
            {
                cnt++;
                maxv = y;
            }
            else
            {
                maxv = max(maxv, y);
            }
        }

        res += 2LL * cnt * (right - left);
    }
    return res;
}

signed main()
{
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> a, b;
        cin >> a.first >> a.second >> b.first >> b.second;
        rec[i] = {a, b};
    }
    res += get();
    for (int i = 0; i < n; i++) // 交换 x，y 坐标，再用相同的方法计算平行于 y 轴的边的总长度
    {
        swap(rec[i].a.first, rec[i].a.second);
        swap(rec[i].b.first, rec[i].b.second);
    }
    res += get();
    cout << res << "\n";
    return 0;
}