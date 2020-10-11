#include<bits/stdc++.h>

using namespace std;
int dp[100005];
int maxn = 200000;

int coinChange(vector<int> &coins, int amount) {
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        dp[i] = maxn;
        for (int j = 0; j < coins.size(); j++) {
            if (i - coins[j] >= 0)
                dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
        }
    }
    if (dp[amount] == maxn) {
        return -1;
    } else {
        return dp[amount];
    }
}

int main() {
    int n;
    int num, amount;
    vector<int> coins;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        coins.emplace_back(num);
    }
    cin >> amount;
    cout << coinChange(coins, amount) << endl;
    return 0;
}