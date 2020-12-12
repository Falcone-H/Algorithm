#include<bits/stdc++.h>

using namespace std;
const int N = 100005;   // 总节点数
int number[N];
struct node{
    int left, right;    // 区间的左右边界
    int sum;            // 区间元素之和
    int lazy;           // 懒惰标记
}a[N];


// 更新
void update(int k) {
    a[k].sum = a[k << 1].sum + a[k << 1 | 1].sum;
    // 相当于a[k].sum = a[k * 2].sum + a[k * 2 + 1].sum;
    // 意思为将左边区间的和与右边区间的和相加
    // 如果有懒惰标记的话，要进行相应的改变
}

// 初始化
// k为当前节点的编号，left为区间的左边界，right为区间的有边界
void build(int k, int left, int right) {
    a[k].left = left;
    a[k].right = right;
    if(left == right) {     // 为叶节点
        a[k].sum = number[left];
        return;
    }
    int mid = (left + right) / 2;
    build(k << 1, left, mid);   // 递归到左儿子
    build(k << 1 | 1, mid + 1, right);  // 递归到右儿子
    update(k);      // 用左右子区间的值来更新整个区间的值
}


// 单点修改
// k为当前节点的编号，x为要修改节点的编号，y为要把编号为x的节点修改成的值
void change(int k, int x, int y) {
    if(a[k].left == a[k].right) {
        // 如果当前区间只包含一个元素，那么该元素一定是我们要修改的节点。
        a[k].sum = y;
        return;
    }
    int mid = (a[k].left + a[k].right) / 2;
    if(x <= mid)
        change(k << 1, x, y);       // 递归到左儿子
    else
        change(k << 1 | 1, x, y);   // 递归到右儿子
    update(k);      // 因为子节点被修改，因此要更新当前节点的值
}


// 区间修改
// 当前节点为k，要把[left...right]区间中的所有元素的值加x
void changeSegment(int k, int left, int right, int x) {
    if(a[k].left == left && a[k].right == right) {
        // 如果找到了全部元素都要被修改的区间
        a[k].sum += (right - left + 1) * x;
        // 更新该区间的和
        a[k].lazy += x;
        // 懒惰标记叠加
        return;
    }
    int mid = (a[k].left + a[k].right) / 2;
    if(right <= mid)
        // 如果被修改区间完全在左区间
        changeSegment(k << 1, left, right, x);
    else if(left > mid)
        // 如果被修改区间完全在右区间
        changeSegment(k << 1 | 1, left, right, x);
    else {
        // 如果被修改区间被中心点分成两块，分别往左右区间递归
        changeSegment(k << 1, left, mid, x);
        changeSegment(k << 1 | 1, mid + 1, right, x);
    }
    update(k);  // 更新k点的值
}

// 下传标记
void pushdown(int k) {
    if(a[k].left == a[k].right) {
        // 如果节点k已经是叶节点，没有子节点，那么标记就不用下传，直接删除即可
        a[k].lazy = 0;
        return;
    }
    // 改变左边子区间的和
    a[k << 1].sum += (a[k << 1].right - a[k << 1].left + 1) * a[k].lazy;
    // 改变右边子区间的和
    a[k << 1 | 1].sum += (a[k << 1 | 1].right - a[k << 1 | 1].left + 1) * a[k].lazy;
    // 给k的子节点的懒惰标记重新赋值，下传标记
    a[k << 1].lazy += a[k].lazy;
    a[k << 1 | 1].lazy += a[k].lazy;
    a[k].lazy = 0;  // 清空标记
}

// 当前节点为k，查询[left...right]的和
int query(int k, int left, int right) {
    if(a[k].lazy)   // 如果当前节点被打上了懒惰标记，那么先把标记下传
        pushdown(k);
    if(a[k].left == left && a[k].right == right)    // 如果当前区间就是被询问区间，完全重合，那么直接返回
        return a[k].sum;
    int mid = (a[k].left + a[k].right) / 2;
    if(right <= mid)    // 如果询问区间包含在右子区间中
        return query(k << 1 | 1, left, right);
    if(left > mid)      // 如果询问区间包含在左子区间中
        return query(k << 1, left, right);
    // 如果询问区间跨越两个子区间
    return query(k << 1, left, mid) + query(k << 1 | 1, mid + 1, right);
}


int main() {

}