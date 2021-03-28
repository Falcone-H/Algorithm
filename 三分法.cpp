// https://www.luogu.com.cn/problem/P3382
// 三分法
#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-6;

int n;
double l, r;
double a[15];

double f(double x)
{
    double res = 0, k = 1;
    for (int i = n + 1; i >= 1; i--)
    {
        res = res + k * a[i];
        k = k * x;
    }
    return res;
}

int main()
{
    cin >> n >> l >> r;
    for (int i = 1; i <= n + 1; i++)
    {
        cin >> a[i];
    }
    while (l + eps < r)
    {
        double midl = (l + r) / 2;
        double midr = (midl + r) / 2;
        if (f(midl) > f(midr))
            r = midr;
        else
            l = midl;
    }
    printf("%.7lf", l);
    return 0;
}