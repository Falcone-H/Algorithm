// http://poj.org/problem?id=3279
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

const int N = 20;
int m, n;
int g[N][N];    // 原状态
int flip[N][N]; // 记录每个格子是否被翻转
int opt[N][N];  // 记录最终的方案
int dir[5][2] = {{1,  0},
                 {-1, 0},
                 {0,  1},
                 {0,  -1},
                 {0,  0}};

// 查看 (x, y) 是否为黑色
int get(int x, int y) {
    int c = g[x][y];
    for (int i = 0; i < 5; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (tx >= 0 && tx < m && ty >= 0 && ty < n) {
            c += flip[tx][ty];
        }
    }
    return c % 2;
}

// 计算方案中被翻转的次数
int calc() {
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // 如果 (i - 1, j) 为黑色，则 (i, j) 必须要翻转
            if (get(i - 1, j)) {
                flip[i][j] = 1;
            }
        }
    }

    // 检查最后一行是否全为白色
    for (int j = 0; j < n; j++) {
        if (get(m - 1, j)) {
            return -1;
        }
    }

    // 计算翻转的总次数
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum += flip[i][j];
        }
    }

    return sum;
}

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
        }
    }

    int ans = 2e9;

    // 先确定第一行的方案
    for (int i = 0; i < (1 << n); i++) {
        memset(flip, 0, sizeof flip);
        for (int j = 0; j < n; j++) {
            flip[0][n - 1 - j] = (i >> j) & 1;
        }
        int num = calc();
        if (num != -1 && num < ans) {
            ans = num;
            memcpy(opt, flip, sizeof flip);
        }
    }

    if (ans == 2e9) {
        printf("IMPOSSIBLE\n");
    } else {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", opt[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}