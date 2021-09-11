// https://www.acwing.com/problem/content/109/
// 思路：归并排序，逆序对
#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N = 5e5 + 5;
int a[N];
int ans;

void merge(int l, int mid, int r) {
    int tmp[r - l + 5];
    int idx = 0;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] > a[j]) {
            ans += (mid - i + 1);
            tmp[idx++] = a[j++];
        } else {
            tmp[idx++] = a[i++];
        }
    }
    while (i <= mid) tmp[idx++] = a[i++];
    while (j <= r) tmp[idx++] = a[j++];
    for (int k = l; k <= r; k++) {
        a[k] = tmp[k - l];
    }
}

void merge_sort(int l, int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    merge(l, mid, r);
}

signed main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        ans = 0;
        for (int i = 0; i < n; i++) cin >> a[i];
        merge_sort(0, n - 1);
        cout << ans << "\n";
    }
    return 0;
}