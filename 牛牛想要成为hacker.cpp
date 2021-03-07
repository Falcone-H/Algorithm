// https://ac.nowcoder.com/acm/contest/9982/J
// 思路：要形成三角形，就要有两边之和大于第三边；但是斐波那契数列，则有当前的数等于之前两个数的和，正好不能构成三角形。
// 而设有前 k 个数，符合斐波那契数列，三重循环之后，大于要求的次数；然后 k + 1 到 n 都可以为1
// 按照这个要求构造数列，就要求出 k
// 因为 log2 1e5 约等于 17
// 然后，解方程得到 k 等于 33 的时候，符合要求
// 而在合法范围内，斐波那契数列中有 42 个数
// 因此，按此前 42 个数，构造斐波那契数列，后面的数，用 1 补上就行
#include <bits/stdc++.h>
#define int long long
using namespace std;
int f[100005];
int mod = 1e9 + 7;
signed main()
{
    for (int i = 43; i <= 100005; i++)
    {
        f[i] = 1;
    }
    for (int i = 42; i >= 1; i--)
    {
        f[i] = f[i + 1] + f[i + 2];
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << f[i] << " ";
    }
    return 0;
}