#include<bits/stdc++.h>

using namespace std;
int a[] = {1, 5, 7, 9, 0, 2, 4, 3, 8};
int dp[100];
int n = 9;

void solve() {  // O(N*log(N))
    fill(dp, dp + n, INT_MAX);
    for (int i = 0; i < n; i++) {
        *lower_bound(dp, dp + n, a[i]) = a[i];
    }
    printf("%d\n", lower_bound(dp, dp + n, INT_MAX) - dp);
}

int main() {
    int res = 0;
    for (int i = 0; i < n; i++) {   // O(N^2)
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }
    cout << res << endl;
    return 0;
}