// POJ 1182
#include<bits/stdc++.h>

using namespace std;
const int MAX_N = 10005;
int par[MAX_N];

void init() {
    for (int i = 0; i < MAX_N; i++) {
        par[i] = i;
    }
}

int find(int x) {
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

int main() {
    init();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x > y) {
            swap(x, y);
        }
        par[y] = par[x];
    }
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        cout << par[num] << endl;
    }
    return 0;
}