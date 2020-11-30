#include<iostream>

#define int long long
using namespace std;
const int Max = 1003;
int a[Max][Max];
int f[Max][Max];

signed main() {
    int n, m, c;
    cin >> n >> m >> c;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
        }
    }


    int k;
    cin >> k;
    for (int i = 1; i <= k; ++i) {
        int x1, x2, y1, y2;     // x1,y1是左上角的坐标，另一对是右下角的坐标
        cin >> x1 >> y1 >> x2 >> y2;
        cout << f[x2][y2] - f[x1 - 1][y2] - f[x2][y1 - 1] + f[x1 - 1][y1 - 1];
    }
    return 0;
}