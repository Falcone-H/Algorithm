// https://ac.nowcoder.com/acm/contest/9925/G
// 思路：https://blog.csdn.net/weixin_45780686/article/details/111300784


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