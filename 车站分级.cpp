// P1983 车站分级
// 思路：拓扑排序，维护一种优先级大小的关系
// 将每一个车次中，暂停的站一定比未暂停的站的级别大，因此维护一个图，将暂停的站指向范围内（从起始站到终点站）未暂停的站，
// 然后，利用拓扑排序，入度为0的站为等级最高的站，然后不断删边，重复以上步骤
#include<bits/stdc++.h>

using namespace std;
int s[1005][1005];
int has_conn[1005][1005];
vector<int> g[1005];
int vis[1005];
int in_degree[1005];
int n, m;
int maxv;

void conn(int start, int end, int x) {
    for (int i = start; i <= end; i++) {
        if (vis[i] && !has_conn[i][x]) {
            has_conn[i][x] = 1;
            g[i].push_back(x);
            in_degree[x]++;
        }
    }
}

void topo() {
    queue<pair<int, int> > q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(make_pair(i, 1));
        }
    }
    while (!q.empty()) {
        int node = q.front().first;
        int floor = q.front().second;
        q.pop();
        maxv = max(maxv, floor);
        for (int i = 0; i < g[node].size(); i++) {
            int to = g[node][i];
            in_degree[to]--;
            if (in_degree[to] == 0) {
                q.push(make_pair(to, floor + 1));
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> s[i][0];
        int size = s[i][0];
        memset(vis, 0, sizeof(vis));
        for (int j = 1; j <= size; j++) {
            cin >> s[i][j];
            vis[s[i][j]] = 1;
        }
        int start = s[i][1];
        int end = s[i][size];
        for (int j = start; j <= end; j++) {
            if (vis[j])
                continue;
            conn(start, end, j);
        }
    }
    topo();
    cout << maxv << endl;

    return 0;
}