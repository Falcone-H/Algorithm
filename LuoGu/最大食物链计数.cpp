//P4017 ���ʳ��������
//˼·�����������Ϊ�㣨�����ߣ��ĵ������У�Ȼ������������ܵ���ĵ㣬����Щ�ܵ���ĵ����ȼ�һ�������Щ�����ȱ�Ϊ�㣬�������У��ظ��ղŵĲ���
//      ��󣬽����г���Ϊ��ĵ㣨���յ������ߣ����ܵ���Ĵ�����ans�������������ɵõ��𰸡�
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 80112002;
int out_degree[5005];   //����
int in_degree[5005];    //���
int ans[5005];  //��¼ÿ���㱻���ʵĴ���
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