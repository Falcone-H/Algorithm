// POJ 3069
// 算法：贪心
#include<bits/stdc++.h>

using namespace std;
int n, r;
int x[1005];
int res;

void solve() {
    int i = 0;
    int left;
    while (i < n) {
        // 没有被覆盖的最左边的点
        left = x[i];
        // 找出可以覆盖left的最右边的点
        while (i < n && x[i] <= left + r)
            i++;
        // 标记
        res++;
        // 将left改为被标记的点的位置
        left = x[i - 1];
        // 找出被标记点覆盖的最右边的点
        while (i < n && x[i] <= left + r)
            i++;
        // 定位到没有被覆盖的最左边的点
        i++;
    }
}

int main() {
    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x, x + n);
    solve();
    cout << res << endl;
}