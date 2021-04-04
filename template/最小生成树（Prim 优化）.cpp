#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define int long long
using namespace std;
const int N = 5005;
int n, m;

struct Node {
    int to;
    int cost;

    Node() {};

    Node(int to, int cost) : to(to), cost(cost) {};

    friend bool operator<(Node a, Node b) {
        return b.cost < a.cost;
    }
};

priority_queue<Node> e[N];

int val[N];
int res;

void init() {
    for (int i = 0; i <= n; i++) {
        val[i] = INT_MAX;
    }
}

void Prim() {
    while(!e[1].empty()){
        Node node = e[1].top();
        e[1].pop();
        val[node.to] = min(val[node.to], node.cost);
    }
    val[1] = 0;
    int cnt = 0;
    while (cnt < n - 1) {
        int k = -1;
        int minv = INT_MAX;
        for (int i = 1; i <= n; i++) {
            if (val[i] < minv && val[i] != 0) {
                minv = val[i];
                k = i;
            }
        }
        if (k == -1) {
            cout << "-1" << endl;
            return;
        }
        res += val[k];
        val[k] = 0;
        cnt++;
        while(!e[k].empty()){
            Node node = e[k].top();
            e[k].pop();
            val[node.to] = min(val[node.to], node.cost);
        }
    }
}

signed main() {
    IOS;
    cin >> n >> m;
    int x, y, z;
    init();
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        e[x].push(Node(y, z));
        e[y].push(Node(x, z));
    }
    Prim();
    cout << res << endl;
    return 0;
}