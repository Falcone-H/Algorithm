// https://leetcode-cn.com/problems/single-number-iii/submissions/
// 思路：首先，对数组内每一个都进行异或，最终得到的结果是那两个出现次数为 1 的数的异或和 s
// 然后，在 s 中取得从右到左第一个 1 的位置 k。（其他位置的 1 也可以）
// 接下来，对原数组中每一个数，都检查在 k 这一位上，是 1 还是 0。由此，可以将原数组分为两堆
// 之后，对其中一堆的所有数进行一次异或和，得到的结果就是其中一个出现次数为 1 的数
// 再用 ans2 = s ^ ans1，就可以得到另一个出现次数为 1 的数
class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        int s = 0;
        for (auto n : nums)
            s ^= n;
        int k = 0;
        int ans1 = 0;
        while (!(s >> k & 1))
            k++;
        for (auto n : nums) {
            if (n >> k & 1)
                ans1 ^= n;
        }
        int ans2 = ans1 ^s;
        return vector<int>({ans1, ans2});
    }
};