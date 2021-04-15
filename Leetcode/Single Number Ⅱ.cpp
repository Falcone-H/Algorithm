// https://leetcode-cn.com/problems/single-number-ii/
// 思路：对于每一个二进制位，统计该位上为 1 的数的个数 cnt，如果 cnt % 3 == 0 ，则说明在该位上为 1 的数都有 3 个，
// 如果 cnt % 3 == 1，则说明 个数为 1 的数在该位上也有贡献，因此，用 ans |= mask 将该位取出。
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int mask = 1;
            mask <<= i;
            int cnt = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] & mask)
                    cnt++;
            }
            if (cnt % 3 != 0)
                ans |= mask;
        }
        return ans;
    }
};


