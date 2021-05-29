// https://www.acwing.com/problem/content/description/93/
// 思路：状压DP
#include<bits/stdc++.h>
using namespace std;
const int N = 20, M = 1 << N;
int n;
int w[N][N];
int f[M][N];    // f[i][j] 表示状态 i，最后到达点 j

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> w[i][j];

    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;

    for(int i = 0; i < (1 << n); i++) {
        for(int j = 0; j < n; j++) {
            if(i >> j & 1) {
                for(int k = 0; k < n; k++) {
                    if(i >> k & 1)
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);
                }
            }
        }
    }

    cout << f[(1 << n) - 1][n - 1] << endl;
    return 0;
}