#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<pair<int, int>, int> m;
    int x, y;
    for (int i = 1; i <= n - 1; i++) {
        cin >> x >> y;
        pair<int, int> p(min(x, y), max(x, y));
        m[p] = 1;
    }
    int res = 0;
    for (int i = 1; i <= n - 1; i++) {
        cin >> x >> y;
        pair<int, int> p(min(x, y), max(x, y));
        if (!m[p])
            res++;
    }
    cout << res << endl;
    return 0;
}