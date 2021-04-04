#include<bits/stdc++.h>

using namespace std;

// 题解：https://www.jiuzhang.com/solution/maximum-product-subarray/
/*
 * Max[i]用来保存到第i个时的最大值
 * Min[i]用来保存到第i个时的最小值
 */

int maxProduct(vector<int> &nums) {
    int length = nums.size();
    int Max[length], Min[length];
    int res;
    res = Max[0] = Min[0] = nums[0];
    for (int i = 1; i < length; i++) {
        Min[i] = Max[i] = nums[i];
        if (nums[i] > 0) {
            Max[i] = max(Max[i], Max[i - 1] * nums[i]);
            Min[i] = min(Min[i], Min[i - 1] * nums[i]);
        } else {
            Max[i] = max(Max[i], Min[i - 1] * nums[i]);
            Min[i] = min(Min[i], Max[i - 1] * nums[i]);
        }
        res = max(res, Max[i]);
    }
    return res;
}

int maxProduct2(vector<int> &nums) {
    int length = nums.size();
    vector<int> Min, Max;
    Min.push_back(nums[0]);
    Max.push_back(nums[0]);
    int res = nums[0];
    for (int i = 1; i < length; i++) {
        Max.push_back(max(max(Min[i - 1] * nums[i], Max[i - 1] * nums[i]), nums[i]));
        Min.push_back(min(min(Min[i - 1] * nums[i], Max[i - 1] * nums[i]), nums[i]));
        res = max(res, Max[i]);
    }
    return res;
}

int main() {
    int n, num;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.emplace_back(num);
    }
    cout << maxProduct(v) << endl;
    return 0;
}