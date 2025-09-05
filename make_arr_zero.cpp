/*
https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/submissions/1561126238/
2357. Make Array Zero by Subtracting Equal Amounts
Solved
Easy
Topics
Companies
Hint
You are given a non-negative integer array nums. In one operation, you must:

Choose a positive integer x such that x is less than or equal to the smallest non-zero element in nums.
Subtract x from every positive element in nums.
Return the minimum number of operations to make every element in nums equal to 0.

 

Example 1:

Input: nums = [1,5,0,3,5]
Output: 3
Explanation:
In the first operation, choose x = 1. Now, nums = [0,4,0,2,4].
In the second operation, choose x = 2. Now, nums = [0,2,0,0,2].
In the third operation, choose x = 2. Now, nums = [0,0,0,0,0].
Example 2:

Input: nums = [0]
Output: 0
Explanation: Each element in nums is already 0 so no operations are needed.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100
Seen this question in a real interview before?
1/5
Yes
No
Accepted
141K
Submissions
193K
Acceptance Rate
73.1%
Topics
Companies
Hint 1
Hint 2
Hint 3
Similar Questions
Discussion (33)
*/
/*
Accepted
95 / 95 testcases passed
pointnotfoe
pointnotfoe
submitted at Mar 02, 2025 22:31

Solution
Runtime
0
ms
Beats
100.00%
Analyze Complexity
Memory
10.94
MB
Beats
69.86%
*/
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> unique;
        for (auto &num : nums)
        {
            if (num != 0)
            {
                unique.insert(num);
            }
        }
        return unique.size();
    }
};