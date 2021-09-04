// https://www.acwing.com/problem/content/description/274/
// 思路：线性dp
// f[i][j] 表示 A[1..i] 和 B[1..j] 中，且以 B[j] 结尾的最长公共上升子序列
// 当不包含 A[i] 时，f[i][j] = f[i - 1][j]
// 当包含 A[i] ，且 A[i] == B[j] 时，f[i][j] 为 f[i][1..j-1] 中，符合 a[i] > b[k] 的最大 f[i][k] + 1
#include<bits/stdc++.h>

using namespace std;
const int N = 3005;
int a[N], b[N];
int f[N][N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

//    朴素dp
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            f[i][j] = f[i - 1][j];
//            if (a[i] == b[j]) {
//                int maxv = 1;
//                for (int k = 1; k < j; k++) {
//                    if (a[i] > b[k]) maxv = max(maxv, f[i - 1][k]);
//                }
//                f[i][j] = maxv + 1;
//            }
//        }
//    }

//    优化
    for(int i = 1; i <= n; i++) {
        int maxv = 1;
        for(int j = 1; j <= n; j++) {
            f[i][j] = f[i - 1][j];
            if(a[i] == b[j])    f[i][j] = max(f[i][j], maxv);
            if(a[i] > b[j])     maxv = max(maxv, f[i - 1][j] + 1);
        }
    }


    int ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, f[n][i]);
    cout << ans << endl;
    return 0;
}