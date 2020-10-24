// POJ 3617
// 算法：贪心
// 思路：按照字典序比较字符串s，和s反转后的字符串，选出较小的一个，将开头字符放在t后
#include<bits/stdc++.h>

using namespace std;
string temp = "s";

void solve(string &s, string &t) {
    int left = 0, right = s.size() - 1;
    while (left <= right) {
        bool flag = false;
        for (int i = 0; left + i <= right; i++) {
            if (s[left + i] < s[right - i]) {   //顺序字符串小
                flag = true;
                break;
            } else if (s[left + i] > s[right - i]) {    //反序字符串小
                flag = false;
                break;
            } else {    //若相等，则继续比较下一个字符
                continue;
            }
        }
        if (flag) {
            temp[0] = s[left++];
            t += temp;
        } else {
            temp[0] = s[right--];
            t += temp;
        }
    }
}

int main() {
    string s, t="";
    cin >> s;
    solve(s, t);
    cout << t << endl;
    return 0;
}