// https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/
// 寻找 left 和 right 之间的最长相同前缀，然后，从第一位不相同的数开始，相与之后都会变成0
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int mask = 1 << 30;
        int ans = 0;
        while(mask > 0 && (left & mask) == (right & mask)) {
            ans |= (left & mask);
            mask >>= 1;
        }
        return ans;
    }
};