// AtCode Line++
// 思路：假如没有额外增加的那一条边，那么两点之间的距离就等于j - i，
//      现在加入了从x到y这一条边，意味着在y后面的边都得到松弛
//      所以，到x之前的点的距离就为j - i
//            从x之前到y之后的距离，就为x之前那个点到x的距离，加上y之后那个点到y的距离，再加上x与y之间的距离1

#include<bits/stdc++.h>
using namespace std;
int a[20005];
int main() {
    int n, x, y;
    cin >> n >> x >> y;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            int temp = min(j - i, abs(i - x) + abs(j - y) + 1);
            a[temp]++;
        }
    }
    for(int i = 1; i <= n - 1; i++) {
        cout << a[i] << endl;
    }
    return 0;
}