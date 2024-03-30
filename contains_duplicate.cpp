/*
217 https://leetcode.com/problems/contains-duplicate/description/
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

/*
Runtime
92
ms
Beats
61.14%
of users with C++
Memory
73.15
MB
Beats
43.67%
of users with C++
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> unique;
        for (auto num : nums)
        {
            if (unique.count(num))
            {
                return true;
            }
            unique.insert(num);
        }
        return false;
    }
};
/*
Runtime
105
ms
Beats
32.14%
of users with C++
Memory
73.13
MB
Beats
43.67%
of users with C++

for (const auto &num : nums)
*/

/*
Runtime
97
ms
Beats
47.28%
of users with C++
Memory
73.24
MB
Beats
26.60%
of users with C++

for (int idx = 0; idx < nums.size(); idx++)
*/

/*
Runtime
76
ms
Beats
95.29%
of users with C++
Memory
73.02
MB
Beats
60.35%
of users with C++

for (auto &num : nums)
*/