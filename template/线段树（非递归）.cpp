// https://blog.csdn.net/zearot/article/details/48299459
#include<bits/stdc++.h>

#define maxn 100007
using namespace std;
int A[maxn], n, N;  // 原数组，n 为原数组元素个数，N 为扩充元素个数
int Sum[maxn << 2];
int Add[maxn << 2];

// 建树
void Build(int n) {
    // 计算 N
    N = 1;
    while (N < n + 2) N <<= 1;

    // 更新叶节点
    for (int i = 1; i <= n; i++)
        Sum[N + i] = A[i];

    // 更新非叶节点
    for (int i = N - 1; i > 0; i--) {
        // 更新所有非叶节点的统计信息
        Sum[i] = Sum[i << 1] + Sum[i << 1 | 1];
        // 清空所有非叶节点的 Add 标记
        Add[i] = 0;
    }
}

// 单点修改，A[L] += C
void Update(int L, int C) {
    for (int s = N + L; s; s >>= 1)
        Sum[s] += C;
}

// 点修改下的区间查询，求 A[L..R] 的和
int Query(int L, int R) {
    int ans = 0;
    int s = N + L - 1;
    int t = N + R + 1;
    for (; s ^ t ^ 1; s >>= 1, t >>= 1) {
        if (~s & 1) ans += Sum[s ^ 1];
        if (t & 1) ans += Sum[t ^ 1];
    }
    return ans;
}

// 区间修改，A[L..R] += C
void Update(int L, int R, int C) {
    int s = N + L - 1;
    int t = N + R + 1;
    int ln = 0, rn = 0, x = 1;
    /*
     * ln: s 一路走来已经包含了多少个数
     * rn: t 一路走来已经包含了多少个数
     * x: 本层每个节点包含了多少个数
     */
    for (; s ^ t ^ 1; s >>= 1, t >>= 1, x <<= 1) {
        // 更新 Sum
        Sum[s] += C * ln;
        Sum[t] += C * rn;

        // 处理 Add
        if (~s & 1) {
            Add[s ^ 1] += C;
            Sum[s ^ 1] += C * x;
            ln += x;
        }
        if (t & 1) {
            Add[t ^ 1] += C;
            Sum[t ^ 1] += C * x;
            rn += x;
        }

        // 更新上层 Sum
        for (; s; s >>= 1, t >>= 1) {
            Sum[s] += C * ln;
            Sum[t] += C * rn;
        }
    }
}

// 区间修改下的区间查询，求 A[L..R] 的和
int QuerySegment(int L, int R) {
    int s = N + L - 1;
    int t = N + R + 1;
    int ln = 0, rn = 0, x = 1;
    int ans = 0;
    for (; s ^ t ^ 1; s >>= 1, t >>= 1, x <<= 1) {
        // 根据标记更新
        if (Add[s]) ans += Add[s] * ln;
        if (Add[t]) ans += Add[t] * rn;

        // 常规求和
        if (~s & 1) ans += Sum[s ^ 1], ln += x;
        if (t & 1) ans += Sum[t ^ 1], rn += x;

        // 处理上层标记
        for (; s; s >>= 1, t >>= 1) {
            ans += Add[s] * ln;
            ans += Add[t] * rn;
        }
        return ans;
    }
}

int main() {

}