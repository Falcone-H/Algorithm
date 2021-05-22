// https://www.acwing.com/problem/content/880/
// 扩展欧几里得
#include<bits/stdc++.h>
#define int long long
using namespace std;

int exgcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }
    int x1, y1;
    int gcd = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return gcd;
}

signed main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        int a, b, m;
        scanf("%d%d%d", &a, &b, &m);
        int x, y;
        int gcd = exgcd(a, m, x, y);
        if(b % gcd) {
            printf("impossible\n");
        } else {
            x = x * b / gcd % m;
            printf("%d\n", x);
        }
    }
    return 0;
}