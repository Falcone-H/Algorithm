#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    int t;
    cin >> t;
    t /= 1000;
    int n = t % 86400;
    int h = n / 3600;
    int s = n % 60;
    int m = (n % 3600  - s) / 60;
    if(h < 10)  cout << "0";
    cout << h << ":";
    if(m < 10)  cout << "0";
    cout << m << ":";
    if(s < 10) cout << "0";
    cout << s << "\n";
    return 0;
}