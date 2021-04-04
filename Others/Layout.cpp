// POJ 3169
// 思路：差分约束 + Bellman-Ford
// https://blog.csdn.net/weixin_43501684/article/details/97672524
#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N = 20005;
struct edge {
    int from;
    int to;
    int cost;
} g[N];
int n, m;
int ml, md;
int dis[N];

bool find_negative() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            edge e = g[j];
            if (dis[e.to] > dis[e.from] + e.cost) {
                dis[e.to] = dis[e.from] + e.cost;
                if (i == n - 1)
                    return 1;
            }
        }
    }
    return 0;
}

void Ford(int s) {
    for (int i = 1; i <= n; i++) {
        dis[i] = INT_MAX;
    }
    dis[s] = 0;
    while (true) {
        bool update = false;
        for (int i = 0; i < m; i++) {
            edge e = g[i];
            if (dis[e.from] != INT_MAX && dis[e.to] > dis[e.from] + e.cost) {
                dis[e.to] = dis[e.from] + e.cost;
                update = true;
            }
        }
        if (!update)
            break;
    }
}

signed main() {
    cin >> n >> ml >> md;
    for (int i = 0; i < ml; i++) {
        cin >> g[m].from >> g[m].to >> g[m].cost;
        m++;
    }
    for (int i = 0; i < md; i++) {
        cin >> g[m].from >> g[m].to >> g[m].cost;
        g[m].cost = -g[m].cost;
        m++;
    }
    for (int i = 2; i <= n; i++) {
        g[m].from = i;
        g[m].to = i - 1;
        g[m].cost = 0;
        m++;
    }
    if (find_negative()) {
        cout << -1 << endl;
        return 0;
    }
    Ford(1);
    if (dis[n] == INT_MAX)
        dis[n] = -2;
    cout << dis[n] << endl;
    return 0;
}