#include<bits/stdc++.h>

using namespace std;
int dis[1000];  //��¼���
int vis[1000];  //��¼�Ƿ���ʹ�
int edge[100][100]; //��¼����
int prev[1000]; //��¼·��

void get_path(int t) {  //tΪҪ����ĵ�
    vector<int> path;
    for(; t != -1; t = prev[t])
        path.push_back(t);
    reverse(path.begin(), path.end());
    for(int i = 0; i < path.size(); i++){
        printf("%5d", path[i]);
    }
    printf("\n");
}

void Dijkstra(int n) {
    for (int i = 1; i <= n; i++) {
        dis[i] = 10000000;
    }
    for(int i = 1; i <= n; i++) {
        prev[i] = -1;
    }
    dis[1] = 0;
    vis[1] = 1;
    for (int i = 1; i <= n; i++) {
        int x, minn = 10000000;
        for (int i = 1; i <= n; i++) {  // ��û�з��ʹ��Ľڵ��У�ѡ����Сֵ
            if (!vis[i] && dis[i] < minn) {
                minn = dis[i];
                x = i;
            }
        }
        vis[x] = 1;
        for (int i = 1; i <= n; i++) {  // �ɳ�
            if(dis[i] > dis[x] + edge[x][i]){
                dis[i] = dis[x] + edge[x][i];
                prev[i] = x;    //��¼��һ���ڵ�
            }
        }
    }
}

int main() {
    int num;
    cin >> num;
    Dijkstra(num);
}