#include<bits/stdc++.h>

using namespace std;
string a, b;
string origin[10], trans[10];
struct Node {
    string str;
    int now;
};
map<string, int> m;
queue<struct Node> q;
int cnt;

string transform(string ori, int i, int index) {
    string ans = ori.substr(0, index);
    ans += trans[i];
    if (index + origin[i].size() > ori.size() - 1)
        return ans;
    ans += ori.substr(index + origin[i].size());
    return ans;
}

void bfs() {
    struct Node node, temp;
    node.str = a;
    node.now = 0;
    q.push(node);
    int i, j;
    while (!q.empty()) {
        node = q.front();
        q.pop();
        for (i = 0; i < cnt; i++) {
            for (j = 0; j < node.str.size(); j++) {
                string s = node.str.substr(j, origin[i].size());
                if (s == origin[i]) {
                    temp.str = transform(node.str, i, j);
                    temp.now = node.now + 1;
                    if (!m[temp.str]) {
                        if (temp.now > 10) {
                            cout << "NO ANSWER!" << endl;
                            return;
                        }
                        if (temp.str == b) {
                            cout << temp.now << endl;
                            return;
                        }
                        q.push(temp);
                        m[temp.str] = 1;
                    }
                }
            }
        }
    }
    cout << "NO ANSWER!" << endl;
    return;
}

int main() {
    cin >> a >> b;
    while (cin >> origin[cnt] >> trans[cnt]) {
        cnt++;
    }
    bfs();
    return 0;
}