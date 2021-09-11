// https://www.acwing.com/solution/content/9524/
// c[i] = c[i - 1] + a[i] - avg
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, m, t;
int row[N], col[N], tmp[N];

signed main() {
    cin >> n >> m >> t;
    for (int i = 1; i <= t; i++) {
        int x, y;
        cin >> x >> y;
        row[x]++, col[y]++;
    }
    int res1 = -1;
    if (t % n == 0) {
        int sum = 0;
        for (int i = 1; i <= n; i++)
            sum += row[i];
        int avg = sum / n;
        for (int i = 1; i <= n; i++)
            tmp[i] = tmp[i - 1] + row[i] - avg;
        sort(tmp + 1, tmp + 1 + n);
        int mid = tmp[(n >> 1) + 1];
        res1 = 0;
        for (int i = 1; i <= n; i++)
            res1 += abs(mid - tmp[i]);
    }
    int res2 = -1;
    if (t % m == 0) {
        int sum = 0;
        for (int i = 1; i <= m; i++)
            sum += col[i];
        int avg = sum / m;
        for (int i = 1; i <= m; i++)
            tmp[i] = tmp[i - 1] + col[i] - avg;
        sort(tmp + 1, tmp + m + 1);
        int mid = tmp[(m >> 1) + 1];
        res2 = 0;
        for (int i = 1; i <= m; i++)
            res2 += abs(mid - tmp[i]);
    }
    if (res1 != -1 && res2 != -1) {
        cout << "both ";
        cout << res1 + res2 << endl;
    } else if (res1 != -1) {
        cout << "row ";
        cout << res1 << endl;
    } else if (res2 != -1) {
        cout << "column ";
        cout << res2 << endl;
    } else {
        cout << "impossible" << endl;
    }
    return 0;
}