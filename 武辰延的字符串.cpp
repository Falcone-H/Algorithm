// https://ac.nowcoder.com/acm/contest/9984/B
// 思路：字符串哈希，对于字符串 s 的每个前缀 str，用二分查找，找到拼接之后，能够匹配上 t 的最大长度 temp
// 那么说明，对于 str ，可以找到 temp 个能够拼接的前缀，去匹配上 t
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 10;
ull base = 131;
ull bin[N];
ull hash1[N], hash2[N];
string s, t;

ull getSub1(int l, int r)
{
    return hash1[r] - hash1[l - 1] * bin[r - l + 1];
}

ull getSub2(int l, int r)
{
    if (r >= t.size())
        return 0;
    return hash2[r] - hash2[l - 1] * bin[r - l + 1];
}

int main()
{
    cin >> s >> t;
    s = " " + s; // 下标从 1 开始
    t = " " + t;
    int len1 = s.size();
    int len2 = t.size();
    bin[0] = 1;
    for (int i = 1; i < max(len1, len2); i++)
    {
        if (i < len1)
            hash1[i] = hash1[i - 1] * base + s[i];
        if (i < len2)
            hash2[i] = hash2[i - 1] * base + t[i];
        bin[i] = bin[i - 1] * base;
    }
    ll cnt = 0;
    for (int i = 1; i < len2 - 1; i++)
    {
        if (s[i] != t[i])
            break;
        if (s[1] != t[i + 1]) // 接下来的t[i + 1]，连 s 的第一个字符都无法匹配，那就不能满足条件，直接找下一个
            continue;
        int left = 1, right = len1 - 1;
        int temp = 0; // 记录可以取的最长前缀的长度
        while (left <= right)
        {
            int mid = (right - left) / 2 + left; // 当前取的前缀的长度
            ull t1 = getSub1(1, mid);            // s 中从 1 到 mid 的前缀
            ull t2 = getSub2(i + 1, i + mid);    // t 中从 i + 1 到 i + mid 的前缀
            if (t1 == t2)                        // 如果当前长度可以匹配，那就继续把长度加大
                temp = mid, left = mid + 1;
            else
                right = mid - 1;
        }
        cnt += temp;
    }
    cout << cnt << "\n";
    return 0;
}