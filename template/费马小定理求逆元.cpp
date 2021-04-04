#include <bits/stdc++.h>

#define int long long
using namespace std;

int pow(int a, int n, int p)
{ // 快速幂 a ^ n % p
    int ans = 1;
    while (n)
    {
        if (n & 1)
            ans = ans * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ans;
}

int Fermat(int a, int p)
{ // 费马小定理求逆元
    return pow(a, p - 2, p);
}

signed main()
{
    int num = Fermat(2, 5);
    cout << num << endl;
    return 0;
}