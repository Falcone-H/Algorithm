// 高精度 除 低精度
#include<bits/stdc++.h>

using namespace std;

// 商是 C， 余数是 r
vector<int> div(vector<int> &A, int b, int &r) {
    vector<int> c;
    for(int i = A.size() - 1; i >= 0; i--) {
        r = r * 10 + A[i];
        c.push_back(r / b);
        r %= b;
    }
    reverse(c.begin(), c.end());
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
    int r = 0;
    vector<int> C = div(A, b, r);
    for (int i = C.size() - 1; i >= 0; i--) {
        cout << C[i];
    }
    cout << "\n";
    cout << r << "\n";
    return 0;
}