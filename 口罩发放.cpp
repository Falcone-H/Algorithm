#include<bits/stdc++.h>

#define int long long
#define IOS ios::sync_with_stdio(false)
using namespace std;
struct Person {
    string name;    // ����
    string ID;      // ���֤
    int situation;  // ���� 0 �� 1
    string post;    // ����ʱ��
    int date;       // �ڵڼ��������
    int order;      // ����˳��
};

vector<Person> v, v1;       // v�����¼�Ϸ������룬v1�����¼�������Ϊ1�ĺϷ�����
map<string, Person> m, m1;  // m�����жϸ����֤��֮ǰ�Ƿ���й��Ϸ����루���Ƿ��ս���v�У���m1�����жϸúϷ������Ƿ����Ϊ1�����Ƿ��ս���v1�У�
int d, p;                   // ��Ŀ����������������

bool check_time(string s1, string s2, int d1, int d2) {     // ��ʱ��ת��Ϊ�����������ж��Ƿ����㹻������
    int h1 = (s1[0] - '0') * 10 + (s1[1] - '0');
    int h2 = (s2[0] - '0') * 10 + (s2[1] - '0');
    int m1 = (s1[3] - '0') * 10 + (s1[4] - '0');
    int m2 = (s2[3] - '0') * 10 + (s2[4] - '0');
    int time1 = d1 * 3600 + h1 * 60 + m1;
    int time2 = d2 * 3600 + h2 * 60 + m2;
    int sub = p * 3600;
    if (time2 - time1 >= sub)
        return true;
    else
        return false;
}

bool check_id(Person person) {      // �ж����֤���Ƿ�Ϸ�
    string id = person.ID;
    if (id.size() != 18)
        return false;
    for (int i = 0; i < id.size(); i++) {
        if (id[i] < '0' || id[i] > '9')
            return false;
    }
}

bool cmp(Person a, Person b) {     // ���� v �ıȽϣ���Ҫ�Ƚ�����ʱ�������˳��
    string s1 = a.post;
    string s2 = b.post;
    int d1 = a.date;
    int d2 = b.date;
    int h1 = (s1[0] - '0') * 10 + (s1[1] - '0');
    int h2 = (s2[0] - '0') * 10 + (s2[1] - '0');
    int m1 = (s1[3] - '0') * 10 + (s1[4] - '0');
    int m2 = (s2[3] - '0') * 10 + (s2[4] - '0');
    int time1 = d1 * 3600 + h1 * 60 + m1;
    int time2 = d2 * 3600 + h2 * 60 + m2;
    if (time1 == time2)
        return a.order < b.order;
    else
        return time1 < time2;
}

bool cmp2(Person a, Person b) {     // ���� v1 �ıȽϣ��Ƚ�����˳�򼴿�
    return a.order < b.order;
}


signed main() {
    IOS;
    cin >> d >> p;
    Person person;
    int cnt = 0;
    for (int i = 1; i <= d; i++) {
        int t, s;
        cin >> t >> s;
        v.clear();
        for (int j = 1; j <= t; j++) {
            cnt++;                              // ÿ��һ�����룬cnt�ͼ�һ����¼����˳��
            cin >> person.name >> person.ID
                >> person.situation >> person.post;
            person.date = i;                    // ����
            person.order = cnt;                 // ����˳��
            string id = person.ID;
            if (check_id(person) && s) {        // ������֤�Ϸ� �� ���е��컹�з�������
                if (m.count(id)) {              // ���֮ǰ���й��Ϸ�����
                    if (check_time(id, person.ID, m[id].date, person.date)) {   // ����Ƿ����㹻������
                        m[id] = person;         // ��������ʱ��
                        v.push_back(person);    // ��¼
                        s--;                    // ���������һ
                    }
                } else {                        // ֮ǰû�н��й��Ϸ�����
                    m[person.ID] = person;
                    v.push_back(person);        // ��¼
                    s--;
                }
            }
            if (person.situation == 1 && m.count(person.ID) && !m1.count(person.ID)) {  // ����Ϸ�����������������Ϊ1������v1��
                m1[person.ID] = person;
                v1.push_back(person);
            }
        }
        sort(v.begin(), v.end(), cmp);
        for (int j = 0; j < v.size(); j++) {
            cout << v[j].name << " " << v[j].ID << endl;
        }
    }

    sort(v1.begin(), v1.end(), cmp2);
    for (int j = 0; j < v1.size(); j++) {
        cout << v1[j].name << " " << v1[j].ID << endl;
    }
    return 0;
}