// https://leetcode-cn.com/problems/house-robber-ii/
// DP，状态转移方程：dp[i + 1] = max(dp[i], dp[i - 1] + nums[i])
// dp[i] 代表前 i 间房屋能获得的最大价值
// 这题是一个环，要避免第一间和最后一间同时被偷
// 因此，在不偷第一间房子 (下标为0) 的情况下，对 1 到 n 进行分析
//      在不偷最后一间房子 (下标为n) 的情况下，对 0 到 n - 1 进行分析
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() - 1;
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        return max(myRob(nums, 0, n - 1),
                   myRob(nums, 1, n) );
    }
    int myRob(vector<int>& nums, int l, int r) {
        int pre = 0, cur = 0;
        int tmp;
        for(int i = l; i <= r; i++) {
            tmp = max(cur, pre + nums[i]);
            pre = cur;
            cur = tmp;
        }
        return cur;
    }
};