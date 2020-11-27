// https://ac.nowcoder.com/acm/contest/9475/B
// ˼·��������ż֮����С��� D �������Ĵ𰸣���ô����� D С������һ�����ǺϷ��ģ�������ż�����԰ڷŽ�ȥ������ D ����������ǲ��Ϸ��ġ�
//      ��ô�������� 1(left) �� λ�õ����ֵ(right) ֮����ֲ��ҡ����ֲ��ҵĹ����м���ֵ�Ƿ�Ϸ����Ӷ��ҳ����ֵ��
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