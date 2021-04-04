#include<bits/stdc++.h>

using namespace std;
vector<int> g[1005];
int color[1005];
int n, m;

//把顶点染成1或-1
bool dfs(int s, int flag) {
    color[s] = flag;    //将顶点s染色
    for (int i = 0; i < g[s].size(); i++) {
        if (color[g[s][i]] == 0) {  //如果相邻顶点还没被染色，则染成-flag
            if (!dfs(g[s][i], -flag))
                return false;
        }
        if (color[g[s][i]] == flag) //如果相邻顶点同色，则返回false
            return false;
    }
    return true;
}

void solve() {
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {    //如果还没染色，则染成1
            if (!dfs(i, 1)) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    cin >> n;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
    }
    solve();
}