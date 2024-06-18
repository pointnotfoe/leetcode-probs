/*https://leetcode.com/problems/find-peak-element/description/
162. Find Peak Element
Solved
Medium
Topics
Companies
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 

Constraints:

1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
nums[i] != nums[i + 1] for all valid i.







*/

/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
11.12
MB
Beats
85.62%
of users with C++
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        int i = 0;
        while (i < len)
        {
            //cout << i << " " << nums[i] << endl;
            if (i == 0 || nums[i] > nums[i-1])
            {
                if (i + 1 >= len || nums[i] > nums[i+1])
                {
                    return i;
                }
            }
            if (i + 1 < len && nums[i+1] < nums[i])
            {
                i++;
            }
            i++;
        }
        return i;
    }
};


/*Intuition behind conditions | Complete Explanation | Diagram | Binary Search

Nam_22
Apr LeetCoding Challenge
2617
54796
Jun 22, 2021
Java
Binary Tree
Given an array, we need to find the peak element.
As, the subportions of the array are increasing/decreasing ( only then we would be able to find peak ), there are subportions of array which are sorted, so we could use binary search to get this problem done. But exactly how ?

This is an interesting part.

For a mid element, there could be three possible cases :
image

Case 1 : mid lies on the right of our result peak ( Observation : Our peak element search space is leftside )
Case 2 : mid is equal to the peak element ( Observation : mid element is greater than its neighbors )
Case 3 : mid lies on the left. ( Observation : Our peak element search space is rightside )

so, the code becomes

Some base cases :

The array could be strictly increasing or strictly decreasing and as we have to return any of the possible peaks, so we could add a condition to check whether the 1st element/last element could be the peak ). This point is also supported by the fact that, we are looking for mid-1/ mid+1 ( and these indices are compremised for 0th index / n-1 th index respectively.

So, our complete code becomes*/

		if(nums.length == 1) return 0; // single element
        
        int n = nums.length;
        
		// check if 0th/n-1th index is the peak element
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
		
		// search in the remaining array
        int start = 1;
        int end = n-2;
        
        while(start <= end) {
            int mid = start + (end - start)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;   // if mid == peak ( case 2 )
            else if(nums[mid] < nums[mid-1]) end = mid - 1; // downward slope and search space left side ( case 1)
            else if(nums[mid] < nums[mid+1]) start = mid + 1; // upward slope and search space right side ( case 3 )
        }
        return -1; // dummy return statement