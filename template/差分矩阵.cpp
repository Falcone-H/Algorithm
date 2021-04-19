#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define tie cin.tie(0), cout.tie(0)
using namespace std;
const int N = 1005;
int n, m, q;
int a[N][N];    // 原二维矩阵
int sub[N][N];  // 差分矩阵
int sum[N][N];  // 差分矩阵的二维前缀和，即原二维矩阵变化后得到的矩阵

void insert(int x1, int y1, int x2, int y2, int c) {
    sub[x1][y1] += c;
    sub[x2 + 1][y1] -= c;
    sub[x1][y2 + 1] -= c;
    sub[x2 + 1][y2 + 1] += c;
}

int main() {
    IOS;
    tie;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            insert(i, j, i, j, a[i][j]);    // 把原二维矩阵看作全部为0，每次输入一个值，都看作是在当前位置的一个 1 * 1 的矩阵内的值发生改变
        }
    }
    while (q--) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }

    // 求差分矩阵的二维前缀和
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + sub[i][j];
            cout << sum[i][j] << " ";
        }
        cout << "\n";
    }
}