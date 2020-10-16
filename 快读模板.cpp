#include<bits/stdc++.h>

#define int long long
using namespace std;

int read() {
    char ch = getchar();
    int x = 0, f = 1;
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

signed main() {
    int num = read();
    cout << num << endl;
    return 0;
}