#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
using namespace std;
const int N = 15;
int n, m;
vector<string> v;
int dp[N][N];

int query(string t, int lit) {
    int ans = 0;
    for (auto s : v) {
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]));
            }
        }
        if(dp[s.size()][t.size()] <= lit)
            ans++;
    }
    return ans;
}

int main() {
    IOS;
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        v.push_back(s);
    }
    for (int i = 0; i < N; i++)
        dp[i][0] = i;
    for (int j = 0; j < N; j++)
        dp[0][j] = j;
    int x;
    for (int i = 0; i < m; i++) {
        cin >> s >> x;
        cout << query(s, x) << "\n";
    }
    return 0;
}