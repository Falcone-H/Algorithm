//P3916 ͼ�ı���
//˼·������ͼ + DFS
//����DFS���ܻ���û�ҵ����ֵ֮ǰ�ͷ������ݣ����磺
/*
5 5
1 2
2 4
4 3
4 5
3 2
*/
//����һ�����ݷ���3ʱ���õ��Ľ����3������ȷ�Ľ��Ӧ����5
#include<bits/stdc++.h>

using namespace std;
int par[100005];
vector<int> node[100005];
int vis[100005];

void DFS(int cur, int maxv) {
    maxv = max(par[cur], maxv);
    if (vis[cur])
        return;
    vis[cur] = 1;
    par[cur] = maxv;
    for (int i = 0; i < node[cur].size(); i++) {
        int num = node[cur][i];
        DFS(num, maxv);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        node[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    for (int i = n; i >= 1; i--) {
        DFS(i, 0);
    }
    for (int i = 1; i <= n; i++) {
        cout << par[i] << " ";
    }
    return 0;
}