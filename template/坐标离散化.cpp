// https://blog.csdn.net/m0_46201544/article/details/116319580
#include<bits/stdc++.h>

using namespace std;
const int MAX_N = 505;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// 输入
int W, H, N;
int X1[MAX_N], X2[MAX_N], Y1[MAX_N], Y2[MAX_N];

// 坐标离散化后的地图
bool fld[MAX_N * 6][MAX_N * 6];

// 对 x1 和 x2 进行坐标离散化，并返回离散化之后的宽度
int compress(int *x1, int *x2, int w) {
    vector<int> xs;

    // 加上 d = -1 和 d = 1 的目的是，使直线与直线之间产生空隙，还原之前的地图
    // 如果不加，每条直线都会紧挨在一起，无法进行宽搜
    for (int i = 0; i < N; i++) {
        for (int d = -1; d <= 1; d++) {
            int tx1 = x1[i] + d;
            int tx2 = x2[i] + d;
            if (1 <= tx1 && tx1 <= W) xs.push_back(tx1);
            if (1 <= tx2 && tx2 <= W) xs.push_back(tx2);
        }
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    for (int i = 0; i < N; i++) {
        x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
        x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
    }

    return xs.size();
}

void solve() {
    // 坐标离散化
    W = compress(X1, X2, W);
    H = compress(Y1, Y2, H);

    // 填充有直线的部分
    memset(fld, 0, sizeof fld);
    for (int i = 0; i < N; i++) {
        for (int y = Y1[i]; y <= Y2[i]; y++) {
            for (int x = X1[i]; x <= X2[i]; x++) {
                fld[y][x] = true;
            }
        }
    }

    // 求区域个数
    int ans = 0;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (fld[y][x]) continue;
            ans++;

            queue<pair<int, int>> q;
            q.push({x, y});
            while (!q.empty()) {
                int sx = q.front().first;
                int sy = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int tx = sx + dx[i];
                    int ty = sy + dy[i];

                    if (tx < 0 || W <= tx || ty < 0 || H <= ty)
                        continue;

                    if (fld[ty][tx]) continue;

                    q.push({tx, ty});
                    fld[ty][tx] = true;
                }
            }
        }
    }
    printf("%d\n", ans);
}

int main() {

}