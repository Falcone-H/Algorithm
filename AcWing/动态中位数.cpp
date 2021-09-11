// https://www.acwing.com/solution/content/34043/
// 对顶堆
#include<bits/stdc++.h>

using namespace std;
const int N = 10005;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int num, n;
        scanf("%d%d", &num, &n);
        printf("%d %d\n", num, (n + 1) / 2);
        priority_queue<int> down;   // 大根堆
        priority_queue<int, vector<int>, greater<>> up; // 小根堆
        int x;
        int k = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);

            if (down.empty() || x <= down.top()) down.push(x);
            else up.push(x);

            if (down.size() > up.size() + 1) {
                up.push(down.top());
                down.pop();
            }
            if (up.size() > down.size()) {
                down.push(up.top());
                up.pop();
            }

            if (i % 2 == 0) {
                printf("%d ", down.top());
                k++;
                if (k >= 10) {
                    k = 0;
                    printf("\n");
                }
            }
        }
        if (k) printf("\n");
    }
    return 0;
}