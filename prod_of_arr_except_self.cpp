/*
Author: pointnotfoe
Leetcode: https://leetcode.com/problems/product-of-array-except-self/

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)


Runtime: 20 ms, faster than 88.04% of C++ online submissions for Product of Array Except Self.
Memory Usage: 24.9 MB, less than 41.64% of C++ online submissions for Product of Array Except Self.
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int prod = 1;
        int zero_count = 0;
        for (int &a : nums)
        {
            if (a == 0)
            {
                zero_count++;
            }
            else //if (0 == zero_count)
            {
                prod *= a;
            }
        }
        for (int &a : nums)
        {
            if (a == 0 && zero_count == 1)
                result.push_back(prod);
            else if (zero_count > 0)
                result.push_back(0);
            else
                result.push_back(prod/a);
        }
        
        return result;
    }
};