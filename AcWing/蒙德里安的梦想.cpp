// https://www.acwing.com/problem/content/293/
// 思路：状压DP
// 讲解：https://lishizheng.blog.csdn.net/article/details/112706309
#include<bits/stdc++.h>

using namespace std;
const int N = 12, M = 1 << N;
long long f[N][M];  // f[i][j] 表示 当前在第 i 列（从 0 开始），第 j 个状态
bool st[M];
vector<int> state[M];   // 记录不冲突的状态
int n, m;

int main() {
    while (cin >> n >> m, n || m) {
        // 预处理
        for (int i = 0; i < (1 << n); i++) {
            int cnt = 0;
            bool isvalid = true;    // 某个状态没有奇数个连续的 0 则标记位 true
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {    // 如果状态 i 的第 j 位为 1
                    if (cnt & 1) { // cnt 为奇数
                        isvalid = false;
                        break;
                    }
                    cnt = 0;
                } else {
                    cnt++;
                }
            }
            if (cnt & 1) isvalid = false;    // 判断最后一段连续 0 的个数
            st[i] = isvalid;    // 记录当前状态是否合法
        }

        // 判断第 i - 2 列伸出来的，和第 i - 1 列伸出去的是否冲突
        for (int j = 0; j < (1 << n); j++) {
            // 对于第 i 列的所有状态
            state[j].clear();
            for (int k = 0; k < (1 << n); k++) {
                // 对于第 i - 1 列的所有状态
                if ((j & k) == 0 && st[j | k]) {
                    // 判断是否有重合的地方，以及同时存在这两种状态时，是否合法（即连续 0 的个数是否为奇数）
                    state[j].push_back(k);
                }
            }
        }

        memset(f, 0, sizeof f);
        f[0][0] = 1;    // 即在第 0 列没有横着摆的情况，只能竖着摆
        for (int i = 1; i <= m; i++) {   // 遍历每一列
            for (int j = 0; j < (1 << n); j++) { // 遍历第 i 列的所有状态
                for (auto k : state[j]) {    // 取出于状态 j 不冲突的，第 i - 1 列的状态 k
                    f[i][j] += f[i - 1][k];
                }
            }
        }

        // f[m][0] 表示前 m - 1 列都处理完，且第 m - 1 列没有伸出到第 m 列的方案数
        cout << f[m][0] << endl;
    }
    return 0;
}