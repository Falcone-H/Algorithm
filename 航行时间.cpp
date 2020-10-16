#include<bits/stdc++.h>
#define int long long
using namespace std;

int getTime() {
    string s;
    getline(cin, s);
    int h1, h2, m1, m2, s1, s2, d = 0;
    if (s.size() > 18) {
        d = s[20] - '0';
    }
    h1 = (s[0] - '0') * 10 + (s[1] - '0');
    m1 = (s[3] - '0') * 10 + (s[4] - '0');
    s1 = (s[6] - '0') * 10 + (s[7] - '0');
    h2 = (s[9] - '0') * 10 + (s[10] - '0');
    m2 = (s[12] - '0') * 10 + (s[13] - '0');
    s2 = (s[15] - '0') * 10 + (s[16] - '0');
    //printf("%d:%d:%d, %d:%d:%d",h1,m1,s1,h2,m2,s2);
    int res = (d * 24 * 3600 + h2 * 3600 + m2 * 60 + s2) - (h1 * 3600 + m1 * 60 + s1);
    return res;
}

signed main() {
    int n;
    cin >> n;
    getchar();
    int time1, time2;
    int res;
    while (n--) {
        time1 = getTime();
        time2 = getTime();
        res = (time1 + time2) / 2;
        printf("%02lld:%02lld:%02lld\n", res / 3600, res / 60 % 60, res % 60);
    }
    return 0;
}