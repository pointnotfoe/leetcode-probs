
/*
287 https://leetcode.com/problems/find-the-duplicate-number/description/

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
 

Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity?

Runtime
67
ms
Beats
92.28%
of users with C++
Memory
63.60
MB
Beats
74.14%
of users with C++
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i =0; i < nums.size(); ++i)
        {
            while (nums[i] != i + 1)
            {
                if (nums[i] == nums[nums[i] - 1])
                    return nums[i];
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i =1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i-1])
            {
                return nums[i];
            }
        }
        return nums[0];
    }
};

/*
https://leetcode.com/problems/find-the-duplicate-number/solutions/1892872/c-6-approaches-interview-question/
Runtime
65
ms
Beats
94.51%
of users with C++
Memory
63.42
MB
Beats
89.59%
of users with C++
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0];
        int slow = nums[0];
        
        do{
            fast = nums[nums[fast]];
            slow = nums[slow];
        }while(fast != slow);
        
        fast = nums[0];
        
        while(fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};