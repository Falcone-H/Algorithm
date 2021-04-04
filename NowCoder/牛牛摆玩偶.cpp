// https://ac.nowcoder.com/acm/contest/9475/B
// 思路：假设玩偶之间最小间隔 D 是这道题的答案，那么间隔比 D 小的数，一定都是合法的（所有玩偶都可以摆放进去），比 D 大的数，都是不合法的。
//      那么，可以在 1(left) 到 位置的最大值(right) 之间二分查找。二分查找的过程中检查该值是否合法，从而找出最大值。
#include<bits/stdc++.h>

using namespace std;

struct Interval {
    int start;
    int end;

    Interval(int s, int e) : start(s), end(e) {};
};

bool cmp(Interval a, Interval b) {
    return a.start < b.start;
}

bool check(vector<Interval> &intervals, int cur, int n) {
    long long now = intervals[0].start;
    int cnt = 0;
    for (int i = 0; i < intervals.size(); i++) {
        if (now > intervals[i].end)
            continue;
        now = max((long long) intervals[i].start, now);
        int nums = (intervals[i].end - now) / cur + 1;
        cnt += nums;
        now += nums * cur;
    }
    return cur >= n;
}

int doll(int n, int m, vector<Interval> &intervals) {
    sort(intervals.begin(), intervals.end(), cmp);
    long long left = 0, right = INT_MAX;
    long long mid;
    long long ans = 0;
    while (left < right) {
        mid = (left + right) / 2;
        if (check(intervals, mid, n)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<Interval> intervals;
    for(int i = 0;i<m;i++){
        int l, r;
        cin >> l >> r;
        intervals.push_back(Interval(l, r));
    }
    int ans = doll(n, m, intervals);
    cout << ans << endl;
    return 0;
}