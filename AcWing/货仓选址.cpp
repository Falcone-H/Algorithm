// https://www.acwing.com/problem/content/106/
// 思路：先将货仓的位置进行排序
// 假如，我们设置仓库的位置为 p, 在仓库的左边有 x 个货仓，在仓库的右边有 y 个货仓
// 现在，仓库的位置往左边移动 k 个距离，
// 那么，左边的所有货仓到仓库 p 的距离会减少 kx
// 而，右边的所有货仓到仓库 p 的距离会增加 ky
// 假如 x > y，则 kx > ky，总距离就会减少 kx - ky
// 假如 x < y，则 kx < ky，总距离就会增加 ky - kx
// 所以，我们自然要向总距离减少的方向移动，也就是向左移动
// 但是，什么时候停止移动呢？
// 就是当 x == y 的时候，就要停止移动
// 因此，我们就要选出中位数，让 x == y，从而得到最小的总距离
#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int a[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int midv;
    if (n % 2 == 1) midv = a[n / 2];
    else midv = (a[n / 2] + a[n / 2] + 1) / 2;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - midv);
    }
    cout << ans << endl;
    return 0;
}