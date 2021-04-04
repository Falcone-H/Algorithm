#include<bits/stdc++.h>

using namespace std;

int fib(int N) {
    vector<int> dp(N + 1, 0); //将数组全部初始化为零
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[N];
}

int main() {
    int n;
    cin >> n;
    cout << fib(n) << endl;
}