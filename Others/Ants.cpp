//POJ NO.1852
//���Լ������������󲻻᷵�أ���Ϊ��ֻ�����������ͷ����ʵ����ֻ���Ͻ��������һ����...

#include<iostream>

#define int long long
using namespace std;

signed main() {
    int m;
    cin >> m;
    while (m--) {
        int l;
        int n;
        int maxv = INT_MIN, minv = INT_MIN;
        int maxn, minn;
        int num;
        cin >> l >> n;
        for (int i = 0; i < n; i++) {
            cin >> num;
            maxn = max(num, l - num);   //��¼ÿһֻ���������˵����ֵ
            minn = min(num, l - num);   //��¼ÿһֻ���������˵���Сֵ
            minv = max(minn, minv);     //��¼����minn�е����ֵ
            maxv = max(maxn, maxv);     //��¼����maxn�е����ֵ
        }
        cout << minv << " " << maxv << endl;
    }
    return 0;
}