#include<bits/stdc++.h>

using namespace std;
int n, m;   //n个点， m条边
struct Graph {
    int begin;
    int end;
    int weight;
} edge[10005];
int par[10005];
int cnt;

bool cmp(struct Graph a, struct Graph b) {
    return a.weight < b.weight;
}

void init() {
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }
}

int find(int x) {
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

void Kruskal() {
    for (int i = 0; i < m; i++) {
        int x1 = find(edge[i].begin);
        int x2 = find(edge[i].end);
        if (x1 != x2) {   //若x1 == x2, 则形成环路，不满足条件
            if (x1 > x2)
                swap(x1, x2);
            par[x2] = x1;
            cnt++;
            printf("%d %d %d\n", edge[i].begin, edge[i].end, edge[i].weight);
            if (cnt == n - 1)    //最小生成树的边数 等于 点数-1
                break;
        }
    }
}

int main() {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
        cin >> edge[i].begin >> edge[i].end >> edge[i].weight;
    }
    sort(edge, edge + m, cmp);
    Kruskal();
}
