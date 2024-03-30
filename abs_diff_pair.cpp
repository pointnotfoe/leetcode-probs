/*
https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/
2006. Count Number of Pairs With Absolute Difference K

Given an integer array nums and an integer k, return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.

The value of |x| is defined as:

x if x >= 0.
-x if x < 0.
 

Example 1:

Input: nums = [1,2,2,1], k = 1
Output: 4
Explanation: The pairs with an absolute difference of 1 are:
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
Example 2:

Input: nums = [1,3], k = 3
Output: 0
Explanation: There are no pairs with an absolute difference of 3.
Example 3:

Input: nums = [3,2,1,5,4], k = 2
Output: 3
Explanation: The pairs with an absolute difference of 2 are:
- [3,2,1,5,4]
- [3,2,1,5,4]
- [3,2,1,5,4]
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
1 <= k <= 99
*/
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        //votrubac
        // int cnt[101] = {}, res = 0;
        // for (auto n : nums)
        //     ++cnt[n];
        // for (int i = k + 1; i < 101; ++i)
        //     res += cnt[i] * cnt[i - k];
        // return res;

        unordered_map<int, int> count;
        int solutions = 0;
        for (const auto &a: nums)
        {
            int sub = abs(a - k);
            int add = abs(a + k);
            auto sub_it = count.find(sub);
            auto add_it = count.find(add);
            if (sub_it != count.end() && abs(sub - a) == k)
            {
                solutions += count[sub];
            }
            if (add_it != count.end() && abs(add - a) == k)
            {
                solutions += count[add];
            }
            count[a]++;
        }
        return solutions;
    }
};