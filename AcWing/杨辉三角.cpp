// https://www.acwing.com/problem/content/3421/
// 因为 C(17, 34) > 1e9 , 所以，从 16 开始，枚举每一个斜行
// 然后，在每一个斜行中进行二分，找到所输入的数字
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;

int C(int a, int b) {
    int res = 1;
    for(int i = a, j = 1; j <= b; i--, j++) {
        res *= i;
        res /= j;
        if(res > n) {
            return res;
        }
    }
    return res;
}

bool check(int x) {
    int l = 2 * x, r = max(n, l);
    while(l <= r) {
        int mid = (l + r) >> 1;
        int num = C(mid, x);
        if(num > n)
            r = mid - 1;
        else if(num < n)
            l = mid + 1;
        else {
            cout << (mid * mid + mid) / 2 + x + 1 << endl;
            return true;
        }
    }
    return false;
}

signed main() {
    cin >> n;
    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }
    for(int i = 16; i >= 1; i--) {
        if(check(i))
            break;
    }
    return 0;
}