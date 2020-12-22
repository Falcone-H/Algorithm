// POJ 1064
// 思路：可以用 { 0，max(a[i]) } 这个区间进行二分，找到能被分割成k份的最大长度
#include<bits/stdc++.h>
using namespace std;
double a[10005];
int n, k;

bool check(double len) {
    int num = 0;
    for(int i = 0; i < n; i++) {
        num += (int)(a[i] / len);
    }
    return num >= k;
}

void solve() {
    double left = 0, right = 10000005;
    for(int i = 0; i < 100; i++) {
        double mid = (left + right) / 2;
        if(check(mid))
            left = mid;
        else
            right = mid;
    }
    cout << floor(right * 100) / 100 << endl;
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve();
}