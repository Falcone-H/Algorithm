// http://poj.org/problem?id=2785
// 折半枚举
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>

#define int long long
using namespace std;
const int N = 4005;
int a[N], b[N], c[N], d[N];
int n;
int v[N * N];

int binarySearch(int target) {
    int l = 0, r = n * n - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (v[mid] > target) r = mid - 1;
        else if (v[mid] < target) l = mid + 1;
        else return mid;
    }
    return -1;
}

signed main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        scanf("%lld", &b[i]);
        scanf("%lld", &c[i]);
        scanf("%lld", &d[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v[i * n + j] = c[i] + d[j];
        }
    }

    sort(v, v + n * n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cd = -(a[i] + b[j]);
            // 可能有多个 c[i] + d[j] 符合条件，因此，需要将它们的个数都找出来
            ans += upper_bound(v, v + n * n, cd) - lower_bound(v, v + n * n, cd);
        }
    }

    printf("%lld", ans);
    return 0;
}