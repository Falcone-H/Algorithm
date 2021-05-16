// https://www.acwing.com/problem/content/876/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int prime[N];
int mark[N];
int ans[N];
int cnt;
void find(int n) {
    ans[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(!mark[i]) {
            prime[cnt++] = i;
            ans[i] = i - 1;
        }
        for(int j = 0; j < cnt && prime[j] * i <= n; j++) {
            mark[prime[j] * i] = 1;
            if(i % prime[j] == 0) {
                ans[prime[j] * i] = prime[j] * ans[i];
                break;
            } else {
                ans[prime[j] * i] = (prime[j] - 1) * ans[i];
            }
        }
    }
}

signed main() {
    int n;
    cin >> n;
    find(n);
    int res = 0;
    for(int i = 1; i <= n; i++) {
        res += ans[i];
    }
    cout << res << "\n";
    return 0;
}