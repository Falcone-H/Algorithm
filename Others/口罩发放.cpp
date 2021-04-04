#include<bits/stdc++.h>

#define int long long
#define IOS ios::sync_with_stdio(false)
using namespace std;
struct Person {
    string name;    // 姓名
    string ID;      // 身份证
    int situation;  // 病况 0 或 1
    string post;    // 申请时间
    int date;       // 在第几天申请的
    int order;      // 申请顺序
};

vector<Person> v, v1;       // v负责记录合法的申请，v1负责记录身体情况为1的合法申请
map<string, Person> m, m1;  // m负责判断该身份证号之前是否进行过合法申请（即是否被收进了v中），m1负责判断该合法申请是否情况为1（即是否被收进了v1中）
int d, p;                   // 题目输入的天数，间隔数

bool check_time(string s1, string s2, int d1, int d2) {     // 将时间转化为分钟数，再判断是否间隔足够的天数
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

bool check_id(Person person) {      // 判断身份证号是否合法
    string id = person.ID;
    if (id.size() != 18)
        return false;
    for (int i = 0; i < id.size(); i++) {
        if (id[i] < '0' || id[i] > '9')
            return false;
    }
}

bool cmp(Person a, Person b) {     // 用于 v 的比较，需要比较申请时间和申请顺序
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

bool cmp2(Person a, Person b) {     // 用于 v1 的比较，比较申请顺序即可
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
            cnt++;                              // 每有一条申请，cnt就加一，记录申请顺序
            cin >> person.name >> person.ID
                >> person.situation >> person.post;
            person.date = i;                    // 天数
            person.order = cnt;                 // 申请顺序
            string id = person.ID;
            if (check_id(person) && s) {        // 如果身份证合法 且 还有当天还有发放名额
                if (m.count(id)) {              // 如果之前进行过合法申请
                    if (check_time(id, person.ID, m[id].date, person.date)) {   // 检查是否间隔足够的天数
                        m[id] = person;         // 更新申请时间
                        v.push_back(person);    // 记录
                        s--;                    // 发放名额减一
                    }
                } else {                        // 之前没有进行过合法申请
                    m[person.ID] = person;
                    v.push_back(person);        // 记录
                    s--;
                }
            }
            if (person.situation == 1 && m.count(person.ID) && !m1.count(person.ID)) {  // 如果合法申请过，且身体情况为1，收入v1中
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