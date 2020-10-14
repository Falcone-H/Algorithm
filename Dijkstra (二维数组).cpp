#include<bits/stdc++.h>

using namespace std;
int dis[1000];  //记录结果
int vis[1000];  //记录是否访问过
int edge[100][100]; //记录距离

void Dijkstra(int n) {
    for (int i = 1; i <= n; i++) {
        dis[i] = 10000000;
    }
    dis[1] = 0;
    vis[1] = 1;
    for (int i = 1; i <= n; i++) {
        int x, minn = 10000000;
        for (int i = 1; i <= n; i++) {  // 从没有访问过的节点中，选出最小值
            if (!vis[i] && dis[i] < minn) {
                minn = dis[i];
                x = i;
            }
        }
        vis[x] = 1;
        for (int i = 1; i <= n; i++) {  // 松弛
            if(dis[i] > dis[x] + edge[x][i]){
                dis[i] = dis[x] + edge[x][i];
            }
        }
    }
}

int main() {
    int num;
    cin >> num;
    Dijkstra(num);
}