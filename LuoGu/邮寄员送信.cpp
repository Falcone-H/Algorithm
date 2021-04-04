// P1629 邮递员送信
// 思路：先用 Dijkstra 求 1号点 到 其他点 的最短路，加起来。然后反向建图，再求一次最短路，表示每次送完信要返回的最短路径，加起来，得到答案。

#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N = 100005;
int dis[N];
int vis[N];
vector<pair<int, int> > g[N];
vector<pair<int, int> > r[N];

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
int n, m;

int ans;

void Dijkstra(int s) {
    for (int i = 1; i <= n; i++) {
        dis[i] = INT_MAX;
    }
    dis[s] = 0;
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
                q.push(Node(to, dis[to]));
            }
        }
    }
}

void re_Dijkstra(int s) {
    for (int i = 1; i <= n; i++) {
        dis[i] = INT_MAX;
    }
    dis[s] = 0;
    q.push(Node(s, 0));
    while (!q.empty()) {
        Node node = q.top();
        q.pop();
        if (vis[node.to])
            continue;
        vis[node.to] = 1;
        for (int i = 0; i < r[node.to].size(); i++) {
            int to = r[node.to][i].first;
            int cost = r[node.to][i].second;
            if (dis[to] > dis[node.to] + cost && !vis[to]) {
                dis[to] = dis[node.to] + cost;
                q.push(Node(to, dis[to]));
            }
        }
    }
}

signed main() {
    cin >> n >> m;
    int x, y, z;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        g[x].push_back(make_pair(y, z));
        r[y].push_back(make_pair(x, z));
    }
    Dijkstra(1);
    for (int i = 1; i <= n; i++) {
        ans += dis[i];
    }
    memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    re_Dijkstra(1);
    for (int i = 2; i <= n; i++) {
        ans += dis[i];
    }
    cout << ans << endl;
    return 0;
}