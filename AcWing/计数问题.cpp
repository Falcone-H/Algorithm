// https://www.acwing.com/problem/content/340/
// 思路：https://www.acwing.com/solution/content/5623/
#include<bits/stdc++.h>
using namespace std;
const int N = 15;
int a, b;
int num[N];

int get_num(int l, int r) {
    // 算出数组num[]第r位到第l位的数是多少
    int ans = 0;
    for(int i = l; i >= r; i--)
        ans = ans * 10 + num[i];
    return ans;
}

int work(int n, int x) {
    if(n == 0)
        return 0;
    int len = 0;
    while(n) {
        num[++len] = n % 10;
        n /= 10;
    }
    int ans = 0;
    if(x != 0) {
        for(int i = len; i > 0; i--) {
            if(i < len)
                ans += get_num(len, i + 1) * pow(10, i - 1);
            if(num[i] == x)
                ans += get_num(i - 1, 1) + 1;
            else if(num[i] > x)
                ans += pow(10, i - 1);
            else
                ans += 0;
        }
    } else {
        for(int i = len - 1; i > 0; i--) {
            ans += (get_num(len, i + 1) - 1) * pow(10, i - 1);
            if(num[i] == x)
                ans += get_num(i - 1, 1) + 1;
            else if(num[i] > x)
                ans += pow(10, i - 1);
            else
                ans += 0;
        }
    }
    return ans;
}

int main() {
    while(cin >> a >> b, a || b) {
        if(a > b)   swap(a, b);
        for(int i = 0; i <= 9; i++) {
            int ans = work(b, i) - work(a - 1, i);
            cout << ans << " ";
        }
        cout << "\n";
    }
    return 0;
}