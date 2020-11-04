//POJ 2431
#include<bits/stdc++.h>

using namespace std;
int a[10005], b[10005];
priority_queue<int> q;

int main() {
    int n, l, p;
    cin >> n >> l >> p;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int cnt = 0;
    while (p < l) {
        int i = 0;
        for (; i < n; i++) {
            if (a[i] <= p) {
                q.push(b[i]);   //�������ļ���վ�������
            }
        }
        if (q.empty()) {
            cout << -1 << endl;
            return 0;
        }
        p += q.top();   //ÿ�ζ���֮ǰ�����ļ���վ��ѡ������ֵ
        q.pop();
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}