#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull; // 自动溢出，相当于自动对 2^64 - 1 取模

const int N = 1e6 + 5;
ull p = 131;
ull bin[N]; // bin[i] 表示 p 的 i 次方
ull hashs[N];
string s;

void init()
{
    bin[0] = 1;
    for (int i = 1; i < s.size(); i++)
    {
        bin[i] = bin[i - 1] * p;
    }
}

void Hash(string s)
{
    hashs[0] = 0;
    for (int i = 1; i < s.size(); i++)
    {
        hashs[i] = hashs[i - 1] * p + s[i]);
    }
}

ull getSub(int l, int r)
{
    return hashs[r] - hashs[l - 1] * bin[r - l + 1];
}

int main()
{
    cin >> s;
    s = " " + s; // 下标从 1 开始
    init();
    Hash(s);
    getSub(1, 5);
    return 0;
}