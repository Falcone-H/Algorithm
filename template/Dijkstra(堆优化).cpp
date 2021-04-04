#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N = 100005;
int n, m;
bool vis[N];
int dis[N];
vector<pair<int, int>> g[N];    //firstΪ��ʼ���Ҫ�����յ㣬secondΪ����

struct Node {
    int id; //�õ�ı��
    int dist;   //�õ㵽��ʼ��ľ���

    Node() {};

    Node(int id, int d) : id(id), dist(d) {};

    friend bool operator < (Node A, Node B){
        return B.dist < A.dist;
    }
    /*
     * ���ȶ���Ĭ���ɴ�С���С�
     * ����������Ϊ�������Ҫ Node B > Node A (��B������A), ����Ҫ B.dist < A.dist
     */
};

void Dijkstra(int s) {
    for (int i = 1; i <= n; i++) {  //��ʼ��
        vis[i] = 0;
        dis[i] = INT_MAX;
    }
    dis[s] = 0;
    priority_queue<Node> q;
    q.push(Node(s, 0));
    Node node;

    while (!q.empty()) {
        node = q.top(); //ȡ����ǰ�ڵ�
        q.pop();
        if (vis[node.id])
            continue;
        vis[node.id] = true;
        for (int i = 0; i < g[node.id].size(); i++) {   //�����뵱ǰ�ڵ������ı�
            int exit = g[node.id][i].first; //�ñߵ��յ�
            int len = g[node.id][i].second; //�ñߵ�Ȩ
            if (node.dist + len < dis[exit] && !vis[exit]) {  //�ɳ�
                dis[exit] = node.dist + len;
                q.push(Node(exit, dis[exit]));
            }
        }
    }
}

signed main() {
    int x, y, z;
    int s, e;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
    while (m--) {
        cin >> x >> y >> z;
        g[x].push_back(make_pair(y, z));
    }
    Dijkstra(s);
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
    cout << endl;
    return 0;
}