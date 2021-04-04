// P4588 [TJOI2018]数学计算
// 思路：线段树，维护一个长度为q的数组，将整个数组的值都初始化为1。
//      当第i个操作为1时，相当于将第i个数的值进行改变，然后返回整个数组的乘积
//      当操作为2时，相当于把对应位置的数的值改为1，然后返回整个数组的乘积
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100005;
int mod;
int number[N];
struct Tree {
    int val;
    int left;
    int right;
}tree[4 * N + 2];

inline void update(int i) {
    tree[i].val = tree[i << 1].val * tree[i << 1 | 1].val;
    tree[i].val %= mod;
}

inline void build(int i, int left, int right) {
    tree[i].left = left;
    tree[i].right = right;
    if(left == right) {
        tree[i].val = 1;
        return;
    }
    int mid = (left + right) >> 1;
    build(i << 1, left, mid);
    build(i << 1 | 1, mid + 1, right);
    update(i);
}

inline int search(int i, int left, int right) {
    if(tree[i].left >= left && tree[i].right <= right)
        return tree[i].val;
    if(tree[i].right < left || tree[i].left > right)
        return 0;
    int sum = 1;
    if(tree[i << 1].right >= left)
        sum *= search(i << 1, left, right);
    sum %= mod;
    if(tree[i << 1 | 1].left >= right)
        sum *= search(i << 1 | 1, left, right);
    sum %= mod;
    return sum;
}

inline void change(int cur, int i, int x) {
    if(tree[cur].left == i && tree[cur].right == i) {
        tree[cur].val = x;
        return;
    }
    if(tree[cur << 1].left <= i && tree[cur << 1].right >= i)
        change(cur << 1, i ,x);
    if(tree[cur << 1 | 1].left <= i && tree[cur << 1 | 1].right >= i)
        change(cur << 1 | 1, i, x);
    update(cur);
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int q;
        cin >> q >> mod;
        build(1, 1, q);
        for(int i = 1; i <= q; i++) {
            int x, y;
            cin >> x >> y;
            if(x == 1) {
                change(1, i, y);
                cout << search(1, 1, q) << endl;
            } else if(x == 2) {
                change(1, y, 1);
                cout << search(1, 1, q) << endl;
            }
        }
    }
    return 0;
}