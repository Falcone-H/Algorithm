// https://www.acwing.com/problem/content/242/
// 并查集
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int p[N], d[N];
int n, k;
void init() {
    for(int i = 0; i < n; i++) {
        p[i] = i;
    }
}

int find(int x) {
    if(p[x] != x) {
        int t = p[x];
        p[x] = find(p[x]);
        d[x] = (d[x] + d[t]) % 3;
    }
    return p[x];
}

bool merge1(int x, int y) {
    int p1 = find(x);
    int p2 = find(y);
    if(p1 == p2)
        return d[x] % 3 == d[y] % 3;
    p[p2] = p1;
    d[p2] = (d[x] - d[y] + 3) % 3;
    return true;
}

bool merge2(int x, int y) {
    int p1 = find(x);
    int p2 = find(y);
    if(p1 == p2)
        return d[x] % 3 == (d[y] + 1) % 3;
    p[p2] = p1;
    d[p2] = (d[x] - d[y] - 1 + 3) % 3;
    return true;
}

int main() {
    int res = 0;
    int D, x, y;
    cin >> n >> k;
    init();
    while(k--) {
        cin >> D >> x >> y;
        if(x > n || y > n) {
            res++;
            continue;
        }
        if(D == 1) {
            if(!merge1(x, y)) res++;
        } else if(D == 2) {
            if(!merge2(x, y)) res++;
        }
    }
    cout << res << endl;
    return 0;
}