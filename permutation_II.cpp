/*https://leetcode.com/problems/permutations-ii/description/
47. Permutations II
Solved
Medium
Topics
Companies
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/

/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
11.39
MB
Beats
63.95%
of users with C++
*/
class Solution {
public:
    int size;
    //https://leetcode.com/problems/permutations-ii/solutions/18596/a-simple-c-solution-in-only-20-lines/
    void recr(vector<int> num, int idx, vector<vector<int>> &result)
    {
        if (idx >= size - 1)
        {
            result.push_back(num);
            return;
        }
        for (int current = idx; current < size; current++)
        {
            if (current != idx && num[idx] == num[current]) continue;
            swap(num[idx], num[current]);
            recr(num, idx + 1, result);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        size = nums.size();
        vector<vector<int>> result;
        recr(nums, 0, result);
        return result;
    }
};