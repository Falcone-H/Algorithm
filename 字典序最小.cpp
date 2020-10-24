// POJ 3617
// �㷨��̰��
// ˼·�������ֵ���Ƚ��ַ���s����s��ת����ַ�����ѡ����С��һ��������ͷ�ַ�����t��
#include<bits/stdc++.h>

using namespace std;
string temp = "s";

void solve(string &s, string &t) {
    int left = 0, right = s.size() - 1;
    while (left <= right) {
        bool flag = false;
        for (int i = 0; left + i <= right; i++) {
            if (s[left + i] < s[right - i]) {   //˳���ַ���С
                flag = true;
                break;
            } else if (s[left + i] > s[right - i]) {    //�����ַ���С
                flag = false;
                break;
            } else {    //����ȣ�������Ƚ���һ���ַ�
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