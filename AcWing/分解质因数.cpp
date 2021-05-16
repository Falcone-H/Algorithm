// https://www.acwing.com/activity/content/problem/content/936/1/
#include<bits/stdc++.h>
using namespace std;

void solve(int n) {
    if(n == 1)  {
        cout << "1 1\n";
    }
    for(int i = 2; i <= n / i; i++) {
        int num = 0;
        if(n % i == 0) {
            while(n % i == 0) {
                n /= i;
                num++;
            }
            cout << i << " " << num << "\n";
        }
    }
    if(n > 1)
        cout << n << " " << 1 << "\n";
    cout << "\n";
    return;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}