#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100005;
int number[N];
struct Tree {
    int sum;
    int left;
    int right;
    int lazy;
} tree[4 * N + 2];

inline void update(int i) {
    tree[i].sum = tree[i << 1].sum + tree[i << 1 | 1].sum;
}

inline void pushdown(int i) {
    if (tree[i].lazy != 0) {
        tree[i << 1].lazy += tree[i].lazy;
        tree[i << 1 | 1].lazy += tree[i].lazy;
        tree[i << 1].sum += tree[i].lazy * (tree[i << 1].right - tree[i << 1].left + 1);
        tree[i << 1 | 1].sum += tree[i].lazy * (tree[i << 1 | 1].right - tree[i << 1 |1].left + 1);
        tree[i].lazy = 0;
    }
}

inline void build(int i, int left, int right) {
    tree[i].left = left;
    tree[i].right = right;
    if (left == right) {
        tree[i].sum = number[left];
        return;
    }
    int mid = (left + right) >> 1;
    build(i << 1, left, mid);
    build(i << 1 | 1, mid + 1, right);
    update(i);
}

inline int query(int i, int left, int right) {
    if (tree[i].left >= left && tree[i].right <= right)
        return tree[i].sum;
    if (tree[i].right < left || tree[i].left > right)
        return 0;
    pushdown(i);
    int sum = 0;
    if (tree[i << 1].right >= left)
        sum += query(i << 1, left, right);
    if (tree[i << 1 | 1].left <= right)
        sum += query(i << 1 | 1, left, right);
    return sum;
}

inline void change(int i, int left, int right, int x) {
    if (tree[i].left >= left && tree[i].right <= right) {
        tree[i].sum += x * (tree[i].right - tree[i].left + 1);
        tree[i].lazy += x;
        return;
    }
    pushdown(i);
    if (tree[i << 1].right >= left)
        change(i << 1, left, right, x);
    if (tree[i << 1 | 1].left <= right)
        change(i << 1 | 1, left, right, x);
    update(i);
}

signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> number[i];
    }
    build(1, 1, n);
    int x, l, r;
    for (int i = 1; i <= m; i++) {
        cin >> x >> l >> r;
        if (x == 1) {
            int v;
            cin >> v;
            change(1, l, r, v);
        } else if (x == 2) {
            cout << query(1, l, r) << endl;
        }
    }
    return 0;
}