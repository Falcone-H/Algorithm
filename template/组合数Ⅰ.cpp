// acwing.com/problem/content/887/
// 1 <= n <= 10000, 1 <= b, a <= 2000
#include<bits/stdc++.h>

using namespace std;
const int N = 2010;
const int mod = 1e9 + 7;
int c[N][N];

int main() {
    for (int i = 0; i <= 2005; i++) {
        for (int j = 0; j <= i; j++) {
            if (!j) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << c[a][b] << "\n";
    }
    return 0;
}