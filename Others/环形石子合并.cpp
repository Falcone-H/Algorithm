// 区间dp
#include<bits/stdc++.h>

using namespace std;
const int N = 1005;
int f[N][N], g[N][N];   // f 记录最小值， g 记录最大值
int sum[N], w[N];
int n;

void init() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == j) {
                f[i][j] = g[i][j] = 0;
            } else {
                f[i][j] = 0x3f;
                g[i][j] = 0xcf;
            }
        }
    }
}

int main() {
    cin >> n;
    init();
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        w[i + n] = w[i];
    }

    for (int i = 1; i <= 2 * n; i++) {
        sum[i] = sum[i - 1] + w[i];
    }

    for (int len = 1; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n * 2; l++) {
            int r = l + len - 1;
            for (int k = l; k <= r; k++) {
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + sum[r] - sum[l - 1]);
                g[l][r] = max(g[l][r], g[l][k] + g[k + 1][r] + sum[r] - sum[l - 1]);
            }
        }
    }

    int maxv = -INT_MAX, minv = INT_MAX;

    for (int i = 1; i <= n; i++) {
        maxv = max(maxv, g[i][i + n - 1]);
        minv = min(minv, f[i][i + n - 1]);
    }

    cout << minv << "\n";
    cout << maxv << "\n";
    return 0;
}