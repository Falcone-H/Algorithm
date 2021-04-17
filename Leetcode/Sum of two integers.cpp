class Solution {
public:
    int getSum(int a, int b) {
        if(!b)
            return a;
        int sum = a ^ b;
        int carry = ((unsigned int)a & b) << 1; // 使用 unsigned int 是为了防止 a 是负数
        return getSum(sum, carry);
    }
};