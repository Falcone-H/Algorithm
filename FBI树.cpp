#include<bits/stdc++.h>

using namespace std;
struct Node {
    char val;
} node[2000];
int maxSize;

void build(int root, string s) {
    int isB = 1;
    int isI = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0')
            isI = 0;
        if (s[i] == '1')
            isB = 0;
        if (!isI && !isB) {
            break;
        }
    }
    if (isB) {
        node[root].val = 'B';
    } else if (isI) {
        node[root].val = 'I';
    } else {
        node[root].val = 'F';
    }
    if (s.size() > 1) {
        build(root * 2, s.substr(0, s.size() / 2));
        build(root * 2 + 1, s.substr(s.size() / 2));
    }
}

void printtree(int root) {
    int left = root * 2;
    int right = root * 2 + 1;
    if (left <= maxSize)
        printtree(left);
    if (right <= maxSize)
        printtree(right);
    cout << node[root].val;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    maxSize = 2 * s.size() - 1;
    build(1, s);
    printtree(1);
    return 0;
}