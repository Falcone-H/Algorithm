// POJ 2456
// 思路：二分
#include<bits/stdc++.h>
using namespace std;
int a[10005];
int n, m;
int maxv;

bool check(int dis) {
    int cur = 0;    // 将第一头牛放在第一个位置
    for(int i = 1; i < m; i++) {
        int temp = cur + 1;  // 找到下一个间隔大于等于 dis 的位置
        while(a[temp] - a[cur] < dis && temp < n)
            temp++;
        if(temp == n)
            return false;
        cur = temp;     // 已经找到合适的位置，更新当前位置
    }
    return true;
}

void solve() {
    int left = 0;
    int right = maxv;
    while(left < right - 1) {
        int mid = (left + right) / 2;
        if(check(mid))  // 比最大合法距离小的数都会合法
            left = mid;
        else
            right = mid;
    }
    cout << left << endl;
    return;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        maxv = max(a[i], maxv);
    }
    sort(a, a + n);
    solve();
    return 0;
}