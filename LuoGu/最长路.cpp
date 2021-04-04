//P1807 最长路
//思路：Dijkstra，只是把单源最短路换成单源最长路
#include<bits/stdc++.h>

#define int long long
using namespace std;
int n, m;
int dis[2000];
int vis[2000];

struct Node {
    int to;
    int cost;

    Node() {};

    Node(int to, int cost) : to(to), cost(cost) {};

    friend bool operator<(Node a, Node b) {
        return b.cost > a.cost;
    }
};

vector<pair<int, int> > g[2000];
priority_queue<Node> q;

void Dijkstra(int s) {
    if (vis[s])
        return;
    vis[s] = 1;
    q.push(Node(s, 0));
    while (!q.empty()) {
        Node node = q.top();
        q.pop();
        for (int i = 0; i < g[node.to].size(); i++) {
            int to = g[node.to][i].first;
            int cost = g[node.to][i].second;
            if (dis[to] < dis[node.to] + cost && !vis[to]) {
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
    }
    Dijkstra(1);
    if (dis[n] == 0)
        cout << -1 << endl;
    else
        cout << dis[n] << endl;
    return 0;
}