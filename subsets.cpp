/*
https://leetcode.com/problems/subsets/description/
Code
Testcase
Testcase
Test Result
78. Subsets
Solved
Medium
Topics
Companies
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/
class Solution {
    vector<vector<int>> result;
public:
    //https://leetcode.com/problems/subsets/solutions/27278/c-recursive-iterative-bit-manipulation/
    /*
        Runtime
    0
    ms
    Beats
    100.00%
    of users with C++
    Memory
    8.46
    MB
    Beats
    53.11%
    of users with C++
    */
    // void recr(vector<int>& nums, vector<int> &current, int idx)
    // {
    //     result.push_back(current);
    //     for (; idx < nums.size(); idx++)
    //     {
    //         current.push_back(nums[idx]);
    //         recr(nums, current, idx + 1);
    //         current.pop_back();
    //     }
    // }

    // vector<vector<int>> subsets(vector<int>& nums) {
    //     vector<int> current;
    //     recr(nums, current, 0);
    //     return result;
    // }
    /*
    Runtime
    5
    ms
    Beats
    14.05%
    of users with C++
    Memory
    8.35
    MB
    Beats
    64.30%
    of users with C++
    */
    vector<vector<int>> subsets(vector<int>& nums) {
        result.push_back({});
        for (auto & num: nums)
        {
            int cur_length = result.size();
            for (int i = 0; i < cur_length; i++)
            {
                result.push_back(result[i]);
                result.back().push_back(num);
            }
        }
        return result;
    }
};