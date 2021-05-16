#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
using namespace std;
const int N = 1e5 + 5;
vector<pair<int, int>> g[N];
int n, m;
int dis[N]; // dis[i] 表示 i 到 源点的距离
int vis[N]; // vis[i] 表示 i 是否在队列中
int cnt[N]; // cnt[i] 表示 i 到 源点的边数，一旦有某个点的到源点的边数为n ，就证明存在负权回路
int book[N];

int spfa(int s) {
    queue<pair<int, int>> q;
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    q.push({s, 0}); // 下标号，到源点距离
    vis[s] = 1;
    pair<int, int> p;
    while(!q.empty()) {
        p = q.front();
        q.pop();
        int pos = p.first;
        // 从队列中取出来之后，该节点就取消标记，代表之后该节点如果发生更新，可以再次入队
        vis[pos] = 0;
        book[pos] = 1;
        for(int i = 0; i < g[pos].size(); i++) {
            int to = g[pos][i].first;
            int cost = g[pos][i].second;
            if(dis[to] > dis[pos] + cost) {
                dis[to] = dis[pos] + cost;
                cnt[to] = cnt[pos] + 1;
                if(cnt[to] == n) {  // 存在负权回路
                    return -1;
                }
                if(!vis[to]) {
                    // 当前已经加入队列的节点，无需再次加入队列，即便发生了更新，也只需要更新数值
                    vis[to] = 1;
                    q.push({to, dis[to]});
                }
            }
        }
    }
    return 0;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
    }
    int res;
    for(int i = 1; i <= n; i++) {
        if(!book[i]) {
            res = spfa(i);
        }
        if(res == -1)
            break;
    }
    if(res == -1)
        cout << "Yes" << "\n";
    else
        cout << "No" << "\n";
    return 0;
}