// https://www.acwing.com/activity/content/problem/content/822/1/
// 思路：归并排序
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int a[N];
int n;
int ans;

void merge(int l, int mid, int r) {
    int temp[r - l + 5];
    int index = 0;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] > a[j]) {
            temp[index++] = a[j++];
            ans += mid - i + 1;
        } else {
            temp[index++] = a[i++];
        }
    }
    while (i <= mid)
        temp[index++] = a[i++];
    while (j <= r)
        temp[index++] = a[j++];
    for (int k = l; k <= r; k++) {
        a[k] = temp[k - l];
    }
}

void merge_sort(int l, int r) {
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    merge(l, mid, r);
}

signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    merge_sort(0, n - 1);
    cout << ans << "\n";
    return 0;
}