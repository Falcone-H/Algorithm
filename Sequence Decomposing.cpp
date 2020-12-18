// https://atcoder.jp/contests/abc134/tasks/abc134_e
// 思路：找出这个数组能组成多少个最长上升子序列
#include<bits/stdc++.h>

#define int long long
using namespace std;
int a[100005];
signed main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    multiset<int> ms;
    /*
    multiset是<set>库中一个非常有用的类型，它可以看成一个序列，插入一个数，
    删除一个数都能够在O(logn)的时间内完成，而且他能时刻保证序列中的数是
    有序的，而且序列中可以存在重复的数。
    默认为从小到大排序。
     */
    for(int i = 0; i < n; i++) {
        auto it = ms.lower_bound(a[i]);     // 找出第一个大于等于a[i]的数
        if(it == ms.begin()) {              // 如果这个数在开始位置，说明后面的数都是大于或者等于它的，所以应该再开一个最长子序列
            ms.insert(a[i]);
        } else {
            it--;
            ms.erase(it);
            ms.insert(a[i]);                // 替换掉最后一个比它小的数，维护最长上升子序列
        }
    }
    cout << ms.size() << endl;
    return 0;
}