// Manacher 算法，寻找最长的回文子串
#include <bits/stdc++.h>

using namespace std;
const int N = 500005;
char chaArr[N];
int pArr[N];

int manacher(string str)
{
    memset(chaArr, 0, sizeof(chaArr));
    memset(pArr, 0, sizeof(pArr));
    // 空字符串直接返回
    if (str.length() == 0)
        return 0;
    // 记录下manacher字符串的长度，方便后面使用
    int len = (int)(str.length() * 2 + 1);
    int index = 0;
    // 字符串的manacher化
    for (int i = 0; i < len; i++)
        chaArr[i] = (i & 1) == 0 ? '#' : str[index++];
    // R 是最右回文边界，C 是 R 对应的最左回文中心
    // maxn 是记录的最大回文半径
    int R = -1, C = -1;
    int maxn = 0;
    // 遍历字符串
    for (int i = 0; i < len; i++)
    {
        // 第一步直接取得可能的最短的回文半径
        // 当 i > R 时，最短的回文半径是 1 ；反之，最短的回文半径可能是 i 对应的 i' 的回文半径， 或者 i 到 R 的距离
        pArr[i] = R > i ? min(R - i, pArr[2 * C - i]) : 1;
        // 取最小值后开始从边界暴力匹配，匹配失败就直接退出
        while (i + pArr[i] < len && i - pArr[i] > -1)
        {
            if (chaArr[i + pArr[i]] == chaArr[i - pArr[i]])
                pArr[i]++;
            else
                break;
        }
        // 观察此时 R 和 C 是否能够更新
        if (i + pArr[i] > R)
        {
            R = i + pArr[i];
            C = i;
        }
        // 更新最大回文半径的值
        maxn = max(maxn, pArr[i]);
    }
    // 因为manacher字符串的长度与原字符串不同，所以这里得到的最大回文半径其实是原字符串的最大回文子串长度加一
    return maxn - 1;
}

int main()
{
    string s2 = "abbbca";
    cout << manacher(s2) << endl;
    return 0;
}
