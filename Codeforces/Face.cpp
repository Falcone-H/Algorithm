// D - Face Produces Unhappiness
// 思路：因为每一次翻转，改变的都是两端的人的满意度，因此总的满意度每次最多会加2
//      所以答案就是min(2 * k + ans, n)

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == s[i - 1])
            ans++;
    }
    ans = min(2 * k + ans, n - 1);
    cout << ans << endl;
    return 0;
}