// https://www.acwing.com/problem/content/848/
// 思路：DFS，对每一个节点进行深搜，找出它所连接的每个子节点的连通数量，因为父节点已经被访问过（vis[i] == true），不会被重复访问，
// 所以，不用担心会重复计算父节点的值
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
vector<int> g[N];
int nums[N];
int ans = 2000000;
bool vis[N];

int dfs(int s) {
    int res = 0;
    for(int i = 0; i < g[s].size(); i++) {
        int to = g[s][i];
        if(!vis[to]) {
            vis[to] = true;
            int t = dfs(to);
            res = max(res, t);
            nums[s] += t;
        }
    }
    nums[s]++;
    res = max(res, n - nums[s]);
    ans = min(ans, res);
    return nums[s];
}

int main() {
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}