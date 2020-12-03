// P1144 最短路计数
// 思路：Dijkstra，第一次找到最短路时，记录上一个点的到达次数，后面如果再次找到的最短路长度相等，则把到达次数相加

#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N = 1000005;
const int mod = 100003;
int n, m;
int dis[N];
int vis[N];
int path[N];
vector<pair<int, int>> g[N];

struct Node {
    int to;
    int cost;

    Node() {};

    Node(int to, int cost) : to(to), cost(cost) {};

    friend bool operator<(Node a, Node b) {
        return b.cost < a.cost;
    }
};

priority_queue<Node> q;

void Dijkstra(int s) {
    for (int i = 0; i <= n; i++) {
        dis[i] = INT_MAX;
    }
    dis[s] = 0;
    path[s] = 1;
    q.push(Node(s, 0));
    while (!q.empty()) {
        Node node = q.top();
        q.pop();
        if (vis[node.to])
            continue;
        vis[node.to] = 1;
        for (int i = 0; i < g[node.to].size(); i++) {
            int to = g[node.to][i].first;
            int cost = g[node.to][i].second;
            if (dis[to] > dis[node.to] + cost && !vis[to]) {
                dis[to] = dis[node.to] + cost;
                path[to] = path[node.to];   // 记录到达次数
                q.push(Node(to, dis[to]));
            }
            else if (dis[to] == dis[node.to] + cost && !vis[to]) {
                path[to] += path[node.to];  // 到达次数相加s
                path[to] %= mod;
            }
        }
    }
}

signed main() {
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        g[x].push_back(make_pair(y, 1));
        g[y].push_back(make_pair(x, 1));
    }
    Dijkstra(1);
    for (int i = 1; i <= n; i++) {
        cout << path[i] << endl;
    }
    return 0;
}