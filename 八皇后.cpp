#include<bits/stdc++.h>

# define IOS ios::sync_with_stdio(false)
using namespace std;
int Col[20], line1[200], line2[200];
int res[20];
int n;
int cnt;

bool isvalid(int row, int col) {
    if (Col[col])
        return 0;
    if (line1[row + col])
        return 0;
    if (line2[row - col + n])
        return 0;
    return 1;
}

void dfs(int row) {
    if (res[n] != 0) {
        if (cnt < 3) {
            for (int i = 1; i <= n; i++) {
                cout << res[i] << " ";
            }
            cout << endl;
        }
        cnt++;
    }
    for (int i = 1; i <= n; i++) {
        if (isvalid(row, i)) {
            Col[i] = 1;
            line1[row + i] = 1;
            line2[row - i + n] = 1;
            res[row] = i;

            dfs(row + 1);

            res[row] = 0;
            Col[i] = 0;
            line1[row + i] = 0;
            line2[row - i + n] = 0;
        }
    }
}

int main() {
    IOS;
    cin >> n;
    dfs(1);
    cout << cnt << endl;
    return 0;
}