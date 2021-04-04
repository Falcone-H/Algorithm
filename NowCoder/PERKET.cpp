#include<bits/stdc++.h>

using namespace std;
int n;
int s[15], b[15];
int s_sum = 1, b_sum = 0;
int minn = INT_MAX;

void dfs(int num) {
    for (int i = num + 1; i <= n; i++) {
        s_sum *= s[i];
        b_sum += b[i];
        minn = min(minn, abs(s_sum - b_sum));
        dfs(i);
        s_sum /= s[i];
        b_sum -= b[i];
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        s_sum *= s[i];
        b_sum += b[i];
        minn = min(minn, abs(s_sum - b_sum));
        dfs(i);
        s_sum /= s[i];
        b_sum -= b[i];
    }
    cout << minn <<endl;
    return 0;
}