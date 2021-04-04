// https://atcoder.jp/contests/abc090/tasks/arc091_b?lang=en
// 思路：在 k+1 <= i <= n 的范围内，找出有多少个数对i取余，得到的结果是大于等于k的。
/*
比如，在 1 到 13 的范围内对 4 取余，
原序列:           1 2 3 4 5 6 7 8 9 10 11 12 13
对 4 取余后的序列: 1 2 3 0 1 2 3 0 1  2  3  0  1
可以看到，对 4 取余后得到的结果是循环的
一共有 13 / 4 = 3 份 1 2 3 0 这样的数，而其中大于等于 2 的数有 2 3 ， 一共为 4 - 2 个
所以，在这三份的数当中，一共有 3 * 2 个 大于等于 2 的数
最后，再计算出剩下的那一份中有多少个数是大于等于 2 的， 就能得到最终结果
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    if(k == 0) {    // 如果 k = 0，那么所有任意两个数取余都是大于等于它的，那么就有 n * n 个
        cout << n * n << endl;
        return 0;
    }
    for(int i = k + 1; i <= n; i++) {   // 因为对一个 小于等于k 的数取余，得到的结果也一定 小于等于k，因此从k+1开始
        int t = n / i;                  // 计算有多少份
        int r = n % i;                  // 计算最后那一部分有多少个数
        ans += t * (i - k) + (r >= k ? r - k + 1 : 0);  // 份数 * 每份中符合条件的个数 + 最后那部分中符合条件的个数
    }
    cout << ans << endl;
    return 0;
}