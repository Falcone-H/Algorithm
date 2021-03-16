// https://ac.nowcoder.com/acm/contest/9983/F
// 思路：将所有字符串中，左边和右边不含有‘#’的子字符串作比较，保留最长的一个
// 然后，用其他字符串，左边和右边不含‘#’的部分与刚才的最长字符串一一比对
// 如果比对结果不正确，则输出零
// 如果比对结果全部正确，又因为所有字符串中都含有‘#’，有无穷多种可能，所以，输出-1
#include <bits/stdc++.h>

using namespace std;
vector<string> v;
vector<pair<int, int>> p;
int maxl = -1;
int maxr = -1;
string partl;
string partr;

int find_left(string s)
{
    int res;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '#')
        {
            res = i;
            break;
        }
    }
    return res - 1 >= 0 ? res - 1 : 0;
}

int find_right(string s)
{
    int res;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '#')
        {
            res = i;
            break;
        }
    }
    return res + 1 < s.size() ? res + 1 : s.size() - 1;
}

bool check_left(int index)
{
    int l = p[index].first;
    if (v[index][0] == '#')
        return true;
    for (int i = 0; i <= l; i++)
    {
        if (v[index][i] != partl[i])
            return false;
    }
    return true;
}

bool check_right(int index)
{
    int r = p[index].second;
    int i = 1;
    if (v[index][v[index].size() - 1] == '#')
        return true;
    while ((int)(v[index].size() - i) >= r) // 注意这里，因为string.size()返回的是unsigned long 类型，只有正整数，因此，减 i 变成负数后，也会转成正数，比 r 大
    {
        int x1 = v[index].size() - i;
        int x2 = partr.size() - i;
        //        cout << v[index] << " " << x1 << endl;
        //        cout << partr << " " << x2 << endl;
        if (v[index][x1] != partr[x2])
            return false;
        i++;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int l, r;
        l = find_left(s);
        r = find_right(s);
        //        cout << l << " " << r << endl;
        v.push_back(s);
        p.push_back(make_pair(l, r));
        if (l > maxl)
        {
            maxl = l;
            partl = s.substr(0, l + 1);
        }
        if ((int)(s.size() - r) > maxr)
        {
            maxr = s.size() - r;
            partr = s.substr(r);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!check_left(i) || !check_right(i))
        {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}