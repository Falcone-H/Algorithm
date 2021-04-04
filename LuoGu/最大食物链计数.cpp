//P4017 最大食物链计数
//思路：将所有入度为零（生产者）的点加入队列，然后遍历它们所能到达的点，将这些能到达的点的入度减一，如果这些点的入度变为零，则加入队列，重复刚才的操作
//      最后，将所有出度为零的点（最终的消费者）所能到达的次数（ans）加起来，即可得到答案。
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 80112002;
int out_degree[5005];   //出度
int in_degree[5005];    //入度
int ans[5005];  //记录每个点被访问的次数
vector<int> node[5005];
queue<int> q;
int n, m;

signed main() {
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        out_degree[x]++;
        in_degree[y]++;
        node[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
            ans[i] = 1;
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < node[cur].size(); i++) {
            int num = node[cur][i];
            in_degree[num]--;
            ans[num] += ans[cur];
            ans[num] %= mod;
            if (in_degree[num] == 0) {
                q.push(num);
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (out_degree[i] == 0) {
            sum += ans[i];
            sum %= mod;
        }
    }
    cout << sum << endl;
    return 0;
}