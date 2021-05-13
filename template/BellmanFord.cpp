#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INTMAX = 0x3f3f3f3f;
int n, m;
int dis[N], backup[N];  // backup 数组是为了防止在同一轮中，被更新的节点又被使用
struct Edge{
    int a, b, w;
}e[N];

int BellmanFord() {
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    for(int i = 1; i <= n; i++) {    // 循环到第 i 轮的意思是，从 a 到 b 最多经过 i 条边松弛
        memcpy(backup, dis, sizeof(dis));
        for(int j = 0; j < m; j++) {
            int a = e[j].a;
            int b = e[j].b;
            int w = e[j].w;
            dis[b] = min(dis[b], backup[a] + w);
        }
    }
    if(dis[n] > INTMAX / 2) return -1;  // 如果不存在负环，那么从 1 到 n 最多经过 n - 1 条边，那么 dis[n] 一定不会是无穷大
    else    return dis[n];
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        e[i] = {a, b, w};
    }
    int t = BellmanFord();
    if(t == -1) cout << "impossible" << endl;
    else cout << t << endl;
    return 0;
}