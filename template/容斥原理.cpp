// https://www.acwing.com/problem/content/892/
#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N = 20;
int p[N];

signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> p[i];
    int res = 0;
    for (int i = 1; i < (1 << m); i++) {
        int cnt = 0;
        int tmp = 1;
        for (int j = 0; j < m; j++) {
            if ((i >> j) & 1) {
                if (tmp * p[j] > n) {
                    tmp = -1;
                    break;
                }
                tmp *= p[j];
                cnt++;
            }
        }
        if(tmp == -1)   continue;

        if(cnt & 1) res += n / tmp;
        else    res -= n / tmp;
    }
    cout << res << endl;
    return 0;
}