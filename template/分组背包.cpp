// https://www.acwing.com/problem/content/9/
#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m;
int dp[N];
int s[N], v[N], w[N];
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        for(int j = 1; j <= s[i]; j++) {
            cin >> v[j] >> w[j];
        }
        for(int j = m; j >= 1; j--) {
            for(int k = 1; k <= s[i]; k++) {
                if(j >= v[k])
                    dp[j] = max(dp[j], dp[j - v[k]] + w[k]);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}