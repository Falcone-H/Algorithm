// https://www.acwing.com/problem/content/description/124/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int a[N], c[N];
int n;
signed main() {
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int avg = sum / n;
    for(int i = 1; i <= n; i++)
        c[i] = c[i - 1] + a[i] - avg;
    sort(c + 1, c + n + 1);
    int ans = 0;
    int mid = c[(n >> 1) + 1];
    for(int i = 1; i <= n; i++)
        ans += abs(c[i] - mid);
    cout << ans << endl;
    return 0;
}