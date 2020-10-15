#include<bits/stdc++.h>

#define int long long
using namespace std;
int dis[100][100];
int path[100][100];
int n, m;   //n为节点数，m为边数

void parentPath(int i, int j) { //递归找到之前的中转点
    int k = path[i][j];
    if (k == -1)
        return;
    parentPath(i, k);
    printf("%d, ", k);
    //parentPath(k, j);
}

void printPath() {  //打印路径
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (dis[i][j] == INT_MAX) {
                printf("%d --> %d has no path\n", i, j);
            } else if (i != j) {
                printf("%d --> %d , dis: %lld, path: ", i, j, dis[i][j]);
                printf("%d, ", i);
                parentPath(i, j);
                printf("%d\n", j);
            }
        }
    }
}

void printArray() { //打印dis数组
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%lld ", dis[i][j]);
        }
        printf("\n");
    }
    printf("---------------\n");
}

void Floyd() {
    int i, j, k;
    for (k = 1; k <= n; k++) {  //以k为中转点
        for (i = 1; i <= n; i++) {  //对于每个 i -> j，都尝试用k为中转去缩短距离
            for (j = 1; j <= n; j++) {
                if (dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    path[i][j] = k; //记录最后一个中转点
                }
            }
        }
    }
    printPath();
}

signed main() {
    int u, v, w;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {  //初始化
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dis[i][j] = 0;
            } else {
                dis[i][j] = INT_MAX;
            }
            path[i][j] = -1;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        dis[v][u] = dis[u][v] = w;
    }
    Floyd();
    return 0;
}