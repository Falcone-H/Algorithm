// https://leetcode-cn.com/problems/single-number/submissions/
// 思路：异或运算满足交换律与结合律。因此，可以看作把出现两次的数都使用异或运算，变成0。那么最后剩下的，一定是只出现过一次的数
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto n : nums) {
            res ^= n;
        }
        return res;
    }
};