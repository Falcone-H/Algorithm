// https://ac.nowcoder.com/acm/contest/9983/H
// 思路：如果大于10（j），就可以拆开；如果合起来小于26（bf），就可以合并
// 注意：10 和 20 不能拆开
#include <bits/stdc++.h>

using namespace std;

string solve1(char c)
{ // 拆分
    int num = c - 'a' + 1;
    string ans = "";
    ans += (char)(num / 10 - 1 + 'a');
    ans += (char)(num % 10 - 1 + 'a');
    return ans;
}

string solve2(char a, char b)
{ // 合并
    int num = a - 'a' + 1;
    num = num * 10 + (b - 'a' + 1);
    string ans = "";
    ans += (char)(num - 1 + 'a');
    return ans;
}

int main()
{
    string s, ans = "";
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] > 'j' && s[i] != 't')
        {
            ans = s.substr(0, i) + solve1(s[i]);
            if (i + 1 < s.size())
                ans += s.substr(i + 1);
            break;
        }
        else if (i + 1 < s.size() && s[i] <= 'b' && s[i + 1] <= 'f')
        {
            ans = s.substr(0, i) + solve2(s[i], s[i + 1]);
            if (i + 2 < s.size())
                ans += s.substr(i + 2);
            break;
        }
    }
    if (ans == "")
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}