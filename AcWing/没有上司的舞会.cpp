// https://www.acwing.com/problem/content/description/287/
// 思路：树形DP
#include<bits/stdc++.h>
using namespace std;
const int N = 6010;
int n;
vector<int> g[N];
int a[N];
int f[N][2];    // f[i][0] 表示不选第 i 个点，f[i][1] 表示选择第 i 个点
int has_fa[N];

void dfs(int u) {
    f[u][1] = a[u];
    for(int i = 0; i < g[u].size(); i++) {
        int son = g[u][i];
        dfs(son);
        f[u][1] += f[son][0];
        f[u][0] += max(f[son][0], f[son][1]);
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[b].push_back(a);
        has_fa[a] = true;
    }
    int root = 1;
    while(has_fa[root]) root++;

    dfs(root);

    int ans = max(f[root][0], f[root][1]);
    cout << ans << endl;
    return 0;
}