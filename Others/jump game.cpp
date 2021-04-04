#include<bits/stdc++.h>

using namespace std;

/*
 * ���һ����
 * �������һ��ɱ������ʯͷj, j + A[j] >= num, �����һ��ʯͷ�ɱ�����
 * �����⣺
 * һ��ʯͷj���ܷ���֮ǰ��ʯͷi������Ƿ���� i + A[i] >= j
 */

bool canJump(vector<int> &A) {
    int num = A.size() - 1;
    bool dp[num + 1];
    dp[0] = true;
    for (int j = 1; j <= num; j++) {
        dp[j] = false;
        for (int i = 0; i < j; i++) {
            if (dp[i] && i + A[i] >= j) {
                dp[j] = true;
                break;
            }
        }
    }
    return dp[num];
}

int main() {
    int n, num;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.emplace_back(num);
    }
    cout << canJump(v) << endl;
    return 0;
}