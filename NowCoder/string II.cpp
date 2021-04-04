// https://ac.nowcoder.com/acm/contest/9715/B
// 思路：尝试将字符串中的每个字母都转化成同一个字母。
//      首先求字符串中，与该字母绝对值相等的字母个数，再求相差1的字母个数，再求相差2的字母个数，一直到26。
#include<bits/stdc++.h>

#define int long long
using namespace std;

int solve(int k, string s) {
    int n = s.length();
    int ans = 0;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        int cur = 0;
        int tmp = k;
        for (int dis = 0; dis < 26; dis++) {
            for (int i = 0; i < n; i++) {
                if (abs(s[i] - ch) == dis && tmp >= dis) {
                    tmp -= dis;
                    cur++;
                }
            }
        }
        ans = max(ans, cur);
    }
    return ans;
}

signed main() {
    int k;
    string s;
    cin >> k;
    cin >> s;
    cout << solve(k, s) << endl;
    return 0;
}
