// https://www.acwing.com/problem/content/792/
#include<bits/stdc++.h>
using namespace std;
int main() {
    double n;
    scanf("%lf", &n);
    double l = -10000, r = 10000;
    while(r - l > 1e-8) {
        double mid = (r + l) / 2;
        if(mid * mid * mid >= n) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%.6lf", l);
    return 0;
}