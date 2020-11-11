#include<bits/stdc++.h>

using namespace std;
struct edge {
    int from;
    int to;
    int cost;
} e[10005];
int n, m;   //n个点，m条边
int dis[1005];

bool find_negative() {  //检查负回路
    bool f = 0;
    memset(dis, 0, sizeof(dis));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(dis[edge[j].to] > dis[edge[j].from] + edge[j].cost) {
                dis[edge[j].to] = dis[edge[j].from] + edge[j].cost;
                if(i == n)
                    return 1;   //如果更新了n次，那么一定有负环
            }
        }
    }
}

void Ford(int s) {
    for (int i = 0; i < n; i++) {
        dis[i] = INT_MAX;
    }
    dis[s] = 0;
    while (true) {
        bool update = false;
        for (int i = 0; i < m; i++) {
            edge d = e[i];
            if (dis[d.from] != INT_MAX && dis[d.to] > dis[d.from] + d.cost) {
                update = true;
                dis[d.to] = dis[d.from] + d.cost;
            }
        }
        if (!update)
            break;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> e[i].from >> e[i].to >> e[i].cost;
    }
    Ford(0);
}