#include<bits/stdc++.h>

using namespace std;
vector<int> g[1005];
int color[1005];
int n, m;

//�Ѷ���Ⱦ��1��-1
bool dfs(int s, int flag) {
    color[s] = flag;    //������sȾɫ
    for (int i = 0; i < g[s].size(); i++) {
        if (color[g[s][i]] == 0) {  //������ڶ��㻹û��Ⱦɫ����Ⱦ��-flag
            if (!dfs(g[s][i], -flag))
                return false;
        }
        if (color[g[s][i]] == flag) //������ڶ���ͬɫ���򷵻�false
            return false;
    }
    return true;
}

void solve() {
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {    //�����ûȾɫ����Ⱦ��1
            if (!dfs(i, 1)) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    cin >> n;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
    }
    solve();
}