#include<bits/stdc++.h>

#define int long long
using namespace std;
int n, m, s;    //n个点，m条边，从第s号点开始
int node;   //当前正在处理的节点
int minn;
int dist[10000];    //记录每个点到起点的距离
bool vis[10000];    //记录是否处理过
struct Edge {    //边的结构体
    int w;  //边权
    int pre, to;    //有向边，pre为起点，to为终点
} l[10000];
struct Node {    //节点的结构体
    int num;    //以这个点为起点的边的个数
    vector<int> about;  //以这个点为起点的边的编号
} a[10000];

int find_new() {    //每次处理完，就去找新的节点
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0 && minn > dist[i]) {
            minn = dist[i];
            node = i;
        }
    }
    return node;
}

signed main() {
    cin >> n >> m >> s; //n为节点数，m为边数，s为起始点
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;  //初始化
    }
    int x, y, z;
    for (int i = 1; i <= m; i++) {  //输入边
        cin >> x >> y >> z;
        l[i].pre = x;
        l[i].to = y;
        l[i].w = z;
        a[x].num++;
        a[x].about.emplace_back(i);
    }
    dist[s] = 0;    //将起点的距离设置为0
    node = s;
    while (!vis[node]) {
        vis[node] = 1;
        minn = INT_MAX;
        for (int i = 0; i < a[node].num; i++) { //枚举每条以这个点为起点的边
            int num = a[node].about[i]; //获取当前枚举到的边的序号
            int exit = l[num].to;   //当前枚举到的边的终点
            dist[exit] = min(dist[exit], dist[node] + l[num].w);  //松弛
        }
        node = find_new();
    }
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}