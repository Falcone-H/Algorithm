// 二分图当且仅当图中不含奇数环（即环中边数为奇数）
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> g[N];
int color[N];
int n, m;

bool dfs(int s, int c) {
    color[s] = c;
    for(int i = 0; i < g[s].size(); i++) {
        int to = g[s][i];
        if(!color[to]) {
            if(!dfs(to, 3 - c)) return false;
        } else {
            if(color[to] == c)  return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bool flag;
    for(int i = 1; i <= n; i++) {
        if(!color[i]) {
            flag = dfs(i, 1);
        }
        if(flag == false)
            break;
    }
    if(flag == false) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}

