// https://www.acwing.com/solution/content/834/
// 思路：离散化
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(0), cout.tie(0)
using namespace std;
const int N = 2e5 + 5;
int pos[N];
unordered_map<int, int> p, sum;
struct Node {
    int a, b;
    int x;
} node[N];
int n, m;
int cnt;

bool cmp(Node n1, Node n2) {
    if (n1.a == n2.a) return n1.b > n2.b;
    return n1.a > n2.a;
}

int main() {
    IOS;
    TIE;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> pos[i];
        // 对比较大的数做离散化
        if (!p[pos[i]])
            p[pos[i]] = (++cnt), pos[i] = cnt;
        else
            pos[i] = p[pos[i]];
        sum[pos[i]]++;
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        x = p[x];
        node[i].a = sum[x];
        node[i].x = i;
    }
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        x = p[x];
        node[i].b = sum[x];
        node[i].x = i;
    }
    sort(node + 1, node + m + 1, cmp);
    cout << node[1].x << endl;
    return 0;
}