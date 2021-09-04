// a1 ^ a2 ^ a3 ^ ... ^ an == 0 则为先手必败
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int main() {
    int n;
    cin >> n;
    int res = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        res ^= a[i];
    }
    if(res) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
