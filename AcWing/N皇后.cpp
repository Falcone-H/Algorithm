// https://www.acwing.com/problem/content/845/
// 思路：回溯算法
#include<bits/stdc++.h>
using namespace std;
const int N = 15;
int a[N][N];
int row[N], col[N];
map<int, int> leftm, rightm;  // left代表从左上角到右下角，right代表从右上角到左下角
// 对于坐标(x, y)
// 从左上角到右下角，x - y 相等
// 从右上角到左下角，x + y 相等
int n;

bool check(int x, int y) {  // x代表第几行，y代表第几列
    if(row[x])  return false;
    if(col[y])  return false;
    if(leftm[x - y]) return false;
    if(rightm[x + y]) return false;
    return true;
}

void update(int x, int y) {
    row[x] = !row[x];
    col[y] = !col[y];
    leftm[x - y] = !leftm[x - y];
    rightm[x + y] = !rightm[x + y];
}

void DFS(int step) {
    if(step == n + 1) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(a[i][j] == 1)
                    cout << 'Q';
                else
                    cout << '.';
            }
            cout << "\n";
        }
        cout << "\n";
        return ;
    }
    for(int i = 1; i <= n; i++) {
        if(check(step, i)) {
            a[step][i] = 1;
            update(step, i);
            DFS(step + 1);
            a[step][i] = 0;
            update(step, i);
        }
    }
}

int main() {
    cin >> n;
    DFS(1);
    return 0;
}