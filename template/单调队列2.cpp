// https://www.acwing.com/problem/content/156/
// 思路：单调队列，一直保留着区间长度为 k 的数组中，最大或最小的数
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, k;
int q[N];   // 存下标
int a[N];
int head, tail;
int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    head = 0, tail = -1;
    for(int i = 0; i < n; i++) {
        if(head <= tail && i - q[head] + 1 > k)
            head++;
        while(head <= tail && a[q[tail]] >= a[i])
            tail--;
        q[++tail] = i;
        if(i >= k - 1)
            cout << a[q[head]] << " ";
    }
    cout << endl;

    head  = 0, tail = -1;
    for(int i = 0; i < n; i++) {
        if(head <= tail && i - q[head] + 1 > k)
            head++;
        while(head <= tail && a[q[tail]] <= a[i])
            tail--;
        q[++tail] = i;
        if(i >= k - 1)
            cout << a[q[head]] << " ";
    }
    cout << endl;

    return 0;
}