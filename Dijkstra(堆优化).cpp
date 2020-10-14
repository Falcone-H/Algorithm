#include<bits/stdc++.h>

#define long long int
using namespace std;
const int N = 100005;
int n, m;
bool vis[N];
int dis[N];
vector<pair<int, int>> g[N];

struct Node {
    int id;
    int dist;

    Node() {};

    Node(int id, int d) : id(id), dist{d} {};

    friend bool operator < (Node A, Node B){
        return B.dist < A.dist;
    }
    /*
     * 优先队列默认由大到小排列。
     * 这里可以理解为，如果需要 Node B > Node A (即B优先于A), 就需要 B.dist < A.dist
     */
};

void Dijkstra(int s) {
    for (int i = 1; i <= n; i++) {  //初始化
        vis[i] = 0;
        dis[i] = INT_MAX;
    }
    dis[s] = 0;
    priority_queue<Node> q;
    q.push(Node(s, 0));
    Node node;

    while (!q.empty()) {
        node = q.top(); //取出当前节点
        q.pop();
        if (vis[node.id])
            continue;
        for (int i = 0; i < g[node.id].size(); i++) {   //遍历与当前节点相连的边
            int exit = g[node.id][i].first; //该边的终点
            int len = g[node.id][i].second; //该边的权
            if (node.dist + len < dis[exit] && !vis[exit]) {  //松弛
                dis[exit] = node.dist + len;
                q.push(Node(exit, dis[exit]));
            }
        }
    }
}

signed main() {
    int x, y, z;
    int s, e;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
    while (m--) {
        cin >> x >> y >> z;
        g[x].push_back(make_pair(y, z));
    }
    Dijkstra(s);
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
    cout << endl;
    return 0;
}