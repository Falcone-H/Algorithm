// P2004 领地选择
// 思路：二维前缀和
#include<bits/stdc++.h>

#define int long long
using namespace std;
int n, m, c;
int a[1005][1005];
int f[1005][1005];

signed main() {
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
        }
    }
    int maxv = 0;
    int x = 0, y = 0;
    for (int i = 1; i <= n - c + 1; i++) {
        for (int j = 1; j <= m - c + 1; j++) {
            int val = f[i + c - 1][j + c - 1] - (f[i - 1][j + c - 1] + f[i + c - 1][j - 1] - f[i - 1][j - 1]);
            if (val > maxv) {
                maxv = val;
                x = i;
                y = j;
            }
        }
    }
    cout << x << " " << y << endl;
    return 0;
}