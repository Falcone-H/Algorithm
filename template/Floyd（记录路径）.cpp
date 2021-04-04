#include<bits/stdc++.h>

#define int long long
using namespace std;
int dis[100][100];
int path[100][100];
int n, m;   //nΪ�ڵ�����mΪ����

void parentPath(int i, int j) { //�ݹ��ҵ�֮ǰ����ת��
    int k = path[i][j];
    if (k == -1)
        return;
    parentPath(i, k);
    printf("%d, ", k);
    //parentPath(k, j);
}

void printPath() {  //��ӡ·��
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

void printArray() { //��ӡdis����
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
    for (k = 1; k <= n; k++) {  //��kΪ��ת��
        for (i = 1; i <= n; i++) {  //����ÿ�� i -> j����������kΪ��תȥ���̾���
            for (j = 1; j <= n; j++) {
                if (dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    path[i][j] = k; //��¼���һ����ת��
                }
            }
        }
    }
    printPath();
}

signed main() {
    int u, v, w;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {  //��ʼ��
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