// https://www.luogu.com.cn/problem/P1439
// 思路：1、因为这题的数据范围在 1e5，所以直接用朴素的线性DP会超时
//      2、这一题中，出现的数字都是唯一的，因此可以先用离散化处理
//      3、比如，3 2 1 4 5 对应的离散化后的数字是 1 2 3 4 5
//      4、在 2 1 4 3 5 中，对应上面离散化后的数字，就是 2 3 4 1 5
//      5、可以发现，在a序列中离散化后的数字一定是上升序列，那么在b的序列中，对应的离散化标记也一定会是一个上升序列
//      6、就比如上面第四点，最长上升子序列是 2 3 4 5，对应在 a 中的数字就是 2 1 4 5
//      7、因此，a序列和b序列的最长公共子序列就是 2 1 4 5

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N];
int dp[N];
int n;
map<int, int> m;
vector<int> v;

int solve() {
    for(int i = 0; i <= n; i++)
        dp[i] = INT_MAX;
    for(int i = 0; i < v.size(); i++) {
        *lower_bound(dp, dp + n, v[i]) = v[i];
    }
    return lower_bound(dp, dp + n, INT_MAX) - dp;
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        m[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        int x = m[b[i]];
        v.push_back(x);
    }
    cout << solve() << endl;
    return 0;
}