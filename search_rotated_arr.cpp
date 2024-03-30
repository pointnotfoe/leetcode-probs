/**
Autor: pointnotfoe
Leetcode: https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/
Runtime: 11 ms, faster than 15.45% of C++ online submissions for Search in Rotated Sorted Array.
Memory Usage: 11.1 MB, less than 29.96% of C++ online submissions for Search in Rotated Sorted Array.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = -1;
        int left = 0; 
        int right = nums.size()-1;
        while(left <= right && pivot == -1)
        {
            int mid = (left + right)/2;
            if(mid +1 < nums.size() && nums[mid] > nums[mid+1])
            {
                pivot = mid;
            }
            else if (mid >=1 && nums[mid] > nums[mid - 1] && nums[0] < nums[mid])
            {
                left = mid+1;
            }
            else
            {
                if(right == left)
                    break;
                right = mid;
            }
        }
        //cout << "pivot = " << pivot << endl;
        if(pivot == -1)
        {
            left = 0; 
            right = nums.size()-1;
        }
        else if (target >= nums[0] && target <= nums[pivot])
        {
            left = 0;
            right = pivot;
        }
        else
        {
            left = pivot +1;
            right = nums.size() - 1;
        }
        //cout << "left = " << left << ", right = "<< right << endl;
        while(left <= right)
        {
            int mid = (left + right)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            if(nums[mid] > target)
            {
                right = mid-1;
            }
            else
            {
                left = mid +1;
            }
        }
        return -1;
        
    }
};
