/*
https://leetcode.com/problems/minimum-average-difference/submissions/1179325575/
2256. Minimum Average Difference
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed integer array nums of length n.

The average difference of the index i is the absolute difference between the average of the first i + 1 elements of nums and the average of the last n - i - 1 elements. Both averages should be rounded down to the nearest integer.

Return the index with the minimum average difference. If there are multiple such indices, return the smallest one.

Note:

The absolute difference of two numbers is the absolute value of their difference.
The average of n elements is the sum of the n elements divided (integer division) by n.
The average of 0 elements is considered to be 0.
 
 Example 1:

Input: nums = [2,5,3,9,5,3]
Output: 3
Explanation:
- The average difference of index 0 is: |2 / 1 - (5 + 3 + 9 + 5 + 3) / 5| = |2 / 1 - 25 / 5| = |2 - 5| = 3.
- The average difference of index 1 is: |(2 + 5) / 2 - (3 + 9 + 5 + 3) / 4| = |7 / 2 - 20 / 4| = |3 - 5| = 2.
- The average difference of index 2 is: |(2 + 5 + 3) / 3 - (9 + 5 + 3) / 3| = |10 / 3 - 17 / 3| = |3 - 5| = 2.
- The average difference of index 3 is: |(2 + 5 + 3 + 9) / 4 - (5 + 3) / 2| = |19 / 4 - 8 / 2| = |4 - 4| = 0.
- The average difference of index 4 is: |(2 + 5 + 3 + 9 + 5) / 5 - 3 / 1| = |24 / 5 - 3 / 1| = |4 - 3| = 1.
- The average difference of index 5 is: |(2 + 5 + 3 + 9 + 5 + 3) / 6 - 0| = |27 / 6 - 0| = |4 - 0| = 4.
The average difference of index 3 is the minimum average difference so return 3.
Example 2:

Input: nums = [0]
Output: 0
Explanation:
The only index is 0 so return 0.
The average difference of index 0 is: |0 / 1 - 0| = |0 - 0| = 0.

Runtime
86
ms
Beats
50.95%
of users with C+
*/

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int N = nums.size();
        long sum = 0;
        for (const auto & num : nums)
        {
            sum += num;
        }
        long min_avg = std::numeric_limits<long>::max();
        long left_sum = 0;
        long right_sum = sum;
        long avg;
        long ret_i =0;
        for (int i = 0; i < N; i++)
        {
            left_sum += nums[i];
            right_sum -= nums[i];
            avg = left_sum ? left_sum/(i+1) : 0;
            avg -= ((N-i-1) ? right_sum/(N-i-1) : 0);
            avg = abs(avg);

            // min_avg = min(min_avg, avg);
            if (avg < min_avg)
            {
                min_avg = avg;
                ret_i = i;
            }
        }
        return ret_i;
    }
};