// �㷨����̬�滮
// ˼·��https://www.jianshu.com/p/a66d5ce49df5
// dp��ά������д���ÿһ����Ʒ���д������С�ı����������ܻ�õ�����ֵ
// ��ÿһ�н��б����������ÿһ����Ʒ����ѡ��

#include<bits/stdc++.h>

using namespace std;
int n, m;   // nΪ��Ʒ������mΪ�����������
int w[105], v[105];
int dp[105][10005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (j >= w[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            printf("%5d", dp[i][j]);
        }
        printf("\n");
    }
    return 0;
}