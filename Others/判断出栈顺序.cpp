#include<bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    int list1[7] = {1, 2, 3, 4, 5, 6, 7};   //进栈顺序
    int list2[7] = {1, 2, 3, 4, 5, 6, 7};   //出栈顺序
    stack<int> s;
    int j = 0;
    for (int i = 0; i < 7; i++) {
        s.push(list1[i]);
        //将栈中满足条件的元素出栈
        while (j < 7 && !s.empty() && list2[j] == s.top()) {
            s.pop();
            j++;
        }
    }
    if (s.empty())
        cout << true << endl;
    else
        cout << false << endl;
    return 0;
}