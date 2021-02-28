// https://ac.nowcoder.com/acm/contest/9981#question
// 思路：并查集

#include <bits/stdc++.h>

#define int long long
using namespace std;
int graph[505][505];
int par[505][505];
int num[360000];
int n;
int mod = 1e9 + 7;
int cnt = 0;
int sum = 1;
int dir[4][2] = {{-1, 0},
                 {0, 1},
                 {1, 0},
                 {0, -1}};

void init()
{ // 初始化
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            par[i][j] = i * n + j;
        }
    }
}

int quick_power(int base, int n)
{ // 快速幂，用来求逆元
    int a = base;
    int res = 1;
    while (n)
    {
        if (n & 1)
        {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        n >>= 1;
    }
    return res % mod;
}

int find(int i, int j)
{ // 并查集寻找父母操作
    if (par[i][j] == i * n + j)
    {
        return par[i][j];
    }
    else
    {
        return par[i][j] = find(par[i][j] / n, par[i][j] % n);
    }
}

void change(int par1, int par2)
{ // 动态改变答案
    sum = (sum * quick_power(num[par2], mod - 2)) % mod;
    sum = (sum * quick_power(num[par1], mod - 2)) % mod;
    num[par1] += num[par2];
    num[par2] = 0;
    sum = (sum * num[par1]) % mod;
    sum = (sum * quick_power(cnt, mod - 2)) % mod;
    cnt--;
}

void merge(int par1, int par2)
{ // 并查集合并操作
    if (par1 > par2)
    {
        swap(par1, par2);
    }
    int x1 = par1 / n;
    int y1 = par1 % n;
    int x2 = par2 / n;
    int y2 = par2 % n;
    par[x2][y2] = par[x1][y1];
    change(par1, par2);
}

void unicom(int i, int j)
{ // 联合当前有1的格子和他周围有1的格子
    for (int t = 0; t < 4; t++)
    {
        int x = i + dir[t][0];
        int y = j + dir[t][1];
        if (x < 0 || x > n || y < 0 || y > n)
            continue;
        if (graph[x][y] == 1 && graph[i][j] == 1)
        {
            int par1 = find(x, y);
            int par2 = find(i, j);
            if (par1 == par2)
                continue;
            merge(par1, par2);
        }
    }
}

int count()
{ // 计算方案数
    for (int i = 0; i < n * n; i++)
    {
        if (num[i] != 0)
        {
            cnt++;
            sum *= num[i];
            sum %= mod;
        }
    }
    for (int i = 1; i <= cnt; i++)
    {
        sum *= i;
        sum %= mod;
    }
    return sum;
}

signed main()
{
    cin >> n;
    string str;
    init();
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = str[j] - '0';
            if (graph[i][j] == 1)
            {
                num[i * n + j] = 1;
            }
        }
    }
    count();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                unicom(i, j);
            }
        }
    }
    // cout << sum << endl;
    int m;
    cin >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        if (graph[x][y] == 0)
        {
            graph[x][y] = 1;
            num[x * n + y] = 1;
            cnt++;
            sum *= cnt;
            sum %= mod;
        }
        unicom(x, y);
        cout << sum << endl;
    }

    return 0;
}