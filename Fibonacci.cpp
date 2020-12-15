// https://ac.nowcoder.com/acm/contest/9925/G
// 思路：一个斐波那契数列为1，1，2，3，5，8，13，21...
// 算了，明天再写

#include<bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    int n;
    cin >> n;
    int ans = 0;
    int x = n / 3;
    ans += x * n - ((3 + 3 * x) * x) / 2;
    int x1 = x, x2 = x;
    if (n % 3 == 2) {
        x1++;
        x2++;
    } else if (n % 3 == 1) {
        x1++;
    }
    ans += x1 * x - x1 * (x1 - 1) / 2;
    ans += x2 * x - x2 * (x2 - 1) / 2;
    cout << ans << endl;
    return 0;
}