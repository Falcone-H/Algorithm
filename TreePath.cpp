#include<bits/stdc++.h>

#define int long long
using namespace std;
vector<int> tree[100005];
bool vis[100005];
int odd, even;

void solve(int root, int num) {
    if(vis[root])   //防止重复访问
        return ;
    vis[root] = 1;
    num % 2 == 0 ? even++ : odd++;
    for (int i = 0; i < tree[root].size(); i++) {
        solve(tree[root][i], num + 1);
    }
    return;
}

signed main() {
    int n;
    cin >> n;
    int p = n - 1;
    int u, v;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    while (p--) {
        cin >> u >> v;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);    //如果不加这一句，那么输入3 1的话，就永远不能从1结点访问到3结点
    }
    solve(1, 0);
    int res = (odd - 1) * odd / 2 + (even - 1) * even / 2;
    cout << res << endl;
    return 0;
}