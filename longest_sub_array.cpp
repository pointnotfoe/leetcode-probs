/*
1438 Medium
Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

 

Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.
Example 2:

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
Example 3:

Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
0 <= limit <= 109
*/
/*
Runtime
79
ms
Beats
59.62%
of users with C++
Memory
66.10
MB
Beats
39.93%
of users with C++
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<pair<int, int>> max_q;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > min_q;
        int left = 0;
        int max_window = 0;
        int len = nums.size();
        for (int right = 0; right < len; ++right)
        {
            max_q.push(make_pair(nums[right], right));
            min_q.push(make_pair(nums[right], right));
            if (abs(max_q.top().first - min_q.top().first) <= limit)
            {
                max_window = max(right - left + 1, max_window);
            }
            else
            {
                left++;
                while (max_q.size() && max_q.top().second < left)
                {
                    max_q.pop();
                }
                while (min_q.size() && min_q.top().second < left)
                {
                    min_q.pop();
                }
            }
        }
        return max_window;
    }
};

/*https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
Runtime
53
ms
Beats
95.77%
of users with C++
Memory
54.34
MB
Beats
85.61%
of users with C++
*/
    int longestSubarray(vector<int>& A, int limit) {
        deque<int> maxd, mind;
        int i = 0, j;
        for (j = 0; j < A.size(); ++j) {
            while (!maxd.empty() && A[j] > maxd.back()) maxd.pop_back();
            while (!mind.empty() && A[j] < mind.back()) mind.pop_back();
            maxd.push_back(A[j]);
            mind.push_back(A[j]);
            if (maxd.front() - mind.front() > limit) {
                if (maxd.front() == A[i]) maxd.pop_front();
                if (mind.front() == A[i]) mind.pop_front();
                ++i;
            }
        }
        return j - i;
    }