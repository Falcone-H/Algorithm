#include<bits/stdc++.h>

#define int long long
using namespace std;
int n, m;
int graph[105][105];
int val[105];   //记录当前集合中的点到其他位置的最短距离
int index[105]; //记录当前集合中的父亲节点

void printVal() {
    for (int i = 1; i <= n; i++) {
        printf("%5d", val[i]);
    }
    printf("\n");
}

void init() {
    for (int i = 0; i <= n; i++) {
        val[i] = INT_MAX;
        index[i] = -1;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INT_MAX;
            }
        }
    }
}

void Prim() {
    int res = 0;    //最小生成树权值和
    int cnt = 0;
    for (int i = 1; i <= n; i++) {  //选择一号节点为初始点
        val[i] = graph[1][i];
        index[i] = 1;
    }
    while (cnt < n - 1) {
        int k;
        int minv = INT_MAX;
        bool flag = false;
        for (int i = 1; i <= n; i++) {  //选出与当前集合距离最小的点
            if(val[i] != 0 && val[i] != INT_MAX)
                flag = true;
            if (val[i] < minv && val[i] != 0) {
                minv = val[i];
                k = i;
            }
        }
        if(!flag){  //不能找出最小生成树
            cout << -1 << endl;
            return ;
        }
        res += val[k];
        val[k] = 0; //标记该点为已访问
        cnt++;
        for (int i = 1; i <= n; i++) {  //缩小其他点到当前集合的距离
            if (val[i] > graph[k][i]) {
                val[i] = graph[k][i];
                index[i] = k;
            }
        }
    }
    cout << res << endl;
    return;
}

signed main() {
    while (cin >> n >> m) {
        int x, y, z;
        init();
        for (int i = 0; i < m; i++) {
            cin >> x >> y >> z;
            graph[x][y] = graph[y][x] = z;
        }
        Prim();
    }
    return 0;
}