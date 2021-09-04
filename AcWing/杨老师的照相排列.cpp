// https://www.acwing.com/problem/content/description/273/
// 思路：线性dp
// f[a, b, c, d, e] 表示第一排有a个人，第二排有b个人，第三排有c个人，第四排有d个人，第五排有e个人的状态
// 现在以最后一个人放在第几排进行转移
// 将最后一个人放在第一排，那么 f[a, b, c, d, e] = f[a - 1, b, c, d, e]
// 将最后一个人放在第二排，那么 f[a, b, c, d, e] = f[a, b - 1, c, d, e]
// 最多五排，以此类推
// 那么 f[a, b, c, d, e] 就相当于以上的五种情况相加
#include<bits/stdc++.h>

#define int long long
using namespace std;
int s[10];
int f[31][31][31][31][31];

signed main() {
    int k;
    while (cin >> k) {
        if (k == 0) break;
        memset(s, 0, sizeof s);
        memset(f, 0, sizeof f);
        for (int i = 0; i < k; i++) cin >> s[i];
        f[0][0][0][0][0] = 1;
        for (int a = 0; a <= s[0]; a++) {
            for (int b = 0; b <= min(a, s[1]); b++) {
                for (int c = 0; c <= min(b, s[2]); c++) {
                    for (int d = 0; d <= min(c, s[3]); d++) {
                        for (int e = 0; e <= min(d, s[4]); e++) {
                            int &v = f[a][b][c][d][e];
                            if (a && (a - 1 >= b))
                                v += f[a - 1][b][c][d][e];
                            if (b && (b - 1 >= c)) v += f[a][b - 1][c][d][e];
                            if (c && (c - 1 >= d)) v += f[a][b][c - 1][d][e];
                            if (d && (d - 1 >= e)) v += f[a][b][c][d - 1][e];
                            if (e) v += f[a][b][c][d][e - 1];
                        }
                    }
                }
            }
        }
        cout << f[s[0]][s[1]][s[2]][s[3]][s[4]] << endl;
    }
    return 0;
}