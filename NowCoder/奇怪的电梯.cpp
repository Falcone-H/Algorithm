#include<bits/stdc++.h>

using namespace std;
int n;
int a, b;
int lift[205];
int vis[205];   //���Ӽ��仯����ֹ MLE �� TLE 
struct Node {
    int floor;  //��ǰ���ڵ�¥��
    int now;    //��ǰ�����ݵĴ���
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