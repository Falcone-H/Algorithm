#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int n;
vector<pair<int, int>> v, res;

void Merge(vector<pair<int, int>> &v) {
    sort(v.begin(), v.end());
    int l = -2e9, r = -2e9; // 区间的左端点和右端点
    for (auto item : v) {
        if (r < item.first) {    // 如果下一个区间与当前区间没有交集，则把上一个区间加入答案中；把左右端点移到下一个区间
            if (l != -2e9) {
                res.push_back({l, r});
            }
            l = item.first;
            r = item.second;
        } else {                // 如果下一个区间与当前区间有交集，则合并
            r = max(r, item.second);
        }
    }
    if (l != -2e9)
        res.push_back({l, r});
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        v.push_back({l, r});
    }
    Merge(v);
    cout << res.size() << "\n";
    return 0;
}