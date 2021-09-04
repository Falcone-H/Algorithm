// https://www.acwing.com/problem/content/910/
// 思路：将所有区间右端点从小到大排序，然后依次遍历，维护当前最右端点的值，如果有区间与当前右端点没有交集，则可以加入答案中
#include<bits/stdc++.h>
using namespace std;

struct Range{
    int l, r;
    bool operator < (const Range &a) {
        if(r == a.r) {
            return l < a.l;
        } else {
            return r < a.r;
        }
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

    int ed = -2e9;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(v[i].l > ed) {
            ans++;
            ed = v[i].r;
        }
    }
    cout << ans << endl;
    return 0;
}