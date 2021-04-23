// https://www.acwing.com/problem/content/description/3305/
// 栈
#include<bits/stdc++.h>

using namespace std;
stack<int> num;
stack<char> oper;
map<char, int> m;

void calc(char c) {
    int num1 = num.top();
    num.pop();
    int num2 = num.top();
    num.pop();
    if (c == '+')
        num.push(num1 + num2);
    else if (c == '-')
        num.push(num2 - num1);
    else if (c == '*')
        num.push(num1 * num2);
    else if (c == '/')
        num.push(num2 / num1);
}

void solve(char c) {
    if (c == '(') {
        oper.push(c);
    } else if (c == ')') {
        while (oper.top() != '(') {
            calc(oper.top());
            oper.pop();
        }
        oper.pop();
    } else {
        while (!oper.empty() && m[oper.top()] >= m[c]) {
            calc(oper.top());
            oper.pop();
        }
        oper.push(c);
    }
}

void init() {
    m['+'] = 1;
    m['-'] = 1;
    m['*'] = 2;
    m['/'] = 2;
}

int main() {
    init();
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            int x = 0;
            while(i < str.size() && isdigit(str[i])) {
                x = x * 10 + (str[i] - '0');
                i++;
            }
            num.push(x);
            i--;
        }
        else
            solve(str[i]);
    }
    while (!oper.empty()) {
        calc(oper.top());
        oper.pop();
    }
    cout << num.top() << "\n";
    return 0;
}