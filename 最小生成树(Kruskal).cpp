#include<bits/stdc++.h>

using namespace std;
int n, m;   //n���㣬 m����
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
        return par[x] = find(x);
}

void Kruskal() {
    for (int i = 0; i < m; i++) {
        int x1 = find(edge[i].begin);
        int x2 = find(edge[i].end);
        if (x1 != x2) {   //��x1 == x2, ���γɻ�·������������
            if (x1 > x2)
                swap(x1, x2);
            par[x2] = x1;
            cnt++;
            printf("%d %d %d\n", edge[i].begin, edge[i].end, edge[i].weight);
            if (cnt == n - 1)    //��С�������ı��� ���� ����-1
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
    sort(edge, edge + n, cmp);
    Kruskal();
}