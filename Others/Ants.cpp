//POJ NO.1852
//可以假设蚂蚁相遇后不会返回，因为两只蚂蚁相遇后回头，其实和两只蚂蚁交身而过是一样的...

#include<iostream>

#define int long long
using namespace std;

signed main() {
    int m;
    cin >> m;
    while (m--) {
        int l;
        int n;
        int maxv = INT_MIN, minv = INT_MIN;
        int maxn, minn;
        int num;
        cin >> l >> n;
        for (int i = 0; i < n; i++) {
            cin >> num;
            maxn = max(num, l - num);   //记录每一只蚂蚁与两端的最大值
            minn = min(num, l - num);   //记录每一只蚂蚁与两端的最小值
            minv = max(minn, minv);     //记录所有minn中的最大值
            maxv = max(maxn, maxv);     //记录所有maxn中的最大值
        }
        cout << minv << " " << maxv << endl;
    }
    return 0;
}