#include<bits/stdc++.h>

using namespace std;
int n;
int a, b;
int lift[205];
int vis[205];   //增加记忆化，防止 MLE 和 TLE 
struct Node {
    int floor;  //当前所在的楼层
    int now;    //当前按电梯的次数
};
queue<struct Node> q;

void bfs(int begin) {
    struct Node node;
    node.floor = begin;
    node.now = 0;
    q.push(node);
    while (!q.empty()) {
        struct Node node = q.front();
        struct Node next;
        if (node.floor == b) {
            cout << node.now << endl;
            return;
        }
        int up = node.floor + lift[node.floor];
        if (up <= n && !vis[up]) {
            vis[up] = 1;
            next.floor = up;
            next.now = node.now + 1;
            q.push(next);
        }
        int down = node.floor - lift[node.floor];
        if (down >= 1 && !vis[down]) {
            vis[down] = 1;
            next.floor = down;
            next.now = node.now + 1;
            q.push(next);
        }
        q.pop();
    }
    cout << -1 << endl;
    return;
}

int main() {
    cin >> n;
    cin >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> lift[i];
    }
    bfs(a);
    return 0;
}