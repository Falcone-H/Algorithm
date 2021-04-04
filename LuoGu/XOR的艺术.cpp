// P2574 XOR的艺术
// 思路：线段树，将原来的加或者乘，改为 (right - left + 1) - sum , 即对区间内每一个数都取反
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 200005;
int mod;
int number[N];
struct Tree {
    int sum;
    int left;
    int right;
    bool is_change;
}tree[4 * N + 2];

inline void update(int i) {
    tree[i].sum = tree[i << 1].sum + tree[i << 1 | 1].sum;
}

inline void build(int i, int left, int right) {
    tree[i].left = left;
    tree[i].right = right;
    tree[i].is_change = false;
    if(left == right) {
        tree[i].sum = number[left];
        return;
    }
    int mid = (left + right) >> 1;
    build(i << 1, left, mid);
    build(i << 1 | 1, mid + 1, right);
    update(i);
}

inline void pushdown(int i) {
    if(tree[i].is_change) {
        tree[i << 1].sum = (tree[i << 1].right - tree[i << 1].left + 1) - tree[i << 1].sum;
        tree[i << 1].is_change = !tree[i << 1].is_change;

        tree[i << 1 | 1].sum = (tree[i << 1 | 1].right - tree[i << 1 | 1].left + 1) - tree[i << 1 | 1].sum;
        tree[i << 1 | 1].is_change = !tree[i << 1 | 1].is_change;

        tree[i].is_change = false;
    }
}

inline int search(int i, int left, int right) {
    if(tree[i].left >= left && tree[i].right <= right)
        return tree[i].sum;
    if(tree[i].right < left || tree[i].left > right)
        return 0;
    pushdown(i);
    int sum = 0;
    if(tree[i << 1].right >= left)
        sum += search(i << 1, left, right);
    if(tree[i << 1 | 1].left <= right)
        sum += search(i << 1 | 1, left, right);
    return sum;
}

inline void change(int i, int left, int right) {
    if(tree[i].left >= left && tree[i].right <= right) {
        tree[i].sum = (tree[i].right - tree[i].left + 1) - tree[i].sum;
        tree[i].is_change = !tree[i].is_change;
        return;
    }
    pushdown(i);
    if (tree[i << 1].right >= left)
        change(i << 1, left, right);
    if (tree[i << 1 | 1].left <= right)
        change(i << 1 | 1, left, right);
    update(i);
}

signed main() {
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++) {
        number[i + 1] = str[i] - '0';
    }
    build(1, 1, str.size());
    int op, l, r;
    while(m--) {
        cin >> op >> l >> r;
        if(op == 0) {
            change(1, l, r);
        }
        else if(op == 1) {
            cout << search(1, l, r) << endl;
        }
    }
    return 0;
}