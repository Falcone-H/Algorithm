// https://www.acwing.com/problem/content/890/
#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int prime[N];
int mark[N];
int sum[N];
int cnt;

void getPrime() {
    for(int i = 2; i <= 5001; ++i) {
        if(!mark[i]) {
            prime[cnt++] = i;
        }
        for(int j = 0; j < cnt && prime[j] * i <= N; ++j) {
            mark[i * prime[j]] = 1;
            if(i % prime[j] == 0)    break;
        }
    }
}

int get(int n, int p) {
    int res = 0;
    while(n) {
        res += n / p;
        n /= p;
    }
    return res;
}

vector<int> mul(vector<int> &a, int b) {
    vector<int> c;
    int t = 0;
    for(int i = 0; i < a.size(); i++) {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while(t) {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}

int main() {
    getPrime();
    int a, b;
    cin >> a >> b;
    for(int i = 0; i < cnt; ++i) {
        int p = prime[i];
        if(prime[i] > a)    break;
        sum[i] = get(a, p) - get(b, p) - get(a - b, p);
    }
    vector<int> ans;
    ans.push_back(1);
    for(int i = 0; i < cnt; ++i) {
        for(int j = 0; j < sum[i]; ++j) {
            ans = mul(ans, prime[i]);
        }
    }
    for(int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
    return 0;
}