// https://www.acwing.com/solution/content/1148/
// 思路：二分
#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int cows[N];
double sum[N];
int n, m;

bool check(double avg) {
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + cows[i] - avg;
    double minv = 2e9;
    for (int i = 0, j = m; j <= n; i++, j++) {
        minv = min(minv, sum[i]);
        if (sum[j] - minv >= 0) return true;
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> cows[i];
    double l = 0, r = 2000;
    while (r - l > 1e-5) {
        double mid = (r + l) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << (int) (r * 1000) << endl;
    return 0;
}