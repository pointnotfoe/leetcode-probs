/*

Autor: pointnotfoe 
Leetcode: https://leetcode.com/problems/merge-intervals/
56. Merge Intervals
Medium

16518

590

Add to List

Share
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
Accepted
1,670,462
Submissions
3,645,108
*/
//mine
/*
Runtime: 76 ms, faster than 47.38% of C++ online submissions for Merge Intervals.
Memory Usage: 19.1 MB, less than 70.01% of C++ online submissions for Merge Intervals.
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        size_t len = intervals.size();
        if (len < 1)
            return result;
        if (len > 1)
            sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < len; i++)
        {
            //if the start of this interval is within the previous one
            if (intervals[i][0] <= end)
            {
               //and if this end is bigger then merge two intervals by taking the bigger end
                if (intervals[i][1] >= end)
                    end = intervals[i][1];
            }
            else//if no overlap
            {
                result.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        result.push_back({start,end});
        return result;

    }
};