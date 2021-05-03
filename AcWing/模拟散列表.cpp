#include<bits/stdc++.h>
using namespace std;
const int N = 100003;
const int mod = 100003;
int h[N], e[N], ne[N];
int cnt;

void insert(int x) {
    int k = (x % mod + mod) % mod;  // x 要先对 mod 取模，是因为要防止 x 为负数，下面同理
    e[cnt] = x;
    ne[cnt] = h[k];
    h[k] = cnt;
    cnt++;
}

bool find(int x) {
    int k = (x % mod + mod) % mod;
    int t = h[k];
    while(t != -1) {
        if(e[t] == x)
            return true;
        t = ne[t];
    }
    return false;
}

int main() {
    memset(h, -1, sizeof(h));
    string oper;
    int x;
    int n;
    cin >> n;
    while(n--) {
        cin >> oper >> x;
        if(oper == "I") {
            insert(x);
        } else if(oper == "Q") {
            cout << (find(x) ? "Yes" : "No") << "\n";
        }
    }
    return 0;
}