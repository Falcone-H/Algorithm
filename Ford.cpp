#include<bits/stdc++.h>

using namespace std;
struct edge {
    int from;
    int to;
    int cost;
} e[10005];
int n, m;   //n¸öµã£¬mÌõ±ß
int dis[1005];

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