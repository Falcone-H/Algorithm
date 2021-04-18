// https://pintia.cn/problem-sets/994805046380707840/problems/994805070971912192
#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N];
int n;
vector<int> back;
bool isMirror = false;

void build(int l, int r) {
    if(l > r)
        return;
    int tl = r;         // l~tl是左区间，tr~r是右区间
    int tr = l + 1;
    if(!isMirror) {
        while(tl > l && a[l] <= a[tl])  // 找到左区间的右边界
            tl--;
        while(tr <= r && a[l] > a[tr])  // 找到右区间的左边界
            tr++;
    } else {
        while(tl > l && a[l] > a[tl])
            tl--;
        while(tr <= r && a[l] <= a[tr])
            tr++;
    }

    if(tr - tl != 1)    // 不符合二叉搜索树
        return;
    build(l + 1, tl);
    build(tr, r);
    back.push_back(a[l]);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    build(0, n - 1);

    if(back.size() != n) {  // 如果正常的二叉搜索树不行，就试一下镜像的
        isMirror = true;
        back.clear();
        build(0, n - 1);
    }

    if(back.size() != n) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for(int i = 0; i < back.size(); i++) {
        cout << back[i];
        if(i != back.size() - 1)
            cout << " ";
    }
    cout << "\n";
    return 0;
}