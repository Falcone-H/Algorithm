// https://www.acwing.com/solution/content/4956/
// 性质：一定存在一组最优解，使得每一个 b[i] 都在 a数组 中出现过
#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N = 2010;
int n;
int a[N], b[N];
int f[N][N];    // f[i][j] 表示在 b[1..j-1] 的情况下，给 b[j] 分配的是 a'[j] 的情况。（a'数组是a数组按照从升序排序的情况）

int dp() {
    for (int i = 1; i <= n; i++) b[i] = a[i];
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        int minv = INT_MAX;
        for (int j = 1; j <= n; j++) {
            minv = min(minv, f[i - 1][j]);
            f[i][j] = minv + abs(a[i] - b[j]);
        }
    }

    int res = INT_MAX;
    for (int i = 1; i <= n; i++) res = min(res, f[n][i]);
    return res;
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int res = dp();
    reverse(a + 1, a + n + 1);
    res = min(res, dp());
    cout << res << endl;
    return 0;
}