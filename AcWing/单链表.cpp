// https://www.acwing.com/problem/content/828/
// 思路：数组模拟链表
#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int a[N], p[N];
int cnt = 1;
int pre = -1;

int main() {
    int m;
    cin >> m;
    int t = m;
    while (t--) {
        int x, k;
        char oper;
        cin >> oper;
        if (oper == 'H') {
            cin >> x;
            a[cnt] = x;
            p[cnt] = pre;
            pre = cnt++;
        } else if (oper == 'D') {
            cin >> k;
            if (k == 0) {
                int head = pre;
                pre = p[head];
                continue;
            }
            int pos = p[k];
            a[pos] = 0;
            p[k] = p[pos];
            p[pos] = 0;
        } else if (oper == 'I') {
            cin >> k >> x;
            a[cnt] = x;
            p[cnt] = p[k];
            p[k] = cnt++;
        }
    }
    int pos = pre;
    while (pos != -1) {
        cout << a[pos] << " ";
        pos = p[pos];
    }
    cout << endl;
    return 0;
}