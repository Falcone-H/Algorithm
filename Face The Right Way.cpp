// POJ 3276
// 挑战程序设计竞赛 第150页
#include<bits/stdc++.h>

using namespace std;
const int MAX_N = 100005;
int N;
int dir[MAX_N];     // 牛的方向(0:F, 1:B)
int f[MAX_N];       // 区间[i, i + k - 1]是否进行反转

// 固定k，求对应的最小操作回数
// 无解的话，则返回-1
int calc(int K) {
    memset(f, 0, sizeof(f));
    int res = 0;
    int sum = 0;    // f的和
    for (int i = 0; i + K - 1 < N; i++) {
        // 计算区间 [i, i + k - 1]
        if ((dir[i] + sum) % 2 != 0) {
            // 面朝前方的牛被反转到面朝后方
            res++;
            f[i] = 1;
        }
        sum += f[i];
        if (i - K + 1 >= 0) {
            sum -= f[i - K + 1];
        }
    }
    // 检查剩下的牛是否有面朝后方的情况
    for (int i = N - K + 1; i < N; i++) {
        if ((dir[i] + sum) % 2 != 0) {
            return -1;  // 无解
        }
        if (i - K + 1 >= 0) {
            sum -= f[i - K + 1];
        }
    }
    return res;
}

void solve() {
    int K = 1;
    int M = N;
    for (int k = 1; k <= N; k++) {
        int m = calc(k);
        if (m >= 0 && M > m) {
            M = m;
            K = k;
        }
    }
    cout << M << K << endl;
}

int main() {
    cin >> N;
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'F')
            dir[i] = 0;
        else
            dir[i] = 1;
    }
    return 0;
}