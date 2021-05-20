// https://www.acwing.com/problem/content/879/
#include<bits/stdc++.h>
using namespace std;

int exgcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1, y = 0;
        return a;
    } else {
        int gcd;
        int x1, y1;
        gcd = exgcd(b, a % b, x1, y1);
        x = y1;
        y = x1 - a / b * y1;
        return gcd;
    }
}

int main() {
    int n;
    int a, b;
    scanf("%d", &n);
    while(n--) {
        scanf("%d%d", &a, &b);
        int x, y;
        exgcd(a, b, x, y);
        printf("%d %d\n", x, y);
    }
    return 0;
}