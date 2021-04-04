// P3397 地毯
// 思路：输入两个坐标之后，对每一行都进行差分，sub[y1]++; sub[y2 + 1]--;
#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false)
using namespace std;
int num[1005][1005];
int sub[1005][1005];

int main() {
    IOS;
    int n, m;
    cin >> n >> m;
    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i <= x2; i++) {
            sub[i][y1]++;
            sub[i][y2 + 1]--;
        }
    }
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += sub[i][j];
            if(j == 1) {
                cout << sum;
            }
            else {
                cout << " " << sum;
            }
        }
        cout << endl;
    }
    return 0;
}