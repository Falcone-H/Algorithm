#include<bits/stdc++.h>

#define int long long
using namespace std;
int n, m;
int graph[105][105];
int val[105];   //��¼��ǰ�����еĵ㵽����λ�õ���̾���
int index[105]; //��¼��ǰ�����еĸ��׽ڵ�

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
    int res = 0;    //��С������Ȩֵ��
    int cnt = 0;
    for (int i = 1; i <= n; i++) {  //ѡ��һ�Žڵ�Ϊ��ʼ��
        val[i] = graph[1][i];
        index[i] = 1;
    }
    while (cnt < n - 1) {
        int k;
        int minv = INT_MAX;
        bool flag = false;
        for (int i = 1; i <= n; i++) {  //ѡ���뵱ǰ���Ͼ�����С�ĵ�
            if(val[i] != 0 && val[i] != INT_MAX)
                flag = true;
            if (val[i] < minv && val[i] != 0) {
                minv = val[i];
                k = i;
            }
        }
        if(!flag){  //�����ҳ���С������
            cout << -1 << endl;
            return ;
        }
        res += val[k];
        val[k] = 0; //��Ǹõ�Ϊ�ѷ���
        cnt++;
        for (int i = 1; i <= n; i++) {  //��С�����㵽��ǰ���ϵľ���
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