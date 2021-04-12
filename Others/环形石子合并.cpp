// 区间dp
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 410;

int f[N][N], g[N][N];
int s[N], w[N];
int n;

void init() {
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            if(i == j) {
                f[i][j] = g[i][j] = 0;
                continue;
            }
            f[i][j] = INT_MAX;
            g[i][j] = -INT_MAX;
        }
    }
}

signed main() {
    cin >> n;
    init();
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        w[i + n] = w[i];
    }

    for (int i = 1; i <= 2 * n; i++)
        s[i] = s[i - 1] + w[i];

    for (int len = 1; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n * 2; l++) {
            int r = l + len - 1;
            for (int k = l; k < r; k++) {
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
                g[l][r] = max(g[l][r], g[l][k] + g[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    }

    int maxv = -INT_MAX, minv = INT_MAX;
    for (int i = 1; i <= n; i++) {
        maxv = max(maxv, g[i][i + n - 1]);
        minv = min(minv, f[i][i + n - 1]);
    }

    cout << minv << endl << maxv << endl;

    return 0;
}