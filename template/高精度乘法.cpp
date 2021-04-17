// 高精度 乘 低精度
#include<bits/stdc++.h>

using namespace std;

vector<int> mul(vector<int> &A, int b) {
    vector<int> c;
    int t = 0;
    for (int i = 0; i < A.size() || t; i++) {
        if (i < A.size())
            t += A[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while(c.size() > 1 && c.back() == 0)
        c.pop_back();
    return c;
}

int main() {
    string a;
    vector<int> A;
    int b;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    vector<int> C = mul(A, b);
    for (int i = C.size() - 1; i >= 0; i--) {
        cout << C[i];
    }
    return 0;
}