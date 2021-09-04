// https://www.acwing.com/problem/content/3826/
// 思路：KMP算法的getNext()
#include<bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;
int Next[N];
int state[N];

void getNext(int next[], string t) {
    next[0] = -1;
    int j = 0, k = -1;
    while (j < t.size()) {
        if ((k == -1) || (t[j] == t[k])) {
            j++;
            k++;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        memset(Next, 0, sizeof Next);
        memset(state, 0, sizeof state);
        getNext(Next, s);
        for (int i = 0; i < s.size(); i++) {
            state[Next[i]] = 1;
        }
        for(int i = 0; i <= s.size(); i++) {
            cout << Next[i] << " ";
        }
        cout << endl;
        int ans = Next[s.size()];
        while (!state[ans]) {
            ans = Next[ans];
            if (ans == -1)
                break;
        }
        if (ans == -1 || ans == 0) cout << "not exist\n";
        else {
            for(int i = 0; i < ans; i++) {
                cout << s[i];
            }
            cout << endl;
        }
    }
    return 0;
}