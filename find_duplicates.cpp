/*
442. Find All Duplicates in an Array https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
Medium
Topics
Companies
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: []
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
Each element in nums appears once or twice.
*/
/*
Runtime
38
ms
Beats
64.49%
of users with C++
Memory
35.99
MB
Beats
61.87%
of users with C++
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            int current_num = nums[i];
            int correct_num = i + 1;
            if (current_num < 0)
            {
                continue;
            }
            else if (current_num == correct_num)
            {
                nums[i] = -correct_num;
            }
            else
            {
                while (current_num != correct_num && current_num > 0)
                {
                    if (nums[current_num - 1] == -current_num)
                    {
                        result.push_back(current_num);
                    }
                    swap(nums[i], nums[current_num - 1]);
                    nums[current_num - 1] = -current_num;
                    current_num = nums[i];
                }
            }
            
        }

        return result;
    }
};

/*
https://leetcode.com/problems/find-all-duplicates-in-an-array/solutions/92395/c-beats-98/
nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
if(nums[abs(nums[i])-1] > 0) res.push_back(abs(nums [i]));
Imagine going through the list and finding a 5 somewhere random (let's say at index 1). 
What the first line says is go to index "5" (whatever may be there) and make it negative whatever the current value is 
(say a 1 sits there, make it -1). Now say we come across another 5 at index 3, we again go to index 5 and make it negative. 
Now the 1 that is at index 5 is now positive, and when we check we'll know we've visited this value twice. 
That means whatever value we're at in our loop is the duplicated value.

*/
vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i ++){
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            if(nums[abs(nums[i])-1] > 0) res.push_back(abs(nums [i]));
        }
        return res;
    }