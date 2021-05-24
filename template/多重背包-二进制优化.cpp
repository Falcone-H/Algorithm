// https://www.acwing.com/problem/content/5/
#include<bits/stdc++.h>

using namespace std;
const int N = 2010;
struct Good {
    int v, w;
};
int dp[N];
int n, m;

int main() {
    vector<Good> goods;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int v, w, s;
        cin >> v >> w >> s;
        for (int k = 1; k <= s; k *= 2) {
            s -= k;
            goods.push_back({v * k, w * k});
        }
        if (s > 0)
            goods.push_back({v * s, w * s});
    }
    for (auto good : goods) {
        for (int j = m; j >= good.v; --j) {
            dp[j] = max(dp[j], dp[j - good.v] + good.w);
        }
    }
    cout << dp[m] << endl;
    return 0;
}