#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100;

int prime[MAXN];        //第i个素数
bool is_pri[MAXN + 10]; //is_pri[i]表示i是素数

int sieve(int n)
{
    int p = 0;
    for (int i = 0; i <= n; i++)
        is_pri[i] = true;

    is_pri[0] = is_pri[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_pri[i])
        {
            prime[++p] = i;
            for (int j = 2 * i; j <= n; j += i)
                is_pri[j] = false;
        }
    }
    return p;
}

int main()
{
}