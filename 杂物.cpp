//P1113 ����
//˼·����¼ÿ�������ȣ�ÿ��֮ǰ��һ�����ɣ��õ����ȱ��һ��ֱ�����Ϊ�㣬�������У���ɸù���
#include<bits/stdc++.h>

using namespace std;
int indegree[10005];    //���
int cus[10005]; //����ʱ��
int ans[10005]; //��
vector<int> node[10005];    //��¼�Ըõ�Ϊ��ȵĵ�

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