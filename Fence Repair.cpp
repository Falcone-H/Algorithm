// POJ 3253
// 算法：贪心
// 思路：每次都选取最小的两个数字，保证每次相加得到的和最小，再把和加入优先队列。

#include <iostream> // 专治POJ不兼容万能头
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstdio>
#define int long long

using namespace std;

priority_queue<int, vector<int>, greater<int>> q;
int n, num, res;
signed main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num;
        q.push(num);
    }
    while(q.size() > 1){
        int q1 = q.top();
        q.pop();
        int q2 = q.top();
        q.pop();
        res += (q1 + q2);
        q.push(q1 + q2);
    }
    cout << res << endl;
    return 0;
}