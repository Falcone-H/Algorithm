// https://www.acwing.com/problem/content/description/145/
// 思路：字典树
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int node[N * 31][2];
int a[N];
int n;
int cnt = 1;

void insert(int x) {
    int cur = 1;
    for(int i = 30; i >= 0; i--) {
        int s = x >> i & 1;
        if(!node[cur][s]) {
            node[cur][s] = ++cnt;
        }
        cur = node[cur][s];
    }
}

int query(int x) {
    int cur = 1;
    int res = 0;
    for(int i = 30; i >= 0; i--) {
        int s = x >> i & 1;
        if(node[cur][!s]) {
            res += (1 << i);
            cur = node[cur][!s];
        } else {
            cur = node[cur][s];
        }
    }
    return res;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        insert(a[i]);
    }
    int res = 0;
    for(int i =0 ; i < n; i++) {
        res = max(res, query(a[i]));
    }
    cout << res << endl;
    return 0;
}