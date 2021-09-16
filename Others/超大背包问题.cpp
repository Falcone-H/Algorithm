/*
 * 超大背包问题
 * 有重量和价值分别为 wi, vi 的 n 个物品。
 * 从这些物品中挑选总重量不超过 W 的物品，求所有挑选方案中价值总和的最大值
 * 1 <= n <= 40
 * 1 <= wi, vi <= 1e15
 * 1 <= W <= 1e15
 *
 * 思路：折半枚举
 */


#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N = 50;

// 输入
int w[N], v[N];
int n, W;

// 重量，价值
pair<int, int> ps[1 << (N / 2)];

void solve() {
    // 枚举前半部分
    int n2 = n / 2;
    for (int i = 0; i < (1 << n2); i++) {
        int sw = 0, sv = 0;
        for (int j = 0; j < n2; j++) {
            if (i >> j & 1) {
                sw += w[j];
                sv += v[j];
            }
        }
        ps[i] = {sw, sv};
    }

    // 去除多余的元素
    sort(ps, ps + (1 << n2));
    int m = 1;
    for (int i = 1; i < (1 << n2); i++) {
        if (ps[m - 1].second < ps[i].second) {
            ps[m++] = ps[i];
        }
    }

    // 枚举后半部分并求解
    int ans = 0;
    for (int i = 0; i < (1 << (n - n2)); i++) {
        int sw = 0, sv = 0;
        for (int j = 0; j < n - n2; j++) {
            if (i >> j & 1) {
                sw += w[n2 + j];
                sv += v[n2 + j];
            }
        }
        if (sw <= W) {
            int tv = (lower_bound(ps, ps + m, make_pair(W - sw, 2e9)) - 1)->second;
            ans = max(ans, sv + tv);
        }
    }
}

signed main() {
    solve();
    return 0;
}