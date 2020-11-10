// POJ No.3723
// 思路：最大生成树
// par[0 ~ m - 1]表示男生， par[m, n - 1]表示女生

#include<bits/stdc++.h>

using namespace std;
const int N = 20005;
int n, m, r;    // n表示女生人数，m表示男生人数，r表示输入的关系数
int par[N];     // 并查集的父亲结点
int ans;

struct edge {
    int from;
    int to;
    int cost;
} g[N];

bool cmp(edge a, edge b) {
    return a.cost > b.cost;
}

void init() {
    for (int i = 0; i < n + m; i++) {
        par[i] = i;
    }
}

int find(int x) {
    if (par[x] == x)
        return x;
    else
        return par[x] = find(x);
}

void Kruskal() {
    init();
    for (int i = 0; i < r; i++) {
        int x = find(g[i].from);
        int y = find(g[i].to + m);
        if (x == y)     // 属于同一集合，则会形成环，跳过
            continue;
        par[y] = x;
        ans += g[i].cost;
        if (i == n + m - 1)
            return;
    }
}

int main() {
    cin >> n >> m >> r;
    int x, y, d;
    for (int i = 0; i < r; i++) {
        cin >> g[i].from >> g[i].to >> g[i].cost;
    }
    sort(g, g + r, cmp);
    Kruskal();
    cout << (n + m) * 10000 - ans << endl;
    return 0;
}