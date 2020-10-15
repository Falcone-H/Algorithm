#include<bits/stdc++.h>

#define long long int
using namespace std;
int dis[100][100];
int n, m;   //nΪ�ڵ�����mΪ����

void Floyd() {
    int i, j, k;
    for (k = 1; k <= n; k++) {  //��kΪ��ת��
        for (i = 1; i <= n; i++) {  //����ÿ�� i -> j����������kΪ��תȥ���̾���
            for (j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

signed main() {
    int u, v, w;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = INT_MAX;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        dis[v][u] = dis[u][v] = w;
    }
    Floyd();
    return 0;
}