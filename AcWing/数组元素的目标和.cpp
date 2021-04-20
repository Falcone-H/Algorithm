// https://www.acwing.com/problem/content/description/802/
// 思路：双指针，一个指向a数组的头，一个指向b数组的尾
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N];
int n, m, x;
int main() {
    cin >> n >> m >> x;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];
    int l = 0, r = m - 1;
    while(r >= 0 && l <= n - 1) {
        r--;
        while(a[l] + b[r] < x) {
            l++;
        }
        if(a[l] + b[r] == x) {
            cout << l << " " << r << "\n";
            break;
        }
    }
    return 0;
}