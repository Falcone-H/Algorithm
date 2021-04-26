// https://www.acwing.com/problem/content/832/
// 思路：单调栈，如果栈顶的数比当前的数大，那么将栈顶的数弹出，否则，将栈顶的数输出。最后，将当前的数推入栈中。
#include<bits/stdc++.h>

using namespace std;
stack<int> s;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while(!s.empty()) {
            if(s.top() >= x)
                s.pop();
            else
                break;
        }
        if(s.empty())   cout << -1 << " ";
        else    cout << s.top() << " ";
        s.push(x);
    }
    return 0;
}