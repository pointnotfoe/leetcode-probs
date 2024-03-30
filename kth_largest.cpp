/*
215: https://leetcode.com/problems/kth-largest-element-in-an-array/description/
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
*/
/*
Runtime
83
ms
Beats
80.95%
of users with C++
Memory
58.92
MB
Beats
65.43%
of users with C++
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};
/*
Runtime
104
ms
Beats
36.76%
of users with C++
Memory
61.18
MB
Beats
42.14%
of users with C++
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end());
        // return nums[nums.size() - k];
        //w/o sorting
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (auto &num: nums)
        {
            min_heap.push(num);
            while (min_heap.size() > k)
            {
                min_heap.pop();
            }
        }
        return min_heap.top();
    }
};


