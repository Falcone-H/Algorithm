#include<bits/stdc++.h>

using namespace std;
int dis[1000];  //记录结果
int vis[1000];  //记录是否访问过
int edge[100][100]; //记录距离
int prev[1000]; //记录路径

void get_path(int t) {  //t为要到达的点
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
                prev[i] = x;    //记录上一个节点
            }
        }
    }
}

int main() {
    int num;
    cin >> num;
    Dijkstra(num);
}