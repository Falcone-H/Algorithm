// POJ 3069
// �㷨��̰��
#include<bits/stdc++.h>

using namespace std;
int n, r;
int x[1005];
int res;

void solve() {
    int i = 0;
    int left;
    while (i < n) {
        // û�б����ǵ�����ߵĵ�
        left = x[i];
        // �ҳ����Ը���left�����ұߵĵ�
        while (i < n && x[i] <= left + r)
            i++;
        // ���
        res++;
        // ��left��Ϊ����ǵĵ��λ��
        left = x[i - 1];
        // �ҳ�����ǵ㸲�ǵ����ұߵĵ�
        while (i < n && x[i] <= left + r)
            i++;
        // ��λ��û�б����ǵ�����ߵĵ�
        i++;
    }
}

int main() {
    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x, x + n);
    solve();
    cout << res << endl;
}