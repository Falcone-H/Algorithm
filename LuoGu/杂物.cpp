//P1113 杂务
//思路：记录每个点的入度，每当之前有一项工作完成，该点的入度便减一，直到入度为零，便加入队列，完成该工作
#include<bits/stdc++.h>

using namespace std;
int indegree[10005];    //入度
int cus[10005]; //消耗时间
int ans[10005]; //答案
vector<int> node[10005];    //记录以该点为入度的点

int main() {
    int n;
    cin >> n;
    int x, z;
    int start;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x >> cus[i] >> z;
        ans[i] = cus[i];
        while (z != 0) {
            indegree[x]++;
            node[z].push_back(x);
            cin >> z;
        }
        if (indegree[x] == 0)
            start = x;
    }
    queue<int> q;
    q.push(start);
    int maxv = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < node[cur].size(); i++) {
            int num = node[cur][i];
            indegree[num]--;
            ans[num] = max(ans[num], ans[cur] + cus[num]);
            maxv = max(maxv, ans[num]);
            if(indegree[num] == 0) {
                q.push(num);
            }
        }
    }
    cout << maxv << endl;
    return 0;
}