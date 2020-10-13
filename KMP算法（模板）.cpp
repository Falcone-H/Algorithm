#include<bits/stdc++.h>

using namespace std;

void getNext(int next[], string t) {
    next[0] = -1;
    int j = 0, k = -1;
    while (j < t.size() - 1) {
        if ((k == -1) || (t[j] == t[k])) {
            j++;
            k++;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
}

//�Ż�
//void getNext(int next[], string t) {
//    next[0] = -1;
//    int j = 0, k = -1;
//    while (j < t.size()) {
//        if (k == -1 || t[j] == t[k]) {
//            j++;
//            k++;
//            if(t[j] == t[k])
//                next[j] = next[k];  //�����ַ���ͬʱ������
//            else
//                next[j] = k;
//        } else {
//            k = next[k];
//        }
//    }
//}


int main() {
    int next[1000];
    string s, t;    //sΪ���ַ�����tΪģ���ַ���
    cin >> s >> t;
    getNext(next, t);
    int j = 0, k = 0;
    int len = t.size(); // ������t.size()�Ƚϣ��᷵��0
    while ((j < s.size()) && (k < len)) {
        if ((k == -1) || (s[j] == t[k])) {
            j++;
            k++;
        } else {
            k = next[k];
        }
    }
    if (k >= t.size()) {
        cout << (j - t.size()) << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}