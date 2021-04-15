/*
 * 步骤：
 * 1、 确定分界点 x
 * 2、 调整区间，将小于 x 的数放在左区间，大于 x 的数放在右区间
 * 3、 递归处理左右两端
 */

#include<bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;
int n;
int a[N];

void quick_sort(int l, int r) {
    if (l >= r)
        return;
    int x = a[(l + r) >> 1];
    int i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (a[i] < x);
        do j--; while (a[j] > x);
        if (i < j)
            swap(a[i], a[j]);
    }
    quick_sort(l, j);
    quick_sort(j + 1, r);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quick_sort(0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
}