// https://ac.nowcoder.com/acm/contest/9981/C
// https://blog.csdn.net/qq_43765333/article/details/113783069
#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false)
using namespace std;
const int N = 100005;
vector<int> graph[N];
int n;
int book[N] = {1};
int cnt = 1;
int ans[N];

void dfs1(int son, int father)
{ // 从底部开始标记
    for (auto kid : graph[son])
    {
        if (kid != father)
            dfs1(kid, son);
    }
    if (!book[son])
    { // 如果该点和它的父亲都没有被标记，则可以染色；如果该点的父亲已经被标记过，证明不存在合法的染色方式
        if (book[father])
        {
            cout << -1 << endl;
            exit(0);
        }
        book[father] = book[son] = cnt++;
    }
}

void dfs2(int son, int father, int color)
{ // 染色
    ans[son] = color;
    for (auto kid : graph[son])
    {
        if (kid != father)
        {
            int temp = (book[kid] == book[son] ? color : !color);
            dfs2(kid, son, temp);
        }
    }
}

int main()
{
    IOS;
    cin >> n;
    int x, y;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);
    for (int i = 1; i <= n; i++)
    {
        if (ans[i])
            cout << 'R';
        else
            cout << 'B';
    }
    return 0;
}