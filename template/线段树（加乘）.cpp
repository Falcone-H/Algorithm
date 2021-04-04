#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N = 100005;
int mod;
int number[N];
struct Tree {
    int sum;
    int left;
    int right;
    int lazy, mul;
} tree[4 * N + 2];

inline void update(int i) {
    tree[i].sum = tree[i << 1].sum + tree[i << 1 | 1].sum;
}

inline void pushdown(int i) {
    if (tree[i].lazy != 0 || tree[i].mul != 1) {
        tree[i << 1].sum *= tree[i].mul;
        tree[i << 1].sum += tree[i].lazy * (tree[i << 1].right - tree[i << 1].left + 1);
        tree[i << 1].sum %= mod;
        tree[i << 1 | 1].sum *= tree[i].mul;
        tree[i << 1 | 1].sum += tree[i].lazy * (tree[i << 1 | 1].right - tree[i << 1 | 1].left + 1);
        tree[i << 1 | 1].sum %= mod;

        tree[i << 1].mul = tree[i << 1].mul * tree[i].mul;
        tree[i << 1].mul %= mod;
        tree[i << 1 | 1].mul = tree[i << 1 | 1].mul * tree[i].mul;
        tree[i << 1 | 1].mul %= mod;

        tree[i << 1].lazy *= tree[i].mul;
        tree[i << 1].lazy += tree[i].lazy;
        tree[i << 1].lazy %= mod;
        tree[i << 1 | 1].lazy *= tree[i].mul;
        tree[i << 1 | 1].lazy += tree[i].lazy;
        tree[i << 1 | 1].lazy %= mod;

        tree[i].lazy = 0;
        tree[i].mul = 1;
    }
}

inline void build(int i, int left, int right) {
    tree[i].left = left;
    tree[i].right = right;
    tree[i].mul = 1;
    if (left == right) {
        tree[i].sum = number[left];
        return;
    }
    int mid = (left + right) >> 1;
    build(i << 1, left, mid);
    build(i << 1 | 1, mid + 1, right);
    update(i);
}

inline int search(int i, int left, int right) {
    if (tree[i].left >= left && tree[i].right <= right)
        return tree[i].sum;
    if (tree[i].right < left || tree[i].left > right)
        return 0;
    pushdown(i);
    int sum = 0;
    if (tree[i << 1].right >= left)
        sum += search(i << 1, left, right);
    if (tree[i << 1 | 1].left <= right)
        sum += search(i << 1 | 1, left, right);
    return sum;
}

inline void add(int i, int left, int right, int x) {
    if (tree[i].left >= left && tree[i].right <= right) {
        tree[i].sum += x * (tree[i].right - tree[i].left + 1);
        tree[i].sum %= mod;
        tree[i].lazy += x;
        tree[i].lazy %= mod;
        return;
    }
    pushdown(i);
    if (tree[i << 1].right >= left)
        add(i << 1, left, right, x);
    if (tree[i << 1 | 1].left <= right)
        add(i << 1 | 1, left, right, x);
    update(i);
}

inline void multiply(int i, int left, int right, int x) {
    if (tree[i].left >= left && tree[i].right <= right) {
        tree[i].sum = tree[i].sum * x;
        tree[i].sum %= mod;
        tree[i].lazy = tree[i].lazy * x;
        tree[i].lazy %= mod;
        tree[i].mul = tree[i].mul * x;
        tree[i].mul %= mod;
        return ;
    }
    pushdown(i);
    if (tree[i << 1].right >= left)
        multiply(i << 1, left, right, x);
    if (tree[i << 1 | 1].left <= right)
        multiply(i << 1 | 1, left, right, x);
    update(i);
}

signed main() {
    int n, m;
    cin >> n >> m >> mod;
    for (int i = 1; i <= n; i++) {
        cin >> number[i];
    }
    build(1, 1, n);
    int x, l, r, v;
    for (int i = 1; i <= m; i++) {
        cin >> x >> l >> r;
        if (x == 1) {
            cin >> v;
            multiply(1, l, r, v);
        } else if (x == 2) {
            cin >> v;
            add(1, l, r, v);
        } else if (x == 3) {
            int ans = search(1, l, r);
            cout << ans % mod << endl;
        }
    }
    return 0;
}