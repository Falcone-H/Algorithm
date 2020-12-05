// P1396 营救
// 思路：Prim，不过不是得到最小生成树，而是每一次都选择拥挤度最小的路线，然后对每一个点进行一次遍历。
#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N = 100005;
int n, m, s, t;
int dis[N];
int vis[N];
vector<pair<int, int> > g[N];

void init() {
    for (int i = 0; i <= n; i++) {
        dis[i] = -1;
    }
}

void Prim() {
    int to, cost;
    for (int i = 0; i < g[s].size(); i++) {
        to = g[s][i].first;
        cost = g[s][i].second;
        dis[to] = max(dis[to], cost);
    }
    vis[s] = 1;
    for (int i = 1; i <= n; i++) {
        int k = -1;
        int minv = INT_MAX;
        for (int j = 1; j <= n; j++) {
            if (dis[j] < minv && !vis[j] && dis[j] != -1) {
                minv = dis[j];
                k = j;
            }
        }
        if (k == -1)
            break;
        vis[k] = 1;
        if(k == t)
            break;
        for (int j = 0; j < g[k].size(); j++) {
            to = g[k][j].first;
            cost = g[k][j].second;
            if(dis[to] == -1)
                dis[to] = max(dis[k], cost);
            else
                dis[to] = min(dis[to], max(dis[k], cost));
        }
    }
}

signed main() {
    cin >> n >> m >> s >> t;
    init();
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back(make_pair(y, z));
        g[y].push_back(make_pair(x, z));
    }
    Prim();
    cout << dis[t] << endl;
    return 0;
}