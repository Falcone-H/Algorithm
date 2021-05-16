#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> g[N];
int n1, n2, m;
int match[N];
int vis[N]; // 用于更改匹配时的标记

bool find(int x) {
    for(int i = 0; i < g[x].size(); i++) {
        int to = g[x][i];
        if(!vis[to]) {
            vis[to] = true;
            if(!match[to] || find(match[to])) {
                match[to] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n1 >> n2 >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    int res = 0;
    for(int i = 1; i <= n1; i++) {
        for(int j = 0; j <= n1; j++)    // 因为每一轮的匹配情况不同，因此每一轮都要初始化
            vis[j] = 0;
        if(find(i)) res++;
    }
    cout << res << endl;
    return 0;
}