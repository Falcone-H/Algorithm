// https://www.acwing.com/problem/content/907/
// 思路：将所有区间的右端点从小到大排序，然后遍历所有区间，动态改变当前最右端点的值，
// 如果下一个区间的左端点比当前的最右端值大，则 ans++
#include<bits/stdc++.h>
using namespace std;

struct Range{
    int l, r;
    bool operator < (const Range &a) {
        return r < a.r;
    }
};

int main() {
    int n;
    cin >> n;
    vector<Range> v;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int ed = -2e9;
    for(int i = 0; i < n; i++) {
        if(v[i].l > ed) {
            ans++;
            ed = v[i].r;
        }
    }
    cout << ans << endl;
    return 0;
}