#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct Tree {
    int left, right;
    int val;
}tree[N];

bool isValidBST(int root, int min, int max) {
    if(root == 0)   // 节点不存在
        return true;
    if(min != -1 && tree[root].val <= min)
        return false;
    if(max != -1 && tree[root].val >= max)
        return false;
    return isValidBST(tree[root].left, min, root) && isValidBST(tree[root].right, root, max);
}

bool isValidBST(int  root) {
    return isValidBST(root, -1, -1);
}

int main() {

}